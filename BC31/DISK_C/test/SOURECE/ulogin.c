#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include"tstruct.h"
#include"mouse.h"
#include"HANZI.H"
#include"SVGAmode.H"
#include "color.h"
#include"drawpage.h"
#include"input.h"
#include"file.h"
#include"login.h"
#include "regis.h"

int Login(User *loginuser,SELLER *loginseller)
{
	int flag1=0,flag2=0;
	int flag3 = 0, flag4 = 0;
	Initmouse(1,1023,1,767);
	draw_login();
	while(1){
		Newxy();
		if(Mouse_press(900,20,970,50)==1)   return -1;
		if(Mouse_press(800,20,870,50)==1)   return 1;   //返回

		if(Mouse_above(620,200,800,250)&&!flag1){
			Bar(620,200,800,250,LIGHT_GRAY);
			printHZ16(680,220,"用户登录",0,1,1,1);
			flag1 = 1;
		}
		else if(Mouse_aboveother(620,200,800,250)&&flag1){
			Bar(620,200,800,250,WHITE);
			printHZ16(680,220,"用户登录",0,1,1,1);
			flag1 = 0;
		}

		if(Mouse_above(801,200,980,250)&&!flag2){
			Bar(801,200,980,250,LIGHT_GRAY);
			printHZ16(860,220,"商家登录",0,1,1,1);
			flag2 = 1;
		}
		else if(Mouse_aboveother(801,200,980,250)&&flag2){
			Bar(801,200,980,250,WHITE);
			printHZ16(860,220,"商家登录",0,1,1,1);
			flag2 = 0;
		}
		if(Mouse_above(800,20,870,50)&&!flag3){
			Barshadow(800,20,870,50,WHEAT,GRAY);
			printHZ16(820,30,"返回",0,1,1,1);
			flag3 = 1;
		}
		else if(Mouse_aboveother(800,20,870,50)&&flag3){
			Barshadow(800,20,870,50,BEIGE,GRAY);
			printHZ16(820,30,"返回",0,1,1,1);
			flag3 = 0;
		}
		if(Mouse_above(900,20,970,50)&&!flag4){
			Barshadow(900,20,970,50,SIENNA,GRAY);
			printHZ16(920,30,"退出",0,1,1,1);
			flag4 = 1;
		}
		else if(Mouse_aboveother(900,20,970,50)&&flag4){
			Barshadow(900,20,970,50,AMBER,GRAY);
			printHZ16(920,30,"退出",0,1,1,1);
			flag4 = 0;
		}
		if(Mouse_press(620,250,980,700)){
			printHZ16(680,270,"请先选择商家或用户登录",0,1,1,1);
			delay(1000);
			Bar(620,270,980,300,WHITE);
		}
		if(Mouse_press(620,200,800,250)){
			Bar(620,200,800,250,GRAY);
			printHZ16(680,220,"用户登录",0,1,1,1);
			return UserLogin(loginuser);
		}

		if(Mouse_press(801,200,980,250)){
			Bar(801,200,980,250,GRAY);
			printHZ16(860,220,"商家登录",0,1,1,1);
			return SellerLogin(loginseller);
		}
	}
	
}

int UserLogin(User *loginuser){
	int namelen=0,codelen=0;    //账号长度，密码长度
	int flag1= 0, flag2 = 0;
	char username[10];  //暂存用户账号
	char usercode[15];  //暂存用户密码
	Initmouse(1,1023,1,767);

	while(1){
		Newxy();
		if(Mouse_above(800,20,870,50)&&!flag1){
			Barshadow(800,20,870,50,WHEAT,GRAY);
			printHZ16(820,30,"返回",0,1,1,1);
			flag1 = 1;
		}
		else if(Mouse_aboveother(800,20,870,50)&&flag1){
			Barshadow(800,20,870,50,BEIGE,GRAY);
			printHZ16(820,30,"返回",0,1,1,1);
			flag1 = 0;
		}
		if(Mouse_above(900,20,970,50)&&!flag2){
			Barshadow(900,20,970,50,SIENNA,GRAY);
			printHZ16(920,30,"退出",0,1,1,1);
			flag2 = 1;
		}
		else if(Mouse_aboveother(900,20,970,50)&&flag2){
			Barshadow(900,20,970,50,AMBER,GRAY);
			printHZ16(920,30,"退出",0,1,1,1);
			flag2 = 0;
		}
		if(Mouse_press(900,20,970,50)==1)   return -1;
		if(Mouse_press(800,20,870,50)==1)   return 1;   //返回

		if(Mouse_press(740,340,900,360)==1){   //点击用户名的输入框
			namelen = Input(740,330,900,359,namelen,username,WHITE,2,2,10,0);//方框位置，字符数量，用户名，输出字符大小
			username[namelen] = '\0';   //添加结束符
		   // put_asc(200,150,username,0,2,2);   //调试用户账号
		}

		if(Mouse_press(730,500,900,520)==1){    //点击用户名的密码框
			codelen = Input(730,490,900,519,codelen,usercode,WHITE,2,2,15,1);
			usercode[codelen] = '\0';   //添加结束符
			//put_asc(200,200,usercode,0,2,2);    //调试用户密码
		}

		if(Mouse_press(730,600,800,630)==1){       //登录
			 if(namelen > 0&&codelen > 0){       //用户名和密码均输入
				switch(UserFind(loginuser,username,usercode)){

					case 0 :     //匹配成功
						{
							Barshadow(400,300,600,400,WHITE,DARK_GRAY);
							printHZ16(410,305,"登录成功",BLACK,2,2,1);
							delay(1000);
							return 4;//进入主页面
						}
					case 1 ://密码错误
						{
							printHZ12(680,270,"密码错误",0,2,2,2);
							delay(1000);
							Bar(620,270,980,300,WHITE);
							break;
						}
					case 2 ://找不到用户
						{
							printHZ12(680,270,"用户不存在",0,2,2,2);
							delay(1000);
							Bar(620,270,980,300,WHITE);
							break;
						}
				}
			}
			else{
				printHZ12(680,270,"请输入用户名和密码",0,2,2,2);
				delay(1000);
				Bar(620,270,980,300,WHITE);
			}
		   return 2;
		}
	}
}

int Regis(User *loginuser,SELLER *loginseller){
    int flag1=0,flag2=0;
	int flag3 = 0, flag4 = 0;
    Initmouse(1,1023,1,767);
	draw_regis();
    while(1){
        Newxy();
        if(Mouse_press(900,20,970,50)==1)   return -1;
		if(Mouse_press(800,20,870,50)==1)   return 1;   //返回

        if(Mouse_above(620,200,800,250)&&!flag1){
			Bar(620,200,800,250,LIGHT_GRAY);
			printHZ16(680,220,"用户注册",0,1,1,1);
			flag1 = 1;
		}
		else if(Mouse_aboveother(620,200,800,250)&&flag1){
			Bar(620,200,800,250,MIMOSA);
			printHZ16(680,220,"用户注册",0,1,1,1);
			flag1 = 0;
		}

		if(Mouse_above(801,200,980,250)&&!flag2){
			Bar(801,200,980,250,LIGHT_GRAY);
			printHZ16(860,220,"商家注册",0,1,1,1);
			flag2 = 1;
		}
		else if(Mouse_aboveother(801,200,980,250)&&flag2){
			Bar(801,200,980,250,WHITE);
			printHZ16(860,220,"商家注册",0,1,1,1);
			flag2 = 0;
		}

		if(Mouse_above(800,20,870,50)&&!flag3){
			Barshadow(800,20,870,50,WHEAT,GRAY);
			printHZ16(820,30,"返回",0,1,1,1);
			flag3 = 1;
		}
		else if(Mouse_aboveother(800,20,870,50)&&flag3){
			Barshadow(800,20,870,50,BEIGE,GRAY);
			printHZ16(820,30,"返回",0,1,1,1);
			flag3 = 0;
		}
		if(Mouse_above(900,20,970,50)&&!flag4){
			Barshadow(900,20,970,50,SIENNA,GRAY);
			printHZ16(920,30,"退出",0,1,1,1);
			flag4 = 1;
		}
		else if(Mouse_aboveother(900,20,970,50)&&flag4){
			Barshadow(900,20,970,50,AMBER,GRAY);
			printHZ16(920,30,"退出",0,1,1,1);
			flag4 = 0;
		}
		if(Mouse_press(620,250,980,700)){
			printHZ16(680,270,"请先选择商家或用户注册",RED,1,1,1);
			delay(1000);
			Bar(620,270,980,300,MIMOSA);
		}

        if(Mouse_press(620,200,800,250)){
		    Bar(620,200,800,250,GRAY);
		    printHZ16(680,220,"用户注册",0,1,1,1);
		    return UserRegis(loginuser);
	    }	
	    if(Mouse_press(801,200,980,250)){
		    Bar(801,200,980,250,GRAY);
		    printHZ16(860,220,"商家注册",0,1,1,1);
		    return SellerRegis(loginseller);
	    }	
    }
}

int UserRegis (User *loginuser){
    int namelen=0, codelen = 0,tellen=0;
	int flag1 = 0, flag2 = 0;
    char username[10];
    char usercode[15];
    char usertel[12];
    Initmouse(1,1023,1,767);

    while(1){
        Newxy();
		if(Mouse_above(800,20,870,50)&&!flag1){
			Barshadow(800,20,870,50,WHEAT,GRAY);
			printHZ16(820,30,"返回",0,1,1,1);
			flag1 = 1;
		}
		else if(Mouse_aboveother(800,20,870,50)&&flag1){
			Barshadow(800,20,870,50,BEIGE,GRAY);
			printHZ16(820,30,"返回",0,1,1,1);
			flag1 = 0;
		}
		if(Mouse_above(900,20,970,50)&&!flag2){
			Barshadow(900,20,970,50,SIENNA,GRAY);
			printHZ16(920,30,"退出",0,1,1,1);
			flag2 = 1;
		}
		else if(Mouse_aboveother(900,20,970,50)&&flag2){
			Barshadow(900,20,970,50,AMBER,GRAY);
			printHZ16(920,30,"退出",0,1,1,1);
			flag2 = 0;
		}
		if(Mouse_press(900,20,970,50))   return -1;  //退出
        if(Mouse_press(800,20,870,50)==1)   return 1;   //返回

        if(Mouse_press(740,320,900,360)==1){   //点击用户名的输入框
			namelen = Input(740,325,900,359,namelen,username,MIMOSA,2,2,10,0);//方框位置，字符数量，用户名，输出字符大小
            username[namelen] = '\0';   //添加结束符
           // put_asc(200,150,username,0,2,2);   //调试用户账号
        }

        if(Mouse_press(730,460,900,480)==1){    //点击用户名的密码框
			codelen = Input(730,455,900,479,codelen,usercode,MIMOSA,2,2,15,1);
            usercode[codelen] = '\0';   //添加结束符
            //put_asc(200,200,usercode,0,2,2);    //调试用户密码
        }
        if(Mouse_press(730,580,900,600)==1){    //点击用户电话输入框
            tellen = Input(730,575,900,599,tellen,usertel,MIMOSA,2,2,11,0);
            usertel[tellen] = '\0';     //添加结束符
        }
        if(Mouse_press(730,630,800,660)==1){       //注册
            if(namelen<5) {
                printHZ12(680,270,"用户名过短",RED,2,2,2);
				delay(1000);
				Bar(620,270,980,300,MIMOSA);
            }
            else if(codelen<5){
                printHZ12(680,270,"密码过短",RED,2,2,2);
				delay(1000);
				Bar(620,270,980,300,MIMOSA);
            }
            else if(tellen!=11){
                printHZ12(680,270,"电话号码不符合要求",RED,2,2,2);
				delay(1000);
				Bar(620,270,980,300,MIMOSA);
            }
            if(namelen>=5&&codelen>=5&&tellen==11){
                if(UserFind(loginuser,username,usercode)!=2){
                    printHZ12(680,270,"该用户已存在",RED,2,2,2);
				    delay(1000);
				    Bar(620,270,980,300,MIMOSA);
                }
                if(UserFind(loginuser,username,usercode)==2){
					strcpy(loginuser->name,username);
					strcpy(loginuser->code,usercode);
					strcpy(loginuser->tel,usertel);
    
                        Barshadow(400,300,600,400,WHITE,DARK_GRAY);
	                    printHZ16(410,305,"注册成功",BLACK,2,2,1);
                        delay(1000);
                        return 31;

                }
            }
        }
    }
}
