#include "public.h"
#include "seller.h"
#include "draw.h"
#include "tstruct.h"
#include "file.h"
#include "showlist.h"

int sellerpage(SELLER *s,list *L)
{
    int flag=1;
	int recommendation_size=0;
   
    storage sto;
	recommends selections;

    while (1)
    {   
        Newxy();
        switch(flag)
        {
			case 1:
			draw_sellerpage();
			Initmouse(1,1023,1,767);
			update_storage(&sto);
			update_list(L);
			recommendation_size=update_recommends(&selections);
			put_asc(100,440,s->account,BLACK,2,2);
			put_asc(100,560,s->phonenum,BLACK,2,2);
			flag=select_sellerpage();
			break;
			case 2:
			delay(600);
		    flag=manage_goods(&sto);
			break;
			case 3:
			delay(600);
			flag=promotion(&selections,recommendation_size);
			break;
			case 4:
			delay(600);
		    flag=watch_listinfo(L);
			break;
			case 5:
			delay(600);
		    flag=charge(L);
			break;
			case 6:
			delay(600);
		   	flag=changeinfo(s);
			break;
			case 7:
			return -1;   
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
		strcpy(sto->G[i].inventory,"0");
		strcpy(sto->G[i].price,"0");
	}
	return;
}

void list_init(list *L) //所有订单相关函数准备修改
{	
	int i=0;
	int j=0;
	char init[3]="\0";
	strcpy(L->name,init);

	L->list_state='0';
	L->pos='0';
	L->top='0';
	
	for(i=0;i<10;i++)
	{
	  	strcpy(L->G[i].picpath,init);
		strcpy(L->G[i].inventory,"0");
		strcpy(L->G[i].price,"0");
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
		if(fread(&temp,sizeof(list),1,fp)==0)
			break;
		if(temp.list_state=='2')
		{
			continue;              //订单已被处理,跳过
		}
		else
		{
			ListCopy(L,&temp);
			fclose(fp);
			return 1;
		}
	}
	return 1;
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
		if(fread(&temp,sizeof(good),1,fp)==0)
			break;
		GoodCopy(&(sto->G[sto->goods_amount]),&temp);
		(sto->goods_amount)++;
	}
	fclose(fp);
	return 1;
}

int update_recommends(recommends *selections)
{
    FILE *fp=NULL;
    good temp;
    int count=0;

    fp=fopen("..\\file\\storage\\reco.txt","r");
    if(fp==NULL)
    {
        return -1;
    }
    while(!feof(fp))
    {
        if(fread(&temp,sizeof(good),1,fp)==0)
			break;
        GoodCopy(&(selections->re[count]),&temp);
        count++;
    }
    fclose(fp);
    return count;
}

int select_sellerpage()
{
	while (1)
	{
		Newxy();
		if(Mouse_press(630,50,800,250)==1)
		{
			return 2;
		}
		if(Mouse_press(820,50,990,250)==1)
		{
			return 3;
		}
		if(Mouse_press(630,300,800,500)==1)
		{
			return 4;
		}
		if(Mouse_press(820,300,990,500)==1)
		{
			return 5;
		}
		if(Mouse_press(850,550,950,700)==1)
		{
			return 6;
		}
		if(Mouse_press(630,550,820,700)==1)
		{
			return 7;
		}
	}
}

void draw_sellerpage()
{   
	Bar(1,1,1023,767,LIGHT_SEA_GREEN);
    printHZ16(100,50,"帅团",GOLDEN,3,3,6);
    printHZ16(300,80,"商家端",GOLDEN,2,2,2);

	Bar(50,350,450,600,PEACH);
	printHZ16(70,380,"商家账号",BLUE_VIOLET,2,2,1);
	printHZ16(70,500,"联系方式",BLUE_VIOLET,2,2,1);
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
    printHZ16(830,330,"收钱",BLACK,4,4,10);
	printHZ16(830,420,"及发货",BLACK,3,3,2);
    printHZ16(860,570,"修改个人信息",BLACK,1,1,1);
    printHZ16(660,630,"退出程序",BLACK,2,2,1);
}