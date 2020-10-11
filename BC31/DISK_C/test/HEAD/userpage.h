#ifndef _USERPAGE_H
#define _USERPAGE_H
#include"tstruct.h"
int UserMain (User *loginuser);
int UserCenter(User *loginuser);
int UserInfo (User *loginuser);
int UserCart(User *loginuser,Cart *usercart);
int UserOrder(User *loginuser);
int Recommend(User *loginuser,Cart *usercart,recommends *recommend);
int Book(User *loginuser,Cart *usercart,books *book);
int Eat(User *loginuser,Cart *usercart,eats *eat);
int Electric(User *loginuser,Cart *usercart,electrics *electric);
#endif