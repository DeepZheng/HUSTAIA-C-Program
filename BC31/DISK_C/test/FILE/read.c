#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct good{
//	char name[16];
	char inventory[5]; //ĳ����Ʒ�Ŀ����,��������������
	char price[7]; //�����ڴ����ڼ併��
	char picpath[4]; //��ƷͼƬ·�� ǰ��λ��ʾ��Ʒ���� ����λ��ʼΪ��Ʒ���� ǰ��λ+.bmpΪ��ƷͼƬ·��
	char t ;
//ratings rat;
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

int main(){
	FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
	int i = 0;
	books book;
	eats eat;
	electrics electric;
	furnitures furniture;
	recommends recommend;
	//����ʳƷ��Ϣ
	fp1 = fopen("storage\\eat.txt","r");
	if(fp1==NULL){
		printf("can't open eat.txt");
	}
	while(!feof(fp1)){
		if(fread(&eat.ea[i],sizeof(good),1,fp1)==0)	
			break;
		printf("%s=%s=%s\n",eat.ea[i].picpath,eat.ea[i].inventory,eat.ea[i].price);
		i++;
	}
	fclose(fp1);
	i=0;
	//����ͼ����Ϣ
	fp2 = fopen("storage\\book.txt","r");
	if(fp2==NULL){
		printf("can't open book.txt");
	}
	while(!feof(fp2)){
		if(fread(&book.bo[i],sizeof(good),1,fp2)==0)
			break;
		printf("%s=%s=%s\n",book.bo[i].picpath,book.bo[i].inventory,book.bo[i].price);
		i++;
	}
	fclose(fp2);
	i=0;
	//����Ҿ���Ϣ
	fp3 = fopen("storage\\furni.txt","r");
	if(fp3==NULL){
		printf("can't open furniture.txt");
	}
	while(!feof(fp3)){
		if(fread(&furniture.fu[i],sizeof(good),1,fp3)==0)
			break;	
		printf("%s=%s=%s\n",furniture.fu[i].picpath,furniture.fu[i].inventory,furniture.fu[i].price);
		i++;
	}
	fclose(fp3);
	i=0;
	//���������Ϣ
	fp4 = fopen("storage\\electric.txt","r");
	if(fp4==NULL){
		printf("can't open electric.txt");
	}
	while(!feof(fp4)){
		if(fread(&electric.el[i],sizeof(good),1,fp4)==0)
			break;
		printf("%s=%s=%s\n",electric.el[i].picpath,electric.el[i].inventory,electric.el[i].price);
		i++;
	}
	fclose(fp4);
	i=0;
	//�����Ƽ���Ϣ
	fp5 = fopen("storage\\recom.txt","r");
	if(fp5==NULL){
		printf("can't open recommend.txt");
	}
	while(!feof(fp5)){
		if(fread(&recommend.re[i],sizeof(good),1,fp5)==0)	
			break;
		printf("%s=%s=%s\n",recommend.re[i].picpath,recommend.re[i].inventory,recommend.re[i].price);
		i++;
	}
	fclose(fp5);
	i=0;
	return 0;
}
