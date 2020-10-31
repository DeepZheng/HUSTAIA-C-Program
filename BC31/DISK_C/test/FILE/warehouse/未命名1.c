#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct good{
	int inventory;
	float price;
	char picpath[4];
	char c;
}good;

int main()
{
	FILE *fp;
	good  temp;
	
	fp=fopen("warehouse.txt","r");
	if(!fp) return 0;
	
	while(!feof(fp))
	{
		fread(&temp,sizeof(good),1,fp);
		printf("%d %f\n",temp.inventory,temp.price);
	}
	fclose(fp);
	return 0;
}

