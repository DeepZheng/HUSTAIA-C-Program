
#include "draw.h"
#include "hanzi.h"
#include"tstruct.h"
#include "time.h"
#include "SVGAmode.h"
#include "color.h"
#include<string.h>





void draw_welcome(void){
	int i;
	Bar(1,1,1023,767,LIGHT_SEA_GREEN);
	
	for(i=1;i<5;i++){
		printHZ16(250+i,150+i,"˧��",GRAY,5,5,15);
		printHZ16(180+i,250+i,"��������һվʽ�Ź�ƽ̨",GRAY,3,3,6);
	}
	printHZ16(250,150,"˧��",BLACK,5,5,15);
	printHZ16(180,250,"��������һվʽ�Ź�ƽ̨",BLACK,3,3,6);
	//����ߵ�ͼ��
	LineThickSha(100,200,140,300,HONEY_ORANGE,GRAY,40,1);
	LineThickSha(130,200,150,230,HONEY_ORANGE,GRAY,150,1);
	LineThickSha(220,300,230,330,HONEY_ORANGE,GRAY,200,1);  
	
	//���ұߵ�ͼ��
	LineThickSha(830,200,800,300,WHITE,GRAY,40,1);
	LineThickSha(860,200,850,230,WHITE,GRAY,100,1);
	LineThickSha(830,270,820,300,WHITE,GRAY,80,1);

	Barshadow(380,590,450,620,PEACH,GRAY);
	printHZ16(400,600,"��¼",0,1,1,1);
	Barshadow(480,590,550,620,TAN,GRAY);
	printHZ16(500,600,"ע��",BLACK,1,1,1);
	Linex(600,620,635,620,31);
	printHZ16(600,600,"�˳�",WHITE,1,1,1);
	Linex(900,720,970,720,31);
	printHZ16(900,700,"��������",WHITE,1,1,1);
	return;
 }

void draw_aboutpage(void){
	int i;
	Bar(1,1,1023,767,LIGHT_SEA_GREEN);
	for(i=1;i<5;i++){
		printHZ16(100+i,30+i,"˧��",GRAY,3,3,6);
	}
	printHZ16(100,30,"˧��",BLACK,3,3,6);
	//����ߵ�ͼ��
	LineThickSha(40,60,50,70,HONEY_ORANGE,GRAY,60,1);
	LineThickSha(50,70,80,100,HONEY_ORANGE,GRAY,25,1);
	LineThickSha(110,100,120,110,HONEY_ORANGE,GRAY,80,1);
	//���ұߵ�ͼ��
	LineThickSha(260,50,250,70,WHITE,GRAY,50,1);
	LineThickSha(235,70,220,100,WHITE,GRAY,25,1);
	LineThickSha(230,100,220,120,WHITE,GRAY,60,1);

	Linex(900,720,935,720,31);
	printHZ16(900,700,"����",WHITE,1,1,1);
	
	for(i=1;i<5;i++){
		printHZ12(310+i,100+i,"��������һվʽ�Ź�ƽ̨",GRAY,4,4,5);
	}
	printHZ12(310,100,"��������һվʽ�Ź�ƽ̨",MIMOSA,4,4,5);
	printHZ16(100,200,"������Ա��",BLUE_VIOLET,1,1,1);
	printHZ16(200,200,"���пƼ���ѧ�˹��������Զ���ѧԺ" ,YELLOW,1,1,1);
	printHZ16(200,230,"�Զ���׿Խʵ���",YELLOW,1,1,1);
	put_asc(350,230,"1901",BURNT_ORANGE,1,1);
	//���ֿ�û���֡�����������Ӣ�������ˡ�
	//printHZ16(250,230,"֣�Z��",WHITE,1,1,1);
	//printHZ16(300,230,"������",WHITE,1,1,1);
	put_asc(420,230,"DeepZheng",BURNT_ORANGE,1,1);
	put_asc(520,230,"RichardLiu",BURNT_ORANGE,1,1);
	printHZ16(100,270,"��������",BLUE_VIOLET,1,1,1);
	put_asc(200,270,"2020/10/29",BURNT_ORANGE,1,1);
	printHZ16(100,320,"�汾��",BLUE_VIOLET,1,1,1);
	put_asc(200,320,"1.0.2",BURNT_ORANGE,1,1);
	printHZ16(120,420,"�����Ϊ���ż���Ʒ���Ե�������Ҫ��ϵ͡�",LIGHT_GOLDENROD_YELLOW,1,1,1);
	printHZ16(120,460,"���������Ϊ�κ���ҵ��;������������κ�Υ����߳�Ϯ����򱻳�Ϯ���󣬿����߽���Ȩ׷�������Ρ�",LIGHT_GOLDENROD_YELLOW,1,1,1);
	printHZ16(120,500,"���Դ˸�л",LIGHT_GOLDENROD_YELLOW,1,1,1);
	put_asc(205,500,"C",LIGHT_GOLDENROD_YELLOW,1,1);
	printHZ16(215,500,"���Կγ���Ƶ�������ʦ�����̣��Լ����������ǵ�ͬѧ��",LIGHT_GOLDENROD_YELLOW,1,1,1);
	printHZ16(120,540,"��������кܶ಻������ǿɸ����Ż��ĵط�",LIGHT_GOLDENROD_YELLOW,1,1,1);
	printHZ16(120,580,"ϣ�������������ƺͿ����������ߵĸ�Զ��",LIGHT_GOLDENROD_YELLOW,1,1,1);
}
void draw_login(void){
	int i;
	Bar(1,1,1023,767,LIGHT_SEA_GREEN);
	for(i=1;i<5;i++){
		printHZ16(100+i,30+i,"˧��",GRAY,3,3,6);
	}
	printHZ16(100,30,"˧��",BLACK,3,3,6);

	LineThickSha(40,60,50,70,MIMOSA,GRAY,60,1);
	LineThickSha(50,70,80,100,MIMOSA,GRAY,25,1);
	LineThickSha(110,100,120,110,MIMOSA,GRAY,80,1);

	LineThickSha(260,50,250,70,WHITE,GRAY,50,1);
	LineThickSha(235,70,220,100,WHITE,GRAY,25,1);
	LineThickSha(230,100,220,120,WHITE,GRAY,60,1);

	Putbmp64k(20,200,"..\\file\\bmp\\meituan.bmp");	//��Ҫ24λͼƬ
	//��¼��
	Barshadow(620,200,980,700,WHITE,GRAY);
	Linex(620,200,980,200,GRAY);
	Linex(620,700,980,700,GRAY);
	Liney(620,200,620,700,GRAY);
	Liney(980,200,980,700,GRAY);

	printHZ16(680,220,"�û���¼",0,1,1,1);
	printHZ16(860,220,"�̼ҵ�¼",0,1,1,1);

	printHZ16(660,340,"�˺�",0,1,1,1);
	Linex(730,360,950,360,0);
	printHZ16(660,500,"����",0,1,1,1);
	Linex(730,520,950,520,0);
	Barshadow(800,20,870,50,BEIGE,GRAY);
	printHZ16(820,30,"����",0,1,1,1);
	Barshadow(900,20,970,50,AMBER,GRAY);
	printHZ16(920,30,"�˳�",0,1,1,1);

	Barshadow(730,600,800,630,PERU,GRAY);
	printHZ16(750,605,"��¼",0,1,1,1);
	return ;
}

void draw_regis(void){
	int i;
	Bar(1,1,1023,767,LIGHT_SEA_GREEN);
	for(i=1;i<5;i++){
		printHZ16(100+i,30+i,"˧��",GRAY,3,3,6);
	}
	printHZ16(100,30,"˧��",BLACK,3,3,6);

	LineThickSha(40,60,50,70,MIMOSA,GRAY,60,1);
	LineThickSha(50,70,80,100,MIMOSA,GRAY,25,1);
	LineThickSha(110,100,120,110,MIMOSA,GRAY,80,1);

	LineThickSha(260,50,250,70,WHITE,GRAY,50,1);
	LineThickSha(235,70,220,100,WHITE,GRAY,25,1);
	LineThickSha(230,100,220,120,WHITE,GRAY,60,1);

	Putbmp64k(20,200,"..\\file\\bmp\\meituan.bmp");	//��Ҫ24λͼƬ
	//��¼��
	Barshadow(620,200,980,700,MIMOSA,GRAY);
	Linex(620,200,980,200,GRAY);
	Linex(620,700,980,700,GRAY);
	Liney(620,200,620,700,GRAY);
	Liney(980,200,980,700,GRAY);

	printHZ16(680,220,"�û�ע��",0,1,1,1);
	printHZ16(860,220,"�̼�ע��",0,1,1,1);

	printHZ16(660,340,"�˺�",0,1,1,1);
	Linex(730,360,950,360,0);
	printHZ16(660,460,"����",0,1,1,1);
	Linex(730,480,950,480,0);
	printHZ16(660,580,"�绰",0,1,1,1);
	Linex(730,600,950,600,0);
	Barshadow(800,20,870,50,BEIGE,GRAY);
	printHZ16(820,30,"����",0,1,1,1);
	Barshadow(900,20,970,50,AMBER,GRAY);
	printHZ16(920,30,"�˳�",0,1,1,1);

	Barshadow(730,630,800,660,PERU,GRAY);
	printHZ16(750,635,"ע��",0,1,1,1);
	return ;
}

void put_name(int x,int y,good g){
	//�����Ʒ��
	if(!strcmp(g.picpath,"ea0"))
		printHZ16(x+120,y+15,"�����ؼ���Ǯ��",BLUE,1,1,1);
	if(!strcmp(g.picpath,"ea1"))
		printHZ16(x+120,y+15,"���ʴ�ײ�",BLUE,1,1,1);
	if(!strcmp(g.picpath,"ea2"))
		printHZ16(x+120,y+15,"��բз",BLUE,1,1,1);
	if(!strcmp(g.picpath,"ea3"))
		printHZ16(x+120,y+15,"ũ��������",BLUE,1,1,1);
	if(!strcmp(g.picpath,"bo0"))
		printHZ16(x+120,y+15,"��׼������Ƽ�Ӧ��",BLUE,1,1,1);
	if(!strcmp(g.picpath,"bo1"))
		printHZ16(x+120,y+15,"�������������",BLUE,1,1,1);
	if(!strcmp(g.picpath,"bo2"))
		printHZ16(x+120,y+15,"�Զ�����ԭ��",BLUE,1,1,1);
	if(!strcmp(g.picpath,"el0"))
		printHZ16(x+120,y+15,"�߼����ܵ����",BLUE,1,1,1);
	if(!strcmp(g.picpath,"el1"))
		printHZ16(x+120,y+15,"���ܵ紵��",BLUE,1,1,1);
	if(!strcmp(g.picpath,"el2"))
		printHZ16(x+120,y+15,"����΢��¯",BLUE,1,1,1);
	if(!strcmp(g.picpath,"fu0"))
		printHZ16(x+120,y+15,"�Ҿ���Ь",BLUE,1,1,1);
	if(!strcmp(g.picpath,"fu1"))
		printHZ16(x+120,y+15,"�ϵ�ر��ɳ��̨��",BLUE,1,1,1);
	if(!strcmp(g.picpath,"fu2"))
		printHZ16(x+120,y+15,"�����ļ���",BLUE,1,1,1);
	if(!strcmp(g.picpath,"ea4"))
		printHZ16(x+120,y+15,"���ʻƻ���",BLUE,1,1,1);
	if(!strcmp(g.picpath,"el3"))
		printHZ16(x+120,y+15,"���ܿ���������",BLUE,1,1,1);
	if(!strcmp(g.picpath,"fu3"))
		printHZ16(x+120,y+15,"����������",BLUE,1,1,1);
	return ;
}

void put_rename(int x,int y,good g){
	if(!strcmp(g.picpath,"ea0"))
		printHZ12(x,y,"�����ؼ���Ǯ��",BLUE,2,2,1);
	if(!strcmp(g.picpath,"ea1"))
		printHZ12(x,y,"���ʴ�ײ�",BLUE,2,2,1);
	if(!strcmp(g.picpath,"ea2"))
		printHZ12(x,y,"��բз",BLUE,2,2,1);
	if(!strcmp(g.picpath,"ea3"))
		printHZ12(x,y,"ũ��������",BLUE,2,2,1);
	if(!strcmp(g.picpath,"bo0"))
		printHZ12(x,y,"��׼������Ƽ�Ӧ��",BLUE,2,2,1);
	if(!strcmp(g.picpath,"bo1"))
		printHZ12(x,y,"�������������",BLUE,2,2,1);
	if(!strcmp(g.picpath,"bo2"))
		printHZ12(x,y,"�Զ�����ԭ��",BLUE,2,2,1);
	if(!strcmp(g.picpath,"el0"))
		printHZ12(x,y,"�߼����ܵ����",BLUE,2,2,1);
	if(!strcmp(g.picpath,"el1"))
		printHZ12(x,y,"���ܵ紵��",BLUE,2,2,1);
	if(!strcmp(g.picpath,"el2"))
		printHZ12(x,y,"����΢��¯",BLUE,2,2,1);
	if(!strcmp(g.picpath,"fu0"))
		printHZ12(x,y,"�Ҿ���Ь",BLUE,2,2,1);
	if(!strcmp(g.picpath,"fu1"))
		printHZ12(x,y,"�ϵ�ر��ɳ��̨��",BLUE,2,2,1);
	if(!strcmp(g.picpath,"fu2"))
		printHZ12(x,y,"�����ļ���",BLUE,2,2,1);
	if(!strcmp(g.picpath,"ea4"))
		printHZ12(x,y,"���ʻƻ���",BLUE,2,2,1);
	if(!strcmp(g.picpath,"el3"))
		printHZ12(x,y,"���ܿ���������",BLUE,2,2,1);
	if(!strcmp(g.picpath,"fu3"))
		printHZ12(x,y,"����������",BLUE,2,2,1);
	return ;
}

void put_good(int x,int y,good g){
	char inventory[5];
	char price[6];
	char picname[30] = "..\\file\\bmp\\";
	strcat(picname,g.picpath);
	strcat(picname,".bmp");
	
	Barshadow(x,y,x+350,y+120,WHITE,GRAY);
	Frame(x,y,x+350,y+120,GRAY,2);
	//��Ʒ��
	put_name(x,y,g);
	//put_asc(x+100,y+15,g.picpath,BLACK,1,1);
	//���
	printHZ16(x+120,y+100,"ʣ��ƴ��",BLACK,1,1,1);
	//sprintf(inventory,"%d",&g.inventory);
	//sprintf(price,"%.1f",&g.price);
	put_asc(x+200,y+100,g.inventory,DARK_GRAY,1,1);
	//�۸�
	printHZ16(x+120,y+60,"�۸�",BLACK,1,1,1);
	put_asc(x+200,y+50,g.price,ORANGE_RED,2,2);
	//���빺�ﳵ��ť
	Bar(x+250,y+90,x+345,y+115,DEEP_SKY_BLUE);
	printHZ16(x+255,y+94,"���빺�ﳵ",BLACK,1,1,1);
	Putbmp64k(x+5,y+5,picname);
	
}

void put_cart(int x,int y,good g){
	char inventory[5];
	char price[6];
	char picname[30] = "..\\file\\bmp\\";
	strcat(picname,g.picpath);
	strcat(picname,".bmp");
	
	//sprintf(inventory,"%d",g.inventory);
	//sprintf(price,"%.1f",g.price);

	Barshadow(x,y,x+350,y+120,WHITE,GRAY);
	Frame(x,y,x+350,y+120,GRAY,2);
	//��Ʒ��
	put_name(x,y,g);
	//���
	printHZ16(x+120,y+100,"ʣ��ƴ��",BLACK,1,1,1);
	put_asc(x+200,y+100,g.inventory,DARK_GRAY,1,1);
	//�۸�
	printHZ16(x+120,y+60,"�۸�",BLACK,1,1,1);
	put_asc(x+200,y+50,g.price,RED,2,2);
	Putbmp64k(x+5,y+5,picname);

}

void put_list(int x,int y,good g,list userlist){
	char inventory[5];
	char price[6];
	char picname[30] = "..\\file\\bmp\\";
//	struct tm *timeinfo;
//	char year[5],month[3],day[3],hour[3],min[3];
	strcat(picname,g.picpath);
	strcat(picname,".bmp");
	Barshadow(x,y,x+360,y+120,WHITE,GRAY);
	Frame(x,y,x+360,y+120,GRAY,2);
	Putbmp64k(x+5,y+5,picname);	
	//��Ʒ��
	put_name(x,y,g);
	//�۸�
	printHZ16(x+120,y+50,"�۸�",BLACK,1,1,1);
	put_asc(x+200,y+50,g.price,RED,1,1);	
	//֧��ʱ��
	//timeinfo = localtime(&userlist->ordertime);
/*	gettime(timeinfo);
	itoa(10,year,timeinfo->tm_year);
	itoa(10,month,timeinfo->tm_mon);
	itoa(10,day,timeinfo->tm_mday);
	itoa(10,hour,timeinfo->tm_hour);
	itoa(10,min,timeinfo->tm_min);
	put_asc(x+480,y+80,asctime(timeinfo),DARK_GRAY,1,1);
	printHZ16(x+120,y+80,"֧��ʱ��",BLACK,1,1,1);
	put_asc(x+180,y+80,year,DARK_GRAY,1,1);
	printHZ12(x+220,y+80,"��",DARK_GRAY,1,1,1);
	put_asc(x+230,y+80,month,DARK_GRAY,1,1);
	printHZ12(x+240,y+80,"��",DARK_GRAY,1,1,1);
	put_asc(x+250,y+80,day,DARK_GRAY,1,1);
	printHZ12(x+260,y+80,"��",DARK_GRAY,1,1,1);
	put_asc(x+270,y+80,hour,DARK_GRAY,1,1);
	printHZ12(x+280,y+80,"ʱ",DARK_GRAY,1,1,1);
	put_asc(x+290,y+80,min,DARK_GRAY,1,1);
	printHZ12(x+300,y+80,"��",DARK_GRAY,1,1,1);*/
	//����״̬
	printHZ16(x+120,y+100,"����״̬",BLACK,1,1,1);
	//��ť������״̬�仯
	switch(userlist.list_state-'0'){
		case 0 :{
			printHZ16(x+200,y+100,"δ����",DARK_GRAY,1,1,1);
			Bar(x+280,y+90,x+355,y+115,LIGHT_BLUE);
			printHZ16(x+285,y+94,"���ѷ���",BLACK,1,1,1);
			break;
		}
		case 1 :{
			printHZ16(x+200,y+100,"����������",DARK_GRAY,1,1,1);
			Bar(x+280,y+90,x+355,y+115,LIGHT_GOLDENROD_YELLOW);
			printHZ16(x+285,y+94,"ȷ���ջ�",BLACK,1,1,1);
			break;
		}
		case 2:{
			printHZ16(x+200,y+100,"���ջ�",DARK_GRAY,1,1,1);
			Bar(x+280,y+90,x+355,y+115,ORANGE_RED);
			printHZ16(x+285,y+94,"�������",BLACK,1,1,1);
			break;
		}
	}
	
	
}
//������ҳ������ʾ��Ϣ
//0 Ϊ���ѷ��� 1 Ϊȷ���ջ�
void put_message(int flag){
	switch(flag){
		case 0 :
		{
			Barshadow(400,300,600,400,WHITE,DARK_GRAY);
			printHZ16(410,305,"���ѳɹ�",BLACK,2,2,1);
			break;
		}
		case 1:
		{
			Barshadow(400,300,600,400,WHITE,DARK_GRAY);
			printHZ16(410,305,"�ջ��ɹ�",BLACK,2,2,1);
		}
	}
}
//����ӳɹ�ҳ��
void put_add(void){
	Barshadow(400,300,600,400,WHITE,DARK_GRAY);
	printHZ16(410,305,"��ӳɹ�",BLACK,2,2,1);
}
//�û���½��������
void draw_usermainpage(void){
	int i ;
	Bar (1,1,1023,50,LIGHT_SEA_GREEN);
	Bar (101,51,1023,767,WHITE);
	Bar (1,51,110,767,MUSTARD);

	for(i=1;i<5;i++){
		printHZ16(15+i,10+i,"˧��",GRAY,2,2,4);
	}
	printHZ16(15,10,"˧��",BLACK,2,2,4);

	printHZ16(700,15,"��������" ,0,1,1,1);
	Rectangle(790,810,30,20,BLACK);
	//���˳�ͼ��
	for(i=8;i<=10;i++){
		Circle(900,20,i,0);
		Liney(909-i,8,909-i,16,0);
	}
	printHZ16(920,15,"�˳�",0,1,1,1);

	printHZ12(8,55,"ȫ������",BLACK,2,2,1);
	printHZ16(30,100,"����",DIMGRAY,1,1,1);
	printHZ16(30,150,"�Ҿ�",DIMGRAY,1,1,1);
	printHZ16(30,200,"����",DIMGRAY,1,1,1);
	printHZ16(30,250,"ͼ��",DIMGRAY,1,1,1);
	printHZ16(30,300,"��ʳ",DIMGRAY,1,1,1);
	Putbmp64k(15,650,"..\\file\\bmp\\crt.bmp");
//	printHZ16(20,600,"���ﳵ",RED,1,1,1);


}

void draw_usercenter(void){
	int i ;
	Bar (1,1,1023,50,LIGHT_SEA_GREEN);
	Bar (101,51,1023,767,WHITE);
	Bar (1,51,110,767,MUSTARD);

	for(i=1;i<5;i++){
		printHZ16(15+i,10+i,"˧��",GRAY,2,2,4);
	}
	printHZ16(15,10,"˧��",BLACK,2,2,4);
	//�˳�ͼ��
	for(i=8;i<=10;i++){
		Circle(900,20,i,0);
		Liney(909-i,8,909-i,16,0);
	}
	printHZ16(920,15,"�˳�",0,1,1,1);

	printHZ16(700,15,"������ҳ" ,0,1,1,1);
	Rectangle(790,810,30,20,BLACK);

	printHZ16(10,100,"������Ϣ",BLACK,1,1,2);
	printHZ16(10,180,"���ﳵ",BLACK,1,1,2);
	printHZ16(10,260,"�ҵĶ���",BLACK,1,1,2);
	printHZ16(10,340,"���۶���",BLACK,1,1,2);
	//Putbmp64k(15,500,"..\\file\\bmp\\crt.bmp");
	
}

void draw_userinfo(User *loginuser){
	int i ;
	Bar (1,1,1023,50,LIGHT_SEA_GREEN);
	Bar (101,51,1023,767,WHITE);
	Bar (1,51,110,767,MUSTARD);

	for(i=1;i<5;i++){
		printHZ16(15+i,10+i,"˧��",GRAY,2,2,4);
	}
	printHZ16(15,10,"˧��",BLACK,2,2,4);
	//�˳�ͼ��
	for(i=8;i<=10;i++){
		Circle(900,20,i,0);
		Liney(909-i,8,909-i,16,0);
	}
	printHZ16(920,15,"�˳�",0,1,1,1);

	printHZ16(700,15,"������ҳ" ,0,1,1,1);
	Rectangle(790,810,30,20,BLACK);

	Bar(1,60,110,140,JASMINE);
	printHZ16(10,100,"������Ϣ",BLACK,1,1,2);
	printHZ16(10,180,"���ﳵ",BLACK,1,1,2);
	printHZ16(10,260,"�ҵĶ���",BLACK,1,1,2);
	printHZ16(10,340,"���۶���",BLACK,1,1,2);

	Putbmp64k(400,150,"..\\file\\bmp\\userinfo.bmp");
	printHZ16(350,400,"�˺�",BLACK,1,1,2);

	printHZ16(350,450,"����",BLACK,1,1,2);
	Barshadow(800,440,880,470,PERU,GRAY);
	printHZ16(810,450,"�޸�����",BLACK,1,1,1);

	printHZ16(350,500,"�绰",BLACK,1,1,2);
	Barshadow(800,490,880,520,PERU,GRAY);
	printHZ16(810,500,"�޸ĵ绰",BLACK,1,1,1);

	printHZ16(350,550,"�ջ���ַ",BLACK,1,1,2);

	put_asc(400,400,loginuser->name,BLACK,1,1);
	put_asc(400,450,loginuser->code,BLACK,1,1);
	put_asc(400,500,loginuser->tel,BLACK,1,1);
	printHZ12(450,550,"�人",BLACK,1,1,1);
	printHZ12(480,550,"��ɽ��",BLACK,1,1,1);
	printHZ12(530,550,"��ɽ�ֵ�",BLACK,1,1,1);
	
	switch(loginuser->pos){
		case 'a':	printHZ12(600,550,"������԰",BLACK,1,1,1);	break;
		case 'b':	printHZ12(600,550,"��������",BLACK,1,1,1);	break;
		case 'c':	printHZ12(600,550,"��ɽ����",BLACK,1,1,1);	break;
		case 'd':	printHZ12(600,550,"��������",BLACK,1,1,1);	break;
		case 'e':	printHZ12(600,550,"���ʱ��㳡",BLACK,1,1,1);	break;
		case 'f':	printHZ12(600,550,"���������",BLACK,1,1,1);	break;
		case 'g':	printHZ12(600,550,"������Ļ�԰",BLACK,1,1,1);	break;
		case 'h':	printHZ12(600,550,"���пƼ���ѧ",BLACK,1,1,1);	break;
		case 'i':	printHZ12(600,550,"���пƼ���ѧ�Ļ�ѧԺ",BLACK,1,1,1);	break;
		case 'j':	printHZ12(600,550,"�羰��԰",BLACK,1,1,1);	break;
		case 'k':	printHZ12(600,550,"���пƼ���ѧ��Է",BLACK,1,1,1);	break;
		case 'l':	printHZ12(600,550,"���пƼ���ѧ��У��",BLACK,1,1,1);	break;
		case 'm':	printHZ12(600,550,"�н�����",BLACK,1,1,1);	break;
		case 'n':	printHZ12(600,550,"���пƼ���ѧ��ݿ",BLACK,1,1,1);	break;
		case 'o':	printHZ12(600,550,"���̫����",BLACK,1,1,1);	break;
		case 'p':	printHZ12(600,550,"�人ְҵ����ѧԺ����",BLACK,1,1,1);	break;
		case 'q':	printHZ12(600,550,"�人ְҵ����ѧԺ����",BLACK,1,1,1);	break;
		case 'r':	printHZ12(600,550,"���пƼ���ѧ��Է",BLACK,1,1,1);	break;
	}
	
	Barshadow(800,710,880,740,RED,GRAY);
	printHZ16(810,720,"ע���û�",BLACK,1,1,1);
}

void draw_usercart(Cart *usercart){
	int i,k = 0;
	char price[8];
	Bar (1,1,1023,50,LIGHT_SEA_GREEN);
	Bar (101,51,1023,767,WHITE);
	Bar (1,51,110,767,MUSTARD);
	Bar (1, 141, 110, 220,JASMINE);
	for(i=1;i<5;i++){
		printHZ16(15+i,10+i,"˧��",GRAY,2,2,4);
	}
	printHZ16(15,10,"˧��",BLACK,2,2,4);
	//�˳�ͼ��
	for(i=8;i<=10;i++){
		Circle(900,20,i,0);
		Liney(909-i,8,909-i,16,0);
	}
	printHZ16(920,15,"�˳�",0,1,1,1);

	printHZ16(700,15,"������ҳ" ,0,1,1,1);
	Rectangle(790,810,30,20,BLACK);

	printHZ16(10,100,"������Ϣ",BLACK,1,1,2);
	printHZ16(10,180,"���ﳵ",BLACK,1,1,2);
	printHZ16(10,260,"�ҵĶ���",BLACK,1,1,2);
	printHZ16(10,340,"���۶���",BLACK,1,1,2);

	Bar(110,700,1023,767,LIGHT_SEA_GREEN);		//�����·�������
	Bar(900,705,1010,750,RED);		//���㰴ť
	printHZ16(925,715,"��������",WHITE,1,1,1);
	printHZ16(600,720,"�ܼ�",BLACK,2,2,1);
	//memset(price,0,sizeof(price));
	sprintf(price,"%.1f",usercart->price);	//��float�ͼ۸�ת��Ϊ�ַ����ͷ������
	put_asc(700,720,price,RED,2,2);
	    //������Ʒ 
		while(k < usercart->top){
			if(k<4){
				put_cart(150,80+150*k,usercart->cartgood[k]);
				k++;
			}
			else{
				put_cart(600,80+150*(k-4),usercart->cartgood[k]);
				k++;
			}	
		}
       
}

void draw_userorder(list *userlist){
	int i ;
	char price[8];
	Bar (1,1,1023,50,LIGHT_SEA_GREEN);
	Bar (101,51,1023,767,WHITE);
	Bar (1,51,110,767,MUSTARD);
	Bar(1, 221, 110, 300, JASMINE);
	for(i=1;i<5;i++){
		printHZ16(15+i,10+i,"˧��",GRAY,2,2,4);
	}
	printHZ16(15,10,"˧��",BLACK,2,2,4);
	//�˳�ͼ��
	for(i=8;i<=10;i++){
		Circle(900,20,i,0);
		Liney(909-i,8,909-i,16,0);
	}
	printHZ16(920,15,"�˳�",0,1,1,1);

	printHZ16(700,15,"������ҳ" ,0,1,1,1);
	Rectangle(790,810,30,20,BLACK);

	printHZ16(10,100,"������Ϣ",BLACK,1,1,2);
	printHZ16(10,180,"���ﳵ",BLACK,1,1,2);
	printHZ16(10,260,"�ҵĶ���",BLACK,1,1,2);
	printHZ16(10,340,"���۶���",BLACK,1,1,2);

	 /*
		//������Ʒ
		i = usercart->top;
		if(i<=1)	put_cart(600,550,usercart->cartgood[0]);
		if(i<=2)	put_cart(150,100,usercart->cartgood[1]);
		if(i<=3)	put_cart(150,250,usercart->cartgood[2]);
		if(i<=4)	put_cart(150,400,usercart->cartgood[3]);
		if(i<=5)	put_cart(150,550,usercart->cartgood[4]);
		if(i<=6)	put_cart(600,100,usercart->cartgood[5]);
		if(i<=7)	put_cart(600,250,usercart->cartgood[6]);
		if(i<=8)	put_cart(600,400,usercart->cartgood[7]);
	   */
}



