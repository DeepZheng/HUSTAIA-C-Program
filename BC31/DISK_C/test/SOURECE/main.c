#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include"login.h"
#include"regis.h"
#include"file.h"
#include"userpage.h"
#include"tstruct.h"
#include"mouse.h"
#include"HANZI.H"
#include"welcome.h"
#include"SVGAmode.H"
#include"color.h"
#include"seller.h"
#include"location.h"

int main(){
    User loginuser; //  用户
	SELLER loginseller; //  商家
    eats eat;
    electrics electric;
    books book;
    furnitures furniture;
    recommends recommend;

	int mark = 1;   //  页码编号
	int flag = 0;   //  退出

	SetSVGA64k();
	Initmouse(1,1023,1,767);
    Initgood(&eat,&electric,&book,&furniture,&recommend);
	while(1){
		switch(mark){
			case 1:{
				mark = Welcome();       //欢迎页
				break;
			}
			case 2:{
				UserInit(&loginuser);             //用户初始化
				mark = Login(&loginuser,&loginseller);         //登录页
				break;
			}
			case 3:{
				UserInit(&loginuser);             //用户初始化
				mark = Regis(&loginuser,&loginseller);          //注册页
				break;
            }
            case 31:{
                mark = ChooseCity(&loginuser);
                break;
            }
            case 32:{
                mark = ChooseTown(&loginuser);
                break;
            }
            case 33:{
                mark = ChooseRoad(&loginuser);
                break;
            }
            case 34:{
                mark = ChooseHome(&loginuser);
                break;
            }
            case 4:{
                mark = UserMain(&loginuser);       //商品主页
                break;
            }
            case 41:{
                mark = Recommend(&loginuser);
                break;
            }
            case 42:{
                mark = Book(&loginuser);
                break;
            }
            case 43:{
                mark = Eat(&loginuser);
                break;
            }
            case 44:{
                mark = Electric(&loginuser);
                break;
            }
            case 45:{
                mark = Furniture(&loginuser);
                break;
            }
            case 5:{
                mark = UserCenter(&loginuser);        //个人中心
                break;
            }
            case 51:{
                mark = UserInfo(&loginuser);        //用户信息页
                break;
            }
            case 52:{
                mark = UserCart(&loginuser);        //购物车
                break;
            }
            case 53:{
                mark = UserOrder(&loginuser);       //用户订单
                break;
            }
            case 6:
            {   
                SellerInit(&loginseller);
                mark =sellerpage(&loginseller);
                break;
            }
            case -1:{
                flag = 1;
                break;
            }
            default: break;
        }
        if(flag==1) break;  //锟斤拷锟斤拷锟斤拷锟斤拷
    }
    return 0;
}
