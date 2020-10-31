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
			sum=sum+atof(L->G[i].price);
        }
    }
    return sum;
}

int chargelist(list *L)
{
    FILE *fp=NULL;
    list temp;

    fp=fopen("..\\file\\list\\list.txt","r");
    if(!fp)
    {
        return 0;
    }

    while (!feof(fp))
    {
        if(fread(&temp,sizeof(list),1,fp)==0)
            break;
        if(temp.list_state=='0')
        {
            fclose(fp);
            delay(1500);
            return 1;
        }
    }
    
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
     //Putbmp64k(50,260,"..\\file\\bmp\\charge.bmp");
     Barshadow(300,200,700,600,MIMOSA,GRAY);
	Barshadow(750,200,950,300,IVY_GREEN,GRAY);
	Barshadow(750,350,950,450,IVY_GREEN,GRAY);
    Barshadow(750,500,950,600,IVY_GREEN,GRAY);
	printHZ16(780,230,"计算总金额",BLACK,2,2,2);
    printHZ16(350,250,"配送状态",BLACK,3,3,2);
    printHZ16(780,380,"收款",BLACK,3,3,3);
    printHZ16(780,530,"发货",BLACK,3,3,3);
    printHZ16(550,100,"订单总金额",RED,2,2,2);
    Barshadow(800,650,950,750,GRASS_GREEN,BLACK);
    printHZ16(830,670,"返回",BLACK,2,2,2);
}

int charge(list *L)
{   
    float total=0;
	char str[10];
	int charge_state=0;
    int deliver_state=0;

	str[0]='\0';
    draw_charge();
    Initmouse(1,1023,1,767);
    if(L->list_state=='1')
    {
        printHZ16(400,400,"已配送至",BLACK,2,2,2);
        deliver_destination(400,480,L);
    }
    while(1)
    {
        Newxy();
        if(Mouse_press(750,200,950,300))
        {   
            if(L->list_state=='0')
            {
                total=calculate_total(L);
                sprintf(str,"%.2f",total);
                put_asc(770,100,str,BLACK,2,2);
            }
            else
            {
                printHZ16(770,100,"已发货",BLACK,2,2,1);
                delay(1000);
                Bar(770,100,970,170,PEACH);   
            }
        }
        if(Mouse_press(750,350,950,450))
        {   
            if(L->list_state=='0')
            {
                charge_state=chargelist(L);
                if(charge_state==0||charge_state==2)
                {
                    printHZ16(400,200,"暂不能收款",BLACK,2,2,2);
                    delay(600);
                    Bar(400,200,700,300,PEACH);
                }
                else if(charge_state==1)
                {
                    printHZ16(400,150,"收款完成",BLACK,2,2,1);
                    delay(600);
                    Bar(400,150,700,199,PEACH);
                }
                else
                {
                    continue;
                }
            }
            else
            {
                printHZ16(770,100,"已发货",BLACK,2,2,1);
                delay(1000);
                Bar(770,100,970,170,PEACH);   
            }
        }
        if(Mouse_press(750,500,950,600))
        {   
            if(L->list_state=='0')
            {
                if(charge_state==0)
                {
                    printHZ16(400,200,"未收款",BLACK,2,2,2);
                    delay(600);
                    Bar(400,200,700,300,PEACH);
                    continue;
                }
                if(charge_state==1)
                {   
                    deliver_state=deliver(L);
                    if(deliver_state==0)
                    {
                        printHZ16(400,200,"暂不能配送",BLACK,2,2,2);
                        delay(1000);
                        Bar(400,200,700,300,MIMOSA);
                        continue;
                    }
                    else
                    {
                        printHZ16(400,450,"配送指令已下达",BLACK,2,2,1);
                        delay(1000);
                        Bar(400,450,650,570,MIMOSA);
                        printHZ16(400,400,"配送至",BLACK,2,2,2);
                        deliver_destination(400,480,L);
                        reduce_inventory(L);
                    }
                }
            }
            else
            {
                printHZ16(770,100,"已发货",BLACK,2,2,1);
                delay(1000);
                Bar(770,100,970,170,PEACH);   
            }
        }
        if(Mouse_press(800,600,950,700))
        {
            return 1;
        }
    }   
}

void draw_deliver()
{ 
	printHZ16(400,450,"处理中",BLACK,2,2,2);
    delay(500);
    Put_Asc16_Size(550,500,2,2,'.',BLACK);
    delay(500);
    Put_Asc16_Size(600,500,2,2,'.',BLACK);
    delay(500);
    Put_Asc16_Size(650,500,2,2,'.',BLACK);
    Bar(400,450,650,510,MIMOSA);
    printHZ16(400,450,"开始配送",BLACK,2,2,2);
    delay(1000);
    Bar(400,450,650,520,MIMOSA);
    return;
}
int deliver(list *L)
{
    FILE *fp1=NULL;
    FILE *fp2=NULL;
    list temp;
    int i=0;
    int inv=0; //用来执行库存量的转换

    fp1=fopen("..\\file\\list\\list.txt","r");
    fp2=fopen("..\\file\\list\\list2.txt","a");

    if(fp1==NULL||fp2==NULL)
    {
        return 0;
    }

    draw_deliver();

    while(!feof(fp1))
    {
        if(fread(&temp,sizeof(list),1,fp1)==0)
            break;
        if(strcmp(L->name,temp.name)==0&&temp.list_state=='0')
        {
            temp.list_state='1';
            for(i=0;i<temp.top-'0';i++)
            {   
                inv=atoi(temp.G[i].inventory);
                inv--;  //发货,库存量减一
                itoa(inv,temp.G[i].inventory,10);
            }
            fwrite(&temp,sizeof(list),1,fp2);
        }
        else
        {   
            fwrite(&temp,sizeof(list),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("..\\file\\list\\list.txt");
    rename("..\\file\\list\\list2.txt","..\\file\\list\\list.txt");
    return 1;
}

void deliver_destination(int x,int y,list *L)
{
    switch (L->pos)
    {
        case 'a':
        printHZ16(x,y,"保利花园",BLACK,2,2,1);
        break;
        case 'b':
        printHZ16(x,y,"关南社区",BLACK,2,2,1);
        break;
        case 'c':
        printHZ16(x,y,"关山春晓",BLACK,2,2,1);
        break;
        case 'd':
        printHZ16(x,y,"光谷青年城",BLACK,2,2,1);
        break;
        case 'e':
        printHZ16(x,y,"光谷时间广场",BLACK,2,2,1);
        break;
        case 'f':
        printHZ16(x,y,"光谷新世界",BLACK,2,2,1);
        break;
        case 'g':
        printHZ16(x,y,"光谷中心花园",BLACK,2,2,1);
        break;
        case 'h':
        printHZ16(x,y,"华中科技大学",BLACK,2,2,1);
        break;
        case 'i':
        printHZ16(x,y,"华中科技大学文华学院",BLACK,2,2,1);
        break;
        case 'j':
        printHZ16(x,y,"虹景花园",BLACK,2,2,1);
        break;
        case 'k':
        printHZ16(x,y,"华中科技大学沁苑",BLACK,2,2,1);
        break;
        case 'l':
        printHZ16(x,y,"华中科技大学东校区",BLACK,2,2,1);
        break;
        case 'm':
        printHZ16(x,y,"中建康城",BLACK,2,2,1);
        break;
        case 'n':
        printHZ16(x,y,"华中科技大学紫菘",BLACK,2,2,1);
        break;
        case 'o':
        printHZ16(x,y,"金地太阳城",BLACK,2,2,1);
        break;
        case 'p':
        printHZ16(x,y,"武汉职业技术学院东区",BLACK,2,2,1);
        break;
        case 'q':
        printHZ16(x,y,"武汉职业技术学院西区",BLACK,2,2,1);
        break;
        case 'r':
        printHZ16(x,y,"华中科技大学韵苑",BLACK,2,2,1);
        break;
        default:
            break;
    }
    return;
}

int reduce_inventory(list *L)
{
    FILE *fp1=NULL;
    FILE *fp2=NULL;
    int i=0;
    int inv=0; //用来执行库存量的转换
    good temp;

    for(i=0;i<L->top-'0';i++)
    {   
        fp1=fopen("..\\file\\storage\\storage.txt","r");
        fp2=fopen("..\\file\\storage\\storage2.txt","a");
        if(fp1==NULL||fp2==NULL)
        {
            return 0;
        }
        while (!feof(fp1))
        {
            if(fread(&temp,sizeof(good),1,fp1)==0)
                break;
            if(strcmp(temp.picpath,L->G[i].picpath)==0)
            {
                inv=atoi(temp.inventory);
                inv--;
                itoa(inv,temp.inventory,10);
                fwrite(&temp,sizeof(good),1,fp2);
            }
            else
            {
                fwrite(&temp,sizeof(good),1,fp2);
            }
        }
        fclose(fp1);
        fclose(fp2);
        remove("..\\file\\storage\\storage.txt");
        rename("..\\file\\storage\\storage2.txt","..\\file\\storage\\storage.txt");
    }

    return 1;
}