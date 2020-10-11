#include "public.h"
#include "seller.h"
#include "tstruct.h"
#include "manage.h"
#include "storage.h"
#include "input.h"

int manage_goods(storage *sto)
{   
    int flag=1; //连接各个子功能
    int pagenum=1;

    while(1)
    {
        Newxy();
        switch (flag)
        {
        case 1:
            draw_managegoods();  //先画出商品管理界面
            flag=select_managegoods();  //默认状态,选择进入哪个具体的功能模块
            break;
        case 2:
            flag=display_storage(sto,2,&pagenum);
            break;
        case 3:
  //          flag=add_goods(sto); //增加新商品
            break;
        case 4:
  //          flag=adjust_goods(sto); //调整商品信息(库存量和价钱,别的信息不允许调整)
            break;
        case 5:
  //          flag=discard_goods(sto); //从货架中移除某种商品
            break;
        case 6:
            return 1;  //回到商家端主界面
        default:
            break;
        }
    }
}

int select_managegoods()
{
    while(1)
    {
        Newxy();
        if(Mouse_press(630,50,800,250))
        {
            return 2;
        }
        if(Mouse_press(820,50,990,250))
        {
            return 3;
        }
        if(Mouse_press(630,300,800,500))
        {
            return 4;
        }
        if(Mouse_press(820,300,990,500))
        {
            return 5;
        }
        if(Mouse_press(630,550,970,700))
        {
            return 6;
        }
    }
}
void draw_managegoods()
{
    Bar(1,1,1023,767,LIGHT_SEA_GREEN);
	
    printHZ16(100,40,"帅团",MIMOSA,3,3,6);
    printHZ16(300,100,"商家端商品管理",ORANGE,2,2,2);

    LineThickSha(40,60,50,70,MIMOSA,BLACK,60,1);
	LineThickSha(50,70,80,100,MIMOSA,BLACK,25,1);
	LineThickSha(110,100,120,110,MIMOSA,BLACK,80,1);

	LineThickSha(260,50,250,70,WHITE,BLACK,50,1);
	LineThickSha(235,70,220,100,WHITE,BLACK,25,1);
	LineThickSha(230,100,220,120,WHITE,BLACK,60,1);

    Putbmp64k(50,250,"..\\file\\bmp\\manage.bmp");

    Line(600,1,600,767,DARK_VIOLET);
    Barshadow(630,50,800,250,RED,BLACK);
    Barshadow(820,50,990,250,GREEN,BLACK);
    Barshadow(630,300,800,500,GOLDEN,BLACK);
    Barshadow(820,300,990,500,AZURE,BLACK);
    Barshadow(630,550,970,700,PURPLE,BLACK);

    printHZ16(640,70,"查看",BLACK,4,4,10);
    printHZ16(660,180,"货架",BLACK,4,4,7);
    printHZ16(830,70,"添加",BLACK,4,4,10);
    printHZ16(830,180,"商品",BLACK,4,4,10);
    printHZ16(640,320,"更新商品",BLACK,2,2,4);
    printHZ16(680,430,"状态",BLACK,2,2,4);
    printHZ16(830,350,"删除",BLACK,2,2,5);
    printHZ16(830,420,"商品",BLACK,2,2,5);
    printHZ16(660,600,"返回商家主页",BLACK,2,2,2);
}

int display_storage(storage *sto,int *pagenum)
{
    draw_storage(sto);
    show_storagepage(sto,1); //默认显示第一页的内容

    while(1)
    {   
        Newxy();
        if(Mouse_press(750,60,824,140))
        {   
            show_storagepage(sto,1);
        }
        if(Mouse_press(825,60,900,140))
        {   
            show_storagepage(sto,2);
        }
        if(Mouse_press(750,730,900,760))
        {
            return 1;
        }
    }
}

void draw_storage()
{
    Bar(1,1,1023,767,LIGHT_LIME);
    Barshadow(30,50,1000,720,GOLDEN,GRAYISH_PURPLE);
    Barshadow(70,160,470,280,WHITE,GRAY);
    Barshadow(70,300,470,420,WHITE,GRAY);
    Barshadow(70,440,470,560,WHITE,GRAY);
    Barshadow(70,580,470,700,WHITE,GRAY);
    Barshadow(530,160,930,280,WHITE,GRAY);
    Barshadow(530,300,930,420,WHITE,GRAY);
    Barshadow(530,440,930,560,WHITE,GRAY);
    Barshadow(530,580,930,700,WHITE,GRAY);
    printHZ16(600,80,"页号",BLACK,2,2,2);
    Bar(750,60,900,140,LIGHT_CORAL);
    Liney(825,60,825,140,BLACK);
    Put_Asc16_Size(780,80,2,2,'1',BLACK);
	Put_Asc16_Size(850,80,2,2,'2',BLACK);
    Barshadow(750,730,900,760,BLUE,GRAY);
	printHZ16(770,735,"返回",BLACK,1,1,2);
}

void show_storagepage(storage *sto,int pagenum)
{   
    int i=0; //循环变量
    char inv[5]="\0"; //显示库存量
    char vol[5]="\0"; //显示销量
    char pri[5]="\0"; //显示价格
    char sco[5]="\0" ; //显示评分
    if(pagenum==1)
    {
        for(i=0;i<4;i++)
        {   
            if(i>=sto->goods_amount) 
                break;
            Putbmp64k(75,165+140*i,sto->G[i].picpath);
            printHZ16(180,165+140*i,"商品名",BLACK,1,1,1);
            put_asc(260,165+140*i,sto->G[i].name,BLACK,1,1);
            printHZ16(180,185+140*i,"售价",BLACK,1,1,1);
            sprintf(pri,".2f",sto->G[i].price);
            put_asc(240,185+140*i,pri,BLACK,1,1);
            pri[0]='\0';  //复位,准备下一个输入
            printHZ16(180,205+140*i,"销量",BLACK,1,1,1);
            sprintf(vol,"%d",sto->G[i].sale_volume);
            put_asc(240,205+140*i,vol,BLACK,1,1);
            vol[0]='\0';
            printHZ16(180,225+140*i,"库存量",BLACK,1,1,1);
            sprintf(inv,"%d",sto->G[i].inventory);
            put_asc(250,225+140*i,inv,BLACK,1,1);
            inv[0]='\0';
            printHZ16(180,245+140*i,"用户评分",BLACK,1,1,1);
            sprintf(sco,"%.2f",sto->G[i].rat.average);
            put_asc(270,245+140*i,sco,BLACK,1,1);
            sco[0]='\0';
        }
        for(i=4;i<8;i++)
        {   
            if(i>=sto->goods_amount) 
                break;
            Putbmp64k(535,165+140*(i-4),sto->G[i].picpath);
            printHZ16(640,165+140*(i-4),"商品名",BLACK,1,1,1);
            put_asc(710,165+140*(i-4),sto->G[i].name,BLACK,1,1);
            printHZ16(640,185+140*(i-4),"售价",BLACK,1,1,1);
            sprintf(pri,".2f",sto->G[i].price);
            put_asc(710,185+140*(i-4),pri,BLACK,1,1);
            pri[0]='\0';  //复位,准备下一个输入
            printHZ16(640,205+140*(i-4),"销量",BLACK,1,1,1);
            sprintf(vol,"%d",sto->G[i].sale_volume);
            put_asc(690,205+140*(i-4),vol,BLACK,1,1);
            vol[0]='\0';
            printHZ16(640,225+140*(i-4),"库存量",BLACK,1,1,1);
            sprintf(inv,"%d",sto->G[i].inventory);
            put_asc(700,225+140*(i-4),inv,BLACK,1,1);
            inv[0]='\0';
            printHZ16(640,245+140*(i-4),"用户评分",BLACK,1,1,1);
            sprintf(sco,"%.2f",sto->G[i].rat.average);
            put_asc(720,245+140*(i-4),sco,BLACK,1,1);
            sco[0]='\0';
        }
    }
    else if(pagenum==2)
    {
        for(i=8;i<12;i++)
        {   
            if(i>=sto->goods_amount) 
                break;
            Putbmp64k(75,165+140*(i-8),sto->G[i].picpath);
            printHZ16(180,165+140*(i-8),"商品名",BLACK,1,1,1);
            put_asc(260,165+140*(i-8),sto->G[i].name,BLACK,1,1);
            printHZ16(180,185+140*(i-8),"售价",BLACK,1,1,1);
            sprintf(pri,".2f",sto->G[i].price);
            put_asc(240,185+140*(i-8),pri,BLACK,1,1);
            pri[0]='\0';  //复位,准备下一个输入
            printHZ16(180,205+140*(i-8),"销量",BLACK,1,1,1);
            sprintf(vol,"%d",sto->G[i].sale_volume);
            put_asc(240,205+140*(i-8),vol,BLACK,1,1);
            vol[0]='\0';
            printHZ16(180,225+140*(i-8),"库存量",BLACK,1,1,1);
            sprintf(inv,"%d",sto->G[i].inventory);
            put_asc(250,225+140*i,inv,BLACK,1,1);
            inv[0]='\0';
            printHZ16(180,245+140*(i-8),"用户评分",BLACK,1,1,1);
            sprintf(sco,"%.2f",sto->G[i].rat.average);
            put_asc(270,245+140*(i-8),sco,BLACK,1,1);
            sco[0]='\0';
        }
        for(i=12;i<15;i++)
        {   
            if(i>=sto->goods_amount)
                break;
            Putbmp64k(535,165+140*(i-12),sto->G[i].picpath);
            printHZ16(640,165+140*(i-12),"商品名",BLACK,1,1,1);
            put_asc(710,165+140*(i-12),sto->G[i].name,BLACK,1,1);
            printHZ16(640,185+140*(i-12),"售价",BLACK,1,1,1);
            sprintf(pri,".2f",sto->G[i].price);
            put_asc(710,185+140*(i-12),pri,BLACK,1,1);
            pri[0]='\0';  //复位,准备下一个输入
            printHZ16(640,205+140*(i-12),"销量",BLACK,1,1,1);
            sprintf(vol,"%d",sto->G[i].sale_volume);
            put_asc(690,205+140*(i-12),vol,BLACK,1,1);
            vol[0]='\0';
            printHZ16(640,225+140*(i-12),"库存量",BLACK,1,1,1);
            sprintf(inv,"%d",sto->G[i].inventory);
            put_asc(700,225+140*(i-12),inv,BLACK,1,1);
            inv[0]='\0';
            printHZ16(640,245+140*(i-12),"用户评分",BLACK,1,1,1);
            sprintf(sco,"%.2f",sto->G[i].rat.average);
            put_asc(720,245+140*(i-12),sco,BLACK,1,1);
            sco[0]='\0';
        }
    }
}

void draw_addgoods()
{
    Barshadow(300,300,750,650,MALLOW,BLACK);
    printHZ16(400,325,"添加商品",BLACK,2,2,2);
    printHZ16(330,400,"商品名称",BLACK,2,2,2);
    Line(450,430,700,430,BLACK);
    printHZ16(330,440,"现有库存量",BLACK,2,2,2);
    Line(550,470,700,470,BLACK);
    printHZ16(330,480,"初定价格",BLACK,2,2,2);
    Line(500,510,700,510,BLACK);
    Barshadow(630,560,730,620,CORAL,GRAY);
    printHZ16(650,580,"返回",1,1,2);
}

void draw_adjustgoods()
{
    Barshadow(300,300,750,650,MALLOW,BLACK);
    printHZ16(400,325,"修改商品信息",BLACK,2,2,2);
    printHZ16(330,400,"商品名称",BLACK,2,2,2);
    printHZ16(330,440,"修改库存量",BLACK,2,2,2);
    Line(550,470,700,470,BLACK);
    printHZ16(330,480,"修改价格",BLACK,2,2,2);
    Line(500,510,700,510,BLACK);
    Barshadow(630,560,730,620,CORAL,GRAY);
    printHZ16(650,580,"返回",1,1,2);
}

int add_goods(storage *sto)
{   
    good temp;
    char str[7]={'\0'};
    int namelen=0,invlen=0,prilen=0;
    
    draw_addgoods();

    while(1)
    {
        Newxy();
        if(Mouse_press(450,400,700,430))
        {
            namelen=Input(450,400,700,430,namelen,(temp.picpath)+3,BLACK,2,2,15,0);
            temp.picpath[namelen+3]='\0';
        }
        if(Mouse_press(550,440,700,470))
        {
            invlen=Input(550,440,700,470,invlen,str,BLACK,2,2,6,0);
            str[invlen]='\0';
            temp.inventory=atoi(str);
            str[0]='\0';
        }
        if(Mouse_press(500,480,700,510))
        {
            prilen=Input(500,480,700,510,prilen,str,BLACK,2,2,6,0);
            str[prilen]='\0';
            temp.price=atof(str);
            str[0]='\0';
        }
        if(Mouse_press(520,560,600,620))
        {
            if(namelen&&invlen&&prilen)
            {
                switch (appendstorage(sto,&temp))
                {
                    case 0:
                        printHZ16(330,550,"未找到该商品",2,2,1);
                        delay(1500);
                        return 1;
                    case 1:
                        printHZ16(330,550,"商品添加成功",2,2,1);
                        delay(1500);
                        return 1;
                    case 2:
                        printHZ16(330,550,"文件打开失败",2,2,1);
                        delay(1500);
                        return 1;
                    default:
                        break;
                }
            }
        }
        if (Mouse_press(630,560,730,620))
        {
            return 1;
        }
    }
}

int iuput_adjustment(good *g)
{
    good temp;
    char str[7]={'\0'};
    int invlen=0,prilen=0;
    
    draw_addgoods();

    while(1)
    {
        Newxy();
        if(Mouse_press(450,400,700,430))
        {
            namelen=Input(450,400,700,430,namelen,temp.picpath+3,BLACK,2,2,15,0);
            temp.picpath[namelen]='\0';
        }
        if(Mouse_press(550,440,700,470))
        {
            invlen=Input(550,440,700,470,invlen,str,BLACK,2,2,6,0);
            str[invlen]='\0';
            temp.inventory=atoi(str);
            str[0]='\0';
        }
        if(Mouse_press(500,480,700,510))
        {
            prilen=Input(500,480,700,510,prilen,str,BLACK,2,2,6,0);
            str[prilen]='\0';
            temp.price=atof(str);
            str[0]='\0';
        }
        if(Mouse_press(520,560,600,620))
        {
            if(namelen&&invlen&&prilen)
            {
                switch (appendstorage(sto,&temp))
                {
                    case 0:
                        printHZ16(330,550,"未找到该商品",2,2,1);
                        delay(1500);
                        return 1;
                    case 1:
                        printHZ16(330,550,"商品添加成功",2,2,1);
                        delay(1500);
                        return 1;
                    case 2:
                        printHZ16(330,550,"文件打开失败",2,2,1);
                        delay(1500);
                        return 1;
                    default:
                        break;
                }
            }
        }
        if (Mouse_press(630,560,730,620))
        {
            return 1;
        }
    }
}

int adjust_goods(storage *sto)
{
    int i=0;
    good g;
    draw_storage();
    printHZ16(50,100,"不要点击没有图的框",RED,1,1,1);
    while (1)
    {
        Newxy();
        show_storagepage(sto,1);
        if(Mouse_press(750,60,825,140))
        {
            show_storagepage(sto,1);
            if(Mouse_press(70,160,470,280))
            {   
                i=0;
                if(i>=sto->goods_amount) return 1; 
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(70,300,470,420))
            {   
                i=1;
                if(i>=sto->goods_amount) return 1; 
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(70,440,470,560))
            {   
                i=2;
                if(i>=sto->goods_amount)    return 1;
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(70,580,470,700))
            {   
                i=3;
                if(i>=sto->goods_amount) return 1;
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,160,930,280))
            {   
                i=4;
                if(i>=sto->goods_amount) return 1;
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,300,930,420))
            {   
                i=5;
                if(i>=sto->goods_amount) return 1;
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,440,930,560))
            {   
                i=6;
                if(i>=sto->goods_amount) return 1;
               
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,580,930,700))
            {   
                i=7;
                if(i>=sto->goods_amount) return 1; 
                
                shrinkstorage(sto,i);
            }
        }
        if(Mouse_press(826,60,900,140))
        {
            show_storagepage(sto,2);
            if(Mouse_press(70,160,470,280))
            {   
                i=8;
                if(i>=sto->goods_amount) return 1; 
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(70,300,470,420))
            {   
                i=9;
                if(i>=sto->goods_amount) return 1;
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(70,440,470,560))
            {   
                i=10;
                if(i>=sto->goods_amount) return 1; 
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(70,580,470,700))
            {   
                i=11;
                if(i>=sto->goods_amount) return 1;
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,160,930,280))
            {   
                i=12;
                if(i>=sto->goods_amount) return 1;
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,300,930,420))
            {   
                i=13;
                if(i>=sto->goods_amount) return 1; 
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,440,930,560))
            {   
                i=14;
                if(i>=sto->goods_amount) return 1; 
                
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,580,930,700))
            {   
                i=15;
                if(i>=sto->goods_amount)  return 1;
                
                shrinkstorage(sto,i);
            }
        }
    }
    if(Mouse_press(750,730,900,760))  return 1;
}

int discard_goods(storage *sto)
{
    int i=0;

    draw_storage();

    while (1)
    {
        Newxy();
        show_storagepage(sto,1);
        if(Mouse_press(750,60,825,140))
        {
            show_storagepage(sto,1);
            if(Mouse_press(70,160,470,280))
            {   
                i=0;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(90,180,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(70,300,470,420))
            {   
                i=1;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(90,320,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(70,440,470,560))
            {   
                i=2;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(90,460,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(70,580,470,700))
            {   
                i=3;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(90,600,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,160,930,280))
            {   
                i=4;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(550,180,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,300,930,420))
            {   
                i=5;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(550,320,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,440,930,560))
            {   
                i=6;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(550,460,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,580,930,700))
            {   
                i=7;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(550,600,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
        }
        if(Mouse_press(826,60,900,140))
        {
            show_storagepage(sto,2);
            if(Mouse_press(70,160,470,280))
            {   
                i=8;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(90,180,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(70,300,470,420))
            {   
                i=9;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(90,320,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(70,440,470,560))
            {   
                i=10;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(90,460,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(70,580,470,700))
            {   
                i=11;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(90,600,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,160,930,280))
            {   
                i=12;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(550,180,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,300,930,420))
            {   
                i=13;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(550,320,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,440,930,560))
            {   
                i=14;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(550,460,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
            if(Mouse_press(530,580,930,700))
            {   
                i=15;
                if(i>=sto->goods_amount)
                {   
                    printHZ16(50,100,"操作非法",RED,2,2,2);
                    delay(1000);
                    return 1;
                } 
                Put_Asc16_Size(550,600,4,4,'x',RED);
                shrinkstorage(sto,i);
            }
        }
    }
    if(Mouse_press(750,730,900,760))
    {
        return 1;
    }
}
