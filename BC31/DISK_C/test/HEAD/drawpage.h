#ifndef _DRAWPAGE_H_
#define _DRAWPAGE_H_

#include"SVGAmode.H"
#include"DRAW.H"

void draw_welcome(void);   //»­»¶Ó­Ò³Ãæ
void draw_aboutpage(void);
void draw_loginpage(void); //»­µÇÂ¼Ò³
void draw_regis(void);  //»­×¢²áÒ³
void draw_usermainpage(void);   //ÓÃ»§µÇÂ¼Ö÷Ò³
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