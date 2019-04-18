#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
//#include <conio.h>
#include <time.h>
 
using namespace std;
 
const int KEY_LEFT = 'a', KEY_RIGHT = 'd', KEY_UP = 'w', KEY_DOWN = 's';
const int HEIGHT=25 , WIDTH=40;
bool hasntWon = true;
int Hp=100;
int Point=0;
 
enum DirectionX {Right, Left};
enum DirectionY {Up, Down};
 
struct Player{
    char sprite;
    int x;
    int y;
};
 
struct Enemy{
    char sprite;
    int x;
    int y;
    DirectionX pastDirX;
    DirectionY pastDirY;
};
 
unsigned char MoveEnemy(Enemy& enemy, unsigned char maze[HEIGHT][WIDTH], int i, int j, string& smove, bool& nc){
    if(nc){
        bool goUp = false;
        //possible up, down, right, left
        bool psbUp = false;
        bool psbDown = false;
        bool psbRight = false;
        bool psbLeft = false;
 
        //is it possible in all given directions?
        if(maze[enemy.y][enemy.x+1] != '#'){//RIGHT
            psbRight = true;
        }
        if(maze[enemy.y][enemy.x-1] != '#'){//LEFT
            psbLeft = true;
        }
        if(maze[enemy.y+1][enemy.x] != '#'){//DOWN
            psbDown = true;
        }
        if(maze[enemy.y-1][enemy.x] != '#'){//UP
            psbUp = true;
        }
 
        //movement tracking
        enum Mv {up, right, down, left, NA};
        Mv move = NA;
 
        //previous movement
        if(smove == "up"){
            move = up;
        }
        else if(smove == "right"){
            move = right;
        }
        else if(smove == "down"){
            move = down;
        }
        else if(smove == "left"){
            move = left;
        }
        else{
            move = NA;
        }
 
        //if previous movement in x was right, but now it's not possible to move to the right
        if(enemy.pastDirX == Right && !psbRight){
            if(enemy.pastDirY == Up){//was the past movement in Y UP?
                if(psbUp){//is it possible to move up
                    move = up;
                }
                else if(psbDown && move != up){//if not is it possible to move down as long as we didn't come from up?
                    move = down;
                }
                else if(psbLeft){//or is it then possible to move left?
                    move = left;
                }
                else{//if there is no other choice move up
                    move = down;
                }
            }
            else{//was the past movement in Y Down?
                if(psbDown){//is it possible to move down?
                    move = down;
                }
                else if(psbUp && move != down){//if not is it possible to move up as long as we didn't come from down?
                    move = up;
                }
                else if(psbLeft){//or is it then possible to move left?
                    move = left;
                }
                else{//if there is no other choice move up
                    move = up;
                }
            }
        }
        else if(enemy.pastDirX == Right && psbRight){
            move = right;//if we can move right and we want to go right, go right.
        }
        else if(enemy.pastDirX == Left && !psbLeft){//STORY REPEATS LIKE THIS FOR ALL DIRECTIONS
            if(enemy.pastDirY == Up){
                if(psbUp){
                    move = up;
                }
                else if(psbDown && move != up){
                    move = down;
                }
                else if(psbRight){
                    move = right;
                }
                else{
                    move = down;
                }
            }
            else{
                if(psbDown){
                    move = down;
                }
                else if(psbUp && move != down){
                    move = up;
                }
                else if(psbRight){
                    move = right;
                }
                else{
                    move = up;
                }
            }
        }
        else if(enemy.pastDirX == Left && psbLeft){
            move = left;
        }
        else if(enemy.pastDirY == Up && !psbUp){
            if(enemy.pastDirX == Right){
                if(psbRight){
                    move = right;
                }
                else if(psbLeft && move != right){
                    move = left;
                }
                else if(psbDown){
                    move = down;
                }
                else{
                    move = left;
                }
            }
            else{
                if(psbLeft){
                    move = left;
                }
                else if(psbRight && move != left){
                    move = right;
                }
                else if(psbDown){
                    move = down;
                }
                else{
                    move = right;
                }
            }
        }
        else if(enemy.pastDirY == Up && psbUp){
            move = up;
        }
        else if(enemy.pastDirY == Down && !psbDown){
            if(enemy.pastDirX == Right){
                if(psbRight){
                    move = right;
                }
                else if(psbLeft && move != right){
                    move = left;
                }
                else if(psbUp){
                    move = up;
                }
                else{
                    move = left;
                }
            }
            else{
                if(psbLeft){
                    move = left;
                }
                else if(psbRight && move != left){
                    move = right;
                }
                else if(psbRight){
                    move = up;
                }
                else{
                    move = right;
                }
            }
        }
        else if(enemy.pastDirY == Down && psbDown){
            move = down;
        }
 
        //what is the said movement=
        switch(move){
            case up://set variables accordingly
                maze[enemy.y][enemy.x] = ' ';
                enemy.pastDirY = Up;
                smove = "up";
                enemy.y--;
                break;
            case right:
                maze[enemy.y][enemy.x] = ' ';
                enemy.pastDirX = Right;
                smove = "right";
                enemy.x++;
                break;
            case down:
                maze[enemy.y][enemy.x] = ' ';
                enemy.pastDirY = Down;
                smove = "down";
                enemy.y++;
                break;
            case left:
                maze[enemy.y][enemy.x] = ' ';
                enemy.pastDirX = Left;
                smove = "left";
                enemy.x--;
                break;
            case NA:
                smove = "NA";
                break;
        }
    }
    nc = false;
    return maze[i][j];
}
 
int main()
{
    srand (time(NULL));
 
    unsigned char maze[HEIGHT][WIDTH] = {
    '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
    ' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#',
    '#','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','#',' ','#','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#',' ','#',
    '#',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','#',
    '#',' ','#','#',' ','#','#','#',' ','#',' ','#',' ','#',' ',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#',
    '#',' ','#',' ',' ','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',
    '#',' ','#',' ','#','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#',' ','#','#',' ','#',
    '#',' ','#',' ','#',' ',' ','#',' ','#','#','#','#',' ','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
    '#',' ','#',' ','#','#',' ','#',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#','#',' ','#','#',' ','#',' ','#','#',
    '#',' ','#',' ',' ',' ',' ','#',' ','#','#','#','#',' ','#','#','#','#','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#','#',' ',' ','#',' ','#',' ',' ','#',
    '#',' ','#','#','#','#',' ','#',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ','#','#','#','#','#',' ','#',
    '#',' ',' ',' ',' ','#',' ','#',' ','#','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#',' ',' ',' ','#',' ','#',' ','#',
    '#',' ','#','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',
    '#',' ','#',' ',' ','#',' ','#',' ','#','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#','#','#',' ','#',' ','#',' ','#','#','#','#','#',
    '#',' ','#',' ','#','#',' ','#',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',
    '#',' ','#',' ','#',' ',' ','#',' ','#','#','#','#','#','#',' ','#',' ','#','#',' ','#','#','#','#','#','#','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',
    '#',' ','#',' ','#',' ','#','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',
    '#',' ','#',' ','#',' ',' ','#',' ','#',' ','#','#','#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',
    '#',' ','#','#','#','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#',
    '#',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#',
    '#',' ','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#',' ',' ',' ','#',' ','#','#','#',' ','#',
    '#',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',
    '#',' ','#','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',
    '#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',
    '#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
    };
 
    Player player;
    player.sprite = '@';
    player.x = 0;
    player.y = 1;
 
    Enemy enemy1;
    enemy1.sprite = '<';
    enemy1.x = rand()%WIDTH;
    enemy1.y = rand()%HEIGHT;
    enemy1.pastDirX = Left;
    enemy1.pastDirY = Up;
 
    while(maze[enemy1.y][enemy1.x] != ' '){
        enemy1.x = rand()%WIDTH;
        enemy1.y = rand()%HEIGHT;
    }
    if(maze[enemy1.y][enemy1.x] == ' '){
        maze[enemy1.y][enemy1.x] = enemy1.sprite;
    }
 
    Enemy enemy2;
    enemy2.sprite = '<';
    enemy2.x = rand()%WIDTH;
    enemy2.y = rand()%HEIGHT;
    enemy2.pastDirX = Left;
    enemy2.pastDirY = Up;
 
    while(maze[enemy2.y][enemy2.x] != ' '){
        enemy2.x = rand()%WIDTH;
        enemy2.y = rand()%HEIGHT;
    }
    if(maze[enemy2.y][enemy2.x] == ' '){
        maze[enemy2.y][enemy2.x] = enemy2.sprite;
    }
 
    Enemy enemy3;
    enemy3.sprite = '<';
    enemy3.x = rand()%WIDTH;
    enemy3.y = rand()%HEIGHT;
    enemy3.pastDirX = Left;
    enemy3.pastDirY = Up;
 
    while(maze[enemy3.y][enemy3.x] != ' '){
        enemy3.x = rand()%WIDTH;
        enemy3.y = rand()%HEIGHT;
    }
    if(maze[enemy3.y][enemy3.x] == ' '){
        maze[enemy3.y][enemy3.x] = enemy3.sprite;
    }
 
    Enemy enemy4;
    enemy4.sprite = '<';
    enemy4.x = rand()%WIDTH;
    enemy4.y = rand()%HEIGHT;
    enemy4.pastDirX = Left;
    enemy4.pastDirY = Up;
 
    while(maze[enemy4.y][enemy4.x] != ' '){
        enemy4.x = rand()%WIDTH;
        enemy4.y = rand()%HEIGHT;
    }
    if(maze[enemy4.y][enemy4.x] == ' '){
        maze[enemy4.y][enemy4.x] = enemy4.sprite;
    }
 
    Enemy enemy5;
    enemy5.sprite = '<';
    enemy5.x = rand()%WIDTH;
    enemy5.y = rand()%HEIGHT;
    enemy5.pastDirX = Left;
    enemy5.pastDirY = Up;
 
    while(maze[enemy5.y][enemy5.x] != ' '){
        enemy5.x = rand()%WIDTH;
        enemy5.y = rand()%HEIGHT;
    }
    if(maze[enemy5.y][enemy5.x] == ' '){
        maze[enemy5.y][enemy5.x] = enemy5.sprite;
    }
 
    string prevmove1 = "NA";
    string prevmove2 = "NA";
    string prevmove3 = "NA";
    string prevmove4 = "NA";
    string prevmove5 = "NA";
 
 
    while(hasntWon){
        if(maze[player.y][player.x] == ' '){
            maze[player.y][player.x] = player.sprite;
    }
 
    maze[enemy1.y][enemy1.x] = enemy1.sprite;
    maze[enemy2.y][enemy2.x] = enemy2.sprite;
    maze[enemy3.y][enemy3.x] = enemy3.sprite;
    maze[enemy4.y][enemy4.x] = enemy4.sprite;
    maze[enemy5.y][enemy5.x] = enemy5.sprite;
 
    for(int y=0 ; y<HEIGHT ; y++){
        cout<<endl;
        for(int x=0 ; x<WIDTH ; x++){
            cout<<maze[y][x];
        }
    }
 
    cout<<endl;
    cout<<endl<<"HP: "<<Hp;
 
    //char key = getch();
  streambuf *teclado = cin.rdbuf();
  char key = teclado->sbumpc();
  cout << "CARACTER LEÍDO: " << key << endl;


 
    switch(key){
        case KEY_LEFT:
            if(maze[player.y][player.x-1] != '#'){
                maze[player.y][player.x] = ' ';
                player.x--;
                if(maze[player.y][player.x-1] == '<'){
                    Hp=Hp-20;
                }
            }
            break;
        case KEY_UP:
            if(maze[player.y-1][player.x] != '#'){
                maze[player.y][player.x] = ' ';
                player.y--;
                if(maze[player.y-1][player.x] == '<'){
                    Hp=Hp-20;
                }
            }
            break;
        case KEY_DOWN:
            if(maze[player.y+1][player.x] != '#'){
                maze[player.y][player.x] = ' ';
                player.y++;
                if(maze[player.y+1][player.x] == '<'){
                    Hp=Hp-20;
                }
            }
            break;
        case KEY_RIGHT:
            if(maze[player.y][player.x+1] != '#'){
                maze[player.y][player.x] = ' ';
                player.x++;
                if(maze[player.y][player.x+1] == '<'){
                    Hp=Hp-20;
                }
            }
            break;
        case 'q':
            exit(0);
            break;
    }
 
    //int x = enemy1.x;
    //int y = enemy1.y;
    bool once1 = true;
    bool once2 = true;
    bool once3 = true;
    bool once4 = true;
    bool once5 = true;
 
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            maze[i][j] = MoveEnemy(enemy1, maze, i, j, prevmove1, once1);
            maze[i][j] = MoveEnemy(enemy2, maze, i, j, prevmove2, once2);
            maze[i][j] = MoveEnemy(enemy3, maze, i, j, prevmove3, once3);
            maze[i][j] = MoveEnemy(enemy4, maze, i, j, prevmove4, once4);
            maze[i][j] = MoveEnemy(enemy5, maze, i, j, prevmove5, once5);
        }
    }
 
    if(player.x==enemy1.x && player.y==enemy1.y){
        Hp=Hp-30;
    }
    if(player.x==enemy2.x && player.y==enemy2.y){
        Hp=Hp-30;
    }
    if(player.x==enemy3.x && player.y==enemy3.y){
        Hp=Hp-30;
    }
    if(player.x==enemy4.x && player.y==enemy4.y){
        Hp=Hp-30;
    }
    if(player.x==enemy5.x && player.y==enemy5.y){
        Hp=Hp-30;
    }
 
    if(Hp==0){
        cout<<endl<<endl<<"YOU LOSE!"<<endl<<endl;
        system("PAUSE");
        hasntWon = false;
    }
    if(player.x == WIDTH-1){
        cout<<endl<<endl<<"A WINRAR IS YOU!"<<endl<<endl;
        system("PAUSE");
        hasntWon = false;
    }
    system("clear");
}
}
