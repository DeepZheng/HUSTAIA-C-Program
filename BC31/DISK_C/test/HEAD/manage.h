#ifndef _MANAGE_H_
#define _MANAGE_H_

#include "public.h"

void draw_managegoods(void);
void draw_addgoods(void);
int select_managegoods(void);
int add_goods(storage *sto);
int adjust_goods(storage *sto);
int discard_goods(storage *sto);
void draw_storage(void);  //画出货架界面的背景及按钮
int display_storage(storage *sto); //调用上面一个函数,并将货架中的内容按要求显示出来
void draw_managegoods(void);
void show_storagepage(storage *sto,int pagenum);
void draw_adjustgoods(void);
int iuput_adjustment(good *g,int pos);
char* Get_picturepath(good g,char *path); //修改商品结构体后,得到图片地址的函数
void display_goodname(good g,int x,int y);
void update_userselection(storage *sto);
#endif