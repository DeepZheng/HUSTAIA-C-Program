#include <stdio.h>
#include <string.h>
typedef struct good{
//	char name[16];
	char inventory[5]; //ĳ����Ʒ�Ŀ����,��������������
	char price[7]; //�����ڴ����ڼ併��
	char picpath[4]; //��ƷͼƬ·�� ǰ��λ��ʾ��Ʒ���� ����λ��ʼΪ��Ʒ���� ǰ��λ+.bmpΪ��ƷͼƬ·��
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
