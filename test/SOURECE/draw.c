#include"draw.h"
//#include"svgamode.h"

/*
���ã������ߺ���
	Linex(int x1,int y1,int x2, int y2,unsigned char color)  
				��������                  ��ɫ
���ã���
���أ���
*/
void Linex(int x1,int y1,int x2, int y2,unsigned char color)      
{
  int i;
  if(x1>=1024||x2>=1024||y1>=768||y2>=768)
  return;

  if(x1<=0||x2<=0||y1<=0||y2<=0) 
  return;

  if(y1!=y2||x1>x2)     //y1Ҫ��֤��y2���
  return;
  for(i=x1;i<=x2;i++)
  Putpixel256(i,y1,color);

  return;
}

/*
���ã������ߺ���
	Liney(int x1,int y1,int x2, int y2,unsigned char color)  
				��������                  ��ɫ
���ã���
���أ���
*/
void Liney(int x1,int y1,int x2, int y2,unsigned char color)
{
  int i;
  if(x1>=1024||x2>=1024||y1>=768||y2>=768)
  return;

  if(x1<=0||x2<=0||y1<=0||y2<=0)
  return;

  if(x1!=x2||y1>y2)             //x1Ҫ��֤��x2���
  return;
  for(i=y1;i<=y2;i++)
  Putpixel256(x1,i,color);
  return;
}
/*
���ã�����һ���ұߵ�������
	Tri_R(int x,int y,int color)
���ã���
���أ���
*/
void Tri_R(int x,int y,int color)
{
  int i;
  for(i=0;i<=39;i++)
  {
	Liney(x+i,y+(i+1)/2,x+i,y+40-(i+1)/2,color);
  }
}
/*
���ã�����������
	LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode)
						��������                   ��ɫ                   ���췽ʽ
���ã���
���أ���
*/
void LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode)
{
	int i;
	if(thick<=1)return;
	if(mode==1)//��������
		for(i=-thick/2;i<=thick/2;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=1023&&x2+i<=1023)
			{
				Line(x1+i,y1,x2+i,y2,color);
			}
		}
	else if(mode==2)//��������
		for(i=-thick/2;i<=thick/2;i++)
		{
			if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
			{
				Line(x1,y1+i,x2,y2+i,color);
			}
		}
	else if(mode==3)//������
		for(i=-thick;i<=0;i++)
		{
			if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
			{
				Line(x1,y1+i,x2,y2+i,color);
			}
		}
	else if(mode==4)//������
		for(i=0;i<=thick;i++)
		{
			if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
			{
				Line(x1,y1+i,x2,y2+i,color);
			}
		}
	if(mode==5)//������
		for(i=-thick;i<=0;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=1023&&x2+i<=1023)
			{
				Line(x1+i,y1,x2+i,y2,color);
			}
		}
	if(mode==6)//������
		for(i=0;i<=thick;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=1023&&x2+i<=1023)
			{
				Line(x1+i,y1,x2+i,y2,color);
			}
		}
	
	return;
}
/*
���ã����˶�С��
	People(int x,int y,unsigned char color,char mode,float size)
			���Ͻ�����           ��ɫ         ��ʲô    ���ű���
���ã���
���أ���
*/
void People(int x,int y,unsigned char color,char mode,float size)
{

	//60*100
	if(size<=0)return;
	switch(mode)
	{
		case 0://ֹͣ
		
			Circlefill(x+25/size,y+15/size,10/size,color);//ͷ
			//Circlefill(x+30/size,y+20/size,5/size,color);//���	
			LineThick(x+25/size,y+25/size,x+25/size,y+45/size,color,10/size,1);//����
			LineThick(x+15/size,y+25/size,x+15/size,y+45/size,color,5/size,1);//����
			LineThick(x+35/size,y+25/size,x+35/size,y+45/size,color,5/size,1);//����
			LineThick(x+23/size,y+48/size,x+23/size,y+78/size,color,5/size,5);//���
			LineThick(x+27/size,y+48/size,x+27/size,y+78/size,color,5/size,6);//�ҽ�
			break;
		case 1://��
		
			Circlefill(x+20/size,y+10/size,10/size,color);//ͷ
			//Circlefill(x+30/size,y+20/size,5/size,color);//���	
			LineThick(x+30/size,y+20/size,x+40/size,y+40/size,color,10/size,1);//����

			LineThick(x+28/size,y+20/size,x+20/size,y+40/size,color,5/size,5);//ǰ��
			LineThick(x+20/size,y+40/size,x+23/size,y+36/size,color,20/size,5);//ǰ�ֱ�
			LineThick(x+40/size,y+40/size,x+30/size,y+50/size,color,7/size,5);//ǰ��
			LineThick(x+30/size,y+50/size,x+26/size,y+65/size,color,4/size,5);//ǰС��

			LineThick(x+28/size,y+10/size,x+50/size,y+10/size,color,5/size,4);//����
			LineThick(x+50/size,y+10/size,x+45/size,y+30/size,color,5/size,5);//���ֱ�
			LineThick(x+40/size,y+40/size,x+45/size,y+55/size,color,6/size,6);//���
			LineThick(x+45/size,y+55/size,x+75/size,y+30/size,color,6/size,6);//��С��
			break;
		case 2://60*100
		
			Circlefill(x+20/size,y+10/size,10/size,color);//ͷ
			//Circlefill(x+30/size,y+20/size,5/size,color);//���	
			LineThick(x+30/size,y+20/size,x+40/size,y+40/size,color,10/size,1);//����

			LineThick(x+28/size,y+20/size,x+30/size,y+40/size,color,5/size,5);//ǰ��
			LineThick(x+30/size,y+40/size,x+20/size,y+36/size,color,15/size,5);//ǰ�ֱ�
			LineThick(x+40/size,y+40/size,x+35/size,y+50/size,color,7/size,5);//ǰ��
			LineThick(x+35/size,y+50/size,x+45/size,y+65/size,color,4/size,5);//ǰС��
			break;

		
		case 3://60*100//��
		
			Circlefill(x+40-20/size,y+10/size,10/size,color);//ͷ
			//Circlefill(x+30/size,y+20/size,5/size,color);//���	
			LineThick(x+40-30/size,y+20/size,x+40-40/size,y+40/size,color,10/size,1);//����

			LineThick(x+40-28/size,y+20/size,x+40-20/size,y+40/size,color,5/size,5);//ǰ��
			LineThick(x+40-20/size,y+40/size,x+40-23/size,y+36/size,color,20/size,6);//ǰ�ֱ�
			LineThick(x+40-40/size,y+40/size,x+40-30/size,y+50/size,color,7/size,5);//ǰ��
			LineThick(x+40-30/size,y+50/size,x+40-26/size,y+65/size,color,4/size,5);//ǰС��

			LineThick(x+40-28/size,y+10/size,x+40-50/size,y+10/size,color,5/size,4);//����
			LineThick(x+40-50/size,y+10/size,x+40-45/size,y+30/size,color,5/size,5);//���ֱ�
			LineThick(x+40-40/size,y+40/size,x+40-45/size,y+55/size,color,6/size,6);//���
			LineThick(x+40-45/size,y+55/size,x+40-75/size,y+30/size,color,6/size,6);//��С��
			break;
		case 4:
		
			Circlefill(x+40-20/size,y+10/size,10/size,color);//ͷ
			//Circlefill(x+30/size,y+20/size,5/size,color);//���	
			LineThick(x+40-30/size,y+20/size,x+40-40/size,y+40/size,color,10/size,1);//����

			LineThick(x+40-28/size,y+20/size,x+40-30/size,y+40/size,color,5/size,5);//ǰ��
			LineThick(x+40-30/size,y+40/size,x+40-20/size,y+36/size,color,15/size,5);//ǰ�ֱ�
			LineThick(x+40-40/size,y+40/size,x+40-35/size,y+50/size,color,7/size,5);//ǰ��
			LineThick(x+40-35/size,y+50/size,x+40-45/size,y+65/size,color,4/size,5);//ǰС��

			break;
		case 5://����
		
			Circlefill(x+25/size,y+10/size,10/size,color);//ͷ
			//Circlefill(x+30/size,y+20/size,5/size,color);//���	
			LineThick(x+25/size,y+25/size,x+25/size,y+45/size,color,10/size,1);//����
			LineThick(x+15/size,y+25/size,x+15/size,y+45/size,color,5/size,1);//����
			LineThick(x+35/size,y+25/size,x+35/size,y+38/size,color,5/size,1);//����
			LineThick(x+23/size,y+48/size,x+23/size,y+60/size,color,5/size,5);//���
			LineThick(x+27/size,y+48/size,x+27/size,y+77/size,color,5/size,6);//�ҽ�
			break;
		case 6:
		
			Circlefill(x+25/size,y+15/size,10/size,color);//ͷ
			LineThick(x+25/size,y+25/size,x+25/size,y+45/size,color,10/size,1);//����
			LineThick(x+15/size,y+25/size,x+15/size,y+38/size,color,5/size,1);//����
			LineThick(x+35/size,y+25/size,x+35/size,y+45/size,color,5/size,1);//����
			LineThick(x+23/size,y+48/size,x+23/size,y+78/size,color,5/size,5);//���
			LineThick(x+27/size,y+48/size,x+27/size,y+60/size,color,5/size,6);//�ҽ�
			break;
		case 7://��
			Circlefill(x+20/size,y+15/size,10/size,color);//ͷ
			LineThick(x+30/size,y+20/size,x+40/size,y+40/size,color,10/size,1);//����

			LineThick(x+28/size,y+20/size,x+30/size,y+40/size,color,5/size,5);//ǰ��
			LineThick(x+30/size,y+40/size,x+20/size,y+36/size,color,15/size,5);//ǰ�ֱ�
			LineThick(x+40/size,y+40/size,x+35/size,y+50/size,color,7/size,5);//ǰ��
			Circlefill(x+15/size,y+55/size,14/size,color);
			Circlefill(x+15/size,y+55/size,10/size,31);
			LineThick(x+35/size,y+50/size,x+45/size,y+65/size,color,4/size,5);//ǰС��
			Circlefill(x+55/size,y+55/size,14/size,color);
			Circlefill(x+55/size,y+55/size,10/size,31);
			break;
		case 8:
			Circlefill(x+20/size,y+10/size,10/size,color);//ͷ
			LineThick(x+30/size,y+20/size,x+40/size,y+40/size,color,10/size,1);//����

			LineThick(x+28/size,y+20/size,x+30/size,y+40/size,color,5/size,5);//ǰ��
			LineThick(x+30/size,y+40/size,x+20/size,y+36/size,color,15/size,5);//ǰ�ֱ�
			LineThick(x+40/size,y+40/size,x+30/size,y+50/size,color,7/size,5);//ǰ��
			Circlefill(x+15/size,y+55/size,14/size,color);
			Circlefill(x+15/size,y+55/size,10/size,31);
			LineThick(x+30/size,y+50/size,x+26/size,y+65/size,color,4/size,5);//ǰС��
			Circlefill(x+55/size,y+55/size,14/size,color);
			Circlefill(x+55/size,y+55/size,10/size,31);
			break;
		case 9://�ҳ�
			Circlefill(x+40-20/size,y+15/size,10/size,color);//ͷ	
			LineThick(x+40-30/size,y+20/size,x+40-40/size,y+40/size,color,10/size,1);//����

			LineThick(x+40-28/size,y+20/size,x+40-30/size,y+40/size,color,5/size,5);//ǰ��
			LineThick(x+40-30/size,y+40/size,x+40-20/size,y+36/size,color,15/size,5);//ǰ�ֱ�
			LineThick(x+40-40/size,y+40/size,x+40-30/size,y+50/size,color,7/size,5);//ǰ��
			LineThick(x+40-30/size,y+50/size,x+40-26/size,y+65/size,color,4/size,5);//ǰС��
			Circlefill(x+40-15/size,y+55/size,14/size,color);
			Circlefill(x+40-15/size,y+55/size,10/size,31);
			Circlefill(x+40-55/size,y+55/size,14/size,color);
			Circlefill(x+40-55/size,y+55/size,10/size,31);
			break;
		case 10:
			Circlefill(x+40-20/size,y+10/size,10/size,color);//ͷ
			LineThick(x+40-30/size,y+20/size,x+40-40/size,y+40/size,color,10/size,1);//����

			LineThick(x+40-28/size,y+20/size,x+40-30/size,y+40/size,color,5/size,5);//ǰ��
			LineThick(x+40-30/size,y+40/size,x+40-20/size,y+36/size,color,15/size,5);//ǰ�ֱ�
			LineThick(x+40-40/size,y+40/size,x+40-35/size,y+50/size,color,7/size,5);//ǰ��
			LineThick(x+40-35/size,y+50/size,x+40-45/size,y+65/size,color,4/size,5);//ǰС��
			Circlefill(x+40-15/size,y+55/size,14/size,color);
			Circlefill(x+40-15/size,y+55/size,10/size,31);
			Circlefill(x+40-55/size,y+55/size,14/size,color);
			Circlefill(x+40-55/size,y+55/size,10/size,31);
			break;
		case 11://���³�
			Circlefill(x+25/size,y+10/size,10/size,color);//ͷ
			//Circlefill(x+30/size,y+20/size,5/size,color);//���	
			LineThick(x+25/size,y+25/size,x+25/size,y+45/size,color,10/size,1);//����
			LineThick(x+15/size,y+25/size,x+15/size,y+38/size,color,5/size,1);//����
			LineThick(x+35/size,y+25/size,x+35/size,y+38/size,color,5/size,1);//����
			LineThick(x+19/size,y+48/size,x+19/size,y+60/size,color,5/size,5);//���
			LineThick(x+30/size,y+48/size,x+30/size,y+72/size,color,5/size,6);//�ҽ�
			
			LineThick(x+25/size,y+48/size,x+25/size,y+77/size,color,6/size,1);//����
			break;
		case 12:
			Circlefill(x+25/size,y+15/size,10/size,color);//ͷ
			LineThick(x+25/size,y+25/size,x+25/size,y+45/size,color,10/size,1);//����
			LineThick(x+15/size,y+25/size,x+15/size,y+38/size,color,5/size,1);//����
			LineThick(x+35/size,y+25/size,x+35/size,y+38/size,color,5/size,1);//����
			LineThick(x+19/size,y+48/size,x+19/size,y+72/size,color,5/size,5);//���
			LineThick(x+30/size,y+48/size,x+30/size,y+60/size,color,5/size,6);//�ҽ�
			
				LineThick(x+25/size,y+48/size,x+25/size,y+77/size,color,6/size,1);//����
			break;
		default: break;

	}
	return;
}
/*
���ã��������
	Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned char color)
			�Խ�����                      ������������    ��ɫ
���ã���
���أ���
*/
void Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned char color)
{
	if(x3>x2&&y3<y1)//������ƫ��
	{
		Bar(x1,y1,x2,y2,color+1);
		LineThick( x2, y1, x3, y3, color-1, y2-y1, 4);
		LineThick( x2, y1, x3, y3, color, x2-x1,5);
	}
	if(x3>x2&&y3>y2)//��������
	{
		Bar(x1,y1,x2,y2,color+1);
		LineThick( x2, y2, x3, y3, color-1, y2-y1, 3);
		LineThick( x2, y2, x3,y3, color, x2-x1,5);
	}
	if(x3<x1&&y3<y1)//������ƫ��
	{
		Bar(x1,y1,x2,y2,color+1);
		LineThick( x1, y1, x3, y3, color-1, y2-y1, 4);
		LineThick( x1, y1, x3,y3, color, x2-x1,6);
	}
	if(x3<x1&&y3>y2)//������ƫ��
	{
		Bar(x1,y1,x2,y2,color+1);
		LineThick( x1, y2, x3, y3, color-1, y2-y1, 3);
		LineThick( x1, y2, x3,y3, color, x2-x1,6);
	}
	return;
}
/*
���ã����μ���Ӱ
	Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor)
					�Խ�����               ������ɫ                  ��Ӱ��ɫ
���ã���
���أ���
*/
void Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor)
{
	Bar( x1+5, y1+5, x2+5, y2+5,shacolor);
	Bar( x1, y1, x2, y2,precolor);
	return;
}
/*
���ã�ƽ���ı��μ���Ӱ
	LineThickSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick,int mode)
					�Խ�����               ������ɫ                  ��Ӱ��ɫ              �������  ���췽ʽ
���ã���
���أ���
*/
void LineThickSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick,int mode)
{
	LineThick(x1+5,y1+5, x2+5, y2+5,shacolor,thick,mode);
	LineThick(x1,y1, x2, y2,precolor,thick,mode);
	return;
}
void FrameSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick)
{
	Frame(x1+5,y1+5, x2+5,y2+5,shacolor,thick);
	Frame(x1,y1, x2,y2,precolor,thick);
	return;
}
//Բ����Ӱ
void CirclefillSha(int x,int y,int r,unsigned char precolor,unsigned char shacolor)
{
	Circlefill(x+10,y+10,r,shacolor);
	Circlefill(x,y,r,precolor);
	return;
}
//��
void Frame(int x1,int y1,int x2,int y2,unsigned char color,int thick)
{
	if(x1<=0||x1>=1024||x2<=0||x2>=1024||y1<=0||y1>=768||y2<=0||y2>=768)return;
	if(x1>=x2||y1>=y2)return;
	
	Bar(x1,y1,x2,y1+thick,color);
	Bar(x1,y2-thick,x2,y2,color);
	Bar(x1,y1,x1+thick,y2,color);
	Bar(x2-thick,y1,x2,y2,color);
	return;
}
void Arrow(int x,int y,unsigned char color,int mode)
{
	int i,k=5;
	if(mode==1)//x��y,x+50,y+50
	{
		Bar(x+15+k,y+25+k,x+35+k,y+30+k,25);
		Bar(x+30+k,y+5+k,x+35+k,y+30+k,25);
		Bar(x+10+k,y+5+k,x+35+k,y+10+k,25);
		for(i=1;i<=10;i++)
		{
			Liney(x+10-i+k,y-2+i+k,x+10-i+k,y+18-i+k,25);
		}
		Bar(x+15,y+25,x+35,y+30,color);
		Bar(x+30,y+5,x+35,y+30,color);
		Bar(x+10,y+5,x+35,y+10,color);
		for(i=1;i<=10;i++)
		{
			Liney(x+10-i,y-2+i,x+10-i,y+18-i,color);
		}
		
	}
	else if(mode==2)//���μ�ͷ
	{
		LineThick(x+5,y+5, x+20+5, y+20+5,25,10,6);
		LineThick(x+5,y+40+5, x+20+5, y+20+5,25,10,6);
		LineThick(x,y, x+20, y+20,color,10,6);
		LineThick(x,y+40, x+20, y+20,color,10,6);
	}
	return;
}
