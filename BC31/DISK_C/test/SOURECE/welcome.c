#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include"mouse.h"
#include"HANZI.H"
#include"SVGAmode.H"
#include"welcome.h"
#include"color.h"


int Welcome(){
    int flag[4] = {0};
    Initmouse(1,1023,1,767);
    draw_welcome();

    while(1){
        Newxy();
        //鼠标移在按钮上阴影功能
        if (Mouse_above(380,590,450,620) && flag[0] == 0)
        {
            Barshadow(380,590,450,620,JASMINE,GRAY);
            printHZ16(400,600,"登录",0,1,1,1);
            flag[0] = 1;
        }
        else if (Mouse_aboveother(380,590,450,620) && flag[0])
        {
            Barshadow(380,590,450,620,PEACH,GRAY);
            printHZ16(400,600,"登录",0,1,1,1);
            flag[0] = 0;
        }

        if (Mouse_above(480,590,550,620) && flag[1] == 0)
        {
            Barshadow(480,590,550,620,DARK_KHAKI,GRAY);
            printHZ16(500,600,"注册",BLACK,1,1,1);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(480,590,550,620) && flag[1])
        {
            Barshadow(480,590,550,620,TAN,GRAY);
            printHZ16(500,600,"注册",BLACK,1,1,1);
            flag[1] = 0;
        }
        if (Mouse_above(600,600,635,620) && flag[2] == 0)
        {
            printHZ16(600,600,"退出",DARK_GRAY,1,1,1);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(600,600,635,620) && flag[2])
        {
            printHZ16(600,600,"退出",WHITE,1,1,1);
            flag[2] = 0;
        }
        if (Mouse_above(900,700,970,720) && flag[3] == 0)
        {
            printHZ16(900,700,"关于我们",DARK_GRAY,1,1,1);
            flag[3] = 1;
        }
        else if (Mouse_aboveother(900,700,970,720) && flag[3])
        {
            printHZ16(900,700,"关于我们",WHITE,1,1,1);
            flag[3] = 0;
        }
        //点击操作
        if(Mouse_press(380,590,450,620)==1){    //登录
            return 2;
        }
        if(Mouse_press(480,590,550,620)==1){    //注册
            return 3;
        }
        if(Mouse_press(600,600,635,620)==1){    //退出
			return -1;
        }
        //关于界面
        if(Mouse_press(900,700,970,720)){
            return 11;
        }
    }
}