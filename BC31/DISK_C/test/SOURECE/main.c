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
    User loginuser; //  �û�
	SELLER loginseller; //  �̼�
    eats eat;
    electrics electric;
    books book;
    furnitures furniture;
    recommends recommend;
    Cart usercart;

	int mark = 1;   //  ҳ����
	int flag = 0;   //  �˳�

	SetSVGA64k();
	Initmouse(1,1023,1,767);
    Initgood(&eat,&electric,&book,&furniture,&recommend);
    InitCart(&usercart);
	while(1){
		switch(mark){
			case 1:{
				mark = Welcome();       //��ӭҳ
				break;
			}
			case 2:{
				UserInit(&loginuser);             //�û���ʼ��
				mark = Login(&loginuser,&loginseller);         //��¼ҳ
				break;
			}
			case 3:{
				UserInit(&loginuser);             //�û���ʼ��
				mark = Regis(&loginuser,&loginseller);          //ע��ҳ
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
                mark = UserMain(&loginuser);       //��Ʒ��ҳ
                break;
            }
            case 41:{
                mark = Recommend(&loginuser,&usercart,&recommend);
                break;
            }
            case 42:{
                mark = Book(&loginuser,&usercart,&book);
                break;
            }
            case 43:{
                mark = Eat(&loginuser,&usercart,&eat);
                break;
            }
            case 44:{
                mark = Electric(&loginuser,&usercart,&electric);
                break;
            }
            case 45:{
                mark = Furniture(&loginuser,&usercart,&furniture);
                break;
            }
            case 5:{
                mark = UserCenter(&loginuser);        //��������
                break;
            }
            case 51:{
                mark = UserInfo(&loginuser);        //�û���Ϣҳ
                break;
            }
            case 52:{
                mark = UserCart(&loginuser,&usercart);        //���ﳵ
                break;
            }
            case 53:{
                mark = UserOrder(&loginuser,&usercart);       //�û�����
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
        if(flag==1) break;  //��������
    }
    return 0;
}