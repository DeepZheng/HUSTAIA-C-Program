#include "public.h"
#include "tstruct.h"
#include "charge.h"
#include "seller.h"

float calculate_total(list *L)
{
    int i=0;
    float sum=0;

    for(i=0;i<10;i++)
    {
		if(strlen(L->G[i].picpath)==0)
        {
            break;
        }
        else
        {
            sum=sum+(L->G[i].price);
        }
    }
    return sum;
}

int chargelist(list *L)
{
    FILE *fp=NULL;
    int state=0;

    fp=fopen("..\\file\\charge\\charge.txt","r");
    if(!fp)
    {
        return 0;
    }

    fread(&state,sizeof(int),1,fp);
    if(state)
    {
        printHZ16(800,100,"收款已完成",RED,2,2,2);
        fclose(fp);
        delay(1500);
        return 1;
    }
    else
    {
        printHZ16(800,100,"收款未完成",RED,2,2,2);
        fclose(fp);
        delay(1500);
        return 2;
    }
}

int finishlist(list *L)
{   
    FILE *fp=NULL;
    list temp;
    long size=sizeof(list);

    L->list_state=FINISHED;
    fp=fopen("..\\file\\list\\list.txt","r");
    if(fp==NULL)
    {
        return 0;
    }
    while(!feof(fp))
    {
        fread(&temp,sizeof(list),1,fp);
        if(temp.list_state==UNFINISHED)
        {
            temp.list_state=FINISHED;
            fseek(fp,-size,SEEK_CUR);
            fwrite(&temp,size,1,fp);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 2;
}
void draw_charge()
{   
    Bar(1,1,1023,767,PEACH);
    printHZ12(100,30,"帅团",BLACK,4,4,6);
    
    LineThickSha(40,60,50,70,MIMOSA,GRAY,60,1);
	LineThickSha(50,70,80,100,MIMOSA,GRAY,25,1);
	LineThickSha(110,100,120,110,MIMOSA,GRAY,80,1);

	LineThickSha(260,50,250,70,WHITE,GRAY,50,1);
	LineThickSha(235,70,220,100,WHITE,GRAY,25,1);
	LineThickSha(230,100,220,120,WHITE,GRAY,60,1);

     printHZ16(300,50,"商家端收款",BLACK,2,2,2);
     Putbmp64k(50,260,"..\\file\\bmp\\charge.bmp");
	Barshadow(750,200,950,300,IVY_GREEN,GRAY);
	Barshadow(750,350,950,450,IVY_GREEN,GRAY);
	printHZ16(780,230,"计算总金额",BLACK,2,2,2);
    printHZ16(780,380,"收款",BLACK,3,3,3);
    printHZ16(550,460,"订单总金额",RED,2,2,2);
    Barshadow(800,600,950,700,GRASS_GREEN,BLACK);
    printHZ16(830,630,"返回",BLACK,2,2,2);
}

int charge(list *L)
{   
    float total=0;
	char str[10];
	int charge_state=0;

	str[0]='\0';
    draw_charge();
    update_list(L);
    while(1)
    {
        Newxy();
        if(Mouse_press(750,200,950,300))
        {
            total=calculate_total(L);
            sprintf(str,".2f",total);
            put_asc(770,480,str,BLACK,2,2);
        }
        if(Mouse_press(750,350,950,450))
        {
            switch (chargelist(L))
            {
                case 0:
                    printHZ16(750,100,"文件打开失败",RED,2,2,2);
                    delay(1000);
                    Bar(750,100,1000,190,PEACH);
                    break;
                case 1:
                    if(finishlist(L)==1)
                    {
                        printHZ16(750,100,"收款完成",RED,2,2,2);
                        delay(1000);
                        return 1;
                    }
                    else
                    {
                        printHZ16(750,100,"收款途中出错",RED,2,2,2);
                        delay(1000);
                        Bar(750,100,1000,190,PEACH);                      
                    }
                    break;
                case 2:
                    printHZ16(750,100,"收款未完成",RED,2,2,2);
                    delay(1000);
                    Bar(750,100,1000,190,PEACH);
                    break;
                default:
                    break;
            }
        }
        if(Mouse_press(800,600,950,700))
        {
            return 1;
        }
    }   
}