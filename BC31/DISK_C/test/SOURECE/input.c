#include "hanzi.h"
#include "MOUSE.h"
#include "draw.h"
#include <bios.h>
#include <stdio.h>
#include"tstruct.h"
#include "color.h"
#include <stdlib.h>


/*�հ׿��������ַ���ע������ʱ�������ƿ�����Ӱ���ַ���ʾ��ɾ��*/
int Input(int xmin,int ymin,int xmax,int ymax,int n,char *s,int color,int dx,int dy, int len,char secret)
{

	int get_char=0,i=0;
	dy++;
	dy--;
	while(bioskey(1))//ɾ��֮ǰ�����Ұ��������ַ�
	{
		getch();
	}
	
	while(1)
	{
		if(Mouse_pressother(xmin,ymin,xmax,ymax)!=1)//���û�е����������
		{
			while(1)
			{
				Newxy();
				delay(10);
				Liney(xmin+n*8*dx+2,ymin,xmin+n*8*dx+2,ymax,0);
				delay(10);
				Liney(xmin+n*8*dx+2,ymin,xmin+n*8*dx+2,ymax,color);
				
				if(Mouse_pressother(xmin,ymin,xmax,ymax)==1)
					return n;
				
				if(bioskey(1))
				{
					get_char=bioskey(0);
					
					if(get_char==0x0e08&&n>0)//�����˸��Ҵ����ַ�
					{
						for(i=xmin+n*8*dx;i>=xmin+(n-1)*8*dx;i--)//�˸񸲸ǣ�8*dx��hanzi.h����������������
						{
							Liney(i,ymin,i,ymax,color);
						}
						n=n-1;
					}
					else
						if(get_char==0x1c0d)//�س��˳�����
							return n;
						else 	if(n>=len)//�������С����ÿ���������len���ַ�
						{
							return n;
						}
					
						else//�˴���ȱδ���������ַ��ж�,δ���ӳ���xmax�ж�
						{
							//put_asc(300+n*8,300+n*10,"A",0,10,10);//����
							//n++;//����
							switch(get_char)
							{
								case 0x0231://�����̼�ֵ
								put_asc(xmin+n*8*dx,ymin,"1",0,dx,dx);
								s[n] = '1';
									break;
								case 0x0332:
								put_asc(xmin+n*8*dx,ymin,"2",0,dx,dx);
								s[n] = '2';
									break;
								case 0x0433:
								put_asc(xmin+n*8*dx,ymin,"3",0,dx,dx);
								s[n] = '3';
									break;
								case 0x0534:
								put_asc(xmin+n*8*dx,ymin,"4",0,dx,dx);
								s[n] = '4';
									break;
								case 0x0635:
								put_asc(xmin+n*8*dx,ymin,"5",0,dx,dx);
								s[n] = '5';
									break;
								case 0x0736:
								put_asc(xmin+n*8*dx,ymin,"6",0,dx,dx);
								s[n] = '6';
									break;
								case 0x0837:
								put_asc(xmin+n*8*dx,ymin,"7",0,dx,dx);
								s[n] = '7';
									break;
								case 0x0938:
								put_asc(xmin+n*8*dx,ymin,"8",0,dx,dx);
								s[n] = '8';
									break;
								case 0x0a39:
								put_asc(xmin+n*8*dx,ymin,"9",0,dx,dx);
								s[n] = '9';
									break;
								case 0x0b30:
								put_asc(xmin+n*8*dx,ymin,"0",0,dx,dx);
								s[n] = '0';
									break;
								case 0x1071:
								put_asc(xmin+n*8*dx,ymin,"q",0,dx,dx);
								s[n] = 'q';
									break;
								case 0x1177:
								put_asc(xmin+n*8*dx,ymin,"w",0,dx,dx);
								s[n] = 'w';
									break;
								case 0x1265:
								put_asc(xmin+n*8*dx,ymin,"e",0,dx,dx);
								s[n] = 'e';
									break;
								case 0x1372:
								put_asc(xmin+n*8*dx,ymin,"r",0,dx,dx);
								s[n] = 'r';
									break;
								case 0x1474:
								put_asc(xmin+n*8*dx,ymin,"t",0,dx,dx);
								s[n] = 't';
									break;
								case 0x1579:
								put_asc(xmin+n*8*dx,ymin,"y",0,dx,dx);
								s[n] = 'y';
									break;
								case 0x1675:
								put_asc(xmin+n*8*dx,ymin,"u",0,dx,dx);
								s[n] = 'u';
									break;
								case 0x1769:
								put_asc(xmin+n*8*dx,ymin,"i",0,dx,dx);
								s[n] = 'i';
									break;
								case 0x186f:
								put_asc(xmin+n*8*dx,ymin,"o",0,dx,dx);
								s[n] = 'o';
									break;
								case 0x1970:
								put_asc(xmin+n*8*dx,ymin,"p",0,dx,dx);
								s[n] = 'p';
									break;
								case 0x1e61:
								put_asc(xmin+n*8*dx,ymin,"a",0,dx,dx);
								s[n] = 'a';
									break;
								case 0x1f73:
								put_asc(xmin+n*8*dx,ymin,"s",0,dx,dx);
								s[n] = 's';
									break;
								case 0x2064:
								put_asc(xmin+n*8*dx,ymin,"d",0,dx,dx);
								s[n] = 'd';
									break;
								case 0x2166:
								put_asc(xmin+n*8*dx,ymin,"f",0,dx,dx);
								s[n] = 'f';
									break;
								case 0x2267:
								put_asc(xmin+n*8*dx,ymin,"g",0,dx,dx);
								s[n] = 'g';
									break;
								case 0x2368:
								put_asc(xmin+n*8*dx,ymin,"h",0,dx,dx);
								s[n] = 'h';
									break; 
								case 0x246a:
								put_asc(xmin+n*8*dx,ymin,"j",0,dx,dx);
								s[n] = 'j';
									break;
								case 0x256b:
								put_asc(xmin+n*8*dx,ymin,"k",0,dx,dx);
								s[n] = 'k';
									break;
								case 0x266c:
								put_asc(xmin+n*8*dx,ymin,"l",0,dx,dx);
								s[n] = 'l';
									break;
								case 0x2c7a:
								put_asc(xmin+n*8*dx,ymin,"z",0,dx,dx);
								s[n] = 'z';
									break;
								case 0x2d78:
								put_asc(xmin+n*8*dx,ymin,"x",0,dx,dx);
								s[n] = 'x';
									break;
								case 0x2e63:
								put_asc(xmin+n*8*dx,ymin,"c",0,dx,dx);
								s[n] = 'c';
									break;
								case 0x2f76:
								put_asc(xmin+n*8*dx,ymin,"v",0,dx,dx);
								s[n] = 'v';
									break;
								case 0x3062:
								put_asc(xmin+n*8*dx,ymin,"b",0,dx,dx);
								s[n] = 'b';
									break;
								case 0x316e:
								put_asc(xmin+n*8*dx,ymin,"n",0,dx,dx);
								s[n] = 'n';
									break;
								case 0x326d:
								put_asc(xmin+n*8*dx,ymin,"m",0,dx,dx);
								s[n] = 'm';
									break;
								case 0x0c2d:
								put_asc(xmin+n*8*dx,ymin,"-",0,dx,dx);
								s[n] = '-';
									break;
								case 0x4f31://��е�����ұ�С����
								put_asc(xmin+n*8*dx,ymin,"1",0,dx,dx);
								s[n] = '1';
									break;
								case 0x5032:
								put_asc(xmin+n*8*dx,ymin,"2",0,dx,dx);
								s[n] = '2';
									break;
								case 0x5133:
								put_asc(xmin+n*8*dx,ymin,"3",0,dx,dx);
								s[n] = '3';
									break;
								case 0x4b34:
								put_asc(xmin+n*8*dx,ymin,"4",0,dx,dx);
								s[n] = '4';
									break;
								case 0x4c35:
								put_asc(xmin+n*8*dx,ymin,"5",0,dx,dx);
								s[n] = '5';
									break;
								case 0x4d36:
								put_asc(xmin+n*8*dx,ymin,"6",0,dx,dx);
								s[n] = '6';
									break;
								case 0x4737:
								put_asc(xmin+n*8*dx,ymin,"7",0,dx,dx);
								s[n] = '7';
									break;
								case 0x4838:
								put_asc(xmin+n*8*dx,ymin,"8",0,dx,dx);
								s[n] = '8';
									break;
								case 0x4939:
								put_asc(xmin+n*8*dx,ymin,"9",0,dx,dx);
								s[n] = '9';
									break;
								case 0x5230:
								put_asc(xmin+n*8*dx,ymin,"0",0,dx,dx);
								s[n] = '0';
									break;
								case 0x4a2d:
								put_asc(xmin+n*8*dx,ymin,"-",0,dx,dx);
								s[n] = '-';
									break;
								default :
								n--;
									break;
						
							}
						if(secret==1&&get_char!=0x0e08)//����
						{
							for(i=xmin+(n+1)*8*dx;i>=xmin+n*8*dx;i--)//�˸񸲸ǣ�8*dx��hanzi.h����������������
							{
								Liney(i,ymin,i,ymax,color);
							}
							put_asc(xmin+n*8*dx,ymin,"*",0,dx,dx);
						}
						n++;//�ַ���+1
                          
						}
					if(Mouse_pressother(xmin,ymin,xmax,ymax)==1)
					return n;
		
				}
				
			}
		}
		else
			return n;//�����ַ���
	}
	
}
