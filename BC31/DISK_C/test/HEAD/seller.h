#ifndef _SELLER_H_
#define _SELLER_H_
#include "public.h"
#include "tstruct.h"

void show_sellerpage(void);   //��������
int sellerpage(SELLER *s,list *L);  //�̼Ҷ���������ƺ���
void lightbutton_sellerpage(int color,int flag);
void resetbutton_sellerpage(int flag);
int select_sellerpage(void);    //ѡ����,��ҳ
int manage_goods(storage *sto); //��Ʒ����
void draw_sellerpage(void);
int charge(list *L); //��Ǯ,��Ҫ����������Ϣ
int promotion(recommends *selections,int size); //����,�ڻ�����ѡ��
void list_init(list *L);  //��ʼ������
void storage_init(storage *sto); //��ʼ������
int update_storage(storage *sto); //���»�����Ϣ,�ڻ�����Ϣ�޸�֮����߳����ٴδ�ʱ����
int update_list(list *L);
int update_recommends(recommends *selections);
#endif