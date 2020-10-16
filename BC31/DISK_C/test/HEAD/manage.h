#ifndef _MANAGE_H_
#define _MANAGE_H_

#include "public.h"

void draw_managegoods();
void draw_addgoods();
int select_managegoods();
int add_goods(storage *sto);
int adjust_goods(storage *sto,int pos);
int discard_goods(storage *sto,int pos);
void draw_storage();  //画出货架界面的背景及按钮
int display_storage(storage *sto); //调用上面一个函数,并将货架中的内容按要求显示出来
void draw_managegoods();
void show_storagepage(storage *sto,int pagenum);
void draw_adjustgoods();
int iuput_adjustment(good *g);
char* Get_picturepath(good g,char *path); //修改商品结构体后,得到图片地址的函数

#endif