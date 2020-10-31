#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct good{
//	char name[16];
	char inventory[5]; //某种商品的库存量,即允许的最大销量
	char price[7]; //可以在促销期间降低
	char picpath[4]; //商品图片路径 前两位表示商品分类 第四位开始为商品名称 前三位+.bmp为商品图片路径
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
	//读入食品信息
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
	//读入图书信息
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
	//读入家居信息
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
	//读入电器信息
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
	//读入推荐信息
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
