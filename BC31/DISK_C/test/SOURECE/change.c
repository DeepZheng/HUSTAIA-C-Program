#include "public.h"
#include "seller.h"
#include "input.h"
#include "change.h"
#include "file.h"


int changeinfo(SELLER *s)
{

    int sign1=0; //判断新账号是否输入正确
    int sign2=0; //判断新密码是否输入正确
    int sign3=0; //判断新电话号码是否输入正确

    char NewAC[11];
    char Newp[16];
    char NewPN[12];
    int aclen=0,plen=0,pnlen=0;
    strcpy(NewAC,s->account);
    strcpy(Newp,s->password);
    strcpy(NewPN,s->phonenum);
    draw_changeinfo();
    Initmouse(1,1023,1,767);
 //   put_asc(50,550,s->account,RED,2,2);

    while(1)
    {
        Newxy();
        if (Mouse_press(430,300,900,350))
        {   
            NewAC[0]='\0';    //点击该框,才对newac进行重置,下同
            aclen=Input(430,300,900,350,aclen,NewAC,WHITE,2,2,10,0);
            NewAC[aclen]='\0';
            if(aclen<6)
            {
                printHZ16(920,300,"账号至少六位",0,1,1,1);
                delay(1000);
				Bar(920,300,1020,350,GRASS_GREEN);
                Bar(430,300,900,350,WHITE);
                NewAC[0]='\0';
                continue;
            }
            else
            {
                 printHZ16(920,300,"请继续修改密码",0,1,1,1);
                delay(1000);
				Bar(920,300,1020,350,GRASS_GREEN);
                sign1=1;            //账号输入成功
    //            continue;
            }
        }
        if(Mouse_press(430,380,900,430))
        {   
            Newp[0]='\0';
            plen=Input(430,380,900,430,plen,Newp,WHITE,2,2,10,1);
            Newp[plen]='\0';
            if(plen<6)
            {
                printHZ16(920,380,"密码至少六位",0,1,1,1);  //修改账号后必须修改密码,若实在不想修改,就把原密码再输入一次
                delay(1000);
				Bar(920,380,1020,430,GRASS_GREEN);
                Bar(430,380,900,430,WHITE);
                Newp[0]='\0';
                continue;
            }
            else
            {
                sign2=1;            //密码输入成功
     //           continue;
            }
        }
        if(Mouse_press(430,530,900,580)) 
        {   
            NewPN[0]='\0';
            pnlen=Input(430,530,900,580,pnlen,NewPN,WHITE,2,2,11,0);
            NewPN[pnlen]='\0';
            if(pnlen!=11)
            {
                printHZ16(920,530,"电话应为十一位",0,1,1,1);
                delay(1000);
                Bar(920,530,1020,580,GRASS_GREEN);
                Bar(430,530,900,580,WHITE);
                NewPN[0]='\0';
                continue;
            }
            else
            {
                sign3=1; //电话输入成功
            }
        }
        if(Mouse_press(400,600,600,700))  //点击确认按钮
        {
            if((sign1==1&&sign2==0&&sign3==0)||(sign1==0&&sign2==0&&sign3==0))
            {
                printHZ16(100,600,"信息未完善",0,2,2,2);
                delay(1000);
                Bar(100,600,400,1000,GRASS_GREEN);
                continue;   
            }
            else
            {   
                if(input_changeinfo(s,NewAC,Newp,NewPN)==1)
                {
                    printHZ16(20,600,"信息修改成功",RED,2,2,2);
                    delay(1000);
                    return 7; //返回登录界面
                }
                else if(input_changeinfo(s,NewAC,Newp,NewPN)==0)
                {
                    printHZ16(20,600,"信息修改失败",RED,2,2,2);
                    delay(1000);
                }
                 else if(input_changeinfo(s,NewAC,Newp,NewPN)==2)
                {
                    printHZ16(20,600,"文件打开失败",RED,2,2,2);
                    delay(1000);
                }
            }
        }
        if(Mouse_press(700,600,900,700)) //点击返回按钮,返回商家主界面
        {
            return 1;
        }
    }
}
void draw_changeinfo()
{
    Bar(1,1,1023,767,GRASS_GREEN);
    printHZ12(100,30,"帅团",BLACK,4,4,6);
    
    LineThickSha(40,60,50,70,MIMOSA,GRAY,60,1);
	LineThickSha(50,70,80,100,MIMOSA,GRAY,25,1);
	LineThickSha(110,100,120,110,MIMOSA,GRAY,80,1);

	LineThickSha(260,50,250,70,WHITE,GRAY,50,1);
	LineThickSha(235,70,220,100,WHITE,GRAY,25,1);
	LineThickSha(230,100,220,120,WHITE,GRAY,60,1);

    Putbmp64k(600,50,"..\\file\\bmp\\userinfo.bmp");
    printHZ16(300,50,"商家端信息修改",BLACK,2,2,2);
    printHZ16(200,300,"输入新账号",BLACK,2,2,2);
    Bar(430,300,900,350,WHITE);
    printHZ16(200,380,"输入新密码",BLACK,2,2,2);
    Bar(430,380,900,430,WHITE);
    printHZ16(150,530,"输入新电话号码",BLACK,2,2,2);
    Bar(430,530,900,580,WHITE);
	Bar(400,600,600,700,AZURE);
	Bar(700,600,900,700,AZURE);
	printHZ12(420,630,"确定",BLACK,2,2,2);
	printHZ12(720,630,"返回",BLACK,2,2,2);
}

int input_changeinfo(SELLER *s,char *newac,char *newp,char *newpn)
{
	int flag=0;
	FILE *fp1=NULL,*fp2=NULL;
	SELLER temp;
	long size=sizeof(SELLER);

	fp1 = fopen("..\\file\\seller\\seller2.txt","r");
    fp2= fopen("..\\file\\seller\\temp.txt","a");
    if (fp1==NULL||fp2==NULL)
    {
        return 2;
    }
    
	while (!feof(fp1))
	{
		if(fread(&temp,sizeof(SELLER),1,fp1)==0)
            break;
		if(strcmp(temp.account,s->account)==0)
		{
			strcpy(temp.account,newac);
			strcpy(temp.password,newp);
			strcpy(temp.phonenum,newpn);
			fwrite(&temp,sizeof(SELLER),1,fp2);
			flag=1;
			break;
		}
        else
        {
            fwrite(&temp,sizeof(SELLER),1,fp2);
        }
    }   
    fclose(fp1);
    fclose(fp2);
    remove("..\\file\\seller\\seller2.txt");
    rename("..\\file\\seller\\temp.txt","..\\file\\seller\\seller2.txt");
    return flag;
}