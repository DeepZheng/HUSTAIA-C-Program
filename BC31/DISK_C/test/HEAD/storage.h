#ifndef _STORAGE_H_
#define _STORAGE_H_

int appendstorage(storage *sto,good *g);  //货架变长,即添加商品
int shrinkstorage(storage *sto,int pos);  //货架缩短,即删除商品
int adjuststorage(storage *sto,int pos,char new_inventory,char *new_price);  //调整商品信息

//后两个函数参数不一样,是为了方便在数组中进行整体移动的操作
#endif