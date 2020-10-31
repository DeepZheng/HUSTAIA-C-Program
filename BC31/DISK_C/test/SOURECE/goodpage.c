//本文件用于商品界面相关操作

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
#include "goodpage.h"
#include "drawpage.h"
#include "color.h"

int Recommend(User *loginuser, Cart *usercart, recommends *recommend)
{
    int flag[7] = {0};
    char top[3];
    sprintf(top,"%d",usercart->top);
    put_asc(45,600,top,RED,1,1);
    Initmouse(1, 1023, 1, 767);
    draw_usermainpage();
    printHZ16(500, 15, "返回首页", 0, 1, 1, 1);

    //放置商品
    put_good(150, 100, recommend->re[0]);
    put_good(150, 250, recommend->re[1]);
    put_good(150, 400, recommend->re[2]);
    // 暂时只有两个商品
    //put_good(150,550,recommend->good[3]);
    //put_good(600,100,recommend->good[4]);
    //put_good(600,250,recommend->good[5]);
    //put_good(600,400,recommend->good[6]);
    //put_good(600,550,recommend->good[7]);

    while (1)
    {
        Newxy();
        if (Mouse_press(900, 20, 970, 50))
            return 1;
        if (Mouse_press(700, 15, 810, 30))
            return 5;
        if (Mouse_press(500, 15, 610, 30))
            return 4;
        //鼠标移在按钮上阴影功能
        if (Mouse_above(1, 80, 110, 125) && !flag[0])
        {
            Bar(1, 80, 110, 125, JASMINE);
            printHZ16(30, 100, "生鲜", DIMGRAY, 1, 1, 1);
            flag[0] = 1;
        }
        else if (Mouse_aboveother(1, 80, 110, 125) && flag[0])
        {
            Bar(1, 80, 110, 125, MUSTARD);
            printHZ16(30, 100, "生鲜", DIMGRAY, 1, 1, 1);
            flag[0] = 0;
        }

        if (Mouse_above(1, 126, 110, 175) && !flag[1])
        {
            Bar(1, 126, 110, 175, JASMINE);
            printHZ16(30, 150, "家居", DIMGRAY, 1, 1, 1);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1, 126, 110, 175) && flag[1])
        {
            Bar(1, 126, 110, 175, MUSTARD);
            printHZ16(30, 150, "家居", DIMGRAY, 1, 1, 1);
            flag[1] = 0;
        }

        if (Mouse_above(1, 176, 110, 225) && !flag[2])
        {
            Bar(1, 176, 110, 225, JASMINE);
            printHZ16(30, 200, "电器", DIMGRAY, 1, 1, 1);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1, 176, 110, 225) && flag[2])
        {
            Bar(1, 176, 110, 225, MUSTARD);
            printHZ16(30, 200, "电器", DIMGRAY, 1, 1, 1);
            flag[2] = 0;
        }

        if (Mouse_above(1, 226, 110, 275) && !flag[3])
        {
            Bar(1, 226, 110, 275, JASMINE);
            printHZ16(30, 250, "图书", DIMGRAY, 1, 1, 1);
            flag[3] = 1;
        }
        else if (Mouse_aboveother(1, 226, 110, 275) && flag[3])
        {
            Bar(1, 226, 110, 275, MUSTARD);
            printHZ16(30, 250, "图书", DIMGRAY, 1, 1, 1);
            flag[3] = 0;
        }

        if (Mouse_above(1, 276, 110, 325) && !flag[4])
        {
            Bar(1, 276, 110, 325, JASMINE);
            printHZ16(30, 300, "美食", DIMGRAY, 1, 1, 1);
            flag[4] = 1;
        }
        else if (Mouse_aboveother(1, 276, 110, 325) && flag[4])
        {
            Bar(1, 276, 110, 325, MUSTARD);
            printHZ16(30, 300, "美食", DIMGRAY, 1, 1, 1);
            flag[4] = 0;
        }
        if (Mouse_above(700,15,740,30) && !flag[5])
        {        
            Linex(700,30,740,30,DARK_GRAY);
            printHZ16(700,15,"个人中心",DARK_GRAY,1,1,1);
            
            flag[5] = 1;
        }
        else if (Mouse_aboveother(700,15,740,30) && flag[5])
        {
            printHZ16(700,15,"个人中心" ,0,1,1,1);
            flag[5] = 0;
        }
        if (Mouse_above(920,15,960,30) && !flag[6])
        {        
            Linex(920,30,960,30,DARK_GRAY);
            printHZ16(920,15,"退出",DARK_GRAY,1,1,1);
            flag[6] = 1;
        }
        else if (Mouse_aboveother(920,15,960,30) && flag[6])
        {
            printHZ16(920,15,"退出",0,1,1,1);
            
            flag[6] = 0;
        }
        if (Mouse_press(150, 100, 500, 220))
        {
            AddGood(recommend->re[0], usercart);
            Barshadow(400,300,600,400,WHITE,DARK_GRAY);
			printHZ16(410,305,"添加成功",BLACK,2,2,1);
            delay(600);
            return 41; //解决鼠标重复点击问题
        }
        if (Mouse_press(150, 250, 500, 370))
        {
            if (AddGood(recommend->re[1], usercart))
            {
                Barshadow(400,300,600,400,WHITE,DARK_GRAY);
				printHZ16(410,305,"添加成功",BLACK,2,2,1);
                delay(600);
                return 41; //解决鼠标重复点击问题
            }
        }
        if (Mouse_press(150, 400, 500, 530))
        {
            if (AddGood(recommend->re[2], usercart))
            {
                Barshadow(400,300,600,400,WHITE,DARK_GRAY);
				printHZ16(410,305,"添加成功",BLACK,2,2,1);
                delay(600);
                return 41; //解决鼠标重复点击问题
            }
        }
        //if(Mouse_press(150,550,500,680))    AddGood(recommend->good[3],usercart);
        //if(Mouse_press(600,100,950,220))    AddGood(recommend->good[4],usercart);
        //if(Mouse_press(600,250,950,370))    AddGood(recommend->good[5],usercart);
        //if(Mouse_press(600,400,950,530))    AddGood(recommend->good[6],usercart);
        //if(Mouse_press(600,550,950,680))    AddGood(recommend->good[7],usercart);
    }
}

int Book(User *loginuser, Cart *usercart, books *book)
{
    int flag[7] = {0};
    char top[3];
    sprintf(top,"%d",usercart->top);
    put_asc(45,600,top,RED,1,1);
    Initmouse(1, 1023, 1, 767);
    draw_usermainpage();
    printHZ16(500, 15, "返回首页", 0, 1, 1, 1);
    //放置商品
    if(!strcmp(book->bo[0].picpath,"bo0")||!strcmp(book->bo[0].picpath,"bo1")||!strcmp(book->bo[0].picpath,"bo2"))
        put_good(150, 100, book->bo[0]);
    if(!strcmp(book->bo[1].picpath,"bo0")||!strcmp(book->bo[1].picpath,"bo1")||!strcmp(book->bo[1].picpath,"bo2"))
        put_good(150, 250, book->bo[1]);
    if(!strcmp(book->bo[2].picpath,"bo0")||!strcmp(book->bo[2].picpath,"bo1")||!strcmp(book->bo[2].picpath,"bo2"))  
        put_good(150, 400, book->bo[2]);
    //put_good(150,550,book->good[3]);
    //put_good(600,100,book->good[4]);
    //put_good(600,250,book->good[5]);
    // put_good(600,400,book->good[6]);
    // put_good(600,550,book->good[7]);

    while (1)
    {
        Newxy();
        if (Mouse_press(900, 20, 970, 50))
            return 1;
        if (Mouse_press(700, 15, 810, 30))
            return 5;
        if (Mouse_press(500, 15, 610, 30))
            return 4;
        //跳转商品页
        if (Mouse_press(1, 226, 110, 275))
            return 42; //图书
        if (Mouse_press(1, 75, 110, 125))
            return 43; //生鲜
        if(Mouse_press(1, 176, 110, 225))
            return 44; //电器
        if (Mouse_press(1, 126, 110, 175))
            return 45; //家居
        if(Mouse_press(15,650,85,720))
            return 52;  //购物车

        //鼠标移在按钮上阴影功能
        if (Mouse_above(1, 80, 110, 125) && !flag[0])
        {
            Bar(1, 80, 110, 125, JASMINE);
            printHZ16(30, 100, "生鲜", DIMGRAY, 1, 1, 1);
            flag[0] = 1;
        }
        else if (Mouse_aboveother(1, 80, 110, 125) && flag[0])
        {
            Bar(1, 80, 110, 125, MUSTARD);
            printHZ16(30, 100, "生鲜", DIMGRAY, 1, 1, 1);
            flag[0] = 0;
        }

        if (Mouse_above(1, 126, 110, 175) && !flag[1])
        {
            Bar(1, 126, 110, 175, JASMINE);
            printHZ16(30, 150, "家居", DIMGRAY, 1, 1, 1);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1, 126, 110, 175) && flag[1])
        {
            Bar(1, 126, 110, 175, MUSTARD);
            printHZ16(30, 150, "家居", DIMGRAY, 1, 1, 1);
            flag[1] = 0;
        }

        if (Mouse_above(1, 176, 110, 225) && !flag[2])
        {
            Bar(1, 176, 110, 225, JASMINE);
            printHZ16(30, 200, "电器", DIMGRAY, 1, 1, 1);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1, 176, 110, 225) && flag[2])
        {
            Bar(1, 176, 110, 225, MUSTARD);
            printHZ16(30, 200, "电器", DIMGRAY, 1, 1, 1);
            flag[2] = 0;
        }

        if (Mouse_above(1, 226, 110, 275) && !flag[3])
        {
            Bar(1, 226, 110, 275, JASMINE);
            printHZ16(30, 250, "图书", DIMGRAY, 1, 1, 1);
            flag[3] = 1;
        }
        else if (Mouse_aboveother(1, 226, 110, 275) && flag[3])
        {
            Bar(1, 226, 110, 275, MUSTARD);
            printHZ16(30, 250, "图书", DIMGRAY, 1, 1, 1);
            flag[3] = 0;
        }

        if (Mouse_above(1, 276, 110, 325) && !flag[4])
        {
            Bar(1, 276, 110, 325, JASMINE);
            printHZ16(30, 300, "美食", DIMGRAY, 1, 1, 1);
            flag[4] = 1;
        }
        else if (Mouse_aboveother(1, 276, 110, 325) && flag[4])
        {
            Bar(1, 276, 110, 325, MUSTARD);
            printHZ16(30, 300, "美食", DIMGRAY, 1, 1, 1);
            flag[4] = 0;
        }
        if (Mouse_above(700,15,740,30) && !flag[5])
        {        
            Linex(700,30,740,30,DARK_GRAY);
            printHZ16(700,15,"个人中心",DARK_GRAY,1,1,1);
            
            flag[5] = 1;
        }
        else if (Mouse_aboveother(700,15,740,30) && flag[5])
        {
            printHZ16(700,15,"个人中心" ,0,1,1,1);
            flag[5] = 0;
        }
        if (Mouse_above(920,15,960,30) && !flag[6])
        {        
            Linex(920,30,960,30,DARK_GRAY);
            printHZ16(920,15,"退出",DARK_GRAY,1,1,1);
            flag[6] = 1;
        }
        else if (Mouse_aboveother(920,15,960,30) && flag[6])
        {
            printHZ16(920,15,"退出",0,1,1,1);
            
            flag[6] = 0;
        }
        //添加购物车
        if (Mouse_press(400, 190, 500, 215))
        {
            if(!strcmp(book->bo[0].picpath,"bo0")||!strcmp(book->bo[0].picpath,"bo1")||!strcmp(book->bo[0].picpath,"bo2")){
                if (strcmp(book->bo[0].inventory, "0"))
                {
                    if (AddGood(book->bo[0], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 42; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 42; //解决鼠标重复点击问题
                }
            }
        }
        if (Mouse_press(400, 340, 500, 455))
        {
            if(!strcmp(book->bo[1].picpath,"bo0")||!strcmp(book->bo[1].picpath,"bo1")||!strcmp(book->bo[1].picpath,"bo2")){
                if (strcmp(book->bo[1].inventory, "0"))
                {
                    if (AddGood(book->bo[1], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 42; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 42; //解决鼠标重复点击问题
                }
            }
        }
        if (Mouse_press(400, 490, 500, 515))
        {
            if(!strcmp(book->bo[2].picpath,"bo0")||!strcmp(book->bo[2].picpath,"bo1")||!strcmp(book->bo[2].picpath,"bo2")){
                if (strcmp(book->bo[2].inventory, "0"))
                {
                    if (AddGood(book->bo[2], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 42; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 42; //解决鼠标重复点击问题
                }
            }
        }
        //if(Mouse_press(150,550,500,680))    AddGood(book->good[3],usercart);
        //if(Mouse_press(600,100,950,220))    AddGood(book->good[4],usercart);
        //if(Mouse_press(600,250,950,370))    AddGood(book->good[5],usercart);
        //if(Mouse_press(600,400,950,530))    AddGood(book->good[6],usercart);
        //if(Mouse_press(600,550,950,680))    AddGood(book->good[7],usercart);
    }
}

int Eat(User *loginuser, Cart *usercart, eats *eat)
{
    int flag[7] = {0};
    char top[3];
    //sprintf(top,"%d",usercart->top);
    //put_asc(45,600,top,RED,1,1);
    Initmouse(1, 1023, 1, 767);
    draw_usermainpage();
    printHZ16(500, 15, "返回首页", 0, 1, 1, 1);
    //放置商品
    if(!strcmp(eat->ea[0].picpath,"ea0")||!strcmp(eat->ea[0].picpath,"ea1")||!strcmp(eat->ea[0].picpath,"ea2")||!strcmp(eat->ea[0].picpath,"ea3")||!strcmp(eat->ea[0].picpath,"ea4"))
        put_good(150, 100, eat->ea[0]);
    if(!strcmp(eat->ea[1].picpath,"ea0")||!strcmp(eat->ea[1].picpath,"ea1")||!strcmp(eat->ea[1].picpath,"ea2")||!strcmp(eat->ea[1].picpath,"ea3")||!strcmp(eat->ea[1].picpath,"ea4"))
        put_good(150, 250, eat->ea[1]);
    if(!strcmp(eat->ea[2].picpath,"ea0")||!strcmp(eat->ea[2].picpath,"ea1")||!strcmp(eat->ea[2].picpath,"ea2")||!strcmp(eat->ea[2].picpath,"ea3")||!strcmp(eat->ea[2].picpath,"ea4"))
        put_good(150, 400, eat->ea[2]);
    if(!strcmp(eat->ea[3].picpath,"ea0")||!strcmp(eat->ea[3].picpath,"ea1")||!strcmp(eat->ea[3].picpath,"ea2")||!strcmp(eat->ea[3].picpath,"ea3")||!strcmp(eat->ea[3].picpath,"ea4"))
        put_good(600, 100, eat->ea[3]);
    if(!strcmp(eat->ea[4].picpath,"ea0")||!strcmp(eat->ea[4].picpath,"ea1")||!strcmp(eat->ea[4].picpath,"ea2")||!strcmp(eat->ea[4].picpath,"ea3")||!strcmp(eat->ea[4].picpath,"ea4"))
        put_good(600, 250, eat->ea[4]);
    //put_good(600,250,eat->good[5]);
    //put_good(600,400,eat->good[6]);
    //put_good(600,550,eat->good[7]);

    while (1)
    {
        Newxy();
        if (Mouse_press(900, 20, 970, 50))
            return 1;
        if (Mouse_press(700, 15, 810, 30))
            return 5;
        if (Mouse_press(500, 15, 610, 30))
            return 4;
        //跳转商品页
        if (Mouse_press(1, 226, 110, 275))
            return 42; //图书
        if (Mouse_press(1, 75, 110, 125))
            return 43; //生鲜
        if(Mouse_press(1, 176, 110, 225))
            return 44; //电器
        if (Mouse_press(1, 126, 110, 175))
            return 45; //家居
        if(Mouse_press(15,650,85,720))
            return 52;  //购物车
        //鼠标移在按钮上阴影功能
        if (Mouse_above(1, 80, 110, 125) && !flag[0])
        {
            Bar(1, 80, 110, 125, JASMINE);
            printHZ16(30, 100, "生鲜", DIMGRAY, 1, 1, 1);
            flag[0] = 1;
        }
        else if (Mouse_aboveother(1, 80, 110, 125) && flag[0])
        {
            Bar(1, 80, 110, 125, MUSTARD);
            printHZ16(30, 100, "生鲜", DIMGRAY, 1, 1, 1);
            flag[0] = 0;
        }

        if (Mouse_above(1, 126, 110, 175) && !flag[1])
        {
            Bar(1, 126, 110, 175, JASMINE);
            printHZ16(30, 150, "家居", DIMGRAY, 1, 1, 1);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1, 126, 110, 175) && flag[1])
        {
            Bar(1, 126, 110, 175, MUSTARD);
            printHZ16(30, 150, "家居", DIMGRAY, 1, 1, 1);
            flag[1] = 0;
        }

        if (Mouse_above(1, 176, 110, 225) && !flag[2])
        {
            Bar(1, 176, 110, 225, JASMINE);
            printHZ16(30, 200, "电器", DIMGRAY, 1, 1, 1);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1, 176, 110, 225) && flag[2])
        {
            Bar(1, 176, 110, 225, MUSTARD);
            printHZ16(30, 200, "电器", DIMGRAY, 1, 1, 1);
            flag[2] = 0;
        }

        if (Mouse_above(1, 226, 110, 275) && !flag[3])
        {
            Bar(1, 226, 110, 275, JASMINE);
            printHZ16(30, 250, "图书", DIMGRAY, 1, 1, 1);
            flag[3] = 1;
        }
        else if (Mouse_aboveother(1, 226, 110, 275) && flag[3])
        {
            Bar(1, 226, 110, 275, MUSTARD);
            printHZ16(30, 250, "图书", DIMGRAY, 1, 1, 1);
            flag[3] = 0;
        }

        if (Mouse_above(1, 276, 110, 325) && !flag[4])
        {
            Bar(1, 276, 110, 325, JASMINE);
            printHZ16(30, 300, "美食", DIMGRAY, 1, 1, 1);
            flag[4] = 1;
        }
        else if (Mouse_aboveother(1, 276, 110, 325) && flag[4])
        {
            Bar(1, 276, 110, 325, MUSTARD);
            printHZ16(30, 300, "美食", DIMGRAY, 1, 1, 1);
            flag[4] = 0;
        }
        if (Mouse_above(700,15,740,30) && !flag[5])
        {        
            Linex(700,30,740,30,DARK_GRAY);
            printHZ16(700,15,"个人中心",DARK_GRAY,1,1,1);
            
            flag[5] = 1;
        }
        else if (Mouse_aboveother(700,15,740,30) && flag[5])
        {
            printHZ16(700,15,"个人中心" ,0,1,1,1);
            flag[5] = 0;
        }
        if (Mouse_above(920,15,960,30) && !flag[6])
        {        
            Linex(920,30,960,30,DARK_GRAY);
            printHZ16(920,15,"退出",DARK_GRAY,1,1,1);
            flag[6] = 1;
        }
        else if (Mouse_aboveother(920,15,960,30) && flag[6])
        {
            printHZ16(920,15,"退出",0,1,1,1);
            
            flag[6] = 0;
        }
        //点击加入购物车
        if (Mouse_press(400, 190, 495, 215))
        {
            if(!strcmp(eat->ea[0].picpath,"ea0")||!strcmp(eat->ea[0].picpath,"ea1")||!strcmp(eat->ea[0].picpath,"ea2")||!strcmp(eat->ea[0].picpath,"ea3")||!strcmp(eat->ea[0].picpath,"ea4")){
                if (strcmp(eat->ea[0].inventory, "0"))
                {
                    if (AddGood(eat->ea[0], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 43; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 43; //解决鼠标重复点击问题
                }
            }
        }
        if (Mouse_press(400, 340, 495, 485))
        {   
            if(!strcmp(eat->ea[1].picpath,"ea0")||!strcmp(eat->ea[1].picpath,"ea1")||!strcmp(eat->ea[1].picpath,"ea2")||!strcmp(eat->ea[1].picpath,"ea3")|!strcmp(eat->ea[1].picpath,"ea4")){
                if (strcmp(eat->ea[1].inventory, "0"))
                {
                    if (AddGood(eat->ea[1], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 43; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 43; //解决鼠标重复点击问题
                }
                }
        }
        if (Mouse_press(400, 490, 495, 645))
        {
            if(!strcmp(eat->ea[2].picpath,"ea0")||!strcmp(eat->ea[2].picpath,"ea1")||!strcmp(eat->ea[2].picpath,"ea2")||!strcmp(eat->ea[2].picpath,"ea3")||!strcmp(eat->ea[2].picpath,"ea4")){
                if (strcmp(eat->ea[2].inventory, "0"))
                {
                    if (AddGood(eat->ea[2], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 43; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 43; //解决鼠标重复点击问题
                }
            }
        }
        if (Mouse_press(850, 190, 945, 375))
        {
            if(!strcmp(eat->ea[3].picpath,"ea0")||!strcmp(eat->ea[3].picpath,"ea1")||!strcmp(eat->ea[3].picpath,"ea2")||!strcmp(eat->ea[3].picpath,"ea3")||!strcmp(eat->ea[3].picpath,"ea4")){
                if (strcmp(eat->ea[3].inventory, "0"))
                {
                    if (AddGood(eat->ea[3], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 43; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 43; //解决鼠标重复点击问题
                }
            }
        }
        if (Mouse_press(850, 340, 945, 485))
        {
            if(!strcmp(eat->ea[4].picpath,"ea0")||!strcmp(eat->ea[4].picpath,"ea1")||!strcmp(eat->ea[4].picpath,"ea2")||!strcmp(eat->ea[4].picpath,"ea3")||!strcmp(eat->ea[4].picpath,"ea4")){
                if (strcmp(eat->ea[4].inventory, "0"))
                {
                    if (AddGood(eat->ea[4], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 43; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 43; //解决鼠标重复点击问题
                }
            }
        }
    }
}

int Electric(User *loginuser, Cart *usercart, electrics *electric)
{
    int flag[7] = {0};
    char top[3];
    sprintf(top,"%d",usercart->top);
    put_asc(45,600,top,RED,1,1);
    Initmouse(1, 1023, 1, 767);
    draw_usermainpage();
    
    printHZ16(500, 15, "返回首页", 0, 1, 1, 1);
    //放置商品
    if(!strcmp(electric->el[0].picpath,"el0")||!strcmp(electric->el[0].picpath,"el1")||!strcmp(electric->el[0].picpath,"el2")||!strcmp(electric->el[0].picpath,"el3"))
        put_good(150, 100, electric->el[0]);
    if(!strcmp(electric->el[1].picpath,"el0")||!strcmp(electric->el[1].picpath,"el1")||!strcmp(electric->el[1].picpath,"el2")||!strcmp(electric->el[1].picpath,"el3"))
        put_good(150, 250, electric->el[1]);
    if(!strcmp(electric->el[2].picpath,"el0")||!strcmp(electric->el[2].picpath,"el1")||!strcmp(electric->el[2].picpath,"el2")||!strcmp(electric->el[2].picpath,"el3"))
        put_good(600, 100, electric->el[2]);
    if(!strcmp(electric->el[3].picpath,"el0")||!strcmp(electric->el[3].picpath,"el1")||!strcmp(electric->el[3].picpath,"el2")||!strcmp(electric->el[3].picpath,"el3"))
        put_good(600, 250, electric->el[3]);
    // put_good(600,100,electric->good[4]);
    //put_good(600,250,electric->good[5]);

    while (1)
    {
        Newxy();
        if (Mouse_press(900, 20, 970, 50))
            return 1;
        if (Mouse_press(700, 15, 810, 30))
            return 5;
        if (Mouse_press(500, 15, 610, 30))
            return 4;
        //跳转商品页
        if (Mouse_press(1, 226, 110, 275))
            return 42; //图书
        if (Mouse_press(1, 75, 110, 125))
            return 43; //生鲜
        if(Mouse_press(1, 176, 110, 225))
            return 44; //电器
        if (Mouse_press(1, 126, 110, 175))
            return 45; //家居
        if(Mouse_press(15,650,85,720))
            return 52;  //购物车

        //鼠标移在按钮上阴影功能
        if (Mouse_above(1, 80, 110, 125) && !flag[0])
        {
            Bar(1, 80, 110, 125, JASMINE);
            printHZ16(30, 100, "生鲜", DIMGRAY, 1, 1, 1);
            flag[0] = 1;
        }
        else if (Mouse_aboveother(1, 80, 110, 125) && flag[0])
        {
            Bar(1, 80, 110, 125, MUSTARD);
            printHZ16(30, 100, "生鲜", DIMGRAY, 1, 1, 1);
            flag[0] = 0;
        }

        if (Mouse_above(1, 126, 110, 175) && !flag[1])
        {
            Bar(1, 126, 110, 175, JASMINE);
            printHZ16(30, 150, "家居", DIMGRAY, 1, 1, 1);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1, 126, 110, 175) && flag[1])
        {
            Bar(1, 126, 110, 175, MUSTARD);
            printHZ16(30, 150, "家居", DIMGRAY, 1, 1, 1);
            flag[1] = 0;
        }

        if (Mouse_above(1, 176, 110, 225) && !flag[2])
        {
            Bar(1, 176, 110, 225, JASMINE);
            printHZ16(30, 200, "电器", DIMGRAY, 1, 1, 1);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1, 176, 110, 225) && flag[2])
        {
            Bar(1, 176, 110, 225, MUSTARD);
            printHZ16(30, 200, "电器", DIMGRAY, 1, 1, 1);
            flag[2] = 0;
        }

        if (Mouse_above(1, 226, 110, 275) && !flag[3])
        {
            Bar(1, 226, 110, 275, JASMINE);
            printHZ16(30, 250, "图书", DIMGRAY, 1, 1, 1);
            flag[3] = 1;
        }
        else if (Mouse_aboveother(1, 226, 110, 275) && flag[3])
        {
            Bar(1, 226, 110, 275, MUSTARD);
            printHZ16(30, 250, "图书", DIMGRAY, 1, 1, 1);
            flag[3] = 0;
        }

        if (Mouse_above(1, 276, 110, 325) && !flag[4])
        {
            Bar(1, 276, 110, 325, JASMINE);
            printHZ16(30, 300, "美食", DIMGRAY, 1, 1, 1);
            flag[4] = 1;
        }
        else if (Mouse_aboveother(1, 276, 110, 325) && flag[4])
        {
            Bar(1, 276, 110, 325, MUSTARD);
            printHZ16(30, 300, "美食", DIMGRAY, 1, 1, 1);
            flag[4] = 0;
        }
        if (Mouse_above(700,15,740,30) && !flag[5])
        {        
            Linex(700,30,740,30,DARK_GRAY);
            printHZ16(700,15,"个人中心",DARK_GRAY,1,1,1);
            
            flag[5] = 1;
        }
        else if (Mouse_aboveother(700,15,740,30) && flag[5])
        {
            printHZ16(700,15,"个人中心" ,0,1,1,1);
            flag[5] = 0;
        }
        if (Mouse_above(920,15,960,30) && !flag[6])
        {        
            Linex(920,30,960,30,DARK_GRAY);
            printHZ16(920,15,"退出",DARK_GRAY,1,1,1);
            flag[6] = 1;
        }
        else if (Mouse_aboveother(920,15,960,30) && flag[6])
        {
            printHZ16(920,15,"退出",0,1,1,1);
            
            flag[6] = 0;
        }
        //点击加入购物车
        if (Mouse_press(150+250, 100+90, 150+345, 100+115))
        {
            if(!strcmp(electric->el[0].picpath,"el0")||!strcmp(electric->el[0].picpath,"el1")||!strcmp(electric->el[0].picpath,"el2")||!strcmp(electric->el[0].picpath,"el3")){
                if (strcmp(electric->el[0].inventory, "0"))
                {
                    if (AddGood(electric->el[0], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 44; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 44; //解决鼠标重复点击问题
                }
            }
        }
        if (Mouse_press(150+250, 250+90, 150+345, 250+115))
        {
            if(!strcmp(electric->el[1].picpath,"el0")||!strcmp(electric->el[1].picpath,"el1")||!strcmp(electric->el[1].picpath,"el2")||!strcmp(electric->el[1].picpath,"el3")){
                if (strcmp(electric->el[1].inventory, "0"))
                {
                    if (AddGood(electric->el[1], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 44; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 44; //解决鼠标重复点击问题
                }
            }
        }
            
        if (Mouse_press(850, 190, 950, 215))
        {
            if(!strcmp(electric->el[2].picpath,"el0")||!strcmp(electric->el[2].picpath,"el1")||!strcmp(electric->el[2].picpath,"el2")||!strcmp(electric->el[2].picpath,"el3")){
                if (strcmp(electric->el[2].inventory, "0"))
                {
                    if (AddGood(electric->el[2], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 44; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 44; //解决鼠标重复点击问题
                }
            }
        }
        if (Mouse_press(850, 340, 945, 365))
        {
            if(!strcmp(electric->el[3].picpath,"el0")||!strcmp(electric->el[3].picpath,"el1")||!strcmp(electric->el[3].picpath,"el2")||!strcmp(electric->el[3].picpath,"el3")){
                if (strcmp(electric->el[3].inventory, "0"))
                {
                    if (AddGood(electric->el[3], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 44; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 44; //解决鼠标重复点击问题
                }
            }
        }
        //if(Mouse_press(150,550,500,680))    AddGood(electric->good[3],usercart);
        //if(Mouse_press(600,100,950,220))    AddGood(electric->good[4],usercart);
        //if(Mouse_press(600,250,950,370))    AddGood(electric->good[5],usercart);
        //if(Mouse_press(600,400,950,530))    AddGood(electric->good[6],usercart);
        //if(Mouse_press(600,550,950,680))    AddGood(electric->good[7],usercart);
    }
}

int Furniture(User *loginuser, Cart *usercart, furnitures *furniture)
{
    int flag[7] = {0};
   // char top[3];
   //	sprintf(top,"%d",usercart->top);
   //	put_asc(45,600,top,RED,1,1);
    Initmouse(1, 1023, 1, 767);
    draw_usermainpage();
    printHZ16(500, 15, "返回首页", BLACK, 1, 1, 1);
    //放置商品
    if(!strcmp(furniture->fu[0].picpath,"fu0")||!strcmp(furniture->fu[0].picpath,"fu1")||!strcmp(furniture->fu[0].picpath,"fu2")||!strcmp(furniture->fu[0].picpath,"fu3"))
        put_good(150, 100, furniture->fu[0]);
    if(!strcmp(furniture->fu[1].picpath,"fu0")||!strcmp(furniture->fu[1].picpath,"fu1")||!strcmp(furniture->fu[1].picpath,"fu2")||!strcmp(furniture->fu[1].picpath,"fu3"))
        put_good(150, 250, furniture->fu[1]);
    if(!strcmp(furniture->fu[2].picpath,"fu0")||!strcmp(furniture->fu[2].picpath,"fu1")||!strcmp(furniture->fu[2].picpath,"fu2")||!strcmp(furniture->fu[2].picpath,"fu3"))
        put_good(600, 100, furniture->fu[2]);
    if(!strcmp(furniture->fu[3].picpath,"fu0")||!strcmp(furniture->fu[3].picpath,"fu1")||!strcmp(furniture->fu[3].picpath,"fu2")||!strcmp(furniture->fu[3].picpath,"fu3"))
        put_good(600, 250, furniture->fu[3]);
    //put_good(600,100,furniture->good[4]);
    // put_good(600,100,furniture->good[5]);
    // put_good(600,400,furniture->good[6]);
    // put_good(600,550,furniture->good[7]);

    while (1)
    {
        Newxy();
        if (Mouse_press(900, 20, 970, 50))
            return 1;
        if (Mouse_press(700, 15, 810, 30))
            return 5;
        if (Mouse_press(500, 15, 610, 30))
            return 4;
        //跳转商品页
        if (Mouse_press(1, 226, 110, 275))
            return 42; //图书
        if (Mouse_press(1, 75, 110, 125))
            return 43; //生鲜
        if(Mouse_press(1, 176, 110, 225))
            return 44; //电器
        if (Mouse_press(1, 126, 110, 175))
            return 45; //家居
        if(Mouse_press(15,650,85,720))
            return 52;  //购物车
        //鼠标移在按钮上阴影功能
        if (Mouse_above(1, 80, 110, 125) && !flag[0])
        {
            Bar(1, 80, 110, 125, JASMINE);
            printHZ16(30, 100, "生鲜", DIMGRAY, 1, 1, 1);
            flag[0] = 1;
        }
        else if (Mouse_aboveother(1, 80, 110, 125) && flag[0])
        {
            Bar(1, 80, 110, 125, MUSTARD);
            printHZ16(30, 100, "生鲜", DIMGRAY, 1, 1, 1);
            flag[0] = 0;
        }

        if (Mouse_above(1, 126, 110, 175) && !flag[1])
        {
            Bar(1, 126, 110, 175, JASMINE);
            printHZ16(30, 150, "家居", DIMGRAY, 1, 1, 1);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1, 126, 110, 175) && flag[1])
        {
            Bar(1, 126, 110, 175, MUSTARD);
            printHZ16(30, 150, "家居", DIMGRAY, 1, 1, 1);
            flag[1] = 0;
        }

        if (Mouse_above(1, 176, 110, 225) && !flag[2])
        {
            Bar(1, 176, 110, 225, JASMINE);
            printHZ16(30, 200, "电器", DIMGRAY, 1, 1, 1);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1, 176, 110, 225) && flag[2])
        {
            Bar(1, 176, 110, 225, MUSTARD);
            printHZ16(30, 200, "电器", DIMGRAY, 1, 1, 1);
            flag[2] = 0;
        }

        if (Mouse_above(1, 226, 110, 275) && !flag[3])
        {
            Bar(1, 226, 110, 275, JASMINE);
            printHZ16(30, 250, "图书", DIMGRAY, 1, 1, 1);
            flag[3] = 1;
        }
        else if (Mouse_aboveother(1, 226, 110, 275) && flag[3])
        {
            Bar(1, 226, 110, 275, MUSTARD);
            printHZ16(30, 250, "图书", DIMGRAY, 1, 1, 1);
            flag[3] = 0;
        }

        if (Mouse_above(1, 276, 110, 325) && !flag[4])
        {
            Bar(1, 276, 110, 325, JASMINE);
            printHZ16(30, 300, "美食", DIMGRAY, 1, 1, 1);
            flag[4] = 1;
        }
        else if (Mouse_aboveother(1, 276, 110, 325) && flag[4])
        {
            Bar(1, 276, 110, 325, MUSTARD);
            printHZ16(30, 300, "美食", DIMGRAY, 1, 1, 1);
            flag[4] = 0;
        }
        if (Mouse_above(700,15,740,30) && !flag[5])
        {        
            Linex(700,30,740,30,DARK_GRAY);
            printHZ16(700,15,"个人中心",DARK_GRAY,1,1,1);
            
            flag[5] = 1;
        }
        else if (Mouse_aboveother(700,15,740,30) && flag[5])
        {
            printHZ16(700,15,"个人中心" ,0,1,1,1);
            flag[5] = 0;
        }
        if (Mouse_above(920,15,960,30) && !flag[6])
        {        
            Linex(920,30,960,30,DARK_GRAY);
            printHZ16(920,15,"退出",DARK_GRAY,1,1,1);
            flag[6] = 1;
        }
        else if (Mouse_aboveother(920,15,960,30) && flag[6])
        {
            printHZ16(920,15,"退出",0,1,1,1);
            
            flag[6] = 0;
        }
        //添加购物车操作
        if (Mouse_press(150+250, 100+90, 150+345, 100+115))
        {
            if(!strcmp(furniture->fu[0].picpath,"fu0")||!strcmp(furniture->fu[0].picpath,"fu1")||!strcmp(furniture->fu[0].picpath,"fu2")||!strcmp(furniture->fu[0].picpath,"fu3")){
                if (strcmp(furniture->fu[0].inventory, "0"))
                {
                    if (AddGood(furniture->fu[0], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 45; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 45; //解决鼠标重复点击问题
                }
            }
        }

        if (Mouse_press(150+250, 250+90, 150+345, 250+115))
        {
            if(!strcmp(furniture->fu[1].picpath,"fu0")||!strcmp(furniture->fu[1].picpath,"fu1")||!strcmp(furniture->fu[1].picpath,"fu2")||!strcmp(furniture->fu[1].picpath,"fu3")){
                if (strcmp(furniture->fu[1].inventory, "0"))
                {
                    if (AddGood(furniture->fu[1], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 45; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 45; //解决鼠标重复点击问题
                }
            }
        }
        if (Mouse_press(600+250, 100+90, 600+345, 100+115))
        {
            if(!strcmp(furniture->fu[2].picpath,"fu0")||!strcmp(furniture->fu[2].picpath,"fu1")||!strcmp(furniture->fu[2].picpath,"fu2")||!strcmp(furniture->fu[2].picpath,"fu3")){
                if (strcmp(furniture->fu[2].inventory, "0"))
                {
                    if (AddGood(furniture->fu[2], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 45; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 45; //解决鼠标重复点击问题
                }
            }
        }
        if (Mouse_press(600+250, 250+90, 600+345, 250+115))
        {
            if(!strcmp(furniture->fu[3].picpath,"fu0")||!strcmp(furniture->fu[3].picpath,"fu1")||!strcmp(furniture->fu[3].picpath,"fu2")||!strcmp(furniture->fu[3].picpath,"fu3")){
                if (strcmp(furniture->fu[3].inventory, "0"))
                {
                    if (AddGood(furniture->fu[3], usercart))
                    {
                        Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                        printHZ16(410, 305, "添加成功", BLACK, 2, 2, 1);
                        delay(600);
                        return 45; //解决鼠标重复点击问题
                    }
                }
                else
                {
                    Barshadow(400, 300, 600, 400, WHITE, DARK_GRAY);
                    printHZ16(410, 305, "已售罄", BLACK, 2, 2, 1);
                    delay(600);
                    return 45; //解决鼠标重复点击问题
                }
            }
        }
        //if(Mouse_press(150,550,500,680))    AddGood(furniture->good[3],usercart);
        //if(Mouse_press(600,100,950,220))    AddGood(furniture->good[4],usercart);
        //if(Mouse_press(600,250,950,370))    AddGood(furniture->good[5],usercart);
        // if(Mouse_press(600,400,950,530))    AddGood(furniture->good[6],usercart);
        // if(Mouse_press(600,550,950,680))    AddGood(furniture->good[7],usercart);
    }
} 