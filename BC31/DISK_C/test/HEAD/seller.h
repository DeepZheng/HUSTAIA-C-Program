#ifndef _SELLER_H_
#define _SELLER_H_
#include "public.h"
#include "tstruct.h"

void show_sellerpage();   //��������
int sellerpage(SELLER *s);  //�̼Ҷ���������ƺ���
void lightbutton_sellerpage(int color,int flag);
void resetbutton_sellerpage(int flag);
int select_sellerpage();    //ѡ����,��ҳ
int manage_goods(storage *sto); //��Ʒ����
void draw_sellerpage();
int charge(list *L); //��Ǯ,��Ҫ����������Ϣ
int promotion(storage *sto); //����,�ڻ�����ѡ��
void list_init(list *L);  //��ʼ������
void storage_init(storage *sto); //��ʼ������
int update_storage(storage *sto); //���»�����Ϣ,�ڻ�����Ϣ�޸�֮����߳����ٴδ�ʱ����
int update_list(list *L);
#endif