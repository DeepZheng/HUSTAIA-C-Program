#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include"mouse.h"
#include"HANZI.H"
#include"SVGAmode.H"
#include"welcome.h"


int Welcome(){
    Initmouse(1,1023,1,767);
    draw_welcome();

    while(1){
        Newxy();
        if(Mouse_press(380,590,450,620)==1){    //µÇÂ¼
            return 2;
        }
        if(Mouse_press(480,590,550,620)==1){    //×¢²á
            return 3;
        }
        if(Mouse_press(600,600,635,620)==1){    //ÍË³ö
			return -1;
        }
    }
}