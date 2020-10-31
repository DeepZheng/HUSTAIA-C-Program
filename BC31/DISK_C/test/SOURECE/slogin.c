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

int SellerLogin(SELLER *s)
{
   // SELLER s;
	char AC[21];
	int aclen = 0;
	char P[21];
	int plen = 0;
	int sign=0,temp=0;
	Initmouse(1,1023,1,767);

	while (1)
	{
		Newxy();
		if(Mouse_above(620,200,800,300))
		{
			if(Mouse_press(620,200,800,250)==0)
			{
				if(sign==0)
				{
					sign=1;		
				}
				continue;
			}
			else if(Mouse_press(620,200,800,250)==1)
			{
				sign=1;
				continue;
			}
		}
		 if(Mouse_above(800,200,980,250))
		{
			if(Mouse_press(800,200,980,250)==0)
			{	
				if(sign==0)
				{
					continue;
				}
			}
			else if(Mouse_press(800,200,980,300)==1)
			{
				continue;
			}
		}

		if(Mouse_above(740,310,900,360))
		{
			if(Mouse_press(740,310,900,360)==1)
			{
				AC[0]='\0';
				Bar(740,310,900,358,WHITE);
				aclen = Input(740,330,900,359,aclen,AC,WHITE,2,2,10,0);
				AC[aclen]='\0';
				if((aclen)==0)
				{
					printHZ12(920, 310, "请输入账号", BLACK, 1, 1, 1);
					sign=3;
				}
				else if(aclen!=0&&sign==3)
				{
					Bar(920,310,970,360,WHITE);
					sign=0;
				}
				continue;
			}
			else
			{
				continue;
			}
		}

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
				if(plen==0)
				{
					printHZ12(920,470,"请输入密码",BLACK,1,1,1);
					sign=4;
				}
				else if(plen!=0&&sign==4)
				{
					Bar(920,470,980,360,WHITE);
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
					sign=5;
					continue;
				}
			}
			else if(Mouse_press(730,600,800,630)==1)
			{
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

int SellerRegis(SELLER *loginseller)
{   
    char AC[11]={'\0'}; //account number
    char P[16]={'\0'}; //password
    char PN[12]={'\0'}; //phone num
    int i;
    int sign;
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
                    continue;
                }
            }
            else if(Mouse_press(730,340,950,360)==1)
            {
                sign=1;
				aclen=Input(730,340,950,360,aclen,AC,MIMOSA,2,2,10,0);
                AC[aclen]='\0';
            }
        }
        if(Mouse_above(730,460,950,480))
        {
            if(Mouse_press(730,460,950,480)==0)
            {   
                if(sign==0)
                {
                    sign=2;
                    continue;
                }
            }
            else if(Mouse_press(730,460,950,480)==1)
            {
                sign=2;
                plen=Input(730,460,950,480,plen,P,MIMOSA,2,2,10,1);
                P[plen]='\0';
            }
        }
        if(Mouse_above(730,580,950,600))
        {
            if(Mouse_press(730,580,950,600)==0)
            {
                if(sign==0)
                {
                    sign=3;
                    continue;
                }
            }
            else if(Mouse_press(730,580,950,600)==1)
            {
                sign=3;
                pnlen=Input(730,580,950,600,pnlen,PN,MIMOSA,2,2,11,0);
                PN[pnlen]='\0';
            }
        }
     
        if(Mouse_above(730,630,800,660))
        {
            if(Mouse_press(730,630,800,660)==0)
            {   
                if(sign==0)
                {
                    sign=4;
                    continue;
                }
            }
            else if(Mouse_press(730,630,800,660)==1)
            {   
                if (aclen<6)
                {
                    printHZ12(952,340,"账号不少于六位",CRIMSON,1,1,1);
                }
                if (judge_sameAC(AC)==0)
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
                if(aclen>=6&&judge_sameAC(AC)!=0&&plen>=6&&pnlen==11)
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
            }
        }
        if (Mouse_above(800,20,870,50))
        {
            if(Mouse_press(800,20,870,50)==0)
            {   
                if(sign==0)
                {
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
                    sign=6;
                }
            }
            else if(Mouse_press(900,20,970,50)==1)
            {
                return -1;
            }
        }
    }
}
int judge_sameAC(char *new_ac)
{
    FILE *fp=NULL;
    SELLER temp;

    if(fp=fopen("..\\file\\seller\\seller2.txt","r")==NULL)
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

int input_registerinfo(char *ac,char *p,char *pn,SELLER *s)
{
	FILE* fp;
	SELLER temp;
    fp = fopen("..\\file\\seller\\seller2.txt", "a" );

	if (fp == NULL)
	{
		printf("cannot open file seller2.txt");
		delay(1000);
		return 0;
	}
    strcpy(temp.account,ac);
    strcpy(temp.password,p);
    strcpy(temp.phonenum,pn);
    strcpy(s->account,ac);
    strcpy(s->password,p);
    strcpy(s->phonenum,pn);
	fwrite(&temp,sizeof(SELLER),1,fp);
	fclose(fp);
	return 1;
}