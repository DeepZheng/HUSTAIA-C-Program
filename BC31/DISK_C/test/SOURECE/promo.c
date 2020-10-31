#include "public.h"
#include "promo.h"
#include "manage.h"
#include "file.h"

int promotion(recommends *selections,int size)
{
 //   int selection_size=0;
    int pos=0;

    display_recommends(selections,size);
    Initmouse(1,1023,1,767);
      while(1)
    {
        Newxy();
        if(Mouse_press(70,160,470,280))
        {
            pos=0;
            if(pos>=size) return 1;
            else
            {
                if(input_recommendinfo(selections,pos)==1)
                {
                    printHZ16(450,70,"更新推荐成功",RED,2,2,2);
                    delay(1000);
                    return 1;
                }
            }
        }
        if(Mouse_press(70,300,470,420))
        {
            pos=1;
            if(pos>=size) return 1;
            else
            {
                if(input_recommendinfo(selections,pos)==1)
                {
                    printHZ16(450,70,"更新推荐成功",RED,2,2,2);
                    delay(1000);
                    return 1;
                }
            }
        }
        if(Mouse_press(70,440,470,560))
        {
            pos=2;
            if(pos>=size) return 1;
            else
            {
                if(input_recommendinfo(selections,pos)==1)
                {
                    printHZ16(450,70,"更新推荐成功",RED,2,2,2);
                    delay(1000);
                    return 1;
                }
            }
        }
        if(Mouse_press(70,580,470,700))
        {
            pos=3;
            if(pos>=size) return 1;
            else
            {
                if(input_recommendinfo(selections,pos)==1)
                {
                    printHZ16(450,70,"更新推荐成功",RED,2,2,2);
                    delay(1000);
                    return 1;
                }
            }
        }
        if(Mouse_press(530,160,930,280))
        {
            pos=4;
            if(pos>=size) return 1;
            else
            {
                if(input_recommendinfo(selections,pos)==1)
                {
                    printHZ16(450,70,"更新推荐成功",RED,2,2,2);
                    delay(1000);
                    return 1;
                }
            }
        }
        if(Mouse_press(530,300,930,420))
        {
            pos=5;
            if(pos>=size) return 1;
            else
            {
                if(input_recommendinfo(selections,pos)==1)
                {
                    printHZ16(450,70,"更新推荐成功",RED,2,2,2);
                    delay(1000);
                    return 1;
                }
            }
        }
        if(Mouse_press(530,440,930,560))
        {
            pos=6;
            if(pos>=size) return 1;
            else
            {
                if(input_recommendinfo(selections,pos)==1)
                {
                    printHZ16(450,70,"更新推荐成功",RED,2,2,2);
                    delay(1000);
                    return 1;
                }
            }
        }
        if(Mouse_press(530,580,930,700))
        {
            pos=7;
            if(pos>=size) return 1;
            else
            {
                if(input_recommendinfo(selections,pos)==1)
                {
                    printHZ16(450,70,"更新推荐成功",RED,2,2,2);
                    delay(1000);
                    return 1;
                }
            }
        }
        if(Mouse_press(600,710,800,750))
        {
            return 1;
        }
    }
}


void display_recommends(recommends *recommend,int recommend_size)
{   
    int i=0;
    char path[20]={'\0'};

    Bar(1,1,1023,767,MUSTARD);
    Barshadow(50,50,1000,705,MIMOSA,BLACK);
    printHZ16(70,70,"点击选择推荐商品",RED,2,2,2);
    Barshadow(70,160,470,280,WHITE,GRAY);
    Barshadow(70,300,470,420,WHITE,GRAY);
    Barshadow(70,440,470,560,WHITE,GRAY);
    Barshadow(70,580,470,700,WHITE,GRAY);
    Barshadow(530,160,930,280,WHITE,GRAY);
    Barshadow(530,300,930,420,WHITE,GRAY);
    Barshadow(530,440,930,560,WHITE,GRAY);
    Barshadow(530,580,930,700,WHITE,GRAY);
    Barshadow(600,710,800,750,CORAL,GRAY);
    printHZ16(620,720,"返回",BLACK,1,1,1);

    for(i=0;i<4;i++)
        {   
            if(i>=recommend_size) 
                return;
            Putbmp64k(75,165+140*i,Get_picturepath(recommend->re[i],path));
            printHZ16(190,165+140*i,"商品名",BLACK,1,1,1);
            display_goodname(recommend->re[i],260,165+140*i);
            printHZ16(190,185+140*i,"售价",BLACK,1,1,1);
            put_asc(240,185+140*i,recommend->re[i].price,BLACK,1,1);  
            printHZ16(190,225+140*i,"剩余拼团数",BLACK,1,1,1);
            put_asc(340,225+140*i,recommend->re[i].inventory,BLACK,1,1);
        }
        for(i=4;i<8;i++)
        {   
            if(i>=recommend_size) 
               return;
            Putbmp64k(535,165+140*(i-4),Get_picturepath(recommend->re[i],path));
            printHZ16(650,165+140*(i-4),"商品名",BLACK,1,1,1);
            display_goodname(recommend->re[i],710,165+140*(i-4));
            printHZ16(650,185+140*(i-4),"售价",BLACK,1,1,1);
            put_asc(710,185+140*(i-4),recommend->re[i].price,BLACK,1,1);
            printHZ16(650,225+140*(i-4),"剩余拼团数",BLACK,1,1,1);
			put_asc(800,225+140*(i-4),recommend->re[i].inventory,BLACK,1,1);
        }
}

int input_recommendinfo(recommends *recommend,int pos)
{
    FILE *fp=NULL;

    fp=fopen("..\\file\\storage\\recom.txt","w");
    if(fp==NULL)
    {
        return 0;
    }
    fwrite(&(recommend->re[pos]),sizeof(good),1,fp);
    fclose(fp);
    return 1;
}