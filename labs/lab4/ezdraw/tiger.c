#include "ezdraw.h"
#include <stdio.h>

//defines all of the colors and the dimensions of the windown
#define WINDOWWIDTH 800
#define WINDOWHEIGHT 600
#define ORANGE 252,169,3
#define PURP 189,28,214
#define BLACK 60,60,60
#define WHITE 250,250,250
//declared globally in order to open and close the eyes of the tiger
int close_eyes;
enum boolean{FALSE, TRUE};

//Displays tiger
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
//if the mouse is not held down 
if(close_eyes==0){
EZ_FillRect(346,346,26,6);
EZ_FillRect(436,346,26,6);
}
//if mouse button is held down
else{
EZ_FillCircle(359,349,10);
EZ_FillCircle(451,349,10);
}
//displays the drawing
EZ_DisplayDrawing();
}
//function to handle the mouse button
void handleButton(int updown, int mousex, int mousey){
close_eyes=updown;
}
//main 
int main(){
 int quit=FALSE;
 //initializes close_eyes
 close_eyes=0;
 //title of window
 EZ_Init(WINDOWWIDTH,WINDOWHEIGHT,"Go Tigers!");
 //handle events to update display and handle button
 while(!quit){
	quit = EZ_HandleEvents(updateDisplay, NULL, handleButton, NULL);
	}
 EZ_Quit();
} 
