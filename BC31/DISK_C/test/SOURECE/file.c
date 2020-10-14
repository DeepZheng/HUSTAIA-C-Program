/*
 * ������ʵ�ֶ��ļ�����ض�дƥ�����
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
Function : �û���ʼ��

*/
void UserInit(User *loginuser) //�û���ʼ��
{
	char init[2] = "\0";
	strcpy(loginuser->name, init);
	strcpy(loginuser->code, init);
	strcpy(loginuser->tel, init);
	loginuser->pos = 'z';
	loginuser->ordernum = 0;	//����������
	//strcpy(loginuser->pos,"\0");
	loginuser->t = '\n'; //����
	//memset(pos,0,sizeof(pos));
	//�����û���Ϣ������
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
Function : ��¼ʱ�����Ƿ���ڸ��û�

Return��0 -> ����   1 -> �������   2 -> �޴��û� 
*/
int UserFind(User *loginuser, char *username, char *usercode)
{
	FILE *fp = NULL;
	User copy;
	fp = fopen("..\\file\\user\\user.txt", "r"); //�ı���ֻ��
	if (fp == NULL)
	{
		printf("can't open user.txt\n");
		return 2;
	}
	while (!feof(fp))
	{
		if (fread(&copy, sizeof(User), 1, fp) == 0) //û�ж���ֵ
			break;
		if (strcmp(copy.name, username) == 0) //�ҵ���Ӧ�û���
		{
			if (strcmp(copy.code, usercode) == 0) //����ƥ��ɹ�
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
Function : ���ļ��������ע���û�

Return��0 -> ��ӳɹ�   1 -> ���ʧ��
*/
int UserAdd(User *loginuser)
{
	FILE *fp = NULL;
	fp = fopen("..\\file\\user\\user.txt", "a+"); //׷�Ӵ�һ���ı����ļ�
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
Function : ��ƥ�䵽����Ϣд���¼�û��ṹ����

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
Function : ɾ�����û�

Return : 1 ɾ���ɹ�
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
		{ //������Ҫɾ�����û�
			fwrite(&copy, sizeof(User), 1, fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove("..\\file\\user\\user.txt");		//ɾ��ԭ�ļ�
	rename("..\\file\\user\\del.txt", "..\\file\\user\\user.txt"); //����ʱ�ļ�����ΪԴ�ļ�
	return 1;
}
/*
Function : ���¸��ĺ���û���Ϣ������д���ļ���
mode��ʾ������Ŀ��1Ϊ���� 2Ϊ�绰����ַ����

Return : 1 ���ĳɹ�
*/

int UserUpdate(User *loginuser, int mode, char *tar)
{
	switch (mode)
	{
	case 1: //����
		if (!UserFind(loginuser, loginuser->name, loginuser->code))
		{
			if (UserDel(loginuser))
			{
				strcpy(loginuser->code, tar); //��������
				if(!UserAdd(loginuser))	printHZ16(700,300,"�޸ĳɹ�",ORANGE,2,2,1);			  //�ٴν����û���Ϣд�뵽�ļ���
			}
		}
		return 1;
	case 2:
		if (!UserFind(loginuser, loginuser->name, loginuser->code))
		{
			if (UserDel(loginuser))
			{
				strcpy(loginuser->tel, tar); //���ĵ绰
				if(!UserAdd(loginuser))	printHZ16(900,700,"�޸ĳɹ�",ORANGE,2,2,1);		 //�ٴν����û���Ϣд�뵽�ļ���
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
Function : ���û�ѡ�����Ʒ����빺�ﳵ
Return :
*/
void AddGood(good g,Cart *usercart){
	usercart->cartgood[usercart->top++] = g;
	usercart->price += atof(g.price);
}



void Initgood(eats *eat,electrics *electric,books *book,furnitures *furniture,recommends *recommend){
	FILE *fp;
	int i = 0;
	
	//����ʳƷ��Ϣ
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
	//����ͼ����Ϣ
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
	//����Ҿ���Ϣ
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
	//���������Ϣ
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
	//�����Ƽ���Ϣ
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
Function : �����ﳵ����ƷתΪ����д���ļ���
Return : 1 д��ɹ�
*/
int AddList(Cart *usercart,User *loginuser){
	int i;
	FILE *fp;
	list newlist;
	newlist.list_state = 0;	//δ����
	strcpy(newlist.name,loginuser->name);	// �¶������û���
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