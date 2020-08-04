#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include"mouse.h"
#include"HANZI.H"
#include"SVGAmode.H"


int main(){
    int mark = 1;
    int flag = 0;   //储存是否退出，0:继续循环，1：结束程序

    SetSVGA256();
    Initmouse(1,1023,1,767);

    while(1){
        switch(mark){
            case 1:{
                mark = Welcome();
                break;
            }

            case -1:{
                flag = 1;
                break;
            }
            default: break;
        }
        if(flag==1) break;  //结束程序
    }
    return 0;
}
