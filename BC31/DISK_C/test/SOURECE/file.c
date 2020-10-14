/*
 * 本程序实现对文件的相关读写匹配操作
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "DRAW.H"
#include "SVGAmode.H"
#include "HANZI.H"
#include "TSTRUCT.H"
#include "mouse.h"
#include "color.h"

/*
Function : 用户初始化

*/
void UserInit(User *loginuser) //用户初始化
{
	char init[2] = "\0";
	strcpy(loginuser->name, init);
	strcpy(loginuser->code, init);
	strcpy(loginuser->tel, init);
	loginuser->pos = 'z';
	loginuser->ordernum = 0;	//订单数清零
	//strcpy(loginuser->pos,"\0");
	loginuser->t = '\n'; //换行
	//memset(pos,0,sizeof(pos));
	//更多用户信息待补充
	return;
}
                    l
void SellerInit(SELLER *loginseller)
{
	char init[3] = "\0";
	int i = 0;
	strcpy(loginseller->account, init);
	strcpy(loginseller->password, init);
	strcpy(loginseller->phonenum, init);
	/*
	loginseller->rat.num = 0;
	//	loginseller->rat.score=[0];
	for (i = 0; i < 20; i++)
	{
		loginseller->rat.score[i] = 0;
	}
	loginseller->rat.average = 0;
	*/
   //	return;
}

/*
Function : 登录时查找是否存在该用户

Return：0 -> 存在   1 -> 密码错误   2 -> 无此用户 
*/
int UserFind(User *loginuser, char *username, char *usercode)
{
	FILE *fp = NULL;
	User copy;
	fp = fopen("..\\file\\user\\user.txt", "r"); //文本流只读
	if (fp == NULL)
	{
		printf("can't open user.txt\n");
		return 2;
	}
	while (!feof(fp))
	{
		if (fread(&copy, sizeof(User), 1, fp) == 0) //没有读到值
			break;
		if (strcmp(copy.name, username) == 0) //找到相应用户名
		{
			if (strcmp(copy.code, usercode) == 0) //密码匹配成功
			{
				UserCopy(loginuser, &copy);
				fclose(fp);
				return 0;
			}
			else
			{
				fclose(fp);
				return 1;
			}
		}
	}
	if (fp != NULL)
	{
		fclose(fp);
		return 2;
	}
}
/*
Function : 向文件中添加新注册用户

Return：0 -> 添加成功   1 -> 添加失败
*/
int UserAdd(User *loginuser)
{
	FILE *fp = NULL;
	fp = fopen("..\\file\\user\\user.txt", "a+"); //追加打开一个文本流文件
	if (fp == NULL)
	{
		printf("can't open user.txt\n");
		return 1;
	}

	fwrite(loginuser, sizeof(User), 1, fp);
	fclose(fp);
	return 0;
}
/*
Function : 将匹配到的信息写入登录用户结构体中

*/
void UserCopy(User *loginuser, User *copy)
{
	strcpy(loginuser->name, copy->name);
	strcpy(loginuser->code, copy->code);
	strcpy(loginuser->tel, copy->tel);
	loginuser->pos = copy->pos;
	loginuser->ordernum = copy->ordernum;
	loginuser->t = copy->t;
}

/*
Function : 删除该用户

Return : 1 删除成功
*/
int UserDel(User *loginuser)
{
	FILE *fp1, *fp2;
	User copy;
	fp1 = fopen("..\\file\\user\\user.txt", "r+");
	fp2 = fopen("..\\file\\user\\del.txt", "w+");

	if (fp1 == NULL || fp2 == NULL)
	{
		printf("open error");
		return 0;
	}

	while (fread(&copy, sizeof(User), 1, fp1))
	{
		if (UserFind(loginuser, loginuser->name, loginuser->code))
		{ //若不是要删除的用户
			fwrite(&copy, sizeof(User), 1, fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("..\\file\\user\\user.txt");		//删除原文件
	rename("..\\file\\user\\del.txt", "..\\file\\user\\user.txt"); //将临时文件名改为源文件
	return 1;
}
/*
Function : 更新更改后的用户信息，将其写入文件中
mode表示更改项目，1为密码 2为电话（地址待做

Return : 1 更改成功
*/

int UserUpdate(User *loginuser, int mode, char *tar)
{
	switch (mode)
	{
	case 1: //密码
		if (!UserFind(loginuser, loginuser->name, loginuser->code))
		{
			if (UserDel(loginuser))
			{
				strcpy(loginuser->code, tar); //更改密码
				if(!UserAdd(loginuser))	printHZ16(700,300,"修改成功",ORANGE,2,2,1);			  //再次将该用户信息写入到文件中
			}
		}
		return 1;
	case 2:
		if (!UserFind(loginuser, loginuser->name, loginuser->code))
		{
			if (UserDel(loginuser))
			{
				strcpy(loginuser->tel, tar); //更改电话
				if(!UserAdd(loginuser))	printHZ16(900,700,"修改成功",ORANGE,2,2,1);		 //再次将该用户信息写入到文件中
			}
		}
		return 1;
	default:
		break;
	}
}


void InitCart(Cart *usercart){
	usercart->top=0;
}
/*
Function : 将用户选择的商品添加入购物车
Return :
*/
void AddGood(good g,Cart *usercart){
	usercart->cartgood[usercart->top++] = g;
	usercart->price += atof(g.price);
}



void Initgood(eats *eat,electrics *electric,books *book,furnitures *furniture,recommends *recommend){
	FILE *fp;
	int i = 0;
	
	//读入食品信息
	fp = fopen("..\\file\\storage\\eat.txt","r");
	if(fp=NULL){
		printf("can't open eat.txt");
	}
	while(!feof(fp)){
		if(fscanf(fp,"%s=%s=%s\n",eat->ea[i].picpath,eat->ea[i].price,eat->ea[i].inventory)==0)
			break;
		else i++;
	}
	i=0;
	//读入图书信息
	fp = fopen("..\\file\\storage\\book.txt","r");
	if(fp=NULL){
		printf("can't open book.txt");
	}
	while(!feof(fp)){
		if(fscanf(fp,"%s=%s=%s\n",book->bo[i].picpath,book->bo[i].price,book->bo[i].inventory)==0)
			break;
	else i++;
	}
	i=0;
	//读入家居信息
	fp = fopen("..\\file\\storage\\furniture.txt","r");
	if(fp=NULL){
		printf("can't open furniture.txt");
	}
	while(!feof(fp)){
		if(fscanf(fp,"%s=%s=%s\n",furniture->fu[i].picpath,furniture->fu[i].price,furniture->fu[i].inventory)==0)
			break;
		else i++;
	}
	i=0;
	//读入电器信息
	fp = fopen("..\\file\\storage\\electric.txt","r");
	if(fp=NULL){
		printf("can't open electric.txt");
	}
	while(!feof(fp)){
		if(fscanf(fp,"%s=%s=%s\n",electric->el[i].picpath,electric->el[i].price,electric->el[i].inventory)==0)
			break;
		else i++;
	}
	i=0;
	//读入推荐信息
	fp = fopen("..\\file\\storage\\recommend.txt","r");
	if(fp=NULL){
		printf("can't open recommend.txt");
	}
	while(!feof(fp)){
		if(fscanf(fp,"%s=%s=%s\n",recommend->re[i].picpath,recommend->re[i].price,recommend->re[i].inventory)==0)
			break;
		else i++;
	}
	i=0;
}

/*
Function : 将购物车内商品转为订单写入文件中
Return : 1 写入成功
*/
int AddList(Cart *usercart,User *loginuser){
	int i;
	FILE *fp;
	list newlist;
	newlist.list_state = 0;	//未发货
	strcpy(newlist.name,loginuser->name);	// 下订单的用户名
	fp = fopen ("..\\file\\list\\list.txt","a+");
	for (i =0 ;i <usercart->top;i++){
		newlist.G[i] = usercart->cartgood;
	}
	fwrite(newlist,sizeof(list),1,fp);
	fclose(fp);
	return 1;
}

int FindList(User *loginuser){
	FILE *fp;
	
}