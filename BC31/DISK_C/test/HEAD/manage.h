#ifndef _MANAGE_H_
#define _MANAGE_H_

#include "public.h"

void draw_managegoods();
void draw_addgoods();
int select_managegoods();
int add_goods(storage *sto);
int adjust_goods(storage *sto,int pos);
int discard_goods(storage *sto,int pos);
void draw_storage();  //�������ܽ���ı�������ť
int display_storage(storage *sto); //��������һ������,���������е����ݰ�Ҫ����ʾ����
void draw_managegoods();
void show_storagepage(storage *sto,int pagenum);
void draw_adjustgoods();
int iuput_adjustment(good *g);
char* Get_picturepath(good g,char *path); //�޸���Ʒ�ṹ���,�õ�ͼƬ��ַ�ĺ���

#endif