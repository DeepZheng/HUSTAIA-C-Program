//本头文件记录程序所要用到的相关结构体
//如用户，商家，商品



#ifndef _TSTRUCT_H_
#define _TSTRUCT_H_

#define FOOD 1  //食物
#define FURNITURE 2  //家居
#define ELECTRIC_DEVICE 3  //电器
#define BOOK 4 //图书
#define FRESH 5 //生鲜
//#define UNFINISHED 0
//#define FINISHED 1

typedef struct User{
    char name[10];  //用户账号
    char code[15];  //用户密码
    char tel[12];
	char pos;   //
    char t;        //用户定位，暂时只有武汉
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
	char inventory[5]; //某种商品的库存量,即允许的最大销量
	char price[5]; //可以在促销期间降低
	char picpath[3]; //商品图片路径 前两位表示商品分类 第四位开始为商品名称 前三位+.bmp为商品图片路径
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
	good cartgood[8];	//购物车最多10件商品
	int top;		//目前商品数量
	float price;	//购物车内商品价格
}Cart;

typedef struct list{
	int list_state; //订单状态,0为未处理,1为已处理
	char pos; //订单发货地址
	good G[10];  //最多允许在一个订单中订购10种商品
}list;

typedef struct storage{
	good G[16]; //仓库中最多允许存放16种不同商品,初值全为0
	int goods_amount; //仓库中已有商品种类数
}storage;

#endif