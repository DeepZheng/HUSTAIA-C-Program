//��ͷ�ļ���¼������Ҫ�õ�����ؽṹ��
//���û����̼ң���Ʒ



#ifndef _TSTRUCT_H_
#define _TSTRUCT_H_

#include <time.h>
#define FOOD 1  //ʳ��
#define FURNITURE 2  //�Ҿ�
#define ELECTRIC_DEVICE 3  //����
#define BOOK 4 //ͼ��


typedef struct User{
    char name[10];  //�û��˺�
    char code[15];  //�û�����
    char tel[12];	//�û��绰����
	char pos;   //�û���λ����ʱֻ���人
	char ordernum;	//��������
    char t;        //���з�
} User;

typedef struct SELLER{
	char phonenum[12];
	char account[21];
	char password[21];
//	ratings rat;
}SELLER;

typedef struct good{
//	char name[16];
	char inventory[5]; //ĳ����Ʒ�Ŀ����,��������������
	char price[7]; //�����ڴ����ڼ併��
	char picpath[4]; //��ƷͼƬ·�� ǰ��λ��ʾ��Ʒ���� ����λ��ʼΪ��Ʒ���� ǰ��λ+.bmpΪ��ƷͼƬ·��
	char t;
	//	ratings rat;
}good;

typedef struct{
	good bo[8];
}books;

typedef struct{
	good ea[8];
}eats;

typedef struct{
	good el[8];
}electrics;

typedef struct{
	good fu[8];
}furnitures;

typedef struct{
	good re[8];
}recommends;

typedef struct {
	good cartgood[8];	//���ﳵ���10����Ʒ
	int top;		//Ŀǰ��Ʒ����
	float price;	//���ﳵ����Ʒ�۸�
}Cart;

typedef struct list{
	char name[15];	//�����û�
	char list_state; //����״̬,0Ϊδ����,1Ϊ�Ѵ���,2Ϊ���ջ�
	char pos; //����������ַ
	char top;	//��������Ʒ����
	good G[10];  //���������һ�������ж���10����Ʒ
	char t;		//���з�
}list;

typedef struct storage{
	good G[16]; //�ֿ������������16�ֲ�ͬ��Ʒ,��ֵȫΪ0
	int goods_amount; //�ֿ���������Ʒ������
}storage;

#endif