#ifndef _STORAGE_H_
#define _STORAGE_H_

int appendstorage(storage *sto,good *g);  //���ܱ䳤,�������Ʒ
int shrinkstorage(storage *sto,int pos);  //��������,��ɾ����Ʒ
int adjuststorage(storage *sto,int pos,int new_inventory,float new_price);  //������Ʒ��Ϣ

//����������������һ��,��Ϊ�˷����������н��������ƶ��Ĳ���
#endif