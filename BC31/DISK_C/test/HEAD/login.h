#ifndef _LOGIN_H_
#define _LOGIN_H_
#include"tstruct.h"
int Login(User *loginuser,SELLER *loginseller);   //µÇÂ½½çÃæ
int UserLogin(User *loginuser);
int SellerLogin(SELLER *s);
void lightbutton_login(int color,int flag);
void resetbutton_login(int flag);
int judge_password(SELLER *s,char *p,char *ac);
#endif