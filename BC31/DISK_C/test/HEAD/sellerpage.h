#ifndef _SELLERPAGE_
#define _SELLERPAGE_
#include "universal.h"
#include "tstruct.h"


void show_sellerpage();

//void draw_parallel(int x1,int y1,int x2,int y2,int x3,int y3,int color);

int sellerpage(SELLER *s);

void lightbutton_sellerpage(int color,int flag);

void resetbutton_sellerpage(int flag);

int select_sellerpage();

int manage_goods();

int watch_listinfo();

int charge();

int promotion(good *target);


void list_init(list *L);

void  storage_init(warehouse *W);


#endif