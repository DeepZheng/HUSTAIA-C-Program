#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include"mouse.h"
#include"file.h"
#include"HANZI.H"
#include"SVGAmode.H"
#include"drawpage.h"
#include"tstruct.h"
#include"input.h"
#include"regis.h"
#include "color.h"

int Regis(User *loginuser,SELLER *loginseller){
    int flag1=0,flag2=0;
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
    char username[10];
    char usercode[15];
    char usertel[12];
    Initmouse(1,1023,1,767);

    while(1){
        Newxy();
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
                if(UserFind(&loginuser,username,usercode)==2){
					strcpy(loginuser->name,username);
					strcpy(loginuser->code,usercode);
					strcpy(loginuser->tel,usertel);
    
                        printHZ12(680,270,"注册成功",RED,2,2,2);
				        delay(1000);
                        return 31;

                }
            }
        }
    }
}



int SellerRegis(SELLER *loginseller)
{   
    char AC[11]={'\0'}; //account number
    char P[16]={'\0'}; //password
    char PN[12]={'\0'}; //phone num
    int i;
    int sign=0;
    int aclen = 0;
    int plen = 0;
    int pnlen = 0;
    int num[3];  //validity of ac/p/cp


    while(1)
    {   
        Newxy();
       
        if(Mouse_above(730,340,950,360))
        {
            if(Mouse_press(730,340,950,360)==0)
            {
                if(sign==0)
                {   
                   // lightbutton_register(730,340,950,360,GAINSBORO,1);
                    sign=1;
     //               num[0]=0;
                    continue;
                }
            }
            else if(Mouse_press(730,340,950,360)==1)
            {
              //  lightbutton_register(730,340,950,360,GAINSBORO,1);
                sign=1;
				aclen=Input(730,340,950,360,aclen,AC,MIMOSA,2,2,10,0);
                AC[aclen]='\0';
                
       //         num[0]=1;
            }
        }
        if(Mouse_above(730,460,950,480))
        {
            if(Mouse_press(730,460,950,480)==0)
            {   
                if(sign==0)
                {
                  //  lightbutton_register(730,460,950,480,GAINSBORO,2);
                    sign=2;
       //             num[1]=0;
                    continue;
                }
            }
            else if(Mouse_press(730,460,950,480)==1)
            {
               // lightbutton_register(730,460,950,480,GAINSBORO,2);
                sign=2;
                plen=Input(730,460,950,480,plen,P,MIMOSA,2,2,10,1);
                P[plen]='\0';
                 
        //        num[1]=1;
            }
        }
        if(Mouse_above(730,580,950,600))
        {
            if(Mouse_press(730,580,950,600)==0)
            {
                if(sign==0)
                {
                   // lightbutton_register(730,580,950,600,GAINSBORO,3);
                    sign=3;
      //              num[2]=0;
                }
            }
            else if(Mouse_press(730,580,950,600)==1)
            {
               // lightbutton_register(730,580,950,600,GAINSBORO,3);
                sign=3;
                pnlen=Input(730,580,950,600,pnlen,PN,MIMOSA,2,2,11,0);
                PN[pnlen]='\0';
               
      //          num[2]=1;
            }
        }
     
        if(Mouse_above(730,630,800,660))
        {
            if(Mouse_press(730,630,800,660)==0)
            {   
                if(sign==0)
                {
                  //  lightbutton_register(730,630,800,660,CRIMSON,4);
                    sign=4;
                    continue;
                }
            }
            else if(Mouse_press(730,630,800,660)==1)
            {   
                return 6;
                if (aclen<6)
                {
                    printHZ12(952,340,"账号不少于六位",CRIMSON,1,1,1);
                }
                if (judge_sameAC(AC,1)==0)
                {
            
                    printHZ12(952,340,"此账号已被注册",CRIMSON,1,1,1);
					
                }
                if(plen<6)
                {

                    printHZ12(730,460,"密码不少于六位",CRIMSON,1,1,1);
                    
                }
                 if(pnlen!=11)
                {
                    printHZ12(952,580,"电话号码应为十一位",CRIMSON,1,1,1);
                    
                }
                if(aclen>=6&&judge_sameAC(AC,1)!=0&&plen>=6&&pnlen==11)
                {
                    num[0]=1;
                    num[1]=1;
                    num[2]=1;
                }
                if(num[0]&&num[1]&&num[2])
                {
                    if(input_registerinfo(AC,P,PN,loginseller)){
                        printHZ12(820,630,"注册成功",LIGHT_CORAL,2,2,3);
                        delay(3000);
                        return 6;
                    }
                    else
                    {
                       printHZ12(820,630,"注册失败",LIGHT_CORAL,2,2,3);
                        delay(3000);
                        return 3;
                    } 
                }
                else
                {
                  //  lightbutton_register(730,630,800,660,CRIMSON,4);
                    sign=4;
                    printHZ12(500,400,"错误",0,4,4,4);
                    delay(10000);
                }
            }
        }
        if (Mouse_above(800,20,870,50))
        {
            if(Mouse_press(800,20,870,50)==0)
            {   
                if(sign==0)
                {
                   // lightbutton_register(800,20,870,50,CRIMSON,5);
                    sign=5;
                }
            }
            else if(Mouse_press(800,20,870,50)==1)
            {
                return 1;
            }
        }
        if(Mouse_above(900,20,970,50))
        {
            if(Mouse_press(900,20,970,50)==0)
            {
                if(sign==0)
                {
                   // lightbutton_register(900,20,970,50,CRIMSON,6);
                    sign=6;

                }
            }
            else if(Mouse_press(900,20,970,50)==1)
            {
                return -1;
            }
        }
       // if(sign!=0)
      //  {
       //     reset_button(sign);
       //     sign=0;
       // }
    }
}
     

void lightbutton_register(int x1,int y1,int x2,int y2,int color,int flag)
{
	Bar(x1, y1, x2, y2,color);

    if (flag == 4)
	{
		printHZ16(750,635,"注册成功",0,1,1,1);
	}
    else if(flag==5)
    {
        printHZ16(820,30,"返回",0,1,1,1);
    }
	else if (flag == 6)
	{
		printHZ16(920,30,"退出",0,1,1,1);
	}
}

void reset_button(int flag)
{
    switch (flag)
    {
        case 1:
            Bar(730,340,950,360,MIMOSA); //账号
            break;
        case 2:
            Bar(730,460,950,480,MIMOSA);  //密码
            break;
         case 3:
            Bar(430,460,900,480,MIMOSA);  //电话
            break;
         case 4:
            Bar(730,630,800,660,PERU); //注册按钮
            printHZ16(750,635,"注册成功",0,1,1,1);
            break;
         case 5:
            Bar(800,20,870,50,PERU);  //返回按钮
            printHZ16(820,30,"返回",BLACK,1,1,1);
            break;
         case 6:
            Bar(900,20,970,50,YELLOW);  //退出按钮
            printHZ16(720,630,"退出",BLACK,1,1,1);
            break;
        default:
            printf("something wrong");
            delay(1000);
            exit(1);
    }
}


int judge_sameAC(char *new_ac,int sign)
{
    FILE *fp=NULL;
    SELLER temp;

    if(fp=fopen("seller2.txt","r")==NULL)
    {
		printf("cannot open database");
		delay(1000);
		exit(1);
	}

    while(!feof(fp))
    {
        fread(&temp,sizeof(SELLER),1,fp);
        if(strcmp(temp.account,new_ac)==0)
        {
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return 1;
}

int input_registerinfo(SELLER *s)
{
	FILE* fp;
	SELLER temp;
	if ((fp = fopen("..\\file\\seller\\seller2.txt", "a" )) == NULL)
	{
		printf("cannot open file seller2.txt");
		delay(1000);
		return 1;
	}
	fwrite(s,sizeof(SELLER),1,fp);
	fclose(fp);
	return 0;
}