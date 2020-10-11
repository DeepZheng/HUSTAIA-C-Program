#include"HANZI.H"
#include"svgamode.h"
#include "color.h"
#include"io.h"
#include<FCNTL.H>
void printHZ12(int x,int y,char *s,int color,int dx,int dy,int space)    // 12*12�����ֵ���ʾ
{
	unsigned long offset;
	FILE *fp;
	char buffer[24]; //buffer�����洢һ������
	int m,n,i,j,k;
	unsigned char qh,wh;

	if ((fp=fopen("C:\\test\\hzk\\hzk12","rb"))==NULL)
	{
		printf("Can't open hzk12,Please add it");
		exit(1);
	}
	while(*s)
	{
		qh=*(s)-0xa0; //������λ��
		wh=*(s+1)-0xa0;
		offset=(94*(qh-1)+(wh-1))*24L; //����ú������ֿ���ƫ����
		fseek(fp,offset,SEEK_SET);
		fread(buffer,24,1,fp); //ȡ������32�ֽڵĵ�����ģ����buffer�У�һ�����֣�
		
		for(i=0;i<12;i++) //��32λ�ֽڵĵ���λ����Ļ�ϴ�ӡ����(1:��ӡ,0:����ӡ),��ʾ����
		{
   			for(n=0;n<dx;n++)
   			{
    				for(j=0;j<2;j++)
    				{
     					for(k=0;k<8;k++)
     					{
      						for(m=0;m<dy;m++)
      						{
       							if(((buffer[i*2+j]>>(7-k))&0x1)!=NULL)
       							{
									Putpixel64k(x+8*j*dy+k*dy+m,y+i*dx+n,color);
       							}
      						}
     					}	
    				}
   			}
  		}
  		s+=2; //һ����������ռ�������ֽ�
  		x+=12*dx+space;//�ּ���
 	}
 	fclose(fp);
}

void printHZ16(int x,int y,char *s,int color,int dx,int dy,int space)  // 16*16�����ֵ���ʾ
{
	unsigned long offset;
 	FILE *fp;
 	char buffer[32]; //buffer�����洢һ������
 	int m,n,i,j,k;
 	unsigned char qh,wh;

	if ((fp=fopen("C:\\test\\HZK\\hzk16","rb"))==NULL)
	{
		printf("Can't open hzk16,Please add it");
		exit(1);
	}
	while(*s)
	{
		qh=*(s)-0xa0; //������λ��
		wh=*(s+1)-0xa0;
		offset=(94*(qh-1)+(wh-1))*32L; //����ú������ֿ���ƫ����
		fseek(fp,offset,SEEK_SET);
		fread(buffer,32,1,fp); //ȡ������32�ֽڵĵ�����ģ����buffer�У�һ�����֣�
		
		for(i=0;i<16;i++) //��32λ�ֽڵĵ���λ����Ļ�ϴ�ӡ����(1:��ӡ,0:����ӡ),��ʾ����
		{
			for(n=0;n<dx;n++)
			{
					for(j=0;j<2;j++)
					{
						for(k=0;k<8;k++)
						{
							for(m=0;m<dy;m++)
							{
								if(((buffer[i*2+j]>>(7-k))&0x1)!=NULL)
								{
									Putpixel64k(x+8*j*dy+k*dy+m,y+i*dx+n,color);
								}
							}
						}
					}
			}
		}
		s+=2; //һ����������ռ�������ֽ�
		x+=16*dx+space;//�ּ���
	}
	fclose(fp);

}

void printHZ24F(int x,int y,char *s,int color,int dx,int dy,int space)
{
	unsigned long offset;
 	FILE *fp;
 	char buffer[72]; //buffer�����洢һ������
 	int m,n,i,j,k;
 	unsigned char qh,wh;

	if ((fp=fopen("C:\\test\\hzk\\hzk24F","rb"))==NULL)
	{
		printf("Can't open hzk24F,Please add it");
		exit(1);
	}
	while(*s)
	{
		qh=*(s)-0xa0; //������λ��
		wh=*(s+1)-0xa0;
		offset=(94*(qh-1)+(wh-1))*72L; //����ú������ֿ���ƫ����
		fseek(fp,offset,SEEK_SET);
		fread(buffer,72,1,fp); //ȡ������72�ֽڵĵ�����ģ����buffer�У�һ�����֣�
		
		for(i=0;i<24*dx;i=i+dx) //��72λ�ֽڵĵ���λ����Ļ�ϴ�ӡ����(1:��ӡ,0:����ӡ),��ʾ����
		{
			for(n=0;n<dx;n++)
			{
					for(j=0;j<3;j++)
					{
						for(k=0;k<8;k++)
						{
							for(m=0;m<dy;m++)
							{
								if(((buffer[i/dx*3+j]>>(7-k))&0x1)!=NULL)
								{
									Putpixel64k(x+i+n,y+j*8*dy+k*dy+m,color);
								}
							}
						}
					}
			}
		}
		s+=3; //һ����������ռ�������ֽ�
		x+=24*dx+space;//�ּ���
	}
	fclose(fp);
}

void printHZ24H(int x,int y,char *s,int color,int dx,int dy,int space)
{
	unsigned long offset;
 	FILE *fp;
 	char buffer[72]; //buffer�����洢һ������
 	int m,n,i,j,k;
 	unsigned char qh,wh;

	if ((fp=fopen("C:\\test\\hzk\\hzk24H","rb"))==NULL)
	{
		printf("Can't open hzk24H,Please add it");
		exit(1);
	}
	while(*s)
	{
		qh=*(s)-0xa0; //������λ��
		wh=*(s+1)-0xa0;
		offset=(94*(qh-1)+(wh-1))*72L; //����ú������ֿ���ƫ����
		fseek(fp,offset,SEEK_SET);
		fread(buffer,72,1,fp); //ȡ������72�ֽڵĵ�����ģ����buffer�У�һ�����֣�
		
		for(i=0;i<24*dx;i=i+dx) //��72λ�ֽڵĵ���λ����Ļ�ϴ�ӡ����(1:��ӡ,0:����ӡ),��ʾ����
		{
			for(n=0;n<dx;n++)
			{
					for(j=0;j<3;j++)
					{
						for(k=0;k<8;k++)
						{
							for(m=0;m<dy;m++)
							{
								if(((buffer[i/dx*3+j]>>(7-k))&0x1)!=NULL)
								{
									Putpixel64k(x+i+n,y+j*8*dy+k*dy+m,color);
								}
							}
						}
					}
			}
		}
		s+=3; //һ����������ռ�������ֽ�
		x+=24*dx+space;//�ּ���
	}
	fclose(fp);
}

void printHZ24K(int x,int y,char *s,int color,int dx,int dy,int space)
{
	unsigned long offset;
 	FILE *fp;
 	char buffer[72]; //buffer�����洢һ������
 	int m,n,i,j,k;
 	unsigned char qh,wh;

	if ((fp=fopen("C:\\test\\hzk\\hzk24K","rb"))==NULL)
	{
		printf("Can't open hzk24K,Please add it");
		exit(1);
	}
	while(*s)
	{
		qh=*(s)-0xa0; //������λ��
		wh=*(s+1)-0xa0;
		offset=(94*(qh-1)+(wh-1))*72L; //����ú������ֿ���ƫ����
		fseek(fp,offset,SEEK_SET);
		fread(buffer,72,1,fp); //ȡ������72�ֽڵĵ�����ģ����buffer�У�һ�����֣�
		
		for(i=0;i<24*dx;i=i+dx) //��72λ�ֽڵĵ���λ����Ļ�ϴ�ӡ����(1:��ӡ,0:����ӡ),��ʾ����
		{
			for(n=0;n<dx;n++)
			{
					for(j=0;j<3;j++)
					{
						for(k=0;k<8;k++)
						{
							for(m=0;m<dy;m++)
							{
								if(((buffer[i/dx*3+j]>>(7-k))&0x1)!=NULL)
								{
									Putpixel256(x+i+n,y+j*8*dy+k*dy+m,color);
								}
							}
						}
					}
			}
		}
		s+=3; //һ����������ռ�������ֽ�
		x+=24*dx+space;//�ּ���
	}
	fclose(fp);
}
void printHZ24S(int x,int y,char *s,int color,int dx,int dy,int space)
{
	unsigned long offset;
 	FILE *fp;
 	char buffer[72]; //buffer�����洢һ������
 	int m,n,i,j,k;
 	unsigned char qh,wh;

	if ((fp=fopen("C:\\test\\hzk\\hzk24S","rb"))==NULL)
	{
		printf("Can't open hzk24S,Please add it");
		exit(1);
	}
	while(*s)
	{
		qh=*(s)-0xa0; //������λ��
		wh=*(s+1)-0xa0;
		offset=(94*(qh-1)+(wh-1))*72L; //����ú������ֿ���ƫ����
		fseek(fp,offset,SEEK_SET);
		fread(buffer,72,1,fp); //ȡ������72�ֽڵĵ�����ģ����buffer�У�һ�����֣�
		
		for(i=0;i<24*dx;i=i+dx) //��72λ�ֽڵĵ���λ����Ļ�ϴ�ӡ����(1:��ӡ,0:����ӡ),��ʾ����
		{
			for(n=0;n<dx;n++)
			{
					for(j=0;j<3;j++)
					{
						for(k=0;k<8;k++)
						{
							for(m=0;m<dy;m++)
							{
								if(((buffer[i/dx*3+j]>>(7-k))&0x1)!=NULL)
								{
									Putpixel64k(x+i+n,y+j*8*dy+k*dy+m,color);
								}
							}
						}
					}
			}
		}
		s+=2; //һ����������ռ�������ֽ�
		x+=24*dx+space;//�ּ���
	}
	fclose(fp);
}
void Read_Asc16(char key, unsigned char *buf)
{
	int handle;
	long address;
	handle = open("C:\\test\\hzk\\asc16", O_RDONLY | O_BINARY);
	address = key * 16l;
	lseek(handle, address, SEEK_SET);
	read(handle, buf, 16);
	close(handle);
}

void Put_Asc16(int cx, int cy, char key, char fcolor)
{
	int a, b;
	unsigned char buf[16];
	Read_Asc16(key, buf);
	for (a = 0; a<16; a++)
		for (b = 0; b<8; b++)
			if ((buf[a] >> 7 - b) & 1)
				Putpixel64k(cx + a, cy + b, fcolor);
}

void Put_Asc16_Size(int cx, int cy,int xsize, int ysize, char key,char fcolor)
{
	int a, b, o, k;
	unsigned char buf[16];
	Read_Asc16(key, buf);
	for (a = 0; a<16; a++)
		for (o = 1; o <= ysize; o++)
			for (b = 0; b<8; b++)
				for (k = 1; k <= xsize; k++)
					if ((buf[a] >> 7 - b) & 1)
						//video_buffer[(((cy+o+a*ysize)<<8)+((cy+o+a*ysize)<<6))+cx+xsize*b+k]=fcolor;
						Putpixel64k(cx + b*xsize + k, cy + o + a*ysize, fcolor);
}
/* ��ʾӢ�ĺ����� */
void put_asc(int cx, int cy ,char *s, char color, int xsize, int ysize)
{
	int index;
	for (index = 0; s[index] != 0; index++)
	{
		Put_Asc16_Size(cx + index*xsize * 8, cy, xsize, ysize, s[index], color);
	}
}
