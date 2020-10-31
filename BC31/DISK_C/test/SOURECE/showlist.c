#include "public.h"
#include "tstruct.h"
#include "manage.h"
#include "showlist.h"

int watch_listinfo(list *L)
{   
    Initmouse(1,1023,1,767);
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
    printHZ16(150,70,"当前订单",BLACK,2,2,2);
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
    printHZ16(900,740,"返回",BLACK,1,1,2);
    return ;
}

void display_list(list *L)
{
    int i=0;
    char path[20]={'\0'};
    
    if(strlen(L->name)>0) //读到了未处理完的订单
    {
        put_asc(300,70,L->name,BLACK,2,2);
        if(L->list_state=='0')
        {
            printHZ16(600,70,"未处理",BLACK,2,2,2);
        }
        else if(L->list_state=='1')
        {
            printHZ16(600,70,"已发货",BLACK,2,2,2);
        }
    }

    for(i=0;i<5;i++)
    {   
        if(i>=L->top-'0')
            return ;
        Putbmp64k(50,120+120*i,Get_picturepath(L->G[i],path));
        printHZ16(175,135+120*i,"商品名",BLACK,1,1,1);
        display_goodname(L->G[i],250,135+120*i);
    }

    for(i=5;i<10;i++)
    {   
        if(i>=L->top-'0')
            return ;
        Putbmp64k(570,120+120*(i-5),Get_picturepath(L->G[i],path));
        printHZ16(695,135+120*(i-5),"商品名",BLACK,1,1,1);
        display_goodname(L->G[i],770,135+120*(i-5));
    }
    return ;
}