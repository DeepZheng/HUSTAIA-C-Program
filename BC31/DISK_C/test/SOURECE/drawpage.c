
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
		printHZ16(250+i,150+i,"帅团",GRAY,5,5,15);
		printHZ16(180+i,250+i,"本地生活一站式团购平台",GRAY,3,3,6);
	}
	printHZ16(250,150,"帅团",BLACK,5,5,15);
	printHZ16(180,250,"本地生活一站式团购平台",BLACK,3,3,6);
	//画左边的图形
	LineThickSha(100,200,140,300,HONEY_ORANGE,GRAY,40,1);
	LineThickSha(130,200,150,230,HONEY_ORANGE,GRAY,150,1);
	LineThickSha(220,300,230,330,HONEY_ORANGE,GRAY,200,1);  
	
	//画右边的图形
	LineThickSha(830,200,800,300,WHITE,GRAY,40,1);
	LineThickSha(860,200,850,230,WHITE,GRAY,100,1);
	LineThickSha(830,270,820,300,WHITE,GRAY,80,1);

	Barshadow(380,590,450,620,PEACH,GRAY);
	printHZ16(400,600,"登录",0,1,1,1);
	Barshadow(480,590,550,620,TAN,GRAY);
	printHZ16(500,600,"注册",BLACK,1,1,1);
	Linex(600,620,635,620,31);
	printHZ16(600,600,"退出",WHITE,1,1,1);
	Linex(900,720,970,720,31);
	printHZ16(900,700,"关于我们",WHITE,1,1,1);
	return;
 }

void draw_aboutpage(void){
	int i;
	Bar(1,1,1023,767,LIGHT_SEA_GREEN);
	for(i=1;i<5;i++){
		printHZ16(100+i,30+i,"帅团",GRAY,3,3,6);
	}
	printHZ16(100,30,"帅团",BLACK,3,3,6);
	//画左边的图形
	LineThickSha(40,60,50,70,HONEY_ORANGE,GRAY,60,1);
	LineThickSha(50,70,80,100,HONEY_ORANGE,GRAY,25,1);
	LineThickSha(110,100,120,110,HONEY_ORANGE,GRAY,80,1);
	//画右边的图形
	LineThickSha(260,50,250,70,WHITE,GRAY,50,1);
	LineThickSha(235,70,220,100,WHITE,GRAY,25,1);
	LineThickSha(230,100,220,120,WHITE,GRAY,60,1);

	Linex(900,720,935,720,31);
	printHZ16(900,700,"返回",WHITE,1,1,1);
	
	for(i=1;i<5;i++){
		printHZ12(310+i,100+i,"本地生活一站式团购平台",GRAY,4,4,5);
	}
	printHZ12(310,100,"本地生活一站式团购平台",MIMOSA,4,4,5);
	printHZ16(100,200,"开发人员：",BLUE_VIOLET,1,1,1);
	printHZ16(200,200,"华中科技大学人工智能与自动化学院" ,YELLOW,1,1,1);
	printHZ16(200,230,"自动化卓越实验班",YELLOW,1,1,1);
	put_asc(350,230,"1901",BURNT_ORANGE,1,1);
	//汉字库没有字。。。还是用英文名好了。
	//printHZ16(250,230,"郑璟泓",WHITE,1,1,1);
	//printHZ16(300,230,"刘翀宇",WHITE,1,1,1);
	put_asc(420,230,"DeepZheng",BURNT_ORANGE,1,1);
	put_asc(520,230,"RichardLiu",BURNT_ORANGE,1,1);
	printHZ16(100,270,"更新日期",BLUE_VIOLET,1,1,1);
	put_asc(200,270,"2020/10/29",BURNT_ORANGE,1,1);
	printHZ16(100,320,"版本号",BLUE_VIOLET,1,1,1);
	put_asc(200,320,"1.0.2",BURNT_ORANGE,1,1);
	printHZ16(120,420,"此软件为入门级产品，对电脑配置要求较低。",LIGHT_GOLDENROD_YELLOW,1,1,1);
	printHZ16(120,460,"此软件不作为任何商业用途，如果发现有任何违规或者抄袭现象或被抄袭现象，开发者将有权追究其责任。",LIGHT_GOLDENROD_YELLOW,1,1,1);
	printHZ16(120,500,"谨以此感谢",LIGHT_GOLDENROD_YELLOW,1,1,1);
	put_asc(205,500,"C",LIGHT_GOLDENROD_YELLOW,1,1);
	printHZ16(215,500,"语言课程设计的所有老师、助教，以及帮助过我们的同学。",LIGHT_GOLDENROD_YELLOW,1,1,1);
	printHZ16(120,540,"软件依旧有很多不足或者是可更新优化的地方",LIGHT_GOLDENROD_YELLOW,1,1,1);
	printHZ16(120,580,"希望我们在软件设计和开发方面能走的更远。",LIGHT_GOLDENROD_YELLOW,1,1,1);
}
void draw_login(void){
	int i;
	Bar(1,1,1023,767,LIGHT_SEA_GREEN);
	for(i=1;i<5;i++){
		printHZ16(100+i,30+i,"帅团",GRAY,3,3,6);
	}
	printHZ16(100,30,"帅团",BLACK,3,3,6);

	LineThickSha(40,60,50,70,MIMOSA,GRAY,60,1);
	LineThickSha(50,70,80,100,MIMOSA,GRAY,25,1);
	LineThickSha(110,100,120,110,MIMOSA,GRAY,80,1);

	LineThickSha(260,50,250,70,WHITE,GRAY,50,1);
	LineThickSha(235,70,220,100,WHITE,GRAY,25,1);
	LineThickSha(230,100,220,120,WHITE,GRAY,60,1);

	Putbmp64k(20,200,"..\\file\\bmp\\meituan.bmp");	//需要24位图片
	//登录框
	Barshadow(620,200,980,700,WHITE,GRAY);
	Linex(620,200,980,200,GRAY);
	Linex(620,700,980,700,GRAY);
	Liney(620,200,620,700,GRAY);
	Liney(980,200,980,700,GRAY);

	printHZ16(680,220,"用户登录",0,1,1,1);
	printHZ16(860,220,"商家登录",0,1,1,1);

	printHZ16(660,340,"账号",0,1,1,1);
	Linex(730,360,950,360,0);
	printHZ16(660,500,"密码",0,1,1,1);
	Linex(730,520,950,520,0);
	Barshadow(800,20,870,50,BEIGE,GRAY);
	printHZ16(820,30,"返回",0,1,1,1);
	Barshadow(900,20,970,50,AMBER,GRAY);
	printHZ16(920,30,"退出",0,1,1,1);

	Barshadow(730,600,800,630,PERU,GRAY);
	printHZ16(750,605,"登录",0,1,1,1);
	return ;
}

void draw_regis(void){
	int i;
	Bar(1,1,1023,767,LIGHT_SEA_GREEN);
	for(i=1;i<5;i++){
		printHZ16(100+i,30+i,"帅团",GRAY,3,3,6);
	}
	printHZ16(100,30,"帅团",BLACK,3,3,6);

	LineThickSha(40,60,50,70,MIMOSA,GRAY,60,1);
	LineThickSha(50,70,80,100,MIMOSA,GRAY,25,1);
	LineThickSha(110,100,120,110,MIMOSA,GRAY,80,1);

	LineThickSha(260,50,250,70,WHITE,GRAY,50,1);
	LineThickSha(235,70,220,100,WHITE,GRAY,25,1);
	LineThickSha(230,100,220,120,WHITE,GRAY,60,1);

	Putbmp64k(20,200,"..\\file\\bmp\\meituan.bmp");	//需要24位图片
	//登录框
	Barshadow(620,200,980,700,MIMOSA,GRAY);
	Linex(620,200,980,200,GRAY);
	Linex(620,700,980,700,GRAY);
	Liney(620,200,620,700,GRAY);
	Liney(980,200,980,700,GRAY);

	printHZ16(680,220,"用户注册",0,1,1,1);
	printHZ16(860,220,"商家注册",0,1,1,1);

	printHZ16(660,340,"账号",0,1,1,1);
	Linex(730,360,950,360,0);
	printHZ16(660,460,"密码",0,1,1,1);
	Linex(730,480,950,480,0);
	printHZ16(660,580,"电话",0,1,1,1);
	Linex(730,600,950,600,0);
	Barshadow(800,20,870,50,BEIGE,GRAY);
	printHZ16(820,30,"返回",0,1,1,1);
	Barshadow(900,20,970,50,AMBER,GRAY);
	printHZ16(920,30,"退出",0,1,1,1);

	Barshadow(730,630,800,660,PERU,GRAY);
	printHZ16(750,635,"注册",0,1,1,1);
	return ;
}

void put_name(int x,int y,good g){
	//输出商品名
	if(!strcmp(g.picpath,"ea0"))
		printHZ16(x+120,y+15,"进口特级金钱腱",BLUE,1,1,1);
	if(!strcmp(g.picpath,"ea1"))
		printHZ16(x+120,y+15,"新鲜大白菜",BLUE,1,1,1);
	if(!strcmp(g.picpath,"ea2"))
		printHZ16(x+120,y+15,"大闸蟹",BLUE,1,1,1);
	if(!strcmp(g.picpath,"ea3"))
		printHZ16(x+120,y+15,"农家土猪肘",BLUE,1,1,1);
	if(!strcmp(g.picpath,"bo0"))
		printHZ16(x+120,y+15,"标准程序设计及应用",BLUE,1,1,1);
	if(!strcmp(g.picpath,"bo1"))
		printHZ16(x+120,y+15,"面向对象程序设计",BLUE,1,1,1);
	if(!strcmp(g.picpath,"bo2"))
		printHZ16(x+120,y+15,"自动控制原理",BLUE,1,1,1);
	if(!strcmp(g.picpath,"el0"))
		printHZ16(x+120,y+15,"高级智能电冰箱",BLUE,1,1,1);
	if(!strcmp(g.picpath,"el1"))
		printHZ16(x+120,y+15,"智能电吹风",BLUE,1,1,1);
	if(!strcmp(g.picpath,"el2"))
		printHZ16(x+120,y+15,"智能微波炉",BLUE,1,1,1);
	if(!strcmp(g.picpath,"fu0"))
		printHZ16(x+120,y+15,"家居拖鞋",BLUE,1,1,1);
	if(!strcmp(g.picpath,"fu1"))
		printHZ16(x+120,y+15,"断电必备可充电台灯",BLUE,1,1,1);
	if(!strcmp(g.picpath,"fu2"))
		printHZ16(x+120,y+15,"床上四件套",BLUE,1,1,1);
	if(!strcmp(g.picpath,"ea4"))
		printHZ16(x+120,y+15,"新鲜黄花鱼",BLUE,1,1,1);
	if(!strcmp(g.picpath,"el3"))
		printHZ16(x+120,y+15,"智能空气净化器",BLUE,1,1,1);
	if(!strcmp(g.picpath,"fu3"))
		printHZ16(x+120,y+15,"防病毒口罩",BLUE,1,1,1);
	return ;
}

void put_rename(int x,int y,good g){
	if(!strcmp(g.picpath,"ea0"))
		printHZ12(x,y,"进口特级金钱腱",BLUE,2,2,1);
	if(!strcmp(g.picpath,"ea1"))
		printHZ12(x,y,"新鲜大白菜",BLUE,2,2,1);
	if(!strcmp(g.picpath,"ea2"))
		printHZ12(x,y,"大闸蟹",BLUE,2,2,1);
	if(!strcmp(g.picpath,"ea3"))
		printHZ12(x,y,"农家土猪肘",BLUE,2,2,1);
	if(!strcmp(g.picpath,"bo0"))
		printHZ12(x,y,"标准程序设计及应用",BLUE,2,2,1);
	if(!strcmp(g.picpath,"bo1"))
		printHZ12(x,y,"面向对象程序设计",BLUE,2,2,1);
	if(!strcmp(g.picpath,"bo2"))
		printHZ12(x,y,"自动控制原理",BLUE,2,2,1);
	if(!strcmp(g.picpath,"el0"))
		printHZ12(x,y,"高级智能电冰箱",BLUE,2,2,1);
	if(!strcmp(g.picpath,"el1"))
		printHZ12(x,y,"智能电吹风",BLUE,2,2,1);
	if(!strcmp(g.picpath,"el2"))
		printHZ12(x,y,"智能微波炉",BLUE,2,2,1);
	if(!strcmp(g.picpath,"fu0"))
		printHZ12(x,y,"家居拖鞋",BLUE,2,2,1);
	if(!strcmp(g.picpath,"fu1"))
		printHZ12(x,y,"断电必备可充电台灯",BLUE,2,2,1);
	if(!strcmp(g.picpath,"fu2"))
		printHZ12(x,y,"床上四件套",BLUE,2,2,1);
	if(!strcmp(g.picpath,"ea4"))
		printHZ12(x,y,"新鲜黄花鱼",BLUE,2,2,1);
	if(!strcmp(g.picpath,"el3"))
		printHZ12(x,y,"智能空气净化器",BLUE,2,2,1);
	if(!strcmp(g.picpath,"fu3"))
		printHZ12(x,y,"防病毒口罩",BLUE,2,2,1);
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
	//商品名
	put_name(x,y,g);
	//put_asc(x+100,y+15,g.picpath,BLACK,1,1);
	//库存
	printHZ16(x+120,y+100,"剩余拼团",BLACK,1,1,1);
	//sprintf(inventory,"%d",&g.inventory);
	//sprintf(price,"%.1f",&g.price);
	put_asc(x+200,y+100,g.inventory,DARK_GRAY,1,1);
	//价格
	printHZ16(x+120,y+60,"价格",BLACK,1,1,1);
	put_asc(x+200,y+50,g.price,ORANGE_RED,2,2);
	//加入购物车按钮
	Bar(x+250,y+90,x+345,y+115,DEEP_SKY_BLUE);
	printHZ16(x+255,y+94,"加入购物车",BLACK,1,1,1);
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
	//商品名
	put_name(x,y,g);
	//库存
	printHZ16(x+120,y+100,"剩余拼团",BLACK,1,1,1);
	put_asc(x+200,y+100,g.inventory,DARK_GRAY,1,1);
	//价格
	printHZ16(x+120,y+60,"价格",BLACK,1,1,1);
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
	//商品名
	put_name(x,y,g);
	//价格
	printHZ16(x+120,y+50,"价格",BLACK,1,1,1);
	put_asc(x+200,y+50,g.price,RED,1,1);	
	//支付时间
	//timeinfo = localtime(&userlist->ordertime);
/*	gettime(timeinfo);
	itoa(10,year,timeinfo->tm_year);
	itoa(10,month,timeinfo->tm_mon);
	itoa(10,day,timeinfo->tm_mday);
	itoa(10,hour,timeinfo->tm_hour);
	itoa(10,min,timeinfo->tm_min);
	put_asc(x+480,y+80,asctime(timeinfo),DARK_GRAY,1,1);
	printHZ16(x+120,y+80,"支付时间",BLACK,1,1,1);
	put_asc(x+180,y+80,year,DARK_GRAY,1,1);
	printHZ12(x+220,y+80,"年",DARK_GRAY,1,1,1);
	put_asc(x+230,y+80,month,DARK_GRAY,1,1);
	printHZ12(x+240,y+80,"月",DARK_GRAY,1,1,1);
	put_asc(x+250,y+80,day,DARK_GRAY,1,1);
	printHZ12(x+260,y+80,"日",DARK_GRAY,1,1,1);
	put_asc(x+270,y+80,hour,DARK_GRAY,1,1);
	printHZ12(x+280,y+80,"时",DARK_GRAY,1,1,1);
	put_asc(x+290,y+80,min,DARK_GRAY,1,1);
	printHZ12(x+300,y+80,"分",DARK_GRAY,1,1,1);*/
	//订单状态
	printHZ16(x+120,y+100,"订单状态",BLACK,1,1,1);
	//按钮，根据状态变化
	switch(userlist.list_state-'0'){
		case 0 :{
			printHZ16(x+200,y+100,"未发货",DARK_GRAY,1,1,1);
			Bar(x+280,y+90,x+355,y+115,LIGHT_BLUE);
			printHZ16(x+285,y+94,"提醒发货",BLACK,1,1,1);
			break;
		}
		case 1 :{
			printHZ16(x+200,y+100,"无人配送中",DARK_GRAY,1,1,1);
			Bar(x+280,y+90,x+355,y+115,LIGHT_GOLDENROD_YELLOW);
			printHZ16(x+285,y+94,"确认收货",BLACK,1,1,1);
			break;
		}
		case 2:{
			printHZ16(x+200,y+100,"已收货",DARK_GRAY,1,1,1);
			Bar(x+280,y+90,x+355,y+115,ORANGE_RED);
			printHZ16(x+285,y+94,"订单完成",BLACK,1,1,1);
			break;
		}
	}
	
	
}
//画订单页按键提示信息
//0 为提醒发货 1 为确认收货
void put_message(int flag){
	switch(flag){
		case 0 :
		{
			Barshadow(400,300,600,400,WHITE,DARK_GRAY);
			printHZ16(410,305,"提醒成功",BLACK,2,2,1);
			break;
		}
		case 1:
		{
			Barshadow(400,300,600,400,WHITE,DARK_GRAY);
			printHZ16(410,305,"收货成功",BLACK,2,2,1);
		}
	}
}
//画添加成功页面
void put_add(void){
	Barshadow(400,300,600,400,WHITE,DARK_GRAY);
	printHZ16(410,305,"添加成功",BLACK,2,2,1);
}
//用户登陆后主界面
void draw_usermainpage(void){
	int i ;
	Bar (1,1,1023,50,LIGHT_SEA_GREEN);
	Bar (101,51,1023,767,WHITE);
	Bar (1,51,110,767,MUSTARD);

	for(i=1;i<5;i++){
		printHZ16(15+i,10+i,"帅团",GRAY,2,2,4);
	}
	printHZ16(15,10,"帅团",BLACK,2,2,4);

	printHZ16(700,15,"个人中心" ,0,1,1,1);
	Rectangle(790,810,30,20,BLACK);
	//画退出图标
	for(i=8;i<=10;i++){
		Circle(900,20,i,0);
		Liney(909-i,8,909-i,16,0);
	}
	printHZ16(920,15,"退出",0,1,1,1);

	printHZ12(8,55,"全部分类",BLACK,2,2,1);
	printHZ16(30,100,"生鲜",DIMGRAY,1,1,1);
	printHZ16(30,150,"家居",DIMGRAY,1,1,1);
	printHZ16(30,200,"电器",DIMGRAY,1,1,1);
	printHZ16(30,250,"图书",DIMGRAY,1,1,1);
	printHZ16(30,300,"美食",DIMGRAY,1,1,1);
	Putbmp64k(15,650,"..\\file\\bmp\\crt.bmp");
//	printHZ16(20,600,"购物车",RED,1,1,1);


}

void draw_usercenter(void){
	int i ;
	Bar (1,1,1023,50,LIGHT_SEA_GREEN);
	Bar (101,51,1023,767,WHITE);
	Bar (1,51,110,767,MUSTARD);

	for(i=1;i<5;i++){
		printHZ16(15+i,10+i,"帅团",GRAY,2,2,4);
	}
	printHZ16(15,10,"帅团",BLACK,2,2,4);
	//退出图标
	for(i=8;i<=10;i++){
		Circle(900,20,i,0);
		Liney(909-i,8,909-i,16,0);
	}
	printHZ16(920,15,"退出",0,1,1,1);

	printHZ16(700,15,"返回首页" ,0,1,1,1);
	Rectangle(790,810,30,20,BLACK);

	printHZ16(10,100,"个人信息",BLACK,1,1,2);
	printHZ16(10,180,"购物车",BLACK,1,1,2);
	printHZ16(10,260,"我的订单",BLACK,1,1,2);
	printHZ16(10,340,"评价订单",BLACK,1,1,2);
	//Putbmp64k(15,500,"..\\file\\bmp\\crt.bmp");
	
}

void draw_userinfo(User *loginuser){
	int i ;
	Bar (1,1,1023,50,LIGHT_SEA_GREEN);
	Bar (101,51,1023,767,WHITE);
	Bar (1,51,110,767,MUSTARD);

	for(i=1;i<5;i++){
		printHZ16(15+i,10+i,"帅团",GRAY,2,2,4);
	}
	printHZ16(15,10,"帅团",BLACK,2,2,4);
	//退出图标
	for(i=8;i<=10;i++){
		Circle(900,20,i,0);
		Liney(909-i,8,909-i,16,0);
	}
	printHZ16(920,15,"退出",0,1,1,1);

	printHZ16(700,15,"返回首页" ,0,1,1,1);
	Rectangle(790,810,30,20,BLACK);

	Bar(1,60,110,140,JASMINE);
	printHZ16(10,100,"个人信息",BLACK,1,1,2);
	printHZ16(10,180,"购物车",BLACK,1,1,2);
	printHZ16(10,260,"我的订单",BLACK,1,1,2);
	printHZ16(10,340,"评价订单",BLACK,1,1,2);

	Putbmp64k(400,150,"..\\file\\bmp\\userinfo.bmp");
	printHZ16(350,400,"账号",BLACK,1,1,2);

	printHZ16(350,450,"密码",BLACK,1,1,2);
	Barshadow(800,440,880,470,PERU,GRAY);
	printHZ16(810,450,"修改密码",BLACK,1,1,1);

	printHZ16(350,500,"电话",BLACK,1,1,2);
	Barshadow(800,490,880,520,PERU,GRAY);
	printHZ16(810,500,"修改电话",BLACK,1,1,1);

	printHZ16(350,550,"收货地址",BLACK,1,1,2);

	put_asc(400,400,loginuser->name,BLACK,1,1);
	put_asc(400,450,loginuser->code,BLACK,1,1);
	put_asc(400,500,loginuser->tel,BLACK,1,1);
	printHZ12(450,550,"武汉",BLACK,1,1,1);
	printHZ12(480,550,"洪山区",BLACK,1,1,1);
	printHZ12(530,550,"洪山街道",BLACK,1,1,1);
	
	switch(loginuser->pos){
		case 'a':	printHZ12(600,550,"保利花园",BLACK,1,1,1);	break;
		case 'b':	printHZ12(600,550,"关南社区",BLACK,1,1,1);	break;
		case 'c':	printHZ12(600,550,"关山春晓",BLACK,1,1,1);	break;
		case 'd':	printHZ12(600,550,"光谷青年城",BLACK,1,1,1);	break;
		case 'e':	printHZ12(600,550,"光谷时间广场",BLACK,1,1,1);	break;
		case 'f':	printHZ12(600,550,"光谷新世界",BLACK,1,1,1);	break;
		case 'g':	printHZ12(600,550,"光谷中心花园",BLACK,1,1,1);	break;
		case 'h':	printHZ12(600,550,"华中科技大学",BLACK,1,1,1);	break;
		case 'i':	printHZ12(600,550,"华中科技大学文华学院",BLACK,1,1,1);	break;
		case 'j':	printHZ12(600,550,"虹景花园",BLACK,1,1,1);	break;
		case 'k':	printHZ12(600,550,"华中科技大学沁苑",BLACK,1,1,1);	break;
		case 'l':	printHZ12(600,550,"华中科技大学东校区",BLACK,1,1,1);	break;
		case 'm':	printHZ12(600,550,"中建康城",BLACK,1,1,1);	break;
		case 'n':	printHZ12(600,550,"华中科技大学紫菘",BLACK,1,1,1);	break;
		case 'o':	printHZ12(600,550,"金地太阳城",BLACK,1,1,1);	break;
		case 'p':	printHZ12(600,550,"武汉职业技术学院东区",BLACK,1,1,1);	break;
		case 'q':	printHZ12(600,550,"武汉职业技术学院西区",BLACK,1,1,1);	break;
		case 'r':	printHZ12(600,550,"华中科技大学韵苑",BLACK,1,1,1);	break;
	}
	
	Barshadow(800,710,880,740,RED,GRAY);
	printHZ16(810,720,"注销用户",BLACK,1,1,1);
}

void draw_usercart(Cart *usercart){
	int i,k = 0;
	char price[8];
	Bar (1,1,1023,50,LIGHT_SEA_GREEN);
	Bar (101,51,1023,767,WHITE);
	Bar (1,51,110,767,MUSTARD);
	Bar (1, 141, 110, 220,JASMINE);
	for(i=1;i<5;i++){
		printHZ16(15+i,10+i,"帅团",GRAY,2,2,4);
	}
	printHZ16(15,10,"帅团",BLACK,2,2,4);
	//退出图标
	for(i=8;i<=10;i++){
		Circle(900,20,i,0);
		Liney(909-i,8,909-i,16,0);
	}
	printHZ16(920,15,"退出",0,1,1,1);

	printHZ16(700,15,"返回首页" ,0,1,1,1);
	Rectangle(790,810,30,20,BLACK);

	printHZ16(10,100,"个人信息",BLACK,1,1,2);
	printHZ16(10,180,"购物车",BLACK,1,1,2);
	printHZ16(10,260,"我的订单",BLACK,1,1,2);
	printHZ16(10,340,"评价订单",BLACK,1,1,2);

	Bar(110,700,1023,767,LIGHT_SEA_GREEN);		//界面下方功能条
	Bar(900,705,1010,750,RED);		//结算按钮
	printHZ16(925,715,"立即结算",WHITE,1,1,1);
	printHZ16(600,720,"总计",BLACK,2,2,1);
	//memset(price,0,sizeof(price));
	sprintf(price,"%.1f",usercart->price);	//将float型价格转换为字符串型方便输出
	put_asc(700,720,price,RED,2,2);
	    //放置商品 
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
		printHZ16(15+i,10+i,"帅团",GRAY,2,2,4);
	}
	printHZ16(15,10,"帅团",BLACK,2,2,4);
	//退出图标
	for(i=8;i<=10;i++){
		Circle(900,20,i,0);
		Liney(909-i,8,909-i,16,0);
	}
	printHZ16(920,15,"退出",0,1,1,1);

	printHZ16(700,15,"返回首页" ,0,1,1,1);
	Rectangle(790,810,30,20,BLACK);

	printHZ16(10,100,"个人信息",BLACK,1,1,2);
	printHZ16(10,180,"购物车",BLACK,1,1,2);
	printHZ16(10,260,"我的订单",BLACK,1,1,2);
	printHZ16(10,340,"评价订单",BLACK,1,1,2);

	 /*
		//放置商品
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



