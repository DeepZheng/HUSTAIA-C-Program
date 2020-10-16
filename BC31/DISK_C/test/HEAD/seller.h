#ifndef _SELLER_H_
#define _SELLER_H_
#include "public.h"
#include "tstruct.h"

void show_sellerpage();   //画主界面
int sellerpage(SELLER *s);  //商家端主界面控制函数
void lightbutton_sellerpage(int color,int flag);
void resetbutton_sellerpage(int flag);
int select_sellerpage();    //选择功能,换页
int manage_goods(storage *sto); //商品管理
void draw_sellerpage();
int charge(list *L); //收钱,需要看见订单信息
int promotion(storage *sto); //促销,在货架中选择
void list_init(list *L);  //初始化订单
void storage_init(storage *sto); //初始化货架
int update_storage(storage *sto); //更新货架信息,在货架信息修改之后或者程序再次打开时调用
int update_list(list *L);
#endif