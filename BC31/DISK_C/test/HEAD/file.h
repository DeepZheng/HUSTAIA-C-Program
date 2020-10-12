/*
 * �������¼���ļ�����ض�дƥ�����?
 * 
 * 
 */
#ifndef _FILE_H_
#define _FILE_H_

#include"tstruct.h"

void UserInit(User *loginuser);
void SellerInit(SELLER *loginseller);
int UserFind(User *loginuser ,char * username,char * usercode);
int UserAdd(User *loginuser);
void UserCopy(User *loginuser, User *copy);
int UserDel(User *loginuser);
int UserUpdate(User *loginuser,int mode,char *tar);
void InitCart(Cart *usercart);
void Initgood(eats *eat,electrics *electric,books *book,furnitures *furniture,recommends *recommend);
void AddGood(good g,Cart *usercart);
int judge_password(SELLER *s,char *p,char *ac);
int judge_sameAC(char *new_ac);
void GoodCopy(good *dest,good *src);
#endif

