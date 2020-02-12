#include "ezdraw.h"
#include <stdio.h>

#define WINDOWWIDTH 900
#define WINDOWHEIGHT 700
#define TAN 201,158,38
#define DARKTAN 150,119,33
#define BLUE 41,125,133
#define LIGHTBLUE 0,252,248

int bubblex=655;
int bubbley=225;
int bubbler=1;
int startbubble=0;
int targetx=600;
int targety=95;
int targeth=110;
int targetw=110;
enum boolean{FALSE, TRUE};

void updateDisplay(){
EZ_ClearDrawing();
EZ_SetColor(TAN);
EZ_FillRect(80,75,500,50);
EZ_SetColor(DARKTAN);
EZ_FillRect(580,75,150,150);
EZ_SetColor(BLUE);
EZ_FillRect(targetx,targety,targeth,targetw);
if (startbubble){
	if (bubbley>775){
	bubblex=655;
	bubbley=225;
	bubbler=1;
	startbubble=0;
	}
	EZ_SetColor(LIGHTBLUE);
	EZ_FillCircle(bubblex,bubbley,bubbler);
	bubbley+=5;
	if (bubbler<76){
	bubbler+=3;
	}
}

EZ_DisplayDrawing();
}

void handleButton(int updown, int mousex, int mousey){

if (updown){
	if(mousex>targetx && mousex<(targetx+targetw) && mousey>targety && mousey<(targety+targeth)){
		startbubble=1;
	}	
}
}
int main(){
int quit=FALSE;
EZ_Init(WINDOWWIDTH,WINDOWHEIGHT, "Bubble Pipe");
while(!quit){
	quit=EZ_HandleEvents(updateDisplay, NULL, handleButton, NULL);
}
EZ_Quit();
}
