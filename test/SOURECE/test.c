#include<stdio.h>
#include<graphics.h>
#include<bios.h>
#include<conio.h>
#include"hz.h"
#include"mouse.h"

int main(){
    int graphdriver=DETECT,graphmode;
	initgraph(&graphdriver,&graphmode,"BORLANDC\\BGI");
    mouseinit();
	setbkcolor(BLUE);
	rectangle(200,100,400,200);
	puthz(300,150,"Œ“ «Àß∏Á",16,24,RED);
	while(1){
		newmouse(&MouseX, &MouseY, &press);
		if(getch())	break;
    }
    return 0;
}