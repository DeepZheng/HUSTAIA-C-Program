#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct good{
	char inventory[5];
	char price[7];
	char picpath[4];
	char t;
}good;

int main()
{
	FILE *fp;
	good  temp;
	
	fp=fopen("ware.txt","a");
	if(!fp) return 0;
	
	strcpy(temp.inventory,"261");
	strcpy(temp.price,"388");
	strcpy(temp.picpath,"fu2");
	temp.t='\n';
	fwrite(&temp,sizeof(good),1,fp);
	fclose(fp);
	return 0;
}

