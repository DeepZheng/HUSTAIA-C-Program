#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>
#include"DRAW.H"
#include"mouse.h"
#include"HANZI.H"
#include"input.h"
#include"SVGAmode.H"
#include"userpage.h"
#include "color.h"


int UserMain(User *loginuser)
{
	//unsigned char *buffer;
	int flag[6]={0};     
	Initmouse(1,1023,1,767);
	draw_usermainpage();
    
        Bar (140,80,530,480,LIGHT_SALMON);
        printHZ16(350,150,"美食",0,4,4,8);
        LineThickSha(340,220,360,230,BLACK,GRAY,140,6);

        Bar (140,482,400,750,GOLDEN);
        printHZ16(180,520,"家居",0,4,4,8);
        LineThickSha(170,590,190,600,0,25,140,6);

        Bar (531,80,800,480,LIGHT_SEA_GREEN);
        printHZ16(600,150,"电器",0,4,4,8);
        LineThickSha(590,220,610,230,0,25,140,6);

        Bar(401,482,800,750,LAWN_GREEN);
        printHZ16(550,550,"图书",0,4,4,8);
        LineThickSha(540,620,560,630,BLACK,GRAY,140,6);

        Bar(801,80,1000,750,ALIZARIN_CRIMSON);
        printHZ16(870,100,"今",0,4,4,7);
        printHZ16(870,200,"日",0,4,4,7);
        printHZ16(870,300,"促",0,4,4,7);
        printHZ16(870,400,"销",0,4,4,7);
        LineThickSha(950,120,960,100,BLACK,GRAY,500,4); 

	while(1){
		Newxy();
		if(Mouse_press(900,20,970,50))   return -1;
		if(Mouse_press(700,15,810,30))  return 5;  //进入个人中心

        //鼠标移在按钮上阴影功能
        if(Mouse_above(1,75,110,125)&&!flag[0]){
            Bar(1,80,110,125,JASMINE);
            printHZ16(30,100,"美食",DIMGRAY,1,1,1);
            flag[0] = 1;
        }
        else if(Mouse_aboveother(1,75,110,125)&&flag[0]){
            Bar(1,80,110,125,MUSTARD);
            printHZ16(30,100,"美食",DIMGRAY,1,1,1);
            flag[0] = 0;
        }

        if(Mouse_above(1,126,110,175)&&!flag[1]){
            Bar(1,126,110,175,JASMINE);
            printHZ16(30,150,"家居",DIMGRAY,1,1,1);
            flag[1] = 1;
        }
        else if(Mouse_aboveother(1,126,110,175)&&flag[1]){
            Bar(1,126,110,175,MUSTARD);
            printHZ16(30,150,"家居",DIMGRAY,1,1,1);
            flag[1] = 0;
        }

        if(Mouse_above(1,176,110,225)&&!flag[2]){
            Bar(1,176,110,225,JASMINE);
            printHZ16(30,200,"电器",DIMGRAY,1,1,1);
            flag[2] = 1;
        }
        else if(Mouse_aboveother(1,176,110,225)&&flag[2]){
            Bar(1,176,110,225,MUSTARD);
            printHZ16(30,200,"电器",DIMGRAY,1,1,1);
            flag[2] = 0;
        }

        if(Mouse_above(1,226,110,275)&&!flag[3]){
            Bar(1,226,110,275,JASMINE);
            printHZ16(30,250,"图书",DIMGRAY,1,1,1);
            flag[3] = 1;
        }
        else if(Mouse_aboveother(1,226,110,275)&&flag[3]){
            Bar(1,226,110,275,MUSTARD);
            printHZ16(30,250,"图书",DIMGRAY,1,1,1);
            flag[3] = 0;
        }

        if(Mouse_above(1,276,110,325)&&!flag[4]){
            Bar(1,276,110,325,JASMINE);
            printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
            flag[4] = 1;
        }
        else if(Mouse_aboveother(1,276,110,325)&&flag[4]){
            Bar(1,276,110,325,MUSTARD);
            printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
            flag[4] = 0;
        }


        if(Mouse_press(801,80,1000,750)) return 41;
        if(Mouse_press(401,482,800,750)||Mouse_press(1,226,110,275))    return 42;
        if(Mouse_press(140,80,530,480)||Mouse_press(1,75,110,125))      return 43;
        if(Mouse_press(531,80,800,480)||Mouse_press(1,176,110,225))     return 44;
        if(Mouse_press(531,80,800,480)||Mouse_press(1,176,110,225))     return 45;
  }
}

int UserCenter(User *loginuser){
    int flag[4] = {0};
    Initmouse(1,1023,1,767);
    draw_usercenter();

    while(1){
        Newxy();
        if(Mouse_press(900,20,970,50))   return -1;
		if(Mouse_press(700,15,810,30))  return 4;       //返回首页
        //鼠标移在按钮上阴影功能
        if(Mouse_above(1,60,110,140)&&flag[0]==0){
            Bar(1,60,110,140,JASMINE);
            printHZ16(10,100,"个人信息",BLACK,1,1,2);
            flag[0] = 1;
        }
		else if (Mouse_aboveother(1,60,110,140)&&flag[0]){
            Bar(1,60,110,140,MUSTARD);
            printHZ16(10,100,"个人信息",BLACK,1,1,2);
            flag[0] = 0;
        }

        if(Mouse_above(1,141,110,220)&&flag[1]==0){
            Bar(1,141,110,220,JASMINE);
            printHZ16(10,180,"购物车",BLACK,1,1,2);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1,141,110,220)&&flag[1] ){
            Bar(1,141,110,220,MUSTARD);
            printHZ16(10,180,"购物车",BLACK,1,1,2);
            flag[1] = 0 ;
        }

        if(Mouse_above(1,221,110,300)&&flag[2]==0){
            Bar(1,221,110,300,JASMINE);
            printHZ16(10,260,"我的订单",BLACK,1,1,2);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1,221,110,300)&&flag[2]){
            Bar(1,221,110,300,MUSTARD);
            printHZ16(10,260,"我的订单",BLACK,1,1,2);
            flag[2] = 0;
        }

        if(Mouse_above(1,301,110,380)&&flag[3]==0){
            Bar(1,301,110,380,JASMINE);
            printHZ16(10,340,"评价订单",BLACK,1,1,2);
			flag[3] = 1 ;
        }
        else if(Mouse_aboveother(1,301,110,380)&&flag[3]){
            Bar(1,301,110,380,MUSTARD);
            printHZ16(10,340,"评价订单",BLACK,1,1,2);
            flag[3] = 0;
        }

        //鼠标点击
        if(Mouse_press(1,60,110,140)){
            return 51;
        }
        
        if(Mouse_press(1,141,110,220)){
           return 52;
        }
        
        if(Mouse_press(1,221,110,300)){
            return 53;
        }
        /*
        if(Mouse_press(1,301,110,380)){
            return 54;
        }*/
    }
}

int UserInfo(User *loginuser){
    char code[15],tel[12];
    int codelen = 0, tellen = 0;
    Initmouse(1,1023,1,767);
    draw_userinfo(loginuser);

    while(1){
        Newxy();
        if(Mouse_press(900,20,970,50))  return -1;
        if(Mouse_press(700,15,810,30))  return 4;       //返回首页

        if(Mouse_press(800,440,880,470)){               //修改密码
            Bar(400,440,750,470,WHITE);
            Frame(400,440,750,470,BLACK,1);
            Barshadow(880,440,960,470,PERU,GRAY);
	        printHZ16(890,450,"确认密码",BLACK,1,1,1);
            while(1){
                Newxy();
                if(Mouse_press(400,440,750,470)){
                    codelen = Input(405,445,750,469,codelen,code,WHITE,2,2,15,0);
                    code[codelen] = '\0';
                }
                if(Mouse_press(880,440,960,470)){
                    UserUpdate(loginuser,1,code);
                    delay(1000);
                    return 51;      //刷新个人信息界面
                }       
            }
            
               
        }
        if(Mouse_press(800,490,880,520)){               //修改电话
            Bar(400,490,750,520,WHITE);
            Frame(400,490,750,520,BLACK,1);
            Barshadow(880,490,960,520,PERU,GRAY);
	        printHZ16(890,500,"确认电话",BLACK,1,1,1);
            while(1){
                Newxy();
                if(Mouse_press(400,490,750,520)){
                    tellen = Input(405,495,750,515,tellen,tel,WHITE,2,2,11,0);
                    tel[tellen] = '\0';
                }
                if(Mouse_press(880,490,960,520)){
                    UserUpdate(loginuser,2,tel);
                    delay(1000);
                    return 51;      //刷新个人信息界面
                }   
            }
            
        }

        if(Mouse_press(800,710,880,740)){
            if(UserDel(loginuser)){
                Barshadow(300,300,500,500,WHITE,GRAY);
                printHZ16(350,380,"注销成功",BLACK,3,3,3);
                delay(1000);
                return 1;
            }
        }
    }

}

int UserCart(User *loginuser,Cart *usercart){
    int flag[4] = {0};
    Initmouse(1,1023,1,767);
    draw_usercart(usercart);

    while(1){
        Newxy();
        if(Mouse_press(900,20,970,50))   return -1;
		if(Mouse_press(700,15,810,30))  return 4;       //返回首页
        //鼠标移在按钮上阴影功能
        if(Mouse_above(1,60,110,140)&&flag[0]==0){
            Bar(1,60,110,140,JASMINE);
            printHZ16(10,100,"个人信息",BLACK,1,1,2);
            flag[0] = 1;
        }
		else if (Mouse_aboveother(1,60,110,140)&&flag[0]){
            Bar(1,60,110,140,MUSTARD);
            printHZ16(10,100,"个人信息",BLACK,1,1,2);
            flag[0] = 0;
        }

        if(Mouse_above(1,141,110,220)&&flag[1]==0){
            Bar(1,141,110,220,JASMINE);
            printHZ16(10,180,"购物车",BLACK,1,1,2);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1,141,110,220)&&flag[1] ){
            Bar(1,141,110,220,MUSTARD);
            printHZ16(10,180,"购物车",BLACK,1,1,2);
            flag[1] = 0 ;
        }

        if(Mouse_above(1,221,110,300)&&flag[2]==0){
            Bar(1,221,110,300,JASMINE);
            printHZ16(10,260,"我的订单",BLACK,1,1,2);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1,221,110,300)&&flag[2]){
            Bar(1,221,110,300,MUSTARD);
            printHZ16(10,260,"我的订单",BLACK,1,1,2);
            flag[2] = 0;
        }

        if(Mouse_above(1,301,110,380)&&flag[3]==0){
            Bar(1,301,110,380,JASMINE);
            printHZ16(10,340,"评价订单",BLACK,1,1,2);
			flag[3] = 1 ;
        }
        else if(Mouse_aboveother(1,301,110,380)&&flag[3]){
            Bar(1,301,110,380,MUSTARD);
            printHZ16(10,340,"评价订单",BLACK,1,1,2);
            flag[3] = 0;
        }

        //鼠标点击
        if(Mouse_press(1,60,110,140)){
            return 51;
        }

        if(Mouse_press(1,141,110,220)){
            return 52;
        }
        if(Mouse_press(1,221,110,300)){
            return 53;
        }



    }
}

int UserOrder(User *loginuser){
    int flag[4] = {0};
    Initmouse(1,1023,1,767);
    draw_usercart();

    while(1){
        Newxy();
        if(Mouse_press(900,20,970,50))   return -1;
		if(Mouse_press(700,15,810,30))  return 4;       //返回首页
        //鼠标移在按钮上阴影功能
        if(Mouse_above(1,60,110,140)&&flag[0]==0){
            Bar(1,60,110,140,JASMINE);
            printHZ16(10,100,"个人信息",BLACK,1,1,2);
            flag[0] = 1;
        }
		else if (Mouse_aboveother(1,60,110,140)&&flag[0]){
            Bar(1,60,110,140,MUSTARD);
            printHZ16(10,100,"个人信息",BLACK,1,1,2);
            flag[0] = 0;
        }

        if(Mouse_above(1,141,110,220)&&flag[1]==0){
            Bar(1,141,110,220,JASMINE);
            printHZ16(10,180,"购物车",BLACK,1,1,2);
            flag[1] = 1;
        }
        else if (Mouse_aboveother(1,141,110,220)&&flag[1] ){
            Bar(1,141,110,220,MUSTARD);
            printHZ16(10,180,"购物车",BLACK,1,1,2);
            flag[1] = 0 ;
        }

        if(Mouse_above(1,221,110,300)&&flag[2]==0){
            Bar(1,221,110,300,JASMINE);
            printHZ16(10,260,"我的订单",BLACK,1,1,2);
            flag[2] = 1;
        }
        else if (Mouse_aboveother(1,221,110,300)&&flag[2]){
            Bar(1,221,110,300,MUSTARD);
            printHZ16(10,260,"我的订单",BLACK,1,1,2);
            flag[2] = 0;
        }

        if(Mouse_above(1,301,110,380)&&flag[3]==0){
            Bar(1,301,110,380,JASMINE);
            printHZ16(10,340,"评价订单",BLACK,1,1,2);
			flag[3] = 1 ;
        }
        else if(Mouse_aboveother(1,301,110,380)&&flag[3]){
            Bar(1,301,110,380,MUSTARD);
            printHZ16(10,340,"评价订单",BLACK,1,1,2);
            flag[3] = 0;
        }

        //鼠标点击
        if(Mouse_press(1,60,110,140)){
            return 51;
        }

        if(Mouse_press(1,141,110,220)){
            return 52;
        }
        if(Mouse_press(1,221,110,300)){
            return 53;
        }
        

    }
}

int Recommend(User *loginuser,Cart *usercart,recommends *recommend){
    int flag[6] = {0};
    Initmouse(1,1023,1,767);
    draw_usermainpage();
    printHZ16(500,15,"返回首页",0,1,1,1);
    //放置商品
        put_good(150,100,recommend->good[0]);
        put_good(150,250,recommend->good[1]);
        put_good(150,400,recommend->good[2]);
        put_good(150,550,recommend->good[3]);
        put_good(600,100,recommend->good[4]);
        put_good(600,250,recommend->good[5]);
        put_good(600,400,recommend->good[6]);
        put_good(600,550,recommend->good[7]);

    while(1){
        Newxy();
        if(Mouse_press(900,20,970,50)) return -1;
        if(Mouse_press(700,15,810,30))  return 5;
        if(Mouse_press(500,15,610,30))  return 4;
        //鼠标移在按钮上阴影功能
        if(Mouse_above(1,80,110,125)&&!flag[0]){
            Bar(1,80,110,125,JASMINE);
            printHZ16(30,100,"美食",DIMGRAY,1,1,1);
            flag[0] = 1;
        }
        else if(Mouse_aboveother(1,80,110,125)&&flag[0]){
            Bar(1,80,110,125,MUSTARD);
            printHZ16(30,100,"美食",DIMGRAY,1,1,1);
            flag[0] = 0;
        }

        if(Mouse_above(1,126,110,175)&&!flag[1]){
            Bar(1,126,110,175,JASMINE);
            printHZ16(30,150,"家居",DIMGRAY,1,1,1);
            flag[1] = 1;
        }
        else if(Mouse_aboveother(1,126,110,175)&&flag[1]){
            Bar(1,126,110,175,MUSTARD);
            printHZ16(30,150,"家居",DIMGRAY,1,1,1);
            flag[1] = 0;
        }

        if(Mouse_above(1,176,110,225)&&!flag[2]){
            Bar(1,176,110,225,JASMINE);
            printHZ16(30,200,"电器",DIMGRAY,1,1,1);
            flag[2] = 1;
        }
        else if(Mouse_aboveother(1,176,110,225)&&flag[2]){
            Bar(1,176,110,225,MUSTARD);
            printHZ16(30,200,"电器",DIMGRAY,1,1,1);
            flag[2] = 0;
        }

        if(Mouse_above(1,226,110,275)&&!flag[3]){
            Bar(1,226,110,275,JASMINE);
            printHZ16(30,250,"图书",DIMGRAY,1,1,1);
            flag[3] = 1;
        }
        else if(Mouse_aboveother(1,226,110,275)&&flag[3]){
            Bar(1,226,110,275,MUSTARD);
            printHZ16(30,250,"图书",DIMGRAY,1,1,1);
            flag[3] = 0;
        }

        if(Mouse_above(1,276,110,325)&&!flag[4]){
            Bar(1,276,110,325,JASMINE);
            printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
            flag[4] = 1;
        }
        else if(Mouse_aboveother(1,276,110,325)&&flag[4]){
            Bar(1,276,110,325,MUSTARD);
            printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
            flag[4] = 0;
        }

        if(Mouse_press(150,100,500,220))    AddGood(recommend->good[0],usercart);
        if(Mouse_press(150,250,500,370))    AddGood(recommend->good[1],usercart);
        if(Mouse_press(150,400,500,530))    AddGood(recommend->good[2],usercart);
        if(Mouse_press(150,550,500,680))    AddGood(recommend->good[3],usercart);
        if(Mouse_press(600,100,950,220))    AddGood(recommend->good[4],usercart);
        if(Mouse_press(600,250,950,370))    AddGood(recommend->good[5],usercart);
        if(Mouse_press(600,400,950,530))    AddGood(recommend->good[6],usercart);
        if(Mouse_press(600,550,950,680))    AddGood(recommend->good[7],usercart);

    }
}

int Book(User *loginuser,Cart *usercart,books *book){
    int flag[6] = {0};
    Initmouse(1,1023,1,767);
    draw_usermainpage();
    printHZ16(500,15,"返回首页",0,1,1,1);
    //放置商品
        put_good(150,100,book->good[0]);
        put_good(150,250,book->good[1]);
        put_good(150,400,book->good[2]);
        put_good(150,550,book->good[3]);
        put_good(600,100,book->good[4]);
        put_good(600,250,book->good[5]);
        put_good(600,400,book->good[6]);
        put_good(600,550,book->good[7]);

    while(1){
        Newxy();
        if(Mouse_press(900,20,970,50)) return -1;
        if(Mouse_press(700,15,810,30))  return 5;
        if(Mouse_press(500,15,610,30))  return 4;
        //鼠标移在按钮上阴影功能
        if(Mouse_above(1,80,110,125)&&!flag[0]){
            Bar(1,80,110,125,JASMINE);
            printHZ16(30,100,"美食",DIMGRAY,1,1,1);
            flag[0] = 1;
        }
        else if(Mouse_aboveother(1,80,110,125)&&flag[0]){
            Bar(1,80,110,125,MUSTARD);
            printHZ16(30,100,"美食",DIMGRAY,1,1,1);
            flag[0] = 0;
        }

        if(Mouse_above(1,126,110,175)&&!flag[1]){
            Bar(1,126,110,175,JASMINE);
            printHZ16(30,150,"家居",DIMGRAY,1,1,1);
            flag[1] = 1;
        }
        else if(Mouse_aboveother(1,126,110,175)&&flag[1]){
            Bar(1,126,110,175,MUSTARD);
            printHZ16(30,150,"家居",DIMGRAY,1,1,1);
            flag[1] = 0;
        }

        if(Mouse_above(1,176,110,225)&&!flag[2]){
            Bar(1,176,110,225,JASMINE);
            printHZ16(30,200,"电器",DIMGRAY,1,1,1);
            flag[2] = 1;
        }
        else if(Mouse_aboveother(1,176,110,225)&&flag[2]){
            Bar(1,176,110,225,MUSTARD);
            printHZ16(30,200,"电器",DIMGRAY,1,1,1);
            flag[2] = 0;
        }

        if(Mouse_above(1,226,110,275)&&!flag[3]){
            Bar(1,226,110,275,JASMINE);
            printHZ16(30,250,"图书",DIMGRAY,1,1,1);
            flag[3] = 1;
        }
        else if(Mouse_aboveother(1,226,110,275)&&flag[3]){
            Bar(1,226,110,275,MUSTARD);
            printHZ16(30,250,"图书",DIMGRAY,1,1,1);
            flag[3] = 0;
        }

        if(Mouse_above(1,276,110,325)&&!flag[4]){
            Bar(1,276,110,325,JASMINE);
            printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
            flag[4] = 1;
        }
        else if(Mouse_aboveother(1,276,110,325)&&flag[4]){
            Bar(1,276,110,325,MUSTARD);
            printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
            flag[4] = 0;
        }

        if(Mouse_press(150,100,500,220))    AddGood(book->good[0],usercart);
        if(Mouse_press(150,250,500,370))    AddGood(book->good[1],usercart);
        if(Mouse_press(150,400,500,530))    AddGood(book->good[2],usercart);
        if(Mouse_press(150,550,500,680))    AddGood(book->good[3],usercart);
        if(Mouse_press(600,100,950,220))    AddGood(book->good[4],usercart);
        if(Mouse_press(600,250,950,370))    AddGood(book->good[5],usercart);
        if(Mouse_press(600,400,950,530))    AddGood(book->good[6],usercart);
        if(Mouse_press(600,550,950,680))    AddGood(book->good[7],usercart);
    }
}



int Eat(User *loginuser,Cart *usercart,eats *eat){
        int flag[6] = {0};
    Initmouse(1,1023,1,767);
    draw_usermainpage();
    printHZ16(500,15,"返回首页",0,1,1,1);
    //放置商品
        put_good(150,100,eat->good[0]);
        put_good(150,250,eat->good[1]);
        put_good(150,400,eat->good[2]);
        put_good(150,550,eat->good[3]);
        put_good(600,100,eat->good[4]);
        put_good(600,250,eat->good[5]);
        put_good(600,400,eat->good[6]);
        put_good(600,550,eat->good[7]);

    while(1){
        Newxy();
        if(Mouse_press(900,20,970,50)) return -1;
        if(Mouse_press(700,15,810,30))  return 5;
        if(Mouse_press(500,15,610,30))  return 4;
        //鼠标移在按钮上阴影功能
        if(Mouse_above(1,80,110,125)&&!flag[0]){
            Bar(1,80,110,125,JASMINE);
            printHZ16(30,100,"美食",DIMGRAY,1,1,1);
            flag[0] = 1;
        }
        else if(Mouse_aboveother(1,80,110,125)&&flag[0]){
            Bar(1,80,110,125,MUSTARD);
            printHZ16(30,100,"美食",DIMGRAY,1,1,1);
            flag[0] = 0;
        }

        if(Mouse_above(1,126,110,175)&&!flag[1]){
            Bar(1,126,110,175,JASMINE);
            printHZ16(30,150,"家居",DIMGRAY,1,1,1);
            flag[1] = 1;
        }
        else if(Mouse_aboveother(1,126,110,175)&&flag[1]){
            Bar(1,126,110,175,MUSTARD);
            printHZ16(30,150,"家居",DIMGRAY,1,1,1);
            flag[1] = 0;
        }

        if(Mouse_above(1,176,110,225)&&!flag[2]){
            Bar(1,176,110,225,JASMINE);
            printHZ16(30,200,"电器",DIMGRAY,1,1,1);
            flag[2] = 1;
        }
        else if(Mouse_aboveother(1,176,110,225)&&flag[2]){
            Bar(1,176,110,225,MUSTARD);
            printHZ16(30,200,"电器",DIMGRAY,1,1,1);
            flag[2] = 0;
        }

        if(Mouse_above(1,226,110,275)&&!flag[3]){
            Bar(1,226,110,275,JASMINE);
            printHZ16(30,250,"图书",DIMGRAY,1,1,1);
            flag[3] = 1;
        }
        else if(Mouse_aboveother(1,226,110,275)&&flag[3]){
            Bar(1,226,110,275,MUSTARD);
            printHZ16(30,250,"图书",DIMGRAY,1,1,1);
            flag[3] = 0;
        }

        if(Mouse_above(1,276,110,325)&&!flag[4]){
            Bar(1,276,110,325,JASMINE);
            printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
            flag[4] = 1;
        }
        else if(Mouse_aboveother(1,276,110,325)&&flag[4]){
            Bar(1,276,110,325,MUSTARD);
            printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
            flag[4] = 0;
        }
        if(Mouse_press(150,100,500,220))    AddGood(eat->good[0],usercart);
        if(Mouse_press(150,250,500,370))    AddGood(eat->good[1],usercart);
        if(Mouse_press(150,400,500,530))    AddGood(eat->good[2],usercart);
        if(Mouse_press(150,550,500,680))    AddGood(eat->good[3],usercart);
        if(Mouse_press(600,100,950,220))    AddGood(eat->good[4],usercart);
        if(Mouse_press(600,250,950,370))    AddGood(eat->good[5],usercart);
        if(Mouse_press(600,400,950,530))    AddGood(eat->good[6],usercart);
        if(Mouse_press(600,550,950,680))    AddGood(eat->good[7],usercart);
    }
}

int Electric(User *loginuser,Cart *usercart,electrics *electric){
        int flag[6] = {0};
    Initmouse(1,1023,1,767);
    draw_usermainpage();
    printHZ16(500,15,"返回首页",0,1,1,1);
    //放置商品
        put_good(150,100,electric->good[0]);
        put_good(150,250,electric->good[1]);
        put_good(150,400,electric->good[2]);
        put_good(150,550,electric->good[3]);
        put_good(600,100,electric->good[4]);
        put_good(600,250,electric->good[5]);
        put_good(600,400,electric->good[6]);
        put_good(600,550,electric->good[7]);

    while(1){
        Newxy();
        if(Mouse_press(900,20,970,50)) return -1;
        if(Mouse_press(700,15,810,30))  return 5;
        if(Mouse_press(500,15,610,30))  return 4;
        //鼠标移在按钮上阴影功能
        if(Mouse_above(1,80,110,125)&&!flag[0]){
            Bar(1,80,110,125,JASMINE);
            printHZ16(30,100,"美食",DIMGRAY,1,1,1);
            flag[0] = 1;
        }
        else if(Mouse_aboveother(1,80,110,125)&&flag[0]){
            Bar(1,80,110,125,MUSTARD);
            printHZ16(30,100,"美食",DIMGRAY,1,1,1);
            flag[0] = 0;
        }

        if(Mouse_above(1,126,110,175)&&!flag[1]){
            Bar(1,126,110,175,JASMINE);
            printHZ16(30,150,"家居",DIMGRAY,1,1,1);
            flag[1] = 1;
        }
        else if(Mouse_aboveother(1,126,110,175)&&flag[1]){
            Bar(1,126,110,175,MUSTARD);
            printHZ16(30,150,"家居",DIMGRAY,1,1,1);
            flag[1] = 0;
        }

        if(Mouse_above(1,176,110,225)&&!flag[2]){
            Bar(1,176,110,225,JASMINE);
            printHZ16(30,200,"电器",DIMGRAY,1,1,1);
            flag[2] = 1;
        }
        else if(Mouse_aboveother(1,176,110,225)&&flag[2]){
            Bar(1,176,110,225,MUSTARD);
            printHZ16(30,200,"电器",DIMGRAY,1,1,1);
            flag[2] = 0;
        }

        if(Mouse_above(1,226,110,275)&&!flag[3]){
            Bar(1,226,110,275,JASMINE);
            printHZ16(30,250,"图书",DIMGRAY,1,1,1);
            flag[3] = 1;
        }
        else if(Mouse_aboveother(1,226,110,275)&&flag[3]){
            Bar(1,226,110,275,MUSTARD);
            printHZ16(30,250,"图书",DIMGRAY,1,1,1);
            flag[3] = 0;
        }

        if(Mouse_above(1,276,110,325)&&!flag[4]){
            Bar(1,276,110,325,JASMINE);
            printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
            flag[4] = 1;
        }
        else if(Mouse_aboveother(1,276,110,325)&&flag[4]){
            Bar(1,276,110,325,MUSTARD);
            printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
            flag[4] = 0;
        }
        if(Mouse_press(150,100,500,220))    AddGood(electric->good[0],usercart);
        if(Mouse_press(150,250,500,370))    AddGood(electric->good[1],usercart);
        if(Mouse_press(150,400,500,530))    AddGood(electric->good[2],usercart);
        if(Mouse_press(150,550,500,680))    AddGood(electric->good[3],usercart);
        if(Mouse_press(600,100,950,220))    AddGood(electric->good[4],usercart);
        if(Mouse_press(600,250,950,370))    AddGood(electric->good[5],usercart);
        if(Mouse_press(600,400,950,530))    AddGood(electric->good[6],usercart);
        if(Mouse_press(600,550,950,680))    AddGood(electric->good[7],usercart);
    }
}

int Furniture(User *loginuser,Cart *usercart,furnitures *furniture){
    int flag[6] = {0};
    Initmouse(1,1023,1,767);
    draw_usermainpage();
    printHZ16(500,15,"返回首页",BLACK,1,1,1);
   // Bar()
        //放置商品
        put_good(150,100,furniture->good[0]);
        put_good(150,250,furniture->good[1]);
        put_good(150,400,furniture->good[2]);
        put_good(150,550,furniture->good[3]);
        put_good(600,100,furniture->good[4]);
        put_good(600,250,furniture->good[5]);
        put_good(600,400,furniture->good[6]);
        put_good(600,550,furniture->good[7]);
        
    while(1){
        Newxy();
        if(Mouse_press(900,20,970,50)) return -1;
        if(Mouse_press(700,15,810,30))  return 5;
        if(Mouse_press(500,15,610,30))  return 4;
        //鼠标移在按钮上阴影功能
        if(Mouse_above(1,80,110,125)&&!flag[0]){
            Bar(1,80,110,125,JASMINE);
            printHZ16(30,100,"美食",DIMGRAY,1,1,1);
            flag[0] = 1;
        }
        else if(Mouse_aboveother(1,80,110,125)&&flag[0]){
            Bar(1,80,110,125,MUSTARD);
            printHZ16(30,100,"美食",DIMGRAY,1,1,1);
            flag[0] = 0;
        }

        if(Mouse_above(1,126,110,175)&&!flag[1]){
            Bar(1,126,110,175,JASMINE);
            printHZ16(30,150,"家居",DIMGRAY,1,1,1);
            flag[1] = 1;
        }
        else if(Mouse_aboveother(1,126,110,175)&&flag[1]){
            Bar(1,126,110,175,MUSTARD);
            printHZ16(30,150,"家居",DIMGRAY,1,1,1);
            flag[1] = 0;
        }

        if(Mouse_above(1,176,110,225)&&!flag[2]){
            Bar(1,176,110,225,JASMINE);
            printHZ16(30,200,"电器",DIMGRAY,1,1,1);
            flag[2] = 1;
        }
		else if(Mouse_aboveother(1,176,110,225)&&flag[2]){
			Bar(1,176,110,225,MUSTARD);
			printHZ16(30,200,"电器",DIMGRAY,1,1,1);
			flag[2] = 0;
		}

		if(Mouse_above(1,226,110,275)&&!flag[3]){
			Bar(1,226,110,275,JASMINE);
			printHZ16(30,250,"图书",DIMGRAY,1,1,1);
			flag[3] = 1;
		}
		else if(Mouse_aboveother(1,226,110,275)&&flag[3]){
			Bar(1,226,110,275,MUSTARD);
			printHZ16(30,250,"图书",DIMGRAY,1,1,1);
			flag[3] = 0;
		}

		if(Mouse_above(1,276,110,325)&&!flag[4]){
			Bar(1,276,110,325,JASMINE);
			printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
			flag[4] = 1;
		}
		else if(Mouse_aboveother(1,276,110,325)&&flag[4]){
			Bar(1,276,110,325,MUSTARD);
			printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
			flag[4] = 0;
		}

        if(Mouse_press(150,100,500,220))    AddGood(furniture->good[0],usercart);
        if(Mouse_press(150,250,500,370))    AddGood(furniture->good[1],usercart);
        if(Mouse_press(150,400,500,530))    AddGood(furniture->good[2],usercart);
        if(Mouse_press(150,550,500,680))    AddGood(furniture->good[3],usercart);
        if(Mouse_press(600,100,950,220))    AddGood(furniture->good[4],usercart);
        if(Mouse_press(600,250,950,370))    AddGood(furniture->good[5],usercart);
        if(Mouse_press(600,400,950,530))    AddGood(furniture->good[6],usercart);
        if(Mouse_press(600,550,950,680))    AddGood(furniture->good[7],usercart);


	}
}