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
    int flag = 0;   //�����Ƿ��˳���0:����ѭ����1����������

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
        if(flag==1) break;  //��������
    }
    return 0;
}
