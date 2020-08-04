#include"draw.h"
//#include"svgamode.h"

/*
作用：画横线函数
	Linex(int x1,int y1,int x2, int y2,unsigned char color)  
				两端坐标                  颜色
调用：无
返回：无
*/
void Linex(int x1,int y1,int x2, int y2,unsigned char color)      
{
  int i;
  if(x1>=1024||x2>=1024||y1>=768||y2>=768)
  return;

  if(x1<=0||x2<=0||y1<=0||y2<=0) 
  return;

  if(y1!=y2||x1>x2)     //y1要保证和y2相等
  return;
  for(i=x1;i<=x2;i++)
  Putpixel256(i,y1,color);

  return;
}

/*
作用：画竖线函数
	Liney(int x1,int y1,int x2, int y2,unsigned char color)  
				两端坐标                  颜色
调用：无
返回：无
*/
void Liney(int x1,int y1,int x2, int y2,unsigned char color)
{
  int i;
  if(x1>=1024||x2>=1024||y1>=768||y2>=768)
  return;

  if(x1<=0||x2<=0||y1<=0||y2<=0)
  return;

  if(x1!=x2||y1>y2)             //x1要保证和x2相等
  return;
  for(i=y1;i<=y2;i++)
  Putpixel256(x1,i,color);
  return;
}
/*
作用：画出一个右边的三角形
	Tri_R(int x,int y,int color)
调用：无
返回：无
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
作用：画出粗线条
	LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode)
						两端坐标                   颜色                   拉伸方式
调用：无
返回：无
*/
void LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode)
{
	int i;
	if(thick<=1)return;
	if(mode==1)//左右拉伸
		for(i=-thick/2;i<=thick/2;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=1023&&x2+i<=1023)
			{
				Line(x1+i,y1,x2+i,y2,color);
			}
		}
	else if(mode==2)//上下拉伸
		for(i=-thick/2;i<=thick/2;i++)
		{
			if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
			{
				Line(x1,y1+i,x2,y2+i,color);
			}
		}
	else if(mode==3)//上拉伸
		for(i=-thick;i<=0;i++)
		{
			if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
			{
				Line(x1,y1+i,x2,y2+i,color);
			}
		}
	else if(mode==4)//下拉伸
		for(i=0;i<=thick;i++)
		{
			if(y1+i>=1&&y2+i>=1&&y1+i<=767&&y2+i<=767)
			{
				Line(x1,y1+i,x2,y2+i,color);
			}
		}
	if(mode==5)//左拉伸
		for(i=-thick;i<=0;i++)
		{
			if(x1+i>=1&&x2+i>=1&&x1+i<=1023&&x2+i<=1023)
			{
				Line(x1+i,y1,x2+i,y2,color);
			}
		}
	if(mode==6)//右拉伸
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
作用：画运动小人
	People(int x,int y,unsigned char color,char mode,float size)
			左上角坐标           颜色         画什么    缩放倍数
调用：无
返回：无
*/
void People(int x,int y,unsigned char color,char mode,float size)
{

	//60*100
	if(size<=0)return;
	switch(mode)
	{
		case 0://停止
		
			Circlefill(x+25/size,y+15/size,10/size,color);//头
			//Circlefill(x+30/size,y+20/size,5/size,color);//肩膀	
			LineThick(x+25/size,y+25/size,x+25/size,y+45/size,color,10/size,1);//躯干
			LineThick(x+15/size,y+25/size,x+15/size,y+45/size,color,5/size,1);//左手
			LineThick(x+35/size,y+25/size,x+35/size,y+45/size,color,5/size,1);//右手
			LineThick(x+23/size,y+48/size,x+23/size,y+78/size,color,5/size,5);//左脚
			LineThick(x+27/size,y+48/size,x+27/size,y+78/size,color,5/size,6);//右脚
			break;
		case 1://左
		
			Circlefill(x+20/size,y+10/size,10/size,color);//头
			//Circlefill(x+30/size,y+20/size,5/size,color);//肩膀	
			LineThick(x+30/size,y+20/size,x+40/size,y+40/size,color,10/size,1);//躯干

			LineThick(x+28/size,y+20/size,x+20/size,y+40/size,color,5/size,5);//前手
			LineThick(x+20/size,y+40/size,x+23/size,y+36/size,color,20/size,5);//前手臂
			LineThick(x+40/size,y+40/size,x+30/size,y+50/size,color,7/size,5);//前脚
			LineThick(x+30/size,y+50/size,x+26/size,y+65/size,color,4/size,5);//前小腿

			LineThick(x+28/size,y+10/size,x+50/size,y+10/size,color,5/size,4);//后手
			LineThick(x+50/size,y+10/size,x+45/size,y+30/size,color,5/size,5);//后手臂
			LineThick(x+40/size,y+40/size,x+45/size,y+55/size,color,6/size,6);//后脚
			LineThick(x+45/size,y+55/size,x+75/size,y+30/size,color,6/size,6);//后小腿
			break;
		case 2://60*100
		
			Circlefill(x+20/size,y+10/size,10/size,color);//头
			//Circlefill(x+30/size,y+20/size,5/size,color);//肩膀	
			LineThick(x+30/size,y+20/size,x+40/size,y+40/size,color,10/size,1);//躯干

			LineThick(x+28/size,y+20/size,x+30/size,y+40/size,color,5/size,5);//前手
			LineThick(x+30/size,y+40/size,x+20/size,y+36/size,color,15/size,5);//前手臂
			LineThick(x+40/size,y+40/size,x+35/size,y+50/size,color,7/size,5);//前脚
			LineThick(x+35/size,y+50/size,x+45/size,y+65/size,color,4/size,5);//前小腿
			break;

		
		case 3://60*100//右
		
			Circlefill(x+40-20/size,y+10/size,10/size,color);//头
			//Circlefill(x+30/size,y+20/size,5/size,color);//肩膀	
			LineThick(x+40-30/size,y+20/size,x+40-40/size,y+40/size,color,10/size,1);//躯干

			LineThick(x+40-28/size,y+20/size,x+40-20/size,y+40/size,color,5/size,5);//前手
			LineThick(x+40-20/size,y+40/size,x+40-23/size,y+36/size,color,20/size,6);//前手臂
			LineThick(x+40-40/size,y+40/size,x+40-30/size,y+50/size,color,7/size,5);//前脚
			LineThick(x+40-30/size,y+50/size,x+40-26/size,y+65/size,color,4/size,5);//前小腿

			LineThick(x+40-28/size,y+10/size,x+40-50/size,y+10/size,color,5/size,4);//后手
			LineThick(x+40-50/size,y+10/size,x+40-45/size,y+30/size,color,5/size,5);//后手臂
			LineThick(x+40-40/size,y+40/size,x+40-45/size,y+55/size,color,6/size,6);//后脚
			LineThick(x+40-45/size,y+55/size,x+40-75/size,y+30/size,color,6/size,6);//后小腿
			break;
		case 4:
		
			Circlefill(x+40-20/size,y+10/size,10/size,color);//头
			//Circlefill(x+30/size,y+20/size,5/size,color);//肩膀	
			LineThick(x+40-30/size,y+20/size,x+40-40/size,y+40/size,color,10/size,1);//躯干

			LineThick(x+40-28/size,y+20/size,x+40-30/size,y+40/size,color,5/size,5);//前手
			LineThick(x+40-30/size,y+40/size,x+40-20/size,y+36/size,color,15/size,5);//前手臂
			LineThick(x+40-40/size,y+40/size,x+40-35/size,y+50/size,color,7/size,5);//前脚
			LineThick(x+40-35/size,y+50/size,x+40-45/size,y+65/size,color,4/size,5);//前小腿

			break;
		case 5://上下
		
			Circlefill(x+25/size,y+10/size,10/size,color);//头
			//Circlefill(x+30/size,y+20/size,5/size,color);//肩膀	
			LineThick(x+25/size,y+25/size,x+25/size,y+45/size,color,10/size,1);//躯干
			LineThick(x+15/size,y+25/size,x+15/size,y+45/size,color,5/size,1);//左手
			LineThick(x+35/size,y+25/size,x+35/size,y+38/size,color,5/size,1);//右手
			LineThick(x+23/size,y+48/size,x+23/size,y+60/size,color,5/size,5);//左脚
			LineThick(x+27/size,y+48/size,x+27/size,y+77/size,color,5/size,6);//右脚
			break;
		case 6:
		
			Circlefill(x+25/size,y+15/size,10/size,color);//头
			LineThick(x+25/size,y+25/size,x+25/size,y+45/size,color,10/size,1);//躯干
			LineThick(x+15/size,y+25/size,x+15/size,y+38/size,color,5/size,1);//左手
			LineThick(x+35/size,y+25/size,x+35/size,y+45/size,color,5/size,1);//右手
			LineThick(x+23/size,y+48/size,x+23/size,y+78/size,color,5/size,5);//左脚
			LineThick(x+27/size,y+48/size,x+27/size,y+60/size,color,5/size,6);//右脚
			break;
		case 7://左车
			Circlefill(x+20/size,y+15/size,10/size,color);//头
			LineThick(x+30/size,y+20/size,x+40/size,y+40/size,color,10/size,1);//躯干

			LineThick(x+28/size,y+20/size,x+30/size,y+40/size,color,5/size,5);//前手
			LineThick(x+30/size,y+40/size,x+20/size,y+36/size,color,15/size,5);//前手臂
			LineThick(x+40/size,y+40/size,x+35/size,y+50/size,color,7/size,5);//前脚
			Circlefill(x+15/size,y+55/size,14/size,color);
			Circlefill(x+15/size,y+55/size,10/size,31);
			LineThick(x+35/size,y+50/size,x+45/size,y+65/size,color,4/size,5);//前小腿
			Circlefill(x+55/size,y+55/size,14/size,color);
			Circlefill(x+55/size,y+55/size,10/size,31);
			break;
		case 8:
			Circlefill(x+20/size,y+10/size,10/size,color);//头
			LineThick(x+30/size,y+20/size,x+40/size,y+40/size,color,10/size,1);//躯干

			LineThick(x+28/size,y+20/size,x+30/size,y+40/size,color,5/size,5);//前手
			LineThick(x+30/size,y+40/size,x+20/size,y+36/size,color,15/size,5);//前手臂
			LineThick(x+40/size,y+40/size,x+30/size,y+50/size,color,7/size,5);//前脚
			Circlefill(x+15/size,y+55/size,14/size,color);
			Circlefill(x+15/size,y+55/size,10/size,31);
			LineThick(x+30/size,y+50/size,x+26/size,y+65/size,color,4/size,5);//前小腿
			Circlefill(x+55/size,y+55/size,14/size,color);
			Circlefill(x+55/size,y+55/size,10/size,31);
			break;
		case 9://右车
			Circlefill(x+40-20/size,y+15/size,10/size,color);//头	
			LineThick(x+40-30/size,y+20/size,x+40-40/size,y+40/size,color,10/size,1);//躯干

			LineThick(x+40-28/size,y+20/size,x+40-30/size,y+40/size,color,5/size,5);//前手
			LineThick(x+40-30/size,y+40/size,x+40-20/size,y+36/size,color,15/size,5);//前手臂
			LineThick(x+40-40/size,y+40/size,x+40-30/size,y+50/size,color,7/size,5);//前脚
			LineThick(x+40-30/size,y+50/size,x+40-26/size,y+65/size,color,4/size,5);//前小腿
			Circlefill(x+40-15/size,y+55/size,14/size,color);
			Circlefill(x+40-15/size,y+55/size,10/size,31);
			Circlefill(x+40-55/size,y+55/size,14/size,color);
			Circlefill(x+40-55/size,y+55/size,10/size,31);
			break;
		case 10:
			Circlefill(x+40-20/size,y+10/size,10/size,color);//头
			LineThick(x+40-30/size,y+20/size,x+40-40/size,y+40/size,color,10/size,1);//躯干

			LineThick(x+40-28/size,y+20/size,x+40-30/size,y+40/size,color,5/size,5);//前手
			LineThick(x+40-30/size,y+40/size,x+40-20/size,y+36/size,color,15/size,5);//前手臂
			LineThick(x+40-40/size,y+40/size,x+40-35/size,y+50/size,color,7/size,5);//前脚
			LineThick(x+40-35/size,y+50/size,x+40-45/size,y+65/size,color,4/size,5);//前小腿
			Circlefill(x+40-15/size,y+55/size,14/size,color);
			Circlefill(x+40-15/size,y+55/size,10/size,31);
			Circlefill(x+40-55/size,y+55/size,14/size,color);
			Circlefill(x+40-55/size,y+55/size,10/size,31);
			break;
		case 11://上下车
			Circlefill(x+25/size,y+10/size,10/size,color);//头
			//Circlefill(x+30/size,y+20/size,5/size,color);//肩膀	
			LineThick(x+25/size,y+25/size,x+25/size,y+45/size,color,10/size,1);//躯干
			LineThick(x+15/size,y+25/size,x+15/size,y+38/size,color,5/size,1);//左手
			LineThick(x+35/size,y+25/size,x+35/size,y+38/size,color,5/size,1);//右手
			LineThick(x+19/size,y+48/size,x+19/size,y+60/size,color,5/size,5);//左脚
			LineThick(x+30/size,y+48/size,x+30/size,y+72/size,color,5/size,6);//右脚
			
			LineThick(x+25/size,y+48/size,x+25/size,y+77/size,color,6/size,1);//车轮
			break;
		case 12:
			Circlefill(x+25/size,y+15/size,10/size,color);//头
			LineThick(x+25/size,y+25/size,x+25/size,y+45/size,color,10/size,1);//躯干
			LineThick(x+15/size,y+25/size,x+15/size,y+38/size,color,5/size,1);//左手
			LineThick(x+35/size,y+25/size,x+35/size,y+38/size,color,5/size,1);//右手
			LineThick(x+19/size,y+48/size,x+19/size,y+72/size,color,5/size,5);//左脚
			LineThick(x+30/size,y+48/size,x+30/size,y+60/size,color,5/size,6);//右脚
			
				LineThick(x+25/size,y+48/size,x+25/size,y+77/size,color,6/size,1);//车轮
			break;
		default: break;

	}
	return;
}
/*
作用：立体矩形
	Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned char color)
			对角坐标                      第三个点坐标    颜色
调用：无
返回：无
*/
void Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned char color)
{
	if(x3>x2&&y3<y1)//往右上偏移
	{
		Bar(x1,y1,x2,y2,color+1);
		LineThick( x2, y1, x3, y3, color-1, y2-y1, 4);
		LineThick( x2, y1, x3, y3, color, x2-x1,5);
	}
	if(x3>x2&&y3>y2)//往右下移
	{
		Bar(x1,y1,x2,y2,color+1);
		LineThick( x2, y2, x3, y3, color-1, y2-y1, 3);
		LineThick( x2, y2, x3,y3, color, x2-x1,5);
	}
	if(x3<x1&&y3<y1)//往左上偏移
	{
		Bar(x1,y1,x2,y2,color+1);
		LineThick( x1, y1, x3, y3, color-1, y2-y1, 4);
		LineThick( x1, y1, x3,y3, color, x2-x1,6);
	}
	if(x3<x1&&y3>y2)//往左下偏移
	{
		Bar(x1,y1,x2,y2,color+1);
		LineThick( x1, y2, x3, y3, color-1, y2-y1, 3);
		LineThick( x1, y2, x3,y3, color, x2-x1,6);
	}
	return;
}
/*
作用：矩形加阴影
	Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor)
					对角坐标               矩形颜色                  阴影颜色
调用：无
返回：无
*/
void Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor)
{
	Bar( x1+5, y1+5, x2+5, y2+5,shacolor);
	Bar( x1, y1, x2, y2,precolor);
	return;
}
/*
作用：平行四边形加阴影
	LineThickSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick,int mode)
					对角坐标               矩形颜色                  阴影颜色              拉伸距离  拉伸方式
调用：无
返回：无
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
//圆加阴影
void CirclefillSha(int x,int y,int r,unsigned char precolor,unsigned char shacolor)
{
	Circlefill(x+10,y+10,r,shacolor);
	Circlefill(x,y,r,precolor);
	return;
}
//框
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
	if(mode==1)//x，y,x+50,y+50
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
	else if(mode==2)//矩形箭头
	{
		LineThick(x+5,y+5, x+20+5, y+20+5,25,10,6);
		LineThick(x+5,y+40+5, x+20+5, y+20+5,25,10,6);
		LineThick(x,y, x+20, y+20,color,10,6);
		LineThick(x,y+40, x+20, y+20,color,10,6);
	}
	return;
}
