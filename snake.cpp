#include <iostream>
#include <conio.h>
#include <windows.h>  
#include <ncurses/ncurses.h>

using namespace std;

int maxX,maxY,x,y;
bool game = true;
char arah = 'w';
int score = 0;
int fruitX,fruitY;
int tailLength = 1;
int tailX[100],tailY[100];  

void Draw(){
    WINDOW *win = newwin(maxY, maxX, 0, 0);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
    mvprintw(y,x,"O");
    mvprintw(fruitY,fruitX,"#");
    for(int i=0;i<tailLength;i++){
        mvprintw(tailY[i],tailX[i],"o");
    }
    refresh();
    Sleep(100);
}

void Console(){
    if(kbhit()){
        switch(getch()){
            case 'a' : if(arah!='d')arah = 'a';break;
            case 'd' : if(arah!='a')arah = 'd';break;
            case 'w' : if(arah!='s')arah = 'w';break;
            case 's' : if(arah!='w')arah = 's';break;
            case 'q' : game = false; break;
        }
    }
}

void Algorithm(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prevX2,prevY2;
    tailX[0] = x;
    tailY[0] = y;

    for(int i=1;i<tailLength;i++){
        prevX2 = tailX[i];
        prevY2 = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prevX2;
        prevY = prevY2;
    }

    if(arah=='a')x--;
    if(arah=='d')x++;
    if(arah=='s')y++;
    if(arah=='w')y--;   

    if (x == fruitX && y == fruitY) {
        fruitX = rand() % maxX;
        fruitY = rand() % maxY;
        score++;
        tailLength++;
    }
    if(x <= 0 || y <=0 || x>=maxX || y>=maxY){
        game = false;
    }
    for(int i=0;i<tailLength;i++){
        if(x==tailX[i]&&y==tailY[i])game=false;
    }
}

int main(){
    initscr();
    noecho(); 
    curs_set(0);
    getmaxyx(stdscr,maxY,maxX);
    x = maxX/2,y=maxY/2;
    fruitX = rand()%maxX;
    fruitY= rand()%maxY;


    do{
        Draw();
        Console();
        Algorithm();
    }while(game);
    mvprintw(maxY/2,maxX/2,"Score anda adalah : %d",score);
    refresh();
    getch();
    endwin();
}
