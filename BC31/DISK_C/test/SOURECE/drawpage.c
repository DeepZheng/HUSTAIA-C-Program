
#include "draw.h"
#include "hanzi.h"
#include"tstruct.h"
#include "SVGAmode.h"
#include "color.h"

void put_good(int x,int y,good g){
	char *picname = "..\\file\\bmp\\";
	strcat(picname,g.picpath);
	//strcpy(good->pic,picname);
	Barshadow(x,y,x+350,y+120,WHITE,GRAY);
	Frame(x,y,x+350,y+120,GRAY,2);
	Bar(x+250,y+90,x+345,y+115,DEEP_SKY_BLUE);
	printHZ16(x+255,y+94,"加入购物车",BLACK,1,1,1);
	Putbmp64k(x+5,y+5,picname);
	
	//printHZ16(x+5,y+5,good->name,BLACK,2,2,1);
	//put_asc(x+5,y+30,good);
}

void put_cart(int x,int y,good g){
	Barshadow(x,y,x+350,y+120,WHITE,GRAY);
	Frame(x,y,x+350,y+120,GRAY,2);
	Bar(x+250,y+90,x+345,y+115,DEEP_SKY_BLUE);
	
}


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
	
	return;
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

//用户登陆后主界面
void draw_usermainpage(){
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
	printHZ16(30,100,"美食",DIMGRAY,1,1,1);
	printHZ16(30,150,"家居",DIMGRAY,1,1,1);
	printHZ16(30,200,"电器",DIMGRAY,1,1,1);
	printHZ16(30,250,"图书",DIMGRAY,1,1,1);
	printHZ16(30,300,"生鲜",DIMGRAY,1,1,1);
	


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

	Bar(110,700,1023,767,LIGHT_SEA_GREEN);
	Bar(900,705,1010,750,RED);
	printHZ16(925,715,"立即结算",WHITE,1,1,1);
	printHZ16(600,720,"总计",BLACK,2,2,1);

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
       


}


void draw_sellerpage()
{   
	Bar(1,1,1023,767,LIGHT_SEA_GREEN);
	Putbmp64k(50,350,"..\\file\\bmp\\userinfo.bmp");
    printHZ16(200,200,"帅团",AZURE,3,3,6);
    printHZ16(300,250,"商家端",AZURE,2,2,2);
 
    printHZ16(100,675,"当前用户评分",MAROON,2,2,2);
   //	put_asc()

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

