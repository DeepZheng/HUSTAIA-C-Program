#ifndef _DRAWPAGE_H_
#define _DRAWPAGE_H_

#include"SVGAmode.H"
#include"DRAW.H"

void draw_welcome(void);   //��ʼע�����?
void draw_loginpage(void); //����¼����
void draw_regis(void);  //��ע�����?
void draw_usermainpage(void);   //���û���ҳ
void draw_usercenter(void);
void draw_userinfo(User *loginuser);
void draw_usercart(void);
void draw_userorder(void);

void put_good(int x,int y,good g);
void put_cart(int x,int y,good g);
#endif