#ifndef _REGIS_H_
#define _REGIS_H_
#include"tstruct.h"
int Regis(User *loginuser,SELLER *loginseller);
int UserRegis (User *loginuser);
int SellerRegis(SELLER *loginseller);
void lightbutton_register(int x1,int x2,int y1,int y2,int color,int flag);
void reset_button(int flag);
int check_register_complete(int *nums,int numssize);
int judge_sameAC(char *new_ac);
#endif