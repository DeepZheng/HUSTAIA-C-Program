/*******************************         MOUSE.C         ********************************/
/*������������й����ʵ�ּ���ز���          
                                                        */

#include"mouse.h"
#include"color.h"
#include"draw.h"
#include"time.h"
union REGS regs;

 int mx=0,my=0,buttons=0;
 int mouse_sq[16][16]={0};
 int default1=0;


/*����꺯��*/
void Cursor(int x,int y,int color)
{

  Liney(x,y,x,y+15,color);
  Liney(x+1,y+1,x+1,y+13,color);
  Liney(x+2,y+3,x+2,y+11,color);
  Liney(x+3,y+4,x+3,y+9,color);
  Liney(x+4,y+5,x+4,y+9,color);
  Liney(x+5,y+7,x+5,y+10,color);
  Liney(x+6,y+8,x+6,y+10,color);
  Liney(x+7,y+9,x+7,y+11,color);
  Liney(x+8,y+11,x+8,y+11,color);
  Liney(x+9,y+12,x+9,y+12,color);
}
/*��ʼ����꺯�����ĸ��β�ȷ�������ƶ���Χ*/
int Initmouse(int xmi,int xma,int ymi,int yma)
{
  int retcode;
  regs.x.ax=0;
  int86(51,&regs,&regs);
  retcode=regs.x.ax;
  if(retcode==0)
  {
	return 0;
  }
  regs.x.ax=7;
  regs.x.cx=xmi;
  regs.x.dx=xma;
  int86(51,&regs,&regs);
  regs.x.ax=8;
  regs.x.cx=ymi;
  regs.x.dx=yma;
  //regs.x.bx=0;
  int86(51,&regs,&regs);
  default1=0;
  return retcode;
}
/*��ȡ���״̬����*/
int Readmouse(void)
{
  int xnew,ynew;
//  do
//  {
	regs.x.ax=3;
	int86(51,&regs,&regs);
	xnew=regs.x.cx;
	ynew=regs.x.dx;
	buttons=regs.x.bx;
	delay(10);
//  }
//  while(xnew==xx0&&ynew==yy0&&buttons==buto);
  mx=xnew;
  my=ynew;
return (0);
}
/*�������λ�ú���*/
void Newxy(void)
{
  int xx0=mx,yy0=my,x,y;
 Readmouse();
	if(default1)
	  Mouse_putbk(xx0,yy0);
	Mouse_savebk(mx,my);
	if(default1)
		Cursor(mx,my,0);
	default1=1;
	return;



}
/*����긲�Ǳ�������*/
void Mouse_savebk(int x, int y)
{
  int i,j;
  for(i=0;i<=15;i++)
  for(j=0;j<=15;j++)
  mouse_sq[i][j]=Getpixel64k(x+i,y+j);
}

/*�ָ����Ǳ�������*/
void Mouse_putbk(int x,int y)
{
  int i,j;
  for(i=0;i<=15;i++)
  for(j=0;j<=15;j++)
  Putpixel64k(x+i,y+j,mouse_sq[i][j]);
}
/*�ж�����Ƿ���ĳ������*/
int Mouse_press(int x1,int y1,int x2,int y2)
{
  if(mx>=x1&&mx<=x2&&my>=y1&&my<=y2&&buttons)
  {
	Mouse_putbk(mx,my);
	default1=0;  
	return(1);
  }
  else
  return(0);
}
/*�ж�����Ƿ���ĳ�������ⰴ��*/
int Mouse_pressother(int x1, int y1, int x2, int y2)
{
	if ((mx < x1 || mx >= x2 || my<y1 || my>y2) && buttons)
		return(1);
	else
		return(0);
}
/*�ж�����Ƿ�λ��ĳ�����Ϸ�*/
int Mouse_above(int x1,int y1,int x2,int y2)
{
  if(mx>=x1&&mx<=x2&&my>=y1&&my<=y2)
	return(1);
  else
	return(0);
}

/*�ж�����Ƿ�λ��ĳ������*/
int Mouse_aboveother(int x1, int y1, int x2, int y2)
{
	if(mx < x1 || mx >= x2 || my < y1 || my > y2)
		return(1);
	else
		return(0);
}
int Button(void)
{
	return buttons;
}

void Mouse_press_getxy(int *x,int *y)
{
	if(buttons)
	{
		*x=mx;
		*y=my;
	}
	return;
}