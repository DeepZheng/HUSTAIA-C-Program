#include "public.h"
#include "tstruct.h"


int watch_listinfo(list *L)
{
    draw_listbk();
    display_list(L);
    while(1)
    {   
        Newxy();
        if(Mouse_press(890,735,1000,760))
        {
            return 1;
        }
    }
}

void draw_listbk()
{
    Bar(1,1,1023,767,CORAL_PINK);
    Barshadow(20,20,1000,730,DARK_GOLDENROD,GRAY);
    printHZ16(450,70,"当前订单",BLACK,2,2,2);
    Barshadow(50,120,450,230,WHITE,GRAY);
    Barshadow(50,240,450,350,WHITE,GRAY);
    Barshadow(50,360,450,470,WHITE,GRAY);
    Barshadow(50,480,450,590,WHITE,GRAY);
    Barshadow(50,600,450,710,WHITE,GRAY);
    Barshadow(570,120,970,230,WHITE,GRAY);
    Barshadow(570,240,970,350,WHITE,GRAY);
    Barshadow(570,360,970,470,WHITE,GRAY);
    Barshadow(570,480,970,590,WHITE,GRAY);
    Barshadow(570,600,970,710,WHITE,GRAY);

    Barshadow(890,735,1000,760,MIMOSA,GRAYISH_PURPLE);
    printHZ16(900,740,"返回",1,1,2);
}

void display_list(list *L)
{
    int i=0;
 //   char str[5];
    for(i=0;i<5;i++)
    {
        Putbmp64k(55,125+120*i,L->G[i].picpath);
        printHZ16(175,125+120*i,"商品名",BLACK,1,1,1);
        put_asc(300,125+120*i,L->G[i].name,BLACK,1,1);
     /*   printHZ16(175,175+120*i,"需求量",BLACK,1,1,1);
        sprintf(str,"%d",L->[i]);
        put_asc(300,175+120*i,str,BLACK,1,1);
        str[0]='\0';*/
    }

    for(i=5;i<10;i++)
    {
        Putbmp64k(55,125+120*(i-5),L->G[i].picpath);
        printHZ16(175,125+120*(i-5),"商品名",BLACK,1,1,1);
        put_asc(300,125+120*(i-5),L->G[i].name,BLACK,1,1);
     /*   printHZ16(175,175+120*(i-5),"需求量",BLACK,1,1,1);
        sprintf(str,"%d",L->quantity[i]);
        put_asc(300,175+120*(i-5),str,BLACK,1,1);
        str[0]='\0';*/
    }
}