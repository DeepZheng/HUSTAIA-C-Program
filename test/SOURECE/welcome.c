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
        if(Mouse_press(600,600,635,620)==1){    //ÍË³ö
			return -1;
            break;
        }
    }
}