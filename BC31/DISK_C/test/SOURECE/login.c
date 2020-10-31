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



int Login(User *loginuser,SELLER *loginseller)
{
	int flag1=0,flag2=0;
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
	char username[10];  //暂存用户账号
	char usercode[15];  //暂存用户密码
	Initmouse(1,1023,1,767);

	while(1){
		Newxy();
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

int SellerLogin(SELLER *s)
{
   // SELLER s;
	char AC[21];
	int aclen = 0;
	char P[21];
	int plen = 0;
	int sign=0,temp=0;
//	int is_first[5] = {1,1,1,1,1};

	while (1)
	{
		Newxy();
		if(Mouse_above(620,200,800,300))
		{
			if(Mouse_press(620,200,800,250)==0)
			{
				if(sign==0)
				{
					//lightbutton_login(LIGHT_GRAY,1);
					sign=1;		
				}
				continue;
			}
			else if(Mouse_press(620,200,800,250)==1)
			{
				//lightbutton_login(GRAY,1);
				sign=1;
				continue;
			}
		}
	//	else	is_first[0] = 1;


		 if(Mouse_above(800,200,980,250))
		{
			if(Mouse_press(800,200,980,250)==0)
			{	
				if(sign==0)
				{
					//lightbutton_login(LIGHT_GRAY,2);
					//sign=2;
					continue;
				}
			}
			else if(Mouse_press(800,200,980,300)==1)
			{
				//lightbutton_login(GRAY,2);
				//sign=2;
				continue;
			}
		}
	//	else	is_first[1] = 1;

		if(Mouse_above(740,310,900,360))
		{
			if(Mouse_press(740,310,900,360)==1)
			{
				AC[0]='\0';
				Bar(740,310,900,358,WHITE);
				aclen = Input(740,330,900,359,aclen,AC,WHITE,2,2,10,0);
				AC[aclen]='\0';
				// input_notpassword(AC,740,310,20,BLACK);
				if((aclen)==0)
				{
					printHZ12(920, 310, "请输入账号", BLACK, 1, 1, 1);
					sign=3;
				}
				else if(aclen!=0&&sign==3)
				{
					Bar(920,330,1000,360,WHITE);
					sign=0;
				}
				continue;
			}
			else
			{
				continue;
			}
		}
	//	else	is_first[2]=1;


		if(Mouse_above(730,470,900,520))
		{
			if(Mouse_press(730,470,900,520)==0)
			{
				continue;
			}
			else if(Mouse_press(730,470,900,520)==1)
			{
				P[0]='\0';
				Bar(740,470,900,519,WHITE);
				plen = Input(730,490,900,519,plen,P,WHITE,2,2,15,1);
				P[plen]='\0';
				//input_notpassword(P,730,470,20,BLACK);
				if(plen==0)
				{
					printHZ12(920,470,"请输入密码",BLACK,1,1,1);
					sign=4;
				}
				else if(plen!=0&&sign==4)
				{
					Bar(920,310,1000,360,WHITE);
					sign=0;
				}
				continue;
			}
		}
		if(Mouse_above(730,600,800,630))
		{
			if(Mouse_press(730,600,800,630)==0)
			{	
				if(sign==0)
				{
				//	lightbutton_login(CORAL,5);
					sign=5;
	//			is_first[3] = 0;
					continue;
				}
			}
			else if(Mouse_press(730,600,800,630)==1)
			{
			//	lightbutton_login(RED,5);
				sign=5;
				temp=judge_password(s,P,AC);
				 switch (temp)
				{
					case 0:
					printHZ12(680,270,"不存在此账号",RED,2,2,2);
					delay(1000);
					Bar(620,270,980,300,WHITE);
					break;
					case 1:
					printHZ12(680,270,"密码错误",RED,2,2,2);
					delay(1000);
					 Bar(620,270,980,300,WHITE);
					break;
					case 2:
						
						printHZ12(680,270,"登录成功",RED,2,2,2);
						delay(1000);
						return 6;
					case 3:
					printHZ12(680,270,"打开错误",RED,2,2,2);
					delay(1000);
					Bar(620,270,980,300,WHITE);
					break;
				default:
					printf("something wrong");
					delay(1000);
					break;
				}
			}
		}

		if(Mouse_press(800,20,870,50))
		{
			return 1;
		}
		if(Mouse_press(900,20,970,50))
		{
			return -1;
		}

/*		if(sign==1||sign==2||sign==5)  //sign为1,2,5时锟斤拷示锟斤拷锟斤拷锟斤拷锟斤拷钮锟斤拷锟斤拷锟斤拷
		{
			resetbutton_login(sign);
			sign = 0;
			continue;
		}*/
	}
}
void lightbutton_login(int color,int flag)
{
		switch (flag)
		{
			case 1:
			Bar(620,200,800,250,color);
			printHZ16(680,220,"用户登录",BLACK,1,1,1);
			break;
			case 2:
			Bar(800,200,980,250,color);
			printHZ16(860,220,"商家登录",BLACK,1,1,1);
			break;
			case 5:
			Bar(730,600,800,630,color);
			printHZ12(750,605,"登录",BLACK,1,1,1);
			break;
		default:
			printf("something wrong");
			delay(1000);
			exit(1);
   		 }   
	
}

void resetbutton_login(int flag)
{
    switch (flag)
    {
        case 1:
            Bar(620,200,800,250,GAINSBORO);
            printHZ12(680,220,"用户登录",BLACK,1,1,1);
            break;
        case 2:
            Bar(800,200,980,250,GAINSBORO);
            printHZ12(860,220,"商家登录",BLACK,1,1,1);
            break;
        case 3:
            Bar(730,600,800,630,LIGHT_CORAL);
            printHZ12(750,605,"登录",BLACK,1,1,1);
            break;
        default:
            printf("something wrong");
            delay(1000);
            exit(1);
    }
}

int judge_password(SELLER *s,char *p,char *ac)
{
	FILE *fp=NULL;
	SELLER temp;

	fp=fopen("..\\file\\seller\\seller2.txt","r");
	if(fp==NULL)
	{
		return 3;
	}

	while(!feof(fp))
	{
		fread(&temp,sizeof(SELLER),1,fp);
		if(strcmp(temp.account,ac)==0)
		{
			if(strcmp(temp.password,p)==0)
			{
				strcpy(s->account,ac);
				strcpy(s->password,p);
				strcpy(s->phonenum,temp.phonenum);
				fclose(fp);
				return 2;
			}
			else
			{
				fclose(fp);
				return 1;
			}
		}
	}
	fclose(fp);
	return 0;
}