#ifndef _USERPAGE_H
#define _USERPAGE_H
#include"tstruct.h"
int UserMain (User *loginuser,Cart *usercart,recommends *recommend);
int UserCenter(User *loginuser);
int UserInfo (User *loginuser);
int UserCart(User *loginuser,Cart *usercart);
int UserPay(Cart *usercart,User *loginuser);
int UserOrder(User *loginuser,list *userlist,Cart *usercart);
#endif