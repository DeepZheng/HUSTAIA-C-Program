#include<stdio.h> 
#include<stdlib.h>
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
	FILE *fp;
	books book;
	eats eat;
	electrics electric;
	furnitures furniture;
	recommends recommend;



	strcpy(book.bo[0].inventory,"122");
	strcpy(book.bo[0].price,"38.0");
	strcpy(book.bo[0].picpath,"bo0");
	book.bo[0].t = '\n';
	strcpy(book.bo[1].inventory,"99");
	strcpy(book.bo[1].price,"28.0");
	strcpy(book.bo[1].picpath,"bo1");
	book.bo[1].t = '\n';
	strcpy(book.bo[2].inventory,"56");
	strcpy(book.bo[2].price,"48.0");
	strcpy(book.bo[2].picpath,"bo2");
	book.bo[2].t = '\n';

	strcpy(eat.ea[0].inventory,"35");
	strcpy(eat.ea[0].price,"58.0");
	strcpy(eat.ea[0].picpath,"ea0");
	eat.ea[0].t = '\n';
	strcpy(eat.ea[1].inventory,"0");
	strcpy(eat.ea[1].price,"6.8");
	strcpy(eat.ea[1].picpath,"ea1");
	eat.ea[1].t = '\n';
	strcpy(eat.ea[2].inventory,"79");
	strcpy(eat.ea[2].price,"128.0");
	strcpy(eat.ea[2].picpath,"ea2");
	eat.ea[2].t = '\n';
	strcpy(eat.ea[3].inventory,"288");
	strcpy(eat.ea[3].price,"58.0");
	strcpy(eat.ea[3].picpath,"ea3");
	eat.ea[3].t = '\n';
	strcpy(electric.el[0].inventory,"163");
	strcpy(electric.el[0].price,"8888.0");
	strcpy(electric.el[0].picpath,"el0");
	electric.el[0].t = '\n';
	strcpy(electric.el[1].inventory,"872");
	strcpy(electric.el[1].price,"99.9");
	strcpy(electric.el[1].picpath,"el1");
	electric.el[1].t = '\n';
	strcpy(electric.el[2].inventory,"453");
	strcpy(electric.el[2].price,"488.0");
	strcpy(electric.el[2].picpath,"el2");
	electric.el[2].t = '\n';
	strcpy(furniture.fu[0].inventory,"942");
	strcpy(furniture.fu[0].price,"18.8");
	strcpy(furniture.fu[0].picpath,"fu0");
	furniture.fu[0].t = '\n';
	strcpy(furniture.fu[1].inventory,"564");
	strcpy(furniture.fu[1].price,"28.8");
	strcpy(furniture.fu[1].picpath,"fu1");
	furniture.fu[1].t = '\n';
	strcpy(furniture.fu[2].inventory,"261");
	strcpy(furniture.fu[2].price,"388.0");
	strcpy(furniture.fu[2].picpath,"fu2");
	furniture.fu[2].t = '\n';
	strcpy(recommend.re[0].inventory,"211");
	strcpy(recommend.re[0].price,"18.8");
	strcpy(recommend.re[0].picpath,"ea4");
	recommend.re[0].t = '\n';
	strcpy(eat.ea[4].inventory,"211");
	strcpy(eat.ea[4].price,"18.8");
	strcpy(eat.ea[4].picpath,"ea4");
	eat.ea[4].t = '\n';
	strcpy(electric.el[3].inventory,"265");
	strcpy(electric.el[3].price,"1699.0");
	strcpy(electric.el[3].picpath,"el3");
	electric.el[3].t = '\n';
	strcpy(furniture.fu[3].inventory,"792");
	strcpy(furniture.fu[3].price,"5.8");
	strcpy(furniture.fu[3].picpath,"fu3");
	furniture.fu[3].t = '\n';
	
	fp=fopen("storage\\book.txt","w");
	fwrite(&book.bo[0],sizeof(good),1,fp);
	fwrite(&book.bo[1],sizeof(good),1,fp);
	fwrite(&book.bo[2],sizeof(good),1,fp);
	//fread(&book.bo[0],sizeof(good),1,fp);
	//fread(&book.bo[1],sizeof(good),1,fp);
	//fread(&book.bo[2],sizeof(good),1,fp);
	//printf("%d  %.1f  %s\n",book.bo[0].inventory,book.bo[0].price,book.bo[0].picpath);
	//printf("%d  %.1f  %s\n",book.bo[1].inventory,book.bo[1].price,book.bo[1].picpath);
	//printf("%d  %.1f  %s\n",book.bo[2].inventory,book.bo[2].price,book.bo[2].picpath);
	fclose(fp);
	
	fp=fopen("storage\\eat.txt","w");
	fwrite(&eat.ea[0],sizeof(good),1,fp);
	fwrite(&eat.ea[1],sizeof(good),1,fp);
	fwrite(&eat.ea[2],sizeof(good),1,fp);
	fwrite(&eat.ea[3],sizeof(good),1,fp);
	fwrite(&eat.ea[4],sizeof(good),1,fp);
	fclose(fp);
	fp=fopen("storage\\furni.txt","w");
	fwrite(&furniture.fu[0],sizeof(good),1,fp);
	fwrite(&furniture.fu[1],sizeof(good),1,fp);
	fwrite(&furniture.fu[2],sizeof(good),1,fp);
	fwrite(&furniture.fu[3],sizeof(good),1,fp);
	
	fclose(fp);
	fp=fopen("storage\\recom.txt","w");
	fwrite(&recommend.re[0],sizeof(good),1,fp);
	fclose(fp);
	fp=fopen("storage\\electric.txt","w");
	fwrite(&electric.el[0],sizeof(good),1,fp);
	fwrite(&electric.el[1],sizeof(good),1,fp);
	fwrite(&electric.el[2],sizeof(good),1,fp);
	fwrite(&electric.el[3],sizeof(good),1,fp);
	fclose(fp);
	printf("successful");
	return 0;
}
