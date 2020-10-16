#include "public.h"
#include "seller.h"
#include "draw.h"
#include "tstruct.h"
#include "file.h"
#include "list.h"

int sellerpage(SELLER *s)
{
    int flag=1;
   
    list goodlist;
    storage sto;
    char str[5]; //用来显示商家评分
    
	if(update_storage(&sto))
	{
		printHZ16(400,70,"货架已更新",MIMOSA,2,2,2);
	}
	else
	{
		printHZ16(400,70,"货架更新失败",MIMOSA,2,2,2);
	}
	
	if(update_list(&goodlist))
	{
		printHZ16(400,170,"订单已更新",MIMOSA,2,2,2);
	}
	else
	{
		printHZ16(400,170,"订单更新失败",MIMOSA,2,2,2);
	}
	
	sprintf(str,"%.2f",s->rat.average);
    
    while (1)
    {   
        Newxy();
        switch(flag)
        {
			case 1:
			draw_sellerpage();
			put_asc(430,675,str,VIOLET,1,1);
			flag=select_sellerpage();
			break;
			case 2:
		    flag=manage_goods(&sto);
			break;
			case 3:
		  // 	flag=promotion(&sto);
			break;
			case 4:
		    flag=watch_listinfo(&goodlist);
			break;
			case 5:
		    flag=charge(&goodlist);
			break;
			case 6:
		   flag=changeinfo(s);
			break;
			case 7:
			return 2;   //点击退出商家端,回到登录界面
			default:
			printf("something wrong");
			delay(1000);
			exit(1);
		}

	}
}



void  storage_init(storage *sto)
{
    int i=0;
	int j=0;
	char init[3] = "\0";
	sto->goods_amount=0;
	for(i=0;i<16;i++)
	{
	   strcpy(sto->G[i].picpath,init);
        sto->G[i].price=0;
        sto->G[i].inventory=0;
		sto->G[i].c='\n';
	}
}

void list_init(list *L)
{	
	int i=0;
	int j=0;
	char init[3]='\0';
	L->list_state=UNFINISHED;
	L->pos=0;
	for(i=0;i<10;i++)
	{
	  	strcpy(L->G[i].picpath,init);
        L->G[i].price=0;
        L->G[i].inventory=0;
		L->G[i].c='\n';
	}
	return;
}

int update_list(list *L)
{
	FILE *fp=NULL;
	list temp;
	int i=0;

	list_init(L);
	fp=fopen("..\\file\\list\\list.txt","r");
	if(fp==NULL)
	{
		return 0;
	}

	while (!feof(fp))
	{
		fread(&temp,sizeof(list),1,fp);
		if(temp.list_state==FINISHED)
		{
			continue;              //订单已被处理,跳过
		}
		else
		{
			L->list_state=temp.list_state;            //找到未被处理过的订单
			L->pos=temp.pos;
			for(i=0;i<10;i++)
			{
				L->G[i]=temp.G[i];
			}
			fclose(fp);
			return 1;
		}
	}
}

int update_storage(storage *sto)
{
	FILE *fp=NULL;
	good temp;

	storage_init(sto);
	fp=fopen("..\\file\\storage\\storage.txt","r");
	if(fp==NULL)
	{
		return 0;
	}
	while (!feof(fp))
	{
		fread(&temp,sizeof(good),1,fp);
		sto[sto->goods_amount]=temp;
		(sto->goods_amount)++;
	}
	fclose(fp);
	return 1;
}

int select_sellerpage()
{
	 int light_sign=0;    //判断是否被标亮


	while (1)
	{
		Newxy();
		if(Mouse_above(630,50,800,250))
		{
			if(Mouse_press(630,50,800,250)==0)
			{
				if(light_sign==0)
				{
					//lightbutton_sellerpage(VIOLET,1);
					//light_sign=1;
					continue;
				}
			}
			else if(Mouse_press(630,50,800,250)==1)
				return 2;
		}
		if(Mouse_above(820,50,990,250))
		{
			if(Mouse_press(820,50,990,250)==0)
			{
				if(light_sign==0)
				{
					//lightbutton_sellerpage(VIOLET,2);
					//light_sign=2;
					continue;
				}
			}
			else if(Mouse_press(820,50,990,250)==1)
				return 3;
		}
		if(Mouse_above(630,300,800,500))
		{
			if(Mouse_press(630,300,800,500)==0)
			{
				if(light_sign==0)
				{
					//lightbutton_sellerpage(VIOLET,3);
					//light_sign=3;
					continue;
				}
			}
			else if(Mouse_press(630,300,800,500)==1)
				return 4;
		}
		if(Mouse_above(820,300,990,500))
		{
			if(Mouse_press(820,300,990,500)==0)
			{
				if(light_sign==0)
				{
					//lightbutton_sellerpage(VIOLET,4);
					//light_sign=4;
					continue;
				}
			}
			else if(Mouse_press(820,300,990,500)==1)
			return 5;
		}
		if(Mouse_above(850,550,950,700))
		{
			if(Mouse_press(850,550,950,700)==0)
			{
				if(light_sign==0)
				{
					//lightbutton_sellerpage(ORANGE,5);
					//light_sign=5;
					continue;
				}
			}
			else if(Mouse_press(850,550,950,700)==1)
				return 6;
		}
		if(Mouse_above(630,550,820,700))
		{
			if(Mouse_press(630,550,820,700)==0)
			{
				if(light_sign==0)
				{
					//lightbutton_sellerpage(ORANGE,6);
					//light_sign=6;
					continue;
				}
			}
			else if(Mouse_press(630,550,820,700)==1)
				return 7;
		}

	//if(light_sign!=0)
	//{
	//	resetbutton_sellerpage(light_sign);
	//	light_sign=0;
	  //	continue;
	//}
	}
}

void lightbutton_sellerpage(int color,int flag)
{
	switch (flag)
	{
		case 1:
		Bar(630,50,800,250,color);
		printHZ16(640,70,"商品",BLACK,4,4,10);
		printHZ16(660,180,"管理",BLACK,4,4,7);
		break;
		case 2:
		Bar(820,50,990,250,color);
		printHZ16(830,70,"促销",BLACK,4,4,10);
		printHZ16(830,180,"商品",BLACK,4,4,10);
		break;
		case 3:
		Bar(630,300,800,500,color);
		printHZ16(640,320,"查看订单",BLACK,2,2,7);
		printHZ16(680,430,"信息",BLACK,2,2,7);
		break;
		case 4:
		Bar(820,300,990,500,color);
		printHZ16(830,370,"收钱",BLACK,4,4,10);
		break;
		case 5:
		Bar(850,550,950,700,color);
		printHZ16(860,570,"修改个人信息",BLACK,1,1,1);
		break;
		case 6:
		Bar(630,550,820,700,color);
		printHZ16(630,570,"退出商家端",BLACK,1,1,1);
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
		Bar(630,50,800,250,CORAL);
		printHZ16(640,70,"商品",BLACK,4,4,10);
		printHZ16(660,180,"管理",BLACK,4,4,7);
		break;
		case 2:
		Bar(820,50,990,250,CORAL);
		printHZ16(830,70,"促销",BLACK,4,4,10);
		printHZ16(830,180,"商品",BLACK,4,4,10);
		break;
		case 3:
		Bar(630,300,800,500,CORAL);
		printHZ16(640,320,"查看订单",BLACK,2,2,7);
		printHZ16(680,430,"信息",BLACK,2,2,7);
		break;
		case 4:
		Bar(820,300,990,500,CORAL);
		printHZ16(830,70,"收钱",BLACK,4,4,10);
		break;
		case 5:
		Bar(850,550,950,700,GOLDEN);
		printHZ16(860,570,"修改个人信息",BLACK,1,1,1);
		break;
		case 6:
		Bar(630,550,820,700,GOLDEN);
		printHZ16(630,570,"退出商家端",BLACK,1,1,1);
		break;
		default:
		printf("something wrong");
		exit(1);
		break;
	}
}

void draw_sellerpage()
{   
	Bar(1,1,1023,767,LIGHT_SEA_GREEN);
	Putbmp64k(50,350,"..\\file\\bmp\\userinfo.bmp");
    printHZ16(200,200,"帅团",AZURE,3,3,6);
    printHZ16(300,250,"商家端",AZURE,2,2,2);

    LineThickSha(40,60,50,70,43,25,60,1);
	LineThickSha(50,70,80,100,43,25,25,1);
	LineThickSha(110,100,120,110,43,25,80,1);

	LineThickSha(260,50,250,70,31,25,50,1);
	LineThickSha(235,70,220,100,31,25,25,1);
	LineThickSha(230,100,220,120,31,25,60,1);

    Line(600,1,600,767,DARK_VIOLET);
    Bar(630,50,800,250,CORAL);
    Bar(820,50,990,250,CORAL);
    Bar(630,300,800,500,CORAL);
    Bar(820,300,990,500,CORAL);
    Bar(850,550,970,700,GOLDEN);
    Bar(630,550,820,700,GOLDEN);

    printHZ16(640,70,"商品",BLACK,4,4,10);
    printHZ16(660,180,"管理",BLACK,4,4,7);
    printHZ16(830,70,"促销",BLACK,4,4,10);
    printHZ16(830,180,"商品",BLACK,4,4,10);
    printHZ16(640,320,"查看订单",BLACK,2,2,7);
    printHZ16(680,430,"信息",BLACK,2,2,7);
    printHZ16(830,370,"收钱",BLACK,4,4,10);
    printHZ16(860,570,"修改个人信息",BLACK,1,1,1);
    printHZ16(660,630,"退出商家端",BLACK,1,1,1);
}