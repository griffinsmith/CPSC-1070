#include "ezdraw.h"
#include <stdio.h>

#define WINDOWWIDTH 700
#define WINDOWHEIGHT 900
#define RED 255, 0, 0
#define BLACK 0,0,0 
#define WHITE 255,255,255

int click;
int x;
int y;
enum boolean {FALSE, TRUE};

void updateDisplay(){

    if (click!=0){
        EZ_SetColor(RED);
        EZ_FillCircle(x,y,10);
        EZ_DrawPoint(x,y);
    }
    EZ_DisplayDrawing();
}

void handleButton(int updown, int mousex, int mousey){
    click=updown;
    x=mousex;
    y=mousey;
}

int main(){
    int quit=FALSE;
    click=0;
    EZ_Init(WINDOWWIDTH, WINDOWHEIGHT, "POLYLINE");
    while(!quit){
        quit = EZ_HandleEvents(updateDisplay, NULL, handleButton, NULL);
    }
    EZ_Quit();
    }
