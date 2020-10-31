#ifndef _CHARGE_H_
#define _CHARGE_H_
#include "tstruct.h"

float calculate_total(list *L); //计算订单总金额
void draw_charge(void); //收款功能界面
//int charge(void); //收钱功能主函数
int chargelist(list *L); //收款按钮触发的函数
int finishlist(list *L);
void deliver_destination(int x,int y,list *L);
int reduce_inventory(list *L);
#endif