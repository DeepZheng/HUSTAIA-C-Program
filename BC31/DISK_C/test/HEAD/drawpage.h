#ifndef _DRAWPAGE_H_
#define _DRAWPAGE_H_

#include"SVGAmode.H"
#include"DRAW.H"

void draw_welcome(void);   //����ӭҳ��
void draw_aboutpage(void);
void draw_loginpage(void); //����¼ҳ
void draw_regis(void);  //��ע��ҳ
void draw_usermainpage(void);   //�û���¼��ҳ
void draw_usercenter(void);
void draw_userinfo(User *loginuser);
void draw_usercart(Cart *usercart);
void draw_userorder(list *userlist);
void put_name(int x,int y,good g);
void put_good(int x,int y,good g);
void put_cart(int x,int y,good g);
void put_message(int flag);
void put_add(void);
void put_list(int x,int y,good g,list userlist);
#endif