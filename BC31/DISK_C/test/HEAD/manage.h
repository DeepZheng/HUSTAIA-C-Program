#ifndef _MANAGE_H_
#define _MANAGE_H_

#include "public.h"

void draw_managegoods(void);
void draw_addgoods(void);
int select_managegoods(void);
int add_goods(storage *sto);
int adjust_goods(storage *sto);
int discard_goods(storage *sto);
void draw_storage(void);  //�������ܽ���ı�������ť
int display_storage(storage *sto); //��������һ������,���������е����ݰ�Ҫ����ʾ����
void draw_managegoods(void);
void show_storagepage(storage *sto,int pagenum);
void draw_adjustgoods(void);
int iuput_adjustment(good *g,int pos);
char* Get_picturepath(good g,char *path); //�޸���Ʒ�ṹ���,�õ�ͼƬ��ַ�ĺ���
void display_goodname(good g,int x,int y);
void update_userselection(storage *sto);
#endif