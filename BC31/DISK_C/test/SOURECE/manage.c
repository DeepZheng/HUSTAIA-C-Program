#include "public.h"
#include "seller.h"
#include "tstruct.h"
#include "manage.h"
#include "storage.h"
#include "input.h"

int manage_goods(storage *sto)
{   
    int flag=1; //���Ӹ����ӹ���
    
    while(1)
    {
        Newxy();
        switch (flag)
        {
        case 1:
            draw_managegoods();  //�Ȼ�����Ʒ�������
            Initmouse(1,1023,1,767);
            flag=select_managegoods();  //Ĭ��״̬,ѡ������ĸ�����Ĺ���ģ��
            break;
        case 2:
            flag=display_storage(sto);
            break;
        case 3:
            flag=add_goods(sto); //��������Ʒ
            break;
        case 4:
            flag=adjust_goods(sto); //������Ʒ��Ϣ(������ͼ�Ǯ,�����Ϣ���������)
            break;
        case 5:
            flag=discard_goods(sto); //�ӻ������Ƴ�ĳ����Ʒ
            break;
        case 6:
            update_userselection(sto);  //����4����Ʒtxt�ļ�
            return 1;  //�ص��̼Ҷ�������
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
	
    printHZ16(100,40,"˧��",MIMOSA,3,3,6);
    printHZ16(300,100,"�̼Ҷ���Ʒ����",ORANGE,2,2,2);

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

    printHZ16(640,70,"�鿴",BLACK,4,4,10);
    printHZ16(660,180,"����",BLACK,4,4,7);
    printHZ16(830,70,"���",BLACK,4,4,10);
    printHZ16(830,180,"��Ʒ",BLACK,4,4,10);
    printHZ16(640,320,"������Ʒ",BLACK,2,2,4);
    printHZ16(680,430,"״̬",BLACK,2,2,4);
    printHZ16(830,350,"ɾ��",BLACK,2,2,5);
    printHZ16(830,420,"��Ʒ",BLACK,2,2,5);
    printHZ16(660,600,"�����̼���ҳ",BLACK,2,2,2);
}

int display_storage(storage *sto)
{   
    Initmouse(1,1023,1,767);
    draw_storage();
    show_storagepage(sto,1); //Ĭ����ʾ��һҳ������

    while(1)
    {   
        Newxy();
        if(Mouse_press(750,60,824,140))
        {   
            draw_storage();
            show_storagepage(sto,1);
        }
        if(Mouse_press(825,60,900,140))
        {   
            draw_storage();
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
    printHZ16(600,80,"ҳ��",BLACK,2,2,2);
    Bar(750,60,900,140,LIGHT_CORAL);
    Liney(825,60,825,140,BLACK);
    Put_Asc16_Size(780,80,2,2,'1',BLACK);
	Put_Asc16_Size(850,80,2,2,'2',BLACK);
    Barshadow(750,730,900,760,BLUE,GRAY);
	printHZ16(770,735,"����",BLACK,1,1,2);
}

char* Get_picturepath(good g,char *path)
{
    const char *str1="..\\file\\bmp\\";
    const char *str2=".bmp";
    strcpy(path,str1);
    strcat(path,g.picpath);
    strcat(path,str2);
    return path;
}

void show_storagepage(storage *sto,int pagenum)
{   
    int i=0; //ѭ������
    char path[20]; //����ͼƬ·��

    if(pagenum==1)
    {
        for(i=0;i<4;i++)
        {   
            if(i>=sto->goods_amount) 
                break;
            Putbmp64k(75,165+140*i,Get_picturepath(sto->G[i],path));
            printHZ16(200,165+140*i,"��Ʒ��",BLUE,1,1,1);
            display_goodname(sto->G[i],280,165+140*i);
            printHZ16(200,195+140*i,"�ۼ�",BLUE,1,1,1);
            put_asc(240,195+140*i,sto->G[i].price,BLACK,1,1);  
            printHZ16(200,225+140*i,"ʣ��ƴ����",BLUE,1,1,1);
            put_asc(300,225+140*i,sto->G[i].inventory,BLACK,1,1);
        }
        for(i=4;i<8;i++)
        {   
            if(i>=sto->goods_amount) 
                break;
            Putbmp64k(535,165+140*(i-4),Get_picturepath(sto->G[i],path));
            printHZ16(660,165+140*(i-4),"��Ʒ��",BLUE,1,1,1);
            display_goodname(sto->G[i],730,165+140*(i-4));
            printHZ16(660,195+140*(i-4),"�ۼ�",BLUE,1,1,1);
            put_asc(710,195+140*(i-4),sto->G[i].price,BLACK,1,1);
            printHZ16(660,225+140*(i-4),"ʣ��ƴ����",BLUE,1,1,1);
            put_asc(780,225+140*(i-4),sto->G[i].inventory,BLACK,1,1);
        }
    }
    else if(pagenum==2)
    {
        for(i=8;i<12;i++)
        {   
            if(i>=sto->goods_amount) 
                break;
            Putbmp64k(75,165+140*(i-8),Get_picturepath(sto->G[i],path));
            printHZ16(190,165+140*(i-8),"��Ʒ��",BLUE,1,1,1);
            display_goodname(sto->G[i],280,165+140*(i-8));
            printHZ16(190,195+140*(i-8),"�ۼ�",BLUE,1,1,1);
            put_asc(260,195+140*(i-8),sto->G[i].price,BLACK,1,1);
            printHZ16(190,225+140*(i-8),"ʣ��ƴ����",BLUE,1,1,1);
            put_asc(300,225+140*(i-8),sto->G[i].inventory,BLACK,1,1);
        }
        for(i=12;i<15;i++)
        {   
            if(i>=sto->goods_amount)
                break;
            Putbmp64k(535,165+140*(i-12),Get_picturepath(sto->G[i],path));
            printHZ16(650,165+140*(i-12),"��Ʒ��",BLUE,1,1,1);
            display_goodname(sto->G[i],750,165+140*(i-12));
            printHZ16(650,195+140*(i-12),"�ۼ�",BLUE,1,1,1);
            put_asc(730,195+140*(i-12),sto->G[i].price,BLACK,1,1);
            printHZ16(650,225+140*(i-12),"ʣ��ƴ����",BLUE,1,1,1);
            put_asc(780,225+140*(i-12),sto->G[i].inventory,BLACK,1,1);
        }
    }
}

void draw_addgoods()
{
    Barshadow(300,300,750,650,MIMOSA,BLACK);
    printHZ16(400,325,"�����Ʒ",BLACK,2,2,2);
    printHZ16(310,400,"��Ʒ����",BLACK,2,2,2);
    Line(450,430,700,430,BLACK);
    printHZ16(330,440,"���п����",BLACK,2,2,2);
    Line(550,470,700,470,BLACK);
    printHZ16(330,480,"�����۸�",BLACK,2,2,2);
    Line(500,510,700,510,BLACK);
    Barshadow(520,560,600,620,CORAL,GRAY);
    printHZ16(540,580,"ȷ��",BLACK,1,1,2);
    Barshadow(630,560,730,620,CORAL,GRAY);
    printHZ16(650,580,"����",BLACK,1,1,2);
}

void draw_adjustgoods()
{
    Barshadow(300,300,750,650,MIMOSA,BLACK);
    printHZ16(400,325,"�޸���Ʒ��Ϣ",BLACK,2,2,2);
    printHZ16(330,400,"��Ʒ����",BLACK,2,2,2);
    printHZ16(330,440,"�޸Ŀ����",BLACK,2,2,2);
    Line(550,470,700,470,BLACK);
    printHZ16(330,480,"�޸ļ۸�",BLACK,2,2,2);
    Line(500,510,700,510,BLACK);
    Barshadow(520,560,600,620,CORAL,GRAY);
    printHZ16(540,580,"ȷ��",BLACK,1,1,2);
    Barshadow(630,560,730,620,CORAL,GRAY);
    printHZ16(650,580,"����",BLACK,1,1,2);
}

int add_goods(storage *sto)
{   
    good temp;
    int namelen=0,invlen=0,prilen=0;
    
    draw_addgoods();  //���������Ʒ����
    Initmouse(1,1023,1,767);

    while(1)
    {
        Newxy();
        if(Mouse_press(450,400,700,430))
        {
            namelen=Input(450,400,700,430,namelen,temp.picpath,MIMOSA,2,2,15,0);
            temp.picpath[namelen]='\0';
        }
        if(Mouse_press(550,440,700,470))
        {
            invlen=Input(550,440,700,470,invlen,temp.inventory,MIMOSA,2,2,6,0);
            temp.inventory[invlen]='\0';
        }
        if(Mouse_press(500,480,700,510))
        {
            prilen=Input(500,480,700,510,prilen,temp.price,MIMOSA,2,2,6,0);
            temp.price[prilen]='\0';
        }
        if(Mouse_press(520,560,600,620))
        {
            if(namelen&&invlen&&prilen)
            {
                switch (appendstorage(sto,&temp))
                {
                    case 0:
                        printHZ16(310,550,"δ�ҵ�����Ʒ",RED,2,2,1);
                        delay(1000);
                        return 1;
                    case 1:
                        printHZ16(310,550,"��Ʒ��ӳɹ�",RED,2,2,1);
                        delay(1000);
                        return 1;
                    case 2:
                        printHZ16(310,550,"�ļ���ʧ��",RED,2,2,1);
                        delay(1000);
                        return 1;
                    case 3:
                        printHZ16(310,550,"��������",RED,2,2,1);
                        delay(1000);
                        return 1;
                    case 4:
                        printHZ16(310,550,"��Ʒ�Ѵ���",RED,2,2,1);
                        delay(1000);
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

int input_adjustment(storage *sto,int pos)
{
    good temp;
    int invlen=0,prilen=0;
    
    draw_adjustgoods();
    display_goodname(sto->G[pos],530,400);

    while(1)
    {
        Newxy();
        if(Mouse_press(550,440,700,470))
        {
            invlen=Input(550,440,700,470,invlen,temp.inventory,MIMOSA,2,2,6,0);
            temp.inventory[invlen]='\0';
        }
        if(Mouse_press(500,480,700,510))
        {
            prilen=Input(500,480,700,510,prilen,temp.price,MIMOSA,2,2,6,0);
            temp.price[prilen]='\0';                                          //�ǵ�һ��Ҫ����\0,��Ȼʣ�µ��������֮�󱻶�ȡ!
        }
        if(Mouse_press(520,560,600,620))
        {
            if(invlen&&prilen)
            {
                switch (adjuststorage(sto,pos,temp.inventory,temp.price))
                {
                    case 1:
                        printHZ16(310,550,"��Ϣ�޸ĳɹ�",RED,2,2,1);
                        delay(1000);
                        return 1;
                    case 2:
                        printHZ16(310,550,"�ļ���ʧ��",RED,2,2,1);
                        delay(1000);
                        return 2;
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
    int pagenum=1;

    draw_storage();
    Initmouse(1,1023,1,767);
    show_storagepage(sto,1);
    printHZ16(50,100,"��Ҫ���û��ͼ�Ŀ�",RED,1,1,1);

    while (1)
    {
        Newxy();
        if(Mouse_press(750,60,825,140))
        {   
            draw_storage();
            show_storagepage(sto,1);
            pagenum=1;
        }
        if(Mouse_press(826,60,900,140))
        {   
            draw_storage();
            show_storagepage(sto,2);
            pagenum=2;
        }
        if(Mouse_press(70,160,470,280)&&pagenum==1)
        {   
            i=0;
            if(i>=sto->goods_amount) continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,1);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(70,300,470,420)&&pagenum==1)
        {   
            i=1;
            if(i>=sto->goods_amount) continue;  
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,1);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(70,440,470,560)&&pagenum==1)
        {   
            i=2;
            if(i>=sto->goods_amount)    continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,1);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(70,580,470,700)&&pagenum==1)
        {   
            i=3;
            if(i>=sto->goods_amount) continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,1);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(530,160,930,280)&&pagenum==1)
        {   
            i=4;
            if(i>=sto->goods_amount) continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,1);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(530,300,930,420)&&pagenum==1)
        {   
            i=5;
            if(i>=sto->goods_amount) continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,1);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(530,440,930,560)&&pagenum==1)
        {   
            i=6;
            if(i>=sto->goods_amount) continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,1);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(530,580,930,700)&&pagenum==1)
        {   
            i=7;
            if(i>=sto->goods_amount) continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,1);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(70,160,470,280)&&pagenum==2)
        {   
            i=8;
            if(i>=sto->goods_amount) continue;  
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,2);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(70,300,470,420)&&pagenum==2)
        {   
            i=9;
            if(i>=sto->goods_amount) continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,2);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(70,440,470,560)&&pagenum==2)
        {   
            i=10;
            if(i>=sto->goods_amount) continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,2);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(70,580,470,700)&&pagenum==2)
        {   
            i=11;
            if(i>=sto->goods_amount) continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,2);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(530,160,930,280)&&pagenum==2)
        {   
            i=12;
            if(i>=sto->goods_amount) continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,2);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(530,300,930,420)&&pagenum==2)
        {   
            i=13;
            if(i>=sto->goods_amount) continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,2);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(530,440,930,560)&&pagenum==2)
        {   
            i=14;
            if(i>=sto->goods_amount) continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,2);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(530,580,930,700)&&pagenum==2)
        {   
            i=15;
            if(i>=sto->goods_amount)  continue; 
            if(input_adjustment(sto,i)==1)
            {
                draw_storage();
                show_storagepage(sto,2);  //�޸���ɺ�,ˢ�»���ҳ��
            } 
        }
        if(Mouse_press(750,730,900,760))  return 1;
    }
}

int discard_goods(storage *sto)
{
    int i=0;
    int pagenum=1;

    draw_storage();
    show_storagepage(sto,1);
    printHZ16(50,100,"�����Ҫɾ������Ʒ",RED,1,1,1);
    Initmouse(1,1023,1,767);
    while (1)
    {   
        Newxy();
        if(Mouse_press(750,60,825,140))
        {   
            draw_storage();
            printHZ16(50,100,"�����Ҫɾ������Ʒ",RED,1,1,1);
            show_storagepage(sto,1);
            pagenum=1;
        }
        if(Mouse_press(826,60,900,140))
        {   
            draw_storage();
            show_storagepage(sto,2);
            pagenum=2;
        }
        if(Mouse_press(70,160,470,280)&&pagenum==1)
        {   
            i=0;
            if(i>=sto->goods_amount)
            {   
               continue;
            } 
            Put_Asc16_Size(90,180,4,4,'x',RED);
            shrinkstorage(sto,i);
            draw_storage();
            show_storagepage(sto,1);
        }
        if(Mouse_press(70,300,470,420)&&pagenum==1)
        {   
            i=1;
            if(i>=sto->goods_amount)
            {   
                continue;
            } 
            Put_Asc16_Size(90,320,4,4,'x',RED);
            shrinkstorage(sto,i);
             draw_storage();
            show_storagepage(sto,1);
        }
        if(Mouse_press(70,440,470,560)&&pagenum==1)
        {   
            i=2;
            if(i>=sto->goods_amount)
            {   
               continue;
            } 
            Put_Asc16_Size(90,460,4,4,'x',RED);
            shrinkstorage(sto,i);
             draw_storage();
            show_storagepage(sto,1);
        }
        if(Mouse_press(70,580,470,700)&&pagenum==1)
        {   
            i=3;
            if(i>=sto->goods_amount)
            {   
                continue;
            } 
            Put_Asc16_Size(90,600,4,4,'x',RED);
            shrinkstorage(sto,i);
             draw_storage();
            show_storagepage(sto,1);
        }
        if(Mouse_press(530,160,930,280)&&pagenum==1)
        {   
            i=4;
            if(i>=sto->goods_amount)
            {   
                continue;
            } 
            Put_Asc16_Size(550,180,4,4,'x',RED);
            shrinkstorage(sto,i);
             draw_storage();
            show_storagepage(sto,1);
        }
        if(Mouse_press(530,300,930,420)&&pagenum==1)
        {   
            i=5;
            if(i>=sto->goods_amount)
            {   
                continue;
            } 
            Put_Asc16_Size(550,320,4,4,'x',RED);
            shrinkstorage(sto,i);
             draw_storage();
            show_storagepage(sto,1);
        }
        if(Mouse_press(530,440,930,560)&&pagenum==1)
        {   
            i=6;
            if(i>=sto->goods_amount)
            {   
                continue;
            } 
            Put_Asc16_Size(550,460,4,4,'x',RED);
            shrinkstorage(sto,i);
             draw_storage();
            show_storagepage(sto,1);
        }
        if(Mouse_press(530,580,930,700)&&pagenum==1)
        {   
            i=7;
            if(i>=sto->goods_amount)
            {   
                continue;
            } 
            Put_Asc16_Size(550,600,4,4,'x',RED);
            shrinkstorage(sto,i);
             draw_storage();
            show_storagepage(sto,1);
        }
        if(Mouse_press(70,160,470,280)&&pagenum==2)
        {   
            i=8;
            if(i>=sto->goods_amount)
            {   
               continue;
            } 
            Put_Asc16_Size(90,180,4,4,'x',RED);
            shrinkstorage(sto,i);
             draw_storage();
            show_storagepage(sto,2);
        }
        if(Mouse_press(70,300,470,420)&&pagenum==2)
        {   
            i=9;
            if(i>=sto->goods_amount)
            {   
               continue;
            }
            Put_Asc16_Size(90,320,4,4,'x',RED);
            shrinkstorage(sto,i);
            draw_storage();
            show_storagepage(sto,2);
        }
        if(Mouse_press(70,440,470,560)&&pagenum==2)
        {   
            i=10;
            if(i>=sto->goods_amount)
            {   
               continue;
            } 
            Put_Asc16_Size(90,460,4,4,'x',RED);
            shrinkstorage(sto,i);
            draw_storage();
            show_storagepage(sto,2);
        }
        if(Mouse_press(70,580,470,700)&&pagenum==2)
        {   
            i=11;
            if(i>=sto->goods_amount)
            {   
                continue;
            } 
            Put_Asc16_Size(90,600,4,4,'x',RED);
            shrinkstorage(sto,i);
            draw_storage();
            show_storagepage(sto,2);
        }
        if(Mouse_press(530,160,930,280)&&pagenum==2)
        {   
            i=12;
            if(i>=sto->goods_amount)
            {   
                continue;
            } 
            Put_Asc16_Size(550,180,4,4,'x',RED);
            shrinkstorage(sto,i);
            draw_storage();
            show_storagepage(sto,2);
        }
        if(Mouse_press(530,300,930,420)&&pagenum==2)
        {   
            i=13;
            if(i>=sto->goods_amount)
            {   
                continue;
            } 
            Put_Asc16_Size(550,320,4,4,'x',RED);
            shrinkstorage(sto,i);
            draw_storage();
            show_storagepage(sto,2);
        }
        if(Mouse_press(530,440,930,560)&&pagenum==2)
        {   
            i=14;
            if(i>=sto->goods_amount)
            {   
                continue;
            } 
            Put_Asc16_Size(550,460,4,4,'x',RED);
            shrinkstorage(sto,i);
            draw_storage();
            show_storagepage(sto,2);
        }
        if(Mouse_press(530,580,930,700)&&pagenum==2)
        {   
            i=15;
            if(i>=sto->goods_amount)
            {   
                continue;
            } 
            Put_Asc16_Size(550,600,4,4,'x',RED);
            shrinkstorage(sto,i);
            draw_storage();
            show_storagepage(sto,2);
        }
        if(Mouse_press(750,730,900,760))
        {
            return 1;
        }
    }
}

void display_goodname(good g,int x,int y)
{
    if(strcmp(g.picpath,"bo0")==0)
    {
        Put_Asc16_Size(x,y,1,1,'c',BLACK);
        printHZ16(x+20,y,"���Գ������",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"bo1")==0)
    {
        printHZ16(x,y,"�������������",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"bo2")==0)
    {
        printHZ16(x,y,"�Զ�����ԭ��",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"ea0")==0)
    {
        printHZ16(x,y,"��������Ǯ��",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"ea1")==0)
    {
        printHZ16(x,y,"��ײ�",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"ea2")==0)
    {
        printHZ16(x,y,"�����з",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"ea3")==0)
    {
        printHZ16(x,y,"����������",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"ea4")==0)
    {
        printHZ16(x,y,"���ʻƻ���",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"el0")==0)
    {
        printHZ16(x,y,"�ߵ������",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"el1")==0)
    {
        printHZ16(x,y,"�紵��",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"el2")==0)
    {
        printHZ16(x,y,"΢��¯",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"el3")==0)
    {
        printHZ16(x,y,"����������",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"fu0")==0)
    {
        printHZ16(x,y,"��Ь",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"fu1")==0)
    {
        printHZ16(x,y,"̨��",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"fu2")==0)
    {
        printHZ16(x,y,"�����׼�",BLACK,1,1,1);
    }
    if(strcmp(g.picpath,"fu3")==0)
    {
        printHZ16(x,y,"����",BLACK,1,1,1);
    }
}

void update_userselection(storage *sto)
{
    FILE *fp1=NULL;
    FILE *fp2=NULL;
    FILE *fp3=NULL;
    FILE *fp4=NULL;
    int i=0;

    fp1=fopen("..\\file\\storage\\book1.txt","a");
    fp2=fopen("..\\file\\storage\\eat1.txt","a");
    fp3=fopen("..\\file\\storage\\electri1.txt","a");
    fp4=fopen("..\\file\\storage\\furni1.txt","a");

    if(fp1==NULL||fp2==NULL||fp3==NULL||fp4==NULL)
    {
        return;
    }

    for(i=0;i<sto->goods_amount;i++)
    {
        if(sto->G[i].picpath[0]=='b'&&sto->G[i].picpath[1]=='o')
        {
            fwrite(&sto->G[i],sizeof(good),1,fp1);
        }
        if(sto->G[i].picpath[0]=='e'&&sto->G[i].picpath[1]=='a')
        {
            fwrite(&sto->G[i],sizeof(good),1,fp2);
        }
        if(sto->G[i].picpath[0]=='e'&&sto->G[i].picpath[1]=='l')
        {
            fwrite(&sto->G[i],sizeof(good),1,fp3);
        }
        if(sto->G[i].picpath[0]=='f'&&sto->G[i].picpath[1]=='u')
        {
            fwrite(&sto->G[i],sizeof(good),1,fp4);
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

    remove("..\\file\\storage\\book.txt");
    remove("..\\file\\storage\\eat.txt");
    remove("..\\file\\storage\\electric.txt");
    remove("..\\file\\storage\\furni.txt");

    rename("..\\file\\storage\\book1.txt","..\\file\\storage\\book.txt");
    rename("..\\file\\storage\\eat1.txt","..\\file\\storage\\eat.txt");
    rename("..\\file\\storage\\electri1.txt","..\\file\\storage\\electric.txt");
    rename("..\\file\\storage\\furni1.txt","..\\file\\storage\\furni.txt");

    return;
}