#ifndef _CHARGE_H_
#define _CHARGE_H_
#include "tstruct.h"

float calculate_total(list *L); //计算订单总金额
void draw_charge(); //收款功能界面
int charge(); //收钱功能主函数
int chargelist(list *L); //收款按钮触发的函数
int finishlist(list *L);

#endif