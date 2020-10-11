#include "universal.h"
#include "sellerpage.h"
#include "seller.h"
#include "draw.h"
#include "lists.h"
#include "tstruct.h"

int sellerpage(SELLER *s)
{
    int flag=1;
   
    list goodlist;
    storage sto;
    char str[10]; //������ʾ�̼�����
    storage_init(&sto);

    draw_sellerpage();
    sprintf(str,"%.2f",s->rat->average);
    put_asc(230,675,str,VIOLET,1,1);

    while (1)
    {   
        Newxy();
        switch(flag)
        {
            case 1:
            flag=select_sellerpage();
            break;
            case 2:
            flag=manage_goods();
            break;
            case 3:
            flag=promotion();
            break;
            case 4:
            flag=watch_listinfo();
            break;
            case 5:
            flag=charge();
            break;
            case 6:
            flag=changeinfo(s);
            break;
            case 7:
            return 2;   //����˳��̼Ҷ�,�ص���¼����
            default:
            printf("something wrong");
            delay(1000);
            exit(1);
        }

    }
    









}



void  storage_init(storage *sto)
{
    int i,j,k;

    sto->goods_amount=0;
    for(i=0;i<15;i++)
    {
        sto->G[i].name='\0';
        sto->G[i].price=0;
        sto->G[i].inventory=0;
        sto->G[i].classification=0;
        sto->G[i].sale_volume=0;
        sto->G[i].rat={0,{0},0};
    }
}
int select_sellerpage()
{
     int light_sign=0;    //�ж��Ƿ񱻱���
     
    while (1)
    {
        Newxy();
        if(Mouse_above(630,50,800,250))
        {
            if(Mouse_press(630,50,800,250)==0)
            {
                if(light_sign==0)
                {
                    lightbutton_sellerpage(VIOLET,1);
                    light_sign=1;
                    continue;
                }
            }
            else if(Mouse_press(630,50,800,250)==1)
                return 2;
        }
        if(Mouse_press(820,50,990,250))
        {
            if(Mouse_press(820,50,990,250)==0)
            {
                if(light_sign==0)
                {
                    lightbutton_sellerpage(VIOLET,2);
                    light_sign=2;
                    continue;
                }
            }
            else if(Mouse_press(820,50,990,250)==1)
                return 3;
        }
        if(Mouse_press(630,300,800,500))
        {   
            if(Mouse_press(630,300,800,500)==0)
            {
                if(light_sign==0)
                {
                    lightbutton_sellerpage(VIOLET,3);
                    light_sign=3;
                    continue;
                }
            }
            else if(Mouse_press(630,300,800,500)==1)
                return 4;
        }
        if(Mouse_press(820,300,990,500))
        {   
            if(Mouse_press(820,300,990,500)==0)
            {
                if(light_sign==0)
                {
                    lightbutton_sellerpage(VIOLET,4);
                    light_sign=4;
                    continue;
                }
            }
            else if(Mouse_press(820,300,990,500)==1)
            return 5;
        }
        if(Mouse_press(850,550,950,700))
        {   
            if(Mouse_press(850,550,950,700)==0)
            {
                if(light_sign==0)
                {
                    lightbutton_sellerpage(ORANGE,5);
                    light_sign=5;
                    continue;
                }
            }
            else if(Mouse_press(850,550,950,700)==1)
                return 6;
        }
        if(Mouse_press(630,550,820,700))
        {   
            if(Mouse_press(630,550,820,700)==0)
            {
                if(light_sign==0)
                {
                    lightbutton_sellerpage(ORANGE,6);
                    light_sign=6;
                    continue;
                }
            }
            else if(Mouse_press(630,550,820,700)==1)
                return 7;
        }
    }
    if(light_sign!=0)
    {
        resetbutton_sellerpage(light_sign);
        light_sign=0;
        continue;
    }
  
}

void lightbutton_sellerpage(int color,int flag)
{
    switch (flag)
    {
        case 1:
        Bar(630,50,800,250,CORAL);
        printHZ16(640,70,"��Ʒ",BLACK,4,4,10);
        printHZ16(660,180,"����",BLACK,4,4,7);
        break;
        case 2:
        Bar(820,50,990,250,CORAL);
        printHZ16(830,70,"����",BLACK,4,4,10);
        printHZ16(830,180,"��Ʒ",BLACK,4,4,10);
        break;
        case 3:
        Bar(630,300,800,500,CORAL);
        printHZ16(640,320,"�鿴����",BLACK,2,2,7);
        printHZ16(680,430,"��Ϣ",BLACK,2,2,7);
        break;
        case 4:
        Bar(820,300,990,500,CORAL);
        printHZ16(830,70,"��Ǯ",BLACK,4,4,10);
        break;
        case 5:
        Bar(850,550,950,700,GOLDEN);
        printHZ16(860,570,"�޸ĸ�����Ϣ",BLACK,1,1,1);
        break;
        case 6:
        Bar(630,550,820,700,GOLDEN);
        printHZ16(630,570,"�˳��̼Ҷ�",BLACK,1,1,1);
        break;
        default:
        printf("something wrong");
        exit(1);
        break;
    }
}

void resetbutton_sellerpage(int flag)
{
    switch (flag)
    {
        case 1:
        Bar(630,50,800,250,color);
        printHZ16(640,70,"��Ʒ",BLACK,4,4,10);
        printHZ16(660,180,"����",BLACK,4,4,7);
        break;
        case 2:
        Bar(820,50,990,250,color);
        printHZ16(830,70,"����",BLACK,4,4,10);
        printHZ16(830,180,"��Ʒ",BLACK,4,4,10);
        break;
        case 3:
        Bar(630,300,800,500,color);
        printHZ16(640,320,"�鿴����",BLACK,2,2,7);
        printHZ16(680,430,"��Ϣ",BLACK,2,2,7);
        break;
        case 4:
        Bar(820,300,990,500,color);
        printHZ16(830,70,"��Ǯ",BLACK,4,4,10);
        break;
        case 5:
        Bar(850,550,950,700,color);
        printHZ16(860,570,"�޸ĸ�����Ϣ",BLACK,1,1,1);
        break;
        case 6:
        Bar(630,550,820,700,color);
        printHZ16(630,570,"�˳��̼Ҷ�",BLACK,1,1,1);
        break;
        default:
        printf("something wrong");
        exit(1);
        break;
    }
}