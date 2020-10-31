#include"public.h"
#include"location.h"

int ChooseCity(User *loginuser){
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

    Barshadow(800,20,870,50,BEIGE,GRAY);
	printHZ16(820,30,"返回",0,1,1,1);
	Barshadow(900,20,970,50,AMBER,GRAY);
	printHZ16(920,30,"退出",0,1,1,1);

    Putbmp64k(130,160,"..\\file\\bmp\\loc1.bmp");
    Initmouse(1,1023,1,767);
    while(1){
        Newxy();
        if(Mouse_press(800,20,870,50))  return 1;
        if(Mouse_press(900,20,970,50))  return -1;

        if(Mouse_above(230,300,830,630)){
            if(Mouse_pressother(490,285,580,335)){
                printHZ16(420,200,"该城市暂未开通此服务",RED,2,2,2);
                delay(600);
                Bar(420,200,900,235,WHITE);
            }
            if(Mouse_press(490,285,580,335)){
                printHZ16(420,200,"城市",RED,2,2,2);
                printHZ16(580,200,"武汉",RED,2,2,2);
				//strcpy(loginuser->pos[0],"武汉");
                delay(1000);
                return 32;
            }
        }
    }
}

int ChooseTown(User *loginuser){
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
    
    Barshadow(800,20,870,50,BEIGE,GRAY);
	printHZ16(820,30,"返回",0,1,1,1);
	Barshadow(900,20,970,50,AMBER,GRAY);
	printHZ16(920,30,"退出",0,1,1,1);

    Putbmp64k(130,160,"..\\file\\bmp\\loc2.bmp");
    Initmouse(1,1023,1,767);
    while(1){
        Newxy();
        if(Mouse_press(800,20,870,50))  return 1;
        if(Mouse_press(900,20,970,50))  return -1;
        if(Mouse_above(250,280,800,620)){
            if(Mouse_pressother(470,500,570,540)){
                printHZ16(420,180,"该区暂未开通此服务",RED,2,2,2);
                delay(600);
                Bar(420,180,800,220,WHITE);
            }
            if(Mouse_press(470,500,570,540)){
                printHZ16(500,180,"洪山区",RED,2,2,2);
				//strcpy(loginuser->pos[1],"洪山区");
                delay(1000);
                return 33;
            }
        }
 
    }
}

int ChooseRoad(User *loginuser){
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
    
    Barshadow(800,20,870,50,BEIGE,GRAY);
	printHZ16(820,30,"返回",0,1,1,1);
	Barshadow(900,20,970,50,AMBER,GRAY);
	printHZ16(920,30,"退出",0,1,1,1);

    Putbmp64k(130,160,"..\\file\\bmp\\loc3.bmp");
    Initmouse(1,1023,1,767);
    while(1){
        Newxy();
        if(Mouse_press(800,20,870,50))  return 1;
        if(Mouse_press(900,20,970,50))  return -1;

        if(Mouse_above(220,260,800,610)){
            if(Mouse_pressother(650,490,800,530)){
                printHZ16(420,180,"该区暂未开通此服务",RED,2,2,2);
                delay(600);
                Bar(420,180,800,220,WHITE);
            }
            if(Mouse_press(650,490,800,530)){
                printHZ16(500,180,"洪山街道",RED,2,2,2);
				//strcpy(loginuser->pos[2],"洪山街道");
                delay(1000);
                return 34;
            }
        }
        //if(Mouse_press())
    }
}

int ChooseHome(User *loginuser){
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
    
    Barshadow(800,20,870,50,BEIGE,GRAY);
	printHZ16(820,30,"返回",0,1,1,1);
	Barshadow(900,20,970,50,AMBER,GRAY);
	printHZ16(920,30,"退出",0,1,1,1);

    Putbmp64k(130,160,"..\\file\\bmp\\loc4.bmp");
    Initmouse(1,1023,1,767);
    while(1){
        Newxy();
        if(Mouse_press(800,20,870,50))  return 1;
        if(Mouse_press(900,20,970,50))  return -1;

        if(Mouse_press(185,260,295,285)){
            printHZ16(500,180,"保利花园",RED,2,2,2);
            //strcpy(loginuser->pos[3],"保利花园");
            loginuser->pos = 'a';
            delay(600);
            break;
        }
        if(Mouse_press(360,260,470,285)){
            printHZ16(500,180,"关南社区",RED,2,2,2);
           // strcpy(loginuser->pos[3],"关南社区");
           loginuser->pos = 'b';
            delay(600);
            break;
        }
        if(Mouse_press(525,260,635,285)){
            printHZ16(500,180,"关山春晓",RED,2,2,2);
            loginuser->pos = 'c';
            //strcpy(loginuser->pos[3],"关山春晓");
            delay(600);
            break;
        }
        if(Mouse_press(360,260,470,285)){
            printHZ16(500,180,"光谷青年城",RED,2,2,2);
            loginuser->pos = 'd';
            //strcpy(loginuser->pos[3],"光谷青年城");
            delay(600);
            break;
        }
        if(Mouse_press(185,335,350,360)){
            printHZ16(500,180,"光谷时间广场",RED,2,2,2);
            loginuser->pos = 'e';
            //strcpy(loginuser->pos[3],"光谷时间广场");
            delay(600);
            break;
        }
       
        if(Mouse_press(430,260,565,285)){
            printHZ16(500,180,"光谷新世界",RED,2,2,2);
            loginuser->pos = 'f';
            //strcpy(loginuser->pos[3],"光谷新世界");
            delay(600);
            break;
        }
        if(Mouse_press(680,260,850,285)){
            printHZ16(500,180,"光谷中心花园",RED,2,2,2);
            loginuser->pos = 'g';
            //strcpy(loginuser->pos[3],"光谷中心花园");
            delay(600);
            break;
        }
        if(Mouse_press(190,410,340,440)){
            printHZ16(500,180,"华中科技大学",RED,2,2,2);
            loginuser->pos = 'h';
            //strcpy(loginuser->pos[3],"华中科技大学");
            delay(600);
            break;
        }
        if(Mouse_press(425,410,700,440)){
            printHZ16(500,180,"华中科技大学文华学院",RED,2,2,2);
            loginuser->pos = 'i';
            //strcpy(loginuser->pos[3],"华中科技大学文华学院");
            delay(600);
            break;
        }
        if(Mouse_press(715,410,825,440)){
            printHZ16(500,180,"虹景花园",RED,2,2,2);
            loginuser->pos = 'j';
           // strcpy(loginuser->pos[3],"虹景花园");
            delay(600);
            break;
        }
        if(Mouse_press(185,485,400,510)){
            printHZ16(500,180,"华中科技大学沁苑",RED,2,2,2);
            loginuser->pos = 'k';
            //strcpy(loginuser->pos[3],"华中科技大学沁苑");
            delay(600);
            break;
        }
        if(Mouse_press(435,485,675,510)){
            printHZ16(500,180,"华中科技大学东校区",RED,2,2,2);
            loginuser->pos = 'l';
            //strcpy(loginuser->pos[3],"华中科技大学东校区");
            delay(600);
            break;
        }
        if(Mouse_press(705,485,815,510)){
            printHZ16(500,180,"中建康城",RED,2,2,2);
            loginuser->pos = 'm';
            //strcpy(loginuser->pos[3],"中建康城");
            delay(600);
            break;
        }
        if(Mouse_press(435,570,650,595)){
            printHZ16(500,180,"华中科技大学紫菘",RED,2,2,2);
            //strcpy(loginuser->pos[3],"华中科技大学紫菘");
            loginuser->pos = 'n';
            delay(600);
            break;
        }
        if(Mouse_press(685,570,820,590)){
            printHZ16(500,180,"金地太阳城",RED,2,2,2);
            loginuser->pos = 'o';
            //strcpy(loginuser->pos[3],"金地太阳城");
            delay(600);
            break;
        }
        if(Mouse_press(190,260,505,285)){
            printHZ16(500,180,"武汉职业技术学院东区",RED,2,2,2);
            loginuser->pos = 'p';
            //strcpy(loginuser->pos[3],"武汉职业技术学院东区");
            delay(600);
            break;
        }
        if(Mouse_press(525,640,845,660)){
            printHZ16(500,180,"武汉职业技术学院西区",RED,2,2,2);
            loginuser->pos = 'q';
            //strcpy(loginuser->pos[3],"武汉职业技术学院西区");
            delay(600);
            break;
        }
        if(Mouse_press(185,570,405,595)){
            printHZ16(500,180,"华中科技大学韵苑",RED,2,2,2);
            loginuser->pos = 'r';
            //strcpy(loginuser->pos[3],"华中科技大学韵苑");
            delay(600);
            break;
        }
    }
    if(!UserAdd(loginuser)){                   //向文件中添加用户
            Bar(420,180,800,220,WHITE);
            printHZ16(500,180,"地址初始化成功",RED,2,2,2);
            delay(600);
            Bar(420,180,800,220,WHITE);
            printHZ16(500,180,"即将进入主页",RED,2,2,2);
            delay(1000);
            return 4;
        }
}