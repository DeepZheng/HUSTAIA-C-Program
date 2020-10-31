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
#include "time.h"

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
   //	loginuser->ordernum = copy->ordernum;
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
	usercart->top = 0;
	usercart->price = 0.0;
}
/*
Function : ���û�ѡ�����Ʒ����빺�ﳵ
Return :
*/
int AddGood(good g,Cart *usercart){
	//usercart->cartgood[usercart->top] = g;
	GoodCopy(&usercart->cartgood[usercart->top],&g);
	usercart->top++;
	usercart->price += atof(g.price);
	return 1;
}



void Initgood(eats *eat,electrics *electric,books *book,furnitures *furniture,recommends *recommend){
	FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
	int i = 0;
	
	//����ʳƷ��Ϣ
	fp1 = fopen("..\\file\\storage\\eat.txt","r");
	if(fp1==NULL){
		printf("can't open eat.txt");
	}
	while(!feof(fp1)){
		if(fread(&eat->ea[i++],sizeof(good),1,fp1)==0)	
			break;
	}
	fclose(fp1);
	i=0;
	//����ͼ����Ϣ
	fp2 = fopen("..\\file\\storage\\book.txt","r");
	if(fp2==NULL){
		printf("can't open book.txt");
	}
	while(!feof(fp2)){
		if(fread(&book->bo[i++],sizeof(good),1,fp2)==0)
			break;
	}
	fclose(fp2);
	i=0;
	//����Ҿ���Ϣ
	fp3 = fopen("..\\file\\storage\\furni.txt","r");
	if(fp3==NULL){
		printf("can't open furniture.txt");
	}
	while(!feof(fp3)){
		if(fread(&furniture->fu[i++],sizeof(good),1,fp3)==0)
			break;	
	}
	fclose(fp3);
	i=0;
	//���������Ϣ
	fp4 = fopen("..\\file\\storage\\electric.txt","r");
	if(fp4==NULL){
		printf("can't open electric.txt");
	}
	while(!feof(fp4)){
		if(fread(&electric->el[i++],sizeof(good),1,fp4)==0)
			break;
	}
	fclose(fp4);
	i=0;
	//�����Ƽ���Ϣ
	fp5 = fopen("..\\file\\storage\\recom.txt","r");
	if(fp5==NULL){
		printf("can't open recommend.txt");
	}
	while(!feof(fp5)){
		if(fread(&recommend->re[i++],sizeof(good),1,fp5)==0)	
			break;
	}
	fclose(fp5);
	return ;
}

/*
Function : �����ﳵ����ƷתΪ����д���ļ���
Return : 1 д��ɹ�
*/
int AddList(Cart *usercart,User *loginuser){
	int i;
	FILE *fp;
	list newlist;
	//ʱ��
 //	time_t rawtime;

  //	time ( &rawtime );
  //	newlist.ordertime = rawtime;
	newlist.list_state = '0';	//δ����
	newlist.t = '\n';//����
	newlist.pos = loginuser->pos;
	newlist.top = usercart->top+'0';	//��Ʒ����
	strcpy(newlist.name,loginuser->name);	// �¶������û���
	//Put_Asc16_Size(150,200,2,2,usercart->top+'0',0);
	//Put_Asc16_Size(150,200+100,2,2,newlist.top,0);
	//delay(600);
	fp = fopen ("..\\file\\list\\list.txt","a+");
   	for (i =0 ;i <usercart->top;i++){
		//newlist.G[i] = usercart->cartgood;
		GoodCopy(&newlist.G[i],&usercart->cartgood[i]);
	}
	fwrite(&newlist,sizeof(list),1,fp);
	fclose(fp);
	return 1;
}

void ReadList(User *loginuser,list *userlist){
	int i = 0;
	FILE *fp;
	list copy;
	fp = fopen("..\\file\\list\\list.txt","r+");
	if(fp == NULL){
		printf("open error");
		exit(1);
	}
	while(!feof(fp)){
		if(!fread(&copy,sizeof(list),1,fp)){
			break;
		}
		//put_asc(300,300,copy.name,0,1,1);
		if(!strcmp(copy.name,loginuser->name)){		//�ҵ���Ӧ�û�����Ʒ			
			ListCopy(&userlist[i++],&copy);
			//printHZ16(200,100+10*i,"�ɹ�",0,1,1,1);
			//Put_Asc16_Size(150,200+100*i,2,2,userlist[i-1].top,0);
			//delay(600);
			//put_asc(300,300,userlist->G[0].picpath,0,1,1);
			loginuser->ordernum++;
		}
	}
	fclose(fp);
}
//ˢ�¶���
void RenewList(list *L,int cnt)
{
    FILE *fp1=NULL;
    FILE *fp2=NULL;
    list temp;
    int i=0;

    fp1=fopen("..\\file\\list\\list.txt","r");
    fp2=fopen("..\\file\\list\\list2.txt","a");

    if(fp1==NULL||fp2==NULL)
    {
        return 0;
    }
    while(!feof(fp1))
    {
        if(fread(&temp,sizeof(list),1,fp1)==0)
            break;
        if(strcmp(L->name,temp.name)==0&&cnt==i&&temp.list_state=='1')
        {
            temp.list_state='2';
            fwrite(&temp,sizeof(list),1,fp2);
        }
        else
        {   
			i++;
            fwrite(&temp,sizeof(list),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("..\\file\\list\\list.txt");
    rename("..\\file\\list\\list2.txt","..\\file\\list\\list.txt");
    return 1;
}

void ListCopy(list *dest,list *src){
	int i;
	strcpy(dest->name,src->name);
	dest->list_state = src->list_state;
	dest->pos = src->pos;
	dest->top = src->top;
	dest->t = src->t;
	for(i = 0;i<src->top;i++){
		GoodCopy(&dest->G[i],&src->G[i]);
	}
	//����ʱ��
}
/*
int FindList(User *loginuser){
	FILE *fp;
	
}
*/
void GoodCopy(good *dest,good *src){
	strcpy(dest->inventory,src->inventory);
	strcpy(dest->price , src->price);
	strcpy(dest->picpath,src->picpath);
	dest->t = src->t;
}