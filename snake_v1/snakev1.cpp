#include <iostream>
#include<vector>
#include<conio.h>
#include<windows.h>

using namespace std;

const int WIDTH = 30;
const int HEIGHT = 30;

enum Direction {STOP = 0 , LEFT , RIGHT , UP , DOWN};
Direction dir;

int sx , sy , fx , fy , score;
vector<int> tailx , taily;
int ntail = 0;
bool gameOver;

void setup(){
    gameOver = false;
    dir = STOP;
    sx = WIDTH/2;
    sy = HEIGHT/2;
    fx = rand() % WIDTH;
    fy = rand() % HEIGHT;
    score = 0;
    tailx.clear();
    taily.clear();
    ntail = 0;
}

void Draw(){
    system("cls");

    for(int i = 0 ; i < WIDTH + 2 ; ++i) cout << "_";
    cout << "\n";

    for(int y = 0 ; y < HEIGHT ; ++y){
        for(int x = 0 ; x < WIDTH ; ++x){
            if(x == 0) cout << "|";
            if(y == sy && x == sx)cout << "O";
            else if(y == fy && x == fx) cout <<"0";
            else{
                bool isTail = false;
                for(int i = 0 ; i < ntail ; ++i){
                    if(x == tailx[i] && y == taily[i]){
                        cout << "o";
                        isTail = true;
                        break;
                    }
                }
                if(!isTail) cout << " ";
            }
            if(x == WIDTH - 1) cout << "|";
        }
        cout << "\n";
    }
    cout<<"|";
    for(int i = 1 ; i < WIDTH + 1 ; ++i) cout << "_";
    cout<<"|";
    cout << "\n";
}

void inputcall(){
    if(_kbhit()){
        switch(_getch()){
            case 'a' : case 75: dir = LEFT ; break;
            case 'd' : case 77: dir = RIGHT ; break;
            case 'w' : case 72: dir = UP ; break;
            case 's' : case 80: dir = DOWN ; break;
            case 27 : gameOver = true; break;
        }
    }
}

void logic(){
    
    int px = sx;
    int py = sy;

    switch(dir){
        case LEFT : --px; break;
        case RIGHT : ++px; break;
        case UP : --py ; break;
        case DOWN : ++py ; break;
        default : break;
    }

    if(px >= WIDTH || px < 0 || py >= HEIGHT || py < 0) {
        gameOver = true;
        return;
    }

    for(int i = 0 ; i < ntail ; ++i){
        if(tailx[i] == px && taily[i] == py) {
            gameOver = true;
            return;
        }
    }

    if(px == fx && py == fy){
        score += 10;
        fx = rand() % WIDTH;
        fy = rand() % HEIGHT;
        ntail++;
    }

    if(ntail > 0){
        tailx.insert(tailx.begin(), sx);
        taily.insert(taily.begin(), sy);
        if(tailx.size() > ntail){
            tailx.pop_back();
            taily.pop_back();
        }
    }

    sx = px;
    sy = py;
}

int main(){
    setup();
    while(!gameOver){
        
        inputcall();
        logic();
        Draw();
        Sleep(50);
    }
    cout << "GAME OVER\n" ;
    cout << score << "\n";
    return 0;
}