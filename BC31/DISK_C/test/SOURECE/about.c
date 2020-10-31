//关于界面
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <time.h>
#include "DRAW.H"
#include "mouse.h"
#include "HANZI.H"
#include "input.h"
#include "SVGAmode.H"
#include "about.h"
#include "drawpage.h"
#include "color.h"

int About(){
    int flag = 0;
    Initmouse(1,1023,1,767);

    draw_aboutpage();
    while(1){
        Newxy();
        //标
        if(Mouse_above(900,700,935,720)&&flag==0){
            flag = 1;
            printHZ16(900,700,"返回",DARK_GRAY,1,1,1);
        }
        if(Mouse_aboveother(900,700,935,720)&&flag ==1){
            flag = 0;
            printHZ16(900,700,"返回",WHITE,1,1,1);
        }
        //返回首页
        if (Mouse_press(900,700,935,720))
            return 1;   
    }
}

