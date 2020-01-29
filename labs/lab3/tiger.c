#include "ezdraw.h"
#include <stdio.h>

#define WINDOWWIDTH 800
#define WINDOWHEIGHT 600
#define ORANGE 252,169,3
#define PURP 189,28,214
#define BLACK 60,60,60
#define WHITE 250,250,250

enum boolean{FALSE, TRUE};

void updateDisplay(){
EZ_SetBackColor(PURP);
EZ_ClearDrawing();
EZ_SetColor(ORANGE);
EZ_FillCircle(400,300,125);
EZ_FillCircle(300,400,50);
EZ_FillCircle(500,400,50);
EZ_SetColor(BLACK);
EZ_DrawLine(400,260,500,270);
EZ_DrawLine(400,260,500,260);
EZ_DrawLine(400,260,500,250);
EZ_DrawLine(400,260,300,270);
EZ_DrawLine(400,260,300,260);
EZ_DrawLine(400,260,300,250);
EZ_SetColor(WHITE);
EZ_FillCircle(400,260,45);
EZ_SetColor(BLACK);
EZ_FillCircle(400,300,30);

EZ_DrawLine(350,350,325,350);
EZ_DrawLine(450,350,475,350);
EZ_DisplayDrawing();
}

int main(){
 int quit=FALSE;
 EZ_Init(WINDOWWIDTH,WINDOWHEIGHT,"Go Tigers!");
 while(!quit){
	quit = EZ_HandleEvents(updateDisplay, NULL, NULL, NULL);
	}
 EZ_Quit();
} 
