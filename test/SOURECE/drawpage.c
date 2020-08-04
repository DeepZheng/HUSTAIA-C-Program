
#include "draw.h"
#include "hanzi.h"
#include "SVGAmode.h"


void draw_welcome(){
	int i;
	Bar(1,1,1023,767,52);
	for(i=1;i<5;i++){
		printHZ16(250+i,150+i,"帅团",25,5,5,15);
		printHZ16(180+i,250+i,"本地生活一站式团购平台",25,3,3,6);
	}
	printHZ16(250,150,"帅团",0,5,5,15);
	printHZ16(180,250,"本地生活一站式团购平台",0,3,3,6);

	LineThickSha(100,200,140,300,43,25,40,1);
	LineThickSha(130,200,150,230,43,25,150,1);
	LineThickSha(220,300,230,330,43,25,200,1);
	
	
	LineThickSha(830,200,800,300,31,25,40,1);
	LineThickSha(860,200,850,230,31,25,100,1);
	LineThickSha(830,270,820,300,31,25,80,1);

	Barshadow(380,590,450,620,14,25);
	printHZ16(400,600,"登录",0,1,1,1);
	Barshadow(480,590,550,620,30,25);
	printHZ16(500,600,"注册",0,1,1,1);
	Linex(600,620,635,620,31);
	printHZ16(600,600,"退出",31,1,1,1);
	
	return;
 }
/****************
	display main menu.
	contributor:Richard Liu
****************/
