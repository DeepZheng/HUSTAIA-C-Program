#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <time.h>
#include "DRAW.H"
#include "mouse.h"
#include "HANZI.H"
#include "input.h"
#include "SVGAmode.H"
#include "userpage.h"
#include "drawpage.h"
#include "color.h"

int UserMain(User *loginuser,Cart *usercart, recommends *recommend)
{
    //unsigned char *buffer;
    int flag[7] = {0};
	char picname[30] = "..\\file\\bmp\\";
   // char picname[30] = "..\\file\\bmp\\";
    strcat(picname, recommend->re[0].picpath);
    strcat(picname, ".bmp");
    Initmouse(1, 1023, 1, 767);
    draw_usermainpage();

    Bar(140, 80, 530, 480, LIGHT_SALMON);
    printHZ16(330, 150, "����", 0, 4, 4, 8);
    LineThickSha(320, 220, 350, 230, BLACK, GRAY, 140, 6);

    Bar(140, 482, 400, 750, GOLDEN);
    printHZ16(180, 520, "�Ҿ�", 0, 4, 4, 8);
    LineThickSha(170, 590, 190, 600, 0, 25, 140, 6);

    Bar(531, 80, 800, 480, LIGHT_SEA_GREEN);
    printHZ16(580, 150, "����", 0, 4, 4, 8);
    LineThickSha(570, 220, 590, 230, 0, 25, 140, 6);

    Bar(401, 482, 800, 750, LAWN_GREEN);
    printHZ16(530, 550, "ͼ��", 0, 4, 4, 8);
    LineThickSha(520, 620, 540, 630, BLACK, GRAY, 140, 6);

    Bar(800, 400, 1010, 750, ALIZARIN_CRIMSON);
    printHZ16(835, 410, "���մ���", 0, 2, 2, 3);
    Putbmp64k(840, 500, picname);
    put_rename(835, 630, recommend->re[0]);
    printHZ12(820, 680,"������",0,2,2,3);
    put_asc(920,680,recommend->re[0].price,DARK_KHAKI,2,2);
    //����ӹ��ﳵ����
    Circlefill(985,730,15,DEEP_SKY_BLUE);
    Linex(970,730,1000,730,WHITE);
    Liney(985,715,985,745,WHITE);
   //put_asc(835, 650, recommend->re[0].picpath, BLACK, 2, 2);
    //printHZ16(870,200,"��",0,4,4,7);
    //printHZ16(870,300,"��",0,4,4,7);
    //printHZ16(870,400,"��",0,4,4,7);
    LineThickSha(805, 460, 812, 470, BLACK, GRAY, 180, 6);
    //�û���Ϣ��
    Bar(800, 80, 1010, 400, PINK);
    Putbmp64k(830, 90, "..\\file\\bmp\\info2.bmp");
    printHZ16(860, 250, "��ӭ", BLACK, 2, 2, 1);
    put_asc(830, 330, loginuser->name, DARK_GRAY, 2, 2);

    while (1)
    {
        Newxy();
        if (Mouse_press(900, 20, 970, 50))
            return 1;
        if (Mouse_press(700, 15, 810, 30))
            return 5; //�����������
        if (Mouse_press(800, 80, 1010, 400))  
            return 51; //�����û���Ϣҳ��

        if(Mouse_press(970,715,1000,745)){
            if(AddGood(recommend->re[0],usercart)){
                put_add();
                delay(600);
                return 4;
            }
        }
        //������ڰ�ť����Ӱ����
        if (Mouse_above(1, 75, 110, 125) && !flag[0])
        {
            Bar(1, 80, 110, 125, JASMINE);
            printHZ16(30, 100, "����", DIMGRAY, 1, 1, 1);
            flag[0] = 1;
        }
        else if (Mouse_aboveother(1, 75, 110, 125) && flag[0])
        {
            Bar(1, 80, 110, 125, MUSTARD);
            printHZ16(30, 100, "����", DIMGRAY, 1, 1, 1);
            flag[0] = 0;
        }

        if (Mouse_above(1, 126, 110, 175) && !flag[1])
        {
            Bar(1, 126, 110, 175, JASMINE);
            printHZ16(30, 150, "�Ҿ�", DIMGRAY, 1, 1, 1);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1, 126, 110, 175) && flag[1])
        {
            Bar(1, 126, 110, 175, MUSTARD);
            printHZ16(30, 150, "�Ҿ�", DIMGRAY, 1, 1, 1);
            flag[1] = 0;
        }

        if (Mouse_above(1, 176, 110, 225) && !flag[2])
        {
            Bar(1, 176, 110, 225, JASMINE);
            printHZ16(30, 200, "����", DIMGRAY, 1, 1, 1);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1, 176, 110, 225) && flag[2])
        {
            Bar(1, 176, 110, 225, MUSTARD);
            printHZ16(30, 200, "����", DIMGRAY, 1, 1, 1);
            flag[2] = 0;
        }

        if (Mouse_above(1, 226, 110, 275) && !flag[3])
        {
            Bar(1, 226, 110, 275, JASMINE);
            printHZ16(30, 250, "ͼ��", DIMGRAY, 1, 1, 1);
            flag[3] = 1;
        }
        else if (Mouse_aboveother(1, 226, 110, 275) && flag[3])
        {
            Bar(1, 226, 110, 275, MUSTARD);
            printHZ16(30, 250, "ͼ��", DIMGRAY, 1, 1, 1);
            flag[3] = 0;
        }

        if (Mouse_above(1, 276, 110, 325) && !flag[4])
        {
            Bar(1, 276, 110, 325, JASMINE);
            printHZ16(30, 300, "��ʳ", DIMGRAY, 1, 1, 1);
            flag[4] = 1;
        }
        else if (Mouse_aboveother(1, 276, 110, 325) && flag[4])
        {
            Bar(1, 276, 110, 325, MUSTARD);
            printHZ16(30, 300, "��ʳ", DIMGRAY, 1, 1, 1);
            flag[4] = 0;
        }
        if (Mouse_above(700,15,740,30) && !flag[5])
        {        
            Linex(700,30,740,30,DARK_GRAY);
            printHZ16(700,15,"��������",DARK_GRAY,1,1,1);
            
            flag[5] = 1;
        }
        else if (Mouse_aboveother(700,15,740,30) && flag[5])
        {
            printHZ16(700,15,"��������" ,0,1,1,1);
            flag[5] = 0;
        }
        if (Mouse_above(920,15,960,30) && !flag[6])
        {        
            Linex(920,30,960,30,DARK_GRAY);
            printHZ16(920,15,"�˳�",DARK_GRAY,1,1,1);
            flag[6] = 1;
        }
        else if (Mouse_aboveother(920,15,960,30) && flag[6])
        {
            printHZ16(920,15,"�˳�",0,1,1,1);
            
            flag[6] = 0;
        }
        //if(Mouse_press(801,80,1000,750)) return 41;
        if (Mouse_press(401, 482, 800, 750) || Mouse_press(1, 226, 110, 275))
            return 42; //ͼ��
        if (Mouse_press(140, 80, 530, 480) || Mouse_press(1, 75, 110, 125))
            return 43; //����
        if (Mouse_press(531, 80, 800, 480) || Mouse_press(1, 176, 110, 225))
            return 44; //����
        if (Mouse_press(140, 482, 400, 750) || Mouse_press(1, 126, 110, 175))
            return 45; //�Ҿ�
        if(Mouse_press(15,650,85,720))
            return 52;  //���ﳵ
        
    }
}

int UserCenter(User *loginuser)
{
    int flag[6] = {0};
    Initmouse(1, 1023, 1, 767);
    draw_usercenter();

    while (1)
    {
        Newxy();
        if (Mouse_press(900, 20, 970, 50))
            return 1;
        if (Mouse_press(700, 15, 810, 30))
            return 4; //������ҳ
        //������ڰ�ť����Ӱ����
        if (Mouse_above(1, 60, 110, 140) && flag[0] == 0)
        {
            Bar(1, 60, 110, 140, JASMINE);
            printHZ16(10, 100, "������Ϣ", BLACK, 1, 1, 2);
            flag[0] = 1;
        }
        else if (Mouse_aboveother(1, 60, 110, 140) && flag[0])
        {
            Bar(1, 60, 110, 140, MUSTARD);
            printHZ16(10, 100, "������Ϣ", BLACK, 1, 1, 2);
            flag[0] = 0;
        }

        if (Mouse_above(1, 141, 110, 220) && flag[1] == 0)
        {
            Bar(1, 141, 110, 220, JASMINE);
            printHZ16(10, 180, "���ﳵ", BLACK, 1, 1, 2);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1, 141, 110, 220) && flag[1])
        {
            Bar(1, 141, 110, 220, MUSTARD);
            printHZ16(10, 180, "���ﳵ", BLACK, 1, 1, 2);
            flag[1] = 0;
        }

        if (Mouse_above(1, 221, 110, 300) && flag[2] == 0)
        {
            Bar(1, 221, 110, 300, JASMINE);
            printHZ16(10, 260, "�ҵĶ���", BLACK, 1, 1, 2);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1, 221, 110, 300) && flag[2])
        {
            Bar(1, 221, 110, 300, MUSTARD);
            printHZ16(10, 260, "�ҵĶ���", BLACK, 1, 1, 2);
            flag[2] = 0;
        }

        if (Mouse_above(1, 301, 110, 380) && flag[3] == 0)
        {
            Bar(1, 301, 110, 380, JASMINE);
            printHZ16(10, 340, "���۶���", BLACK, 1, 1, 2);
            flag[3] = 1;
        }
        else if (Mouse_aboveother(1, 301, 110, 380) && flag[3])
        {
            Bar(1, 301, 110, 380, MUSTARD);
            printHZ16(10, 340, "���۶���", BLACK, 1, 1, 2);
            flag[3] = 0;
        }
        if (Mouse_above(700,15,740,30) && !flag[4])
        {        
            Linex(700,30,740,30,DARK_GRAY);
            printHZ16(700,15,"������ҳ",DARK_GRAY,1,1,1);
            
            flag[4] = 1;
        }
        else if (Mouse_aboveother(700,15,740,30) && flag[4])
        {
            printHZ16(700,15,"������ҳ" ,0,1,1,1);
            flag[4] = 0;
        }
        if (Mouse_above(920,15,960,30) && !flag[5])
        {        
            Linex(920,30,960,30,DARK_GRAY);
            printHZ16(920,15,"�˳�",DARK_GRAY,1,1,1);
            
            flag[5] = 1;
        }
        else if (Mouse_aboveother(920,15,960,30) && flag[5])
        {
            printHZ16(920,15,"�˳�",0,1,1,1);
            flag[5] = 0;
        }
        //�����
        if (Mouse_press(1, 60, 110, 140))
        {
            return 51;
        }

        if (Mouse_press(1, 141, 110, 220))
        {
            return 52;
        }

        if (Mouse_press(1, 221, 110, 300))
        {
            return 53;
        }
        
        if(Mouse_press(1,301,110,380)){
            Barshadow(300,300,700,450,MUSTARD,DARK_GRAY);
            printHZ16(305,320,"������δ��ͨ",BLACK,2,2,1);
            printHZ16(305,380,"�����ڴ�",BLACK,2,2,1);
            Put_Asc16_Size(435,375,3,3,'>',BLACK);
            Put_Asc16_Size(445,375,3,3,'_',BLACK);
            Put_Asc16_Size(455,375,3,3,'<',BLACK);
            delay(1000);
            return 5;
        }
    }
}

int UserInfo(User *loginuser)
{
    char code[15], tel[12];
    int flag[6] ={0}; 
    int codelen = 0, tellen = 0;
    Initmouse(1, 1023, 1, 767);
    draw_userinfo(loginuser);

    while (1)
    {
        Newxy();
        if (Mouse_press(900, 20, 970, 50))
            return 1;
        if (Mouse_press(700, 15, 810, 30))
            return 4; //������ҳ
        //������ڰ�ť����Ӱ����
        if (Mouse_above(1, 60, 110, 140) && flag[0] == 0)
        {
            Bar(1, 60, 110, 140, JASMINE);
            printHZ16(10, 100, "������Ϣ", BLACK, 1, 1, 2);
            flag[0] = 1;
        }
        else if (Mouse_aboveother(1, 60, 110, 140) && flag[0])
        {
            Bar(1, 60, 110, 140, MUSTARD);
            printHZ16(10, 100, "������Ϣ", BLACK, 1, 1, 2);
            flag[0] = 0;
        }

        if (Mouse_above(1, 141, 110, 220) && flag[1] == 0)
        {
            Bar(1, 141, 110, 220, JASMINE);
            printHZ16(10, 180, "���ﳵ", BLACK, 1, 1, 2);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1, 141, 110, 220) && flag[1])
        {
            Bar(1, 141, 110, 220, MUSTARD);
            printHZ16(10, 180, "���ﳵ", BLACK, 1, 1, 2);
            flag[1] = 0;
        }

        if (Mouse_above(1, 221, 110, 300) && flag[2] == 0)
        {
            Bar(1, 221, 110, 300, JASMINE);
            printHZ16(10, 260, "�ҵĶ���", BLACK, 1, 1, 2);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1, 221, 110, 300) && flag[2])
        {
            Bar(1, 221, 110, 300, MUSTARD);
            printHZ16(10, 260, "�ҵĶ���", BLACK, 1, 1, 2);
            flag[2] = 0;
        }

        if (Mouse_above(1, 301, 110, 380) && flag[3] == 0)
        {
            Bar(1, 301, 110, 380, JASMINE);
            printHZ16(10, 340, "���۶���", BLACK, 1, 1, 2);
            flag[3] = 1;
        }
        else if (Mouse_aboveother(1, 301, 110, 380) && flag[3])
        {
            Bar(1, 301, 110, 380, MUSTARD);
            printHZ16(10, 340, "���۶���", BLACK, 1, 1, 2);
            flag[3] = 0;
        }
        if (Mouse_above(700,15,740,30) && !flag[4])
        {       
            Linex(700,30,740,30,DARK_GRAY);
            printHZ16(700,15,"������ҳ",DARK_GRAY,1,1,1); 
            
            flag[4] = 1;
        }
        else if (Mouse_aboveother(700,15,740,30) && flag[4])
        {
            printHZ16(700,15,"������ҳ" ,0,1,1,1);
            flag[4] = 0;
        }
        if (Mouse_above(920,15,960,30) && !flag[5])
        {        
            Linex(920,30,960,30,DARK_GRAY);
            printHZ16(920,15,"�˳�",DARK_GRAY,1,1,1);
            
            flag[5] = 1;
        }
        else if (Mouse_aboveother(920,15,960,30) && flag[5])
        {
            printHZ16(920,15,"�˳�",0,1,1,1);
            flag[5] = 0;
        }
        //���
        if (Mouse_press(1, 60, 110, 140))
        {
            return 51; //�����û���Ϣҳ
        }

        if (Mouse_press(1, 141, 110, 220))
        {
            return 52; //���빺�ﳵҳ��
        }
        if (Mouse_press(1, 221, 110, 300))
        {
            return 53; //���붩��ҳ��
        }

        if (Mouse_press(800, 440, 880, 470))
        { //�޸�����
            Bar(400, 440, 750, 470, WHITE);
            Frame(400, 440, 750, 470, BLACK, 1);
            Barshadow(880, 440, 960, 470, PERU, GRAY);
            printHZ16(890, 450, "ȷ������", BLACK, 1, 1, 1);
            while (1)
            {
                Newxy();
                if (Mouse_press(400, 440, 750, 470))
                {
                    codelen = Input(405, 445, 750, 469, codelen, code, WHITE, 2, 2, 15, 0);
                    code[codelen] = '\0';
                }
                if (Mouse_press(880, 440, 960, 470))
                {
                    UserUpdate(loginuser, 1, code);
                    delay(1000);
                    return 51; //ˢ�¸�����Ϣ����
                }
            }
        }
        if (Mouse_press(800, 490, 880, 520))
        { //�޸ĵ绰
            Bar(400, 490, 750, 520, WHITE);
            Frame(400, 490, 750, 520, BLACK, 1);
            Barshadow(880, 490, 960, 520, PERU, GRAY);
            printHZ16(890, 500, "ȷ�ϵ绰", BLACK, 1, 1, 1);
            while (1)
            {
                Newxy();
                if (Mouse_press(400, 490, 750, 520))
                {
                    tellen = Input(405, 495, 750, 515, tellen, tel, WHITE, 2, 2, 11, 0);
                    tel[tellen] = '\0';
                }
                if (Mouse_press(880, 490, 960, 520))
                {
                    UserUpdate(loginuser, 2, tel);
                    delay(1000);
                    return 51; //ˢ�¸�����Ϣ����
                }
            }
        }

        if (Mouse_press(800, 710, 880, 740))
        {
            if (UserDel(loginuser))
            {
                Barshadow(300, 300, 500, 500, WHITE, GRAY);
                printHZ16(350, 380, "ע���ɹ�", BLACK, 3, 3, 3);
                delay(1000);
                return 1;
            }
        }
        //���۶���
        if(Mouse_press(1,301,110,380)){
            Barshadow(300,300,700,450,MUSTARD,DARK_GRAY);
            printHZ16(305,320,"������δ��ͨ",BLACK,2,2,1);
            printHZ16(305,380,"�����ڴ�",BLACK,2,2,1);
            Put_Asc16_Size(435,375,3,3,'>',BLACK);
            Put_Asc16_Size(445,375,3,3,'_',BLACK);
            Put_Asc16_Size(455,375,3,3,'<',BLACK);
            delay(1000);
            return 5;
        }
    }
}

int UserCart(User *loginuser, Cart *usercart)
{
    int flag[6] = {0};
    Initmouse(1, 1023, 1, 767);
    draw_usercart(usercart);

    while (1)
    {
        Newxy();
        if (Mouse_press(900, 20, 970, 50))
            return 1;
        if (Mouse_press(700, 15, 810, 30))
            return 4; //������ҳ
        //������ڰ�ť����Ӱ����
        if (Mouse_above(1, 60, 110, 140) && flag[0] == 0)
        {
            Bar(1, 60, 110, 140, JASMINE);
            printHZ16(10, 100, "������Ϣ", BLACK, 1, 1, 2);
            flag[0] = 1;
        }
        else if (Mouse_aboveother(1, 60, 110, 140) && flag[0])
        {
            Bar(1, 60, 110, 140, MUSTARD);
            printHZ16(10, 100, "������Ϣ", BLACK, 1, 1, 2);
            flag[0] = 0;
        }

        if (Mouse_above(1, 141, 110, 220) && flag[1] == 0)
        {
            Bar(1, 141, 110, 220, JASMINE);
            printHZ16(10, 180, "���ﳵ", BLACK, 1, 1, 2);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1, 141, 110, 220) && flag[1])
        {
            Bar(1, 141, 110, 220, MUSTARD);
            printHZ16(10, 180, "���ﳵ", BLACK, 1, 1, 2);
            flag[1] = 0;
        }

        if (Mouse_above(1, 221, 110, 300) && flag[2] == 0)
        {
            Bar(1, 221, 110, 300, JASMINE);
            printHZ16(10, 260, "�ҵĶ���", BLACK, 1, 1, 2);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1, 221, 110, 300) && flag[2])
        {
            Bar(1, 221, 110, 300, MUSTARD);
            printHZ16(10, 260, "�ҵĶ���", BLACK, 1, 1, 2);
            flag[2] = 0;
        }

        if (Mouse_above(1, 301, 110, 380) && flag[3] == 0)
        {
            Bar(1, 301, 110, 380, JASMINE);
            printHZ16(10, 340, "���۶���", BLACK, 1, 1, 2);
            flag[3] = 1;
        }
        else if (Mouse_aboveother(1, 301, 110, 380) && flag[3])
        {
            Bar(1, 301, 110, 380, MUSTARD);
            printHZ16(10, 340, "���۶���", BLACK, 1, 1, 2);
            flag[3] = 0;
        }
        if (Mouse_above(700,15,740,30) && !flag[4])
        {        
             Linex(700,30,740,30,DARK_GRAY);
            printHZ16(700,15,"������ҳ",DARK_GRAY,1,1,1);
            
            flag[4] = 1;
        }
        else if (Mouse_aboveother(700,15,740,30) && flag[4])
        {
            printHZ16(700,15,"������ҳ" ,0,1,1,1);
            flag[4] = 0;
        }
        if (Mouse_above(920,15,960,30) && !flag[5])
        {        
            Linex(920,30,960,30,DARK_GRAY);
            printHZ16(920,15,"�˳�",DARK_GRAY,1,1,1);
            
            flag[5] = 1;
        }
        else if (Mouse_aboveother(920,15,960,30) && flag[5])
        {
            printHZ16(920,15,"�˳�",0,1,1,1);
            flag[5] = 0;
        }
        //�����
        if (Mouse_press(1, 60, 110, 140))
        {
            return 51; //�����û���Ϣҳ
        }

        if (Mouse_press(1, 141, 110, 220))
        {
            return 52; //���빺�ﳵҳ��
        }
        if (Mouse_press(1, 221, 110, 300))
        {
            return 53; //���붩��ҳ��
        }
        if (Mouse_press(900, 705, 1010, 750))
        {
            if (UserPay(usercart, loginuser))
            {
                InitCart(usercart); //��չ��ﳵ
                return 53;          //��ת������ҳ��
            }
        }
        //���۶���
        if(Mouse_press(1,301,110,380)){
            Barshadow(300,300,700,450,MUSTARD,DARK_GRAY);
            printHZ16(305,320,"������δ��ͨ",BLACK,2,2,1);
            printHZ16(305,380,"�����ڴ�",BLACK,2,2,1);
            Put_Asc16_Size(435,375,3,3,'>',BLACK);
            Put_Asc16_Size(445,375,3,3,'_',BLACK);
            Put_Asc16_Size(455,375,3,3,'<',BLACK);
            delay(1000);
            return 5;
        }
    }
}

int UserPay(Cart *usercart, User *loginuser)
{
    int flag = 0;
    //Initmouse(1,1,1023,767);
    Bar(400, 300, 600, 450, GRAY);
    printHZ16(420, 320, "���ڴ���", BLACK, 2, 2, 1);
    delay(600);
    Bar(300, 200, 750, 600, WHITE);
    Frame(300, 200, 750, 600, DARK_GRAY, 5);
    printHZ16(480, 210, "�븶��", BLACK, 2, 2, 1);
    Putbmp64k(310, 250, "..\\file\\bmp\\wx.bmp");
    Putbmp64k(535, 250, "..\\file\\bmp\\zfb.bmp");
    Barshadow(480, 550, 570, 580, SPRING_GREEN, GRAY);
    printHZ16(490, 555, "���Ѹ���", BLACK, 1, 1, 1);
    while (1)
    {
        Newxy();
        //������ڰ�ť����Ӱ����
        if (Mouse_above(480, 550, 570, 580) && !flag)
        {
            Bar(480, 550, 570, 580, TURQUOISE);
            printHZ16(490, 555, "���Ѹ���", BLACK, 1, 1, 1);
            flag = 1;
        }
        else if (Mouse_aboveother(480, 550, 570, 580) && flag)
        {
            Barshadow(480, 550, 570, 580, SPRING_GREEN, GRAY);
            printHZ16(490, 555, "���Ѹ���", BLACK, 1, 1, 1);
            flag = 0;
        }
        if (Mouse_press(480, 550, 570, 580))
        {
            if (AddList(usercart, loginuser))
            {
                //loginuser->ordernum++;
                Bar(400, 300, 600, 450, WHITE);
                Frame(400, 300, 600, 450, DARK_GRAY, 2);
                printHZ16(420, 320, "����ɹ�", BLACK, 2, 2, 1);
                delay(600);
                Bar(420, 320, 550, 400, WHITE);
                printHZ16(420, 320, "ҳ����ת��", BLACK, 2, 2, 1);
                delay(600);
                break;
            }
        }
    }
    return 1;
}

/****
 * �û�����ҳ
 * ��Ʒ��ʾ����
 * 1��150 230 
 * 2��150 380
 * 3��150 530
 * 4��150 680
 * 5��600 230
 * 6��600 380
 * 7��600 530
 * 8��600 680
*****/
int UserOrder(User *loginuser,list *userlist,Cart *usercart)
{
	int i = 0, goodsum = 0;//��Ʒ����
	int top = 0;    //����������Ʒ����
	int flag[6] = {0};
    int cntgood[8];    //�����ж���Ʒ�����ĸ�����
    memset(cntgood,-1,sizeof(cntgood));
    ReadList(loginuser,userlist);
	Initmouse(1, 1023, 1, 767);
	draw_userorder(loginuser);
	//��ʾ��Ʒ(ǰ��λ)
	while(i < loginuser->ordernum){
		if(top < userlist[i].top-'0'){
			if(goodsum < 4){
				put_list(150,80+150*goodsum,userlist[i].G[top],userlist[i]);
				cntgood[goodsum] = i;
                top++;
				goodsum++;
			}
			else if(goodsum<8){
				put_list(600,80+150*(goodsum-4),userlist[i].G[top],userlist[i]);
                cntgood[goodsum] = i;
                top++;
				goodsum++;
			}
			else
			{
				break;  //�˳���ʾ
			}

		}
		else{
            top = 0;    //��������Ʒ��������
            i++;    //������һ������
        }
    }

    while (1)
    {
        Newxy();
        if (Mouse_press(900, 20, 970, 50))
            return 1;
        if (Mouse_press(700, 15, 810, 30))
            return 4; //������ҳ
        //������ڰ�ť����Ӱ����
        if (Mouse_above(1, 60, 110, 140) && flag[0] == 0)
        {
            Bar(1, 60, 110, 140, JASMINE);
            printHZ16(10, 100, "������Ϣ", BLACK, 1, 1, 2);
            flag[0] = 1;
        }
        else if (Mouse_aboveother(1, 60, 110, 140) && flag[0])
        {
            Bar(1, 60, 110, 140, MUSTARD);
            printHZ16(10, 100, "������Ϣ", BLACK, 1, 1, 2);
            flag[0] = 0;
        }

        if (Mouse_above(1, 141, 110, 220) && flag[1] == 0)
        {
            Bar(1, 141, 110, 220, JASMINE);
            printHZ16(10, 180, "���ﳵ", BLACK, 1, 1, 2);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1, 141, 110, 220) && flag[1])
        {
            Bar(1, 141, 110, 220, MUSTARD);
            printHZ16(10, 180, "���ﳵ", BLACK, 1, 1, 2);
            flag[1] = 0;
        }

        if (Mouse_above(1, 221, 110, 300) && flag[2] == 0)
        {
            Bar(1, 221, 110, 300, JASMINE);
            printHZ16(10, 260, "�ҵĶ���", BLACK, 1, 1, 2);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1, 221, 110, 300) && flag[2])
        {
            Bar(1, 221, 110, 300, MUSTARD);
            printHZ16(10, 260, "�ҵĶ���", BLACK, 1, 1, 2);
            flag[2] = 0;
        }

        if (Mouse_above(1, 301, 110, 380) && flag[3] == 0)
        {
            Bar(1, 301, 110, 380, JASMINE);
            printHZ16(10, 340, "���۶���", BLACK, 1, 1, 2);
            flag[3] = 1;
        }
        else if (Mouse_aboveother(1, 301, 110, 380) && flag[3])
        {
            Bar(1, 301, 110, 380, MUSTARD);
            printHZ16(10, 340, "���۶���", BLACK, 1, 1, 2);
            flag[3] = 0;
        }
        if (Mouse_above(700,15,740,30) && !flag[4])
        {        
            Linex(700,30,740,30,DARK_GRAY);
            printHZ16(700,15,"������ҳ",DARK_GRAY,1,1,1);
           
            flag[4] = 1;
        }
        else if (Mouse_aboveother(700,15,740,30) && flag[4])
        {
            printHZ16(700,15,"������ҳ" ,0,1,1,1);
            flag[4] = 0;
        }
        if (Mouse_above(920,15,960,30) && !flag[5])
        {      
            Linex(920,30,960,30,DARK_GRAY);
            printHZ16(920,15,"�˳�",DARK_GRAY,1,1,1);  
            
            flag[5] = 1;
        }
        else if (Mouse_aboveother(920,15,960,30) && flag[5])
        {
            printHZ16(920,15,"�˳�",0,1,1,1);
            flag[5] = 0;
        }
        //�����
        if (Mouse_press(1, 60, 110, 140))
        {
            return 51;      //�û���Ϣҳ
        }

        if (Mouse_press(1, 141, 110, 220))
        {
            return 52;      //���ﳵ
        }
        if (Mouse_press(1, 221, 110, 300))
        {
            return 53;      //����ҳ
        }   
        //�ж����ѷ�����ȷ���ջ�����
        if(Mouse_press(430,170,500,195)){
            if(userlist[cntgood[0]].list_state=='0'){   //δ�ջ�
                put_message(0);
                delay(600);
                return 53;
            }
            if(userlist[cntgood[0]].list_state=='1'){   //δ�ջ�
                userlist[cntgood[0]].list_state=='2';
                RenewList(userlist,cntgood[0]);
                put_message(1);
                delay(600);
                return 53;
            }
        }
        if(Mouse_press(430,320,500,345)){
            if(userlist[cntgood[1]].list_state=='0'){   //δ�ջ�
                put_message(0);
                delay(600);
                return 53;
            }
            if(userlist[cntgood[1]].list_state=='1'){   //δ�ջ�
                userlist[cntgood[1]].list_state=='2';
                RenewList(userlist,cntgood[1]);
                put_message(1);
                delay(600);
                return 53;
            }
        }
        if(Mouse_press(430,470,500,495)){
            if(userlist[cntgood[2]].list_state=='0'){   //δ�ջ�
                put_message(0);
                delay(600);
                return 53;
            }
            if(userlist[cntgood[2]].list_state=='1'){   //δ�ջ�
                userlist[cntgood[2]].list_state=='2';
                RenewList(userlist,cntgood[2]);
                put_message(1);
                delay(600);
                return 53;
            }
        }
        if(Mouse_press(430,620,500,645)){
            if(userlist[cntgood[3]].list_state=='0'){   //δ�ջ�
                put_message(0);
                delay(600);
                return 53;
            }
            if(userlist[cntgood[3]].list_state=='1'){   //δ�ջ�
                userlist[cntgood[3]].list_state=='2';
                RenewList(userlist,cntgood[3]);
                put_message(1);
                delay(600);
                return 53;
            }
        }
        if(Mouse_press(880,170,955,195)){
            if(userlist[cntgood[4]].list_state=='0'){   //δ�ջ�
                put_message(0);
                delay(600);
                return 53;
            }
            if(userlist[cntgood[4]].list_state=='1'){   //δ�ջ�
                userlist[cntgood[4]].list_state=='2';
                RenewList(userlist,cntgood[4]);
                put_message(1);
                delay(600);
                return 53;
            }
        }
        if(Mouse_press(880,320,955,345)){
            if(userlist[cntgood[5]].list_state=='0'){   //δ�ջ�
                put_message(0);
                delay(600);
                return 53;
            }
            if(userlist[cntgood[5]].list_state=='1'){   //δ�ջ�
                userlist[cntgood[5]].list_state=='2';
                RenewList(userlist,cntgood[5]);
                put_message(1);
                delay(600);
                return 53;
            }
        }
        if(Mouse_press(880,470,955,495)){
            if(userlist[cntgood[6]].list_state=='0'){   //δ�ջ�
                put_message(0);
                delay(600);
                return 53;
            }
            if(userlist[cntgood[6]].list_state=='1'){   //δ�ջ�
                userlist[cntgood[6]].list_state=='2';
                RenewList(userlist,cntgood[6]);
                put_message(1);
                delay(600);
                return 53;
            }
        }
        if(Mouse_press(880,620,955,645)){
            if(userlist[cntgood[7]].list_state=='0'){   //δ�ջ�
                put_message(0);
                delay(600);
                return 53;
            }
            if(userlist[cntgood[7]].list_state=='1'){   //δ�ջ�
                userlist[cntgood[7]].list_state=='2';
                RenewList(userlist,cntgood[7]);
                put_message(1);
                delay(600);
                return 53;
            }
        }
        
    }
}
