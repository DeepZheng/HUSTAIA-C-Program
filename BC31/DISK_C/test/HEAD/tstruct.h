//��ͷ�ļ���¼������Ҫ�õ�����ؽṹ��
//���û����̼ң���Ʒ



#ifndef _TSTRUCT_H_
#define _TSTRUCT_H_

#define FOOD 1  //ʳ��
#define FURNITURE 2  //�Ҿ�
#define ELECTRIC_DEVICE 3  //����
#define BOOK 4 //ͼ��
#define FRESH 5 //����
//#define UNFINISHED 0
//#define FINISHED 1

typedef struct User{
    char name[10];  //�û��˺�
    char code[15];  //�û�����
    char tel[12];
	char pos;   //
    char t;        //�û���λ����ʱֻ���人
} User;

/*typedef struct ratings{
	int num; //how many ratings have been submitted
	float score[20];
	float average; //final rating
}ratings;  */
typedef struct SELLER{
	char phonenum[12];
	char account[21];
	char password[21];
//	ratings rat;
}SELLER;

typedef struct good{
//	char name[16];
	char inventory[5]; //ĳ����Ʒ�Ŀ����,��������������
	char price[5]; //�����ڴ����ڼ併��
	char picpath[3]; //��ƷͼƬ·�� ǰ��λ��ʾ��Ʒ���� ����λ��ʼΪ��Ʒ���� ǰ��λ+.bmpΪ��ƷͼƬ·��
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
	int list_state; //����״̬,0Ϊδ����,1Ϊ�Ѵ���
	char pos; //����������ַ
	good G[10];  //���������һ�������ж���10����Ʒ
}list;

typedef struct storage{
	good G[16]; //�ֿ������������16�ֲ�ͬ��Ʒ,��ֵȫΪ0
	int goods_amount; //�ֿ���������Ʒ������
}storage;

#endif