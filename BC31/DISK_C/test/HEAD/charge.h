#ifndef _CHARGE_H_
#define _CHARGE_H_
#include "tstruct.h"

float calculate_total(list *L); //���㶩���ܽ��
void draw_charge(void); //�տ�ܽ���
//int charge(void); //��Ǯ����������
int chargelist(list *L); //�տť�����ĺ���
int finishlist(list *L);
void deliver_destination(int x,int y,list *L);
int reduce_inventory(list *L);
#endif