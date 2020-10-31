#ifndef _GOODPAGE_H
#define _GOODPAGE_H
#include"tstruct.h"
int Recommend(User *loginuser,Cart *usercart,recommends *recommend);
int Book(User *loginuser,Cart *usercart,books *book);
int Eat(User *loginuser,Cart *usercart,eats *eat);
int Electric(User *loginuser,Cart *usercart,electrics *electric);
int Furniture(User *loginuser, Cart *usercart, furnitures *furniture);
#endif