#include <stdio.h>
#include <string.h>
typedef struct good{
//	char name[16];
	char inventory[5]; //某种商品的库存量,即允许的最大销量
	char price[7]; //可以在促销期间降低
	char picpath[4]; //商品图片路径 前两位表示商品分类 第四位开始为商品名称 前三位+.bmp为商品图片路径
	char t;
	//	ratings rat;
}good;
int main()
{
	FILE *fp=NULL;
	good temp;
	
	fp=fopen("reco.txt","a");
	strcpy(temp.inventory,"792");
	strcpy(temp.price,"5.8");
	strcpy(temp.picpath,"fu3");
	temp.t='\n';
	fwrite(&temp,sizeof(good),1,fp);
	fclose(fp);
	return 0;
}
