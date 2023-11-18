#include <iostream>
#include <conio.h>
#include <windows.h>  
#include <ncurses/ncurses.h>


int maxY,maxX;
int x,y;
char arah = 'd';
int score = 0;
bool game = true;
void Console(){
   if(kbhit()){
        switch(getch()){
            case 'a' : arah = 'a'; break;
            case 'w' : arah = 'w'; break;
            case 's' : arah = 's'; break;
            case 'd' : arah = 'd'; break;
            case 'q' : game = false; break;
        }
    }
}

void Draw(){
    clear();
    WINDOW *win = newwin(maxY, maxX, 0, 0);
    refresh();
    box(win,0,0);
    wrefresh(win);
    mvprintw(y,x,"*");
    refresh();
    Sleep(30);
    
}

void Algorithm(){
    if(arah == 'w'){
        y--;
    }
    if(arah == 's'){
        y++;
    }
    if(arah == 'a'){
        x--;
    }
    if(arah == 'd'){
        x++;
    }
}

int main() {
    // Initialize ncurses
    initscr();
    noecho();  // Don't display typed characters
    curs_set(0);  // Hide the cursor

    getmaxyx(stdscr, maxY, maxX);


     y = maxY / 2;
     x = maxX / 2; 

    do{
        Draw();
        Console();
        Algorithm();
    }while(game);

    //width :100 / 140
    //height: 30

    // End ncurses
    endwin();

    return 0;
}
