/**********************************************************
Copyright (C) 2015 姜君 王鹏晖.
File name:		SVGAmode.H
Author:			姜君
Version：		2.0
Date：			2015/8/12
Description：	SVGA显示模式头文件，包括该模式下基本的初始化函数、操作函数、画图函数、读图函数等的实现。
				宏处理在SVGAmode.h中。
				
				因为宏定义的缘故，严禁在其他文件中定义名称为R、G、B、r、g、b的变量！
				为了与graphics.h中的函数区别，所有自写函数名首字母大写！
				所有自写函数均以屏幕参考系为准！
				
				函数Line、Circle、Circlefill为资料代码，不计入工作量！
				
				对本文件的修改请及时按如下格式记录在下面（每个修改单独列出）！

Function List：
	1.void SetSVGA256(void);
		SVGA显示模式设置函数，设为0x105
		
	2.void SetSVGA64k(void);
		SVGA显示模式设置函数，设为0x117
	
	3.unsigned int GetSVGA(void);
		获取SVGA显示模式号bx
		
	4.void Selectpage(register char page);
		带判断功能的换页函数，解决读写显存时跨段寻址问题
		
	5.void Putpixel256(int x, int y, unsigned char color);
		画点函数，其他画图函数的基础，仅适用于0x105模式！
		
	6.void Putpixel64k(int x, int y, unsigned int color);
		画点函数，其他画图函数的基础，仅适用于0x117模式！
		
	7.int Putbmp256(int x, int y, const char * path);
		8位非压缩bmp图定位显示函数
		
	8.int Putbmp64k(int x, int y, const char * path);
		24位非压缩bmp图定位显示函数
	
	9.void Xorpixel(int x, int y, unsigned char color);
		按位异或画点函数
		
	10.void Horizline(int x, int y, int width, unsigned char color);
		画水平线函数
		
	11.void Line(int x1, int y1, int x2, int y2, unsigned char color);
		画一般直线函数
		
	12.void Bar(int x1, int y1, int x2, int y2, unsigned char color);
		画矩形块函数
		
	13.void Circle(int xc, int yc, int radius, unsigned char color);
		画圆圈函数
		
	14.void Circlefill(int xc, int yc, int radius, unsigned char color);
		画实心圆函数

History：		对本文件的修改请及时按如下格式记录在下面（每个修改单独列出）！
	Example：	Date：
				Author：
				Version：
				Modification：
				
	1.	Date：2015/8/14
		Author：姜君
		Version：2.0
		Modification：文件多处重大修改，版本号升为2.0，文件名改为SVGAmode.h
		
	2.	Date：2015/8/14
		Author：姜君
		Version：2.0
		Modification：函数实现部分分出为新文件SVGAmode.c，本文件只作有关声明
						
	3.	Date：2015/8/14
		Author：姜君
		Version：2.0
		Modification：添加下列函数：
						int Putbmp(int x, int y, const char * path)
		
	4.	Date：2015/8/14
		Author：姜君
		Version：2.0
		Modification：添加以下结构定义
						画图函数调色板颜色结构COLORS
						bmp位图颜色表颜色结构RGBQUAD
						bmp位图信息头结构BITMAPINFOHEADER（备查）
					  
	5.	Date：2015/9/2
		Author：姜君
		Version：2.1
		Modification：文件多处修改，随SVGAmode.c把版本号升为2.1
		
	6.	Date：2015/9/2
		Author：姜君
		Version：2.1
		Modification：添加定义24位bmp图颜色结构COLORS24
		
	7.	Date：2015/9/3
		Author：姜君
		Version：2.1
		Modification：部分函数做以下更名，对应注释修改
					  SetSVGA改为SetSVGA256
					  Putbmp改为Putbmp256
					  Putpixel改为Putpixel256
					  
	8.	Date：2015/9/3
		Author：姜君
		Version：2.1
		Modification：添加以下函数：
					  SetSVGA64k
					  Putpixel64k
					  Putbmp64k
					  设置SVGA模式可以有256色和64k色两种选择，
					  后者仅配有24位bmp转16位读图函数和画点函数，其他基本画图函数一律不适用！
					  
	9.	Date：2015/9/12
		Author：姜君
		Version：2.1
		Modification：把公用的头文件分离出形成head.h
		
	10.	Date：2015/11/5
		Author：姜君
		Version：2.1
		Modification：删去14个无用函数和精简注释，本文件基本定稿
**********************************************************/

#ifndef	_SVGAmode_H_
#define	_SVGAmode_H_

#define	SCR_WIDTH	1024	/*SCREEN_WIDTH的缩写，屏幕宽度像素 */
#define	SCR_HEIGHT	768		/*SCREEN_HEIGHT的缩写，屏幕高度像素 */

#include<dos.h>			/*int86、outportb函数头文件，union REGS的定义文件*/
#include<stdio.h>		/*文件操作函数头文件*/
#include<time.h>		/*time函数头文件，clock_t的定义头文件*/
#include<math.h>		/*abs，fabs，sin，cos函数头文件*/
#include<stdlib.h>		/*rand、srand、exit函数头文件*/
#include<graphics.h>	/*自带画图函数头文件*/
#include<conio.h>		/*getch函数头文件*/
#include<string.h>		/*memmove函数头文件*/
#include<bios.h>		/*bioskey函数头文件*/

/*画图函数调色板颜色结构*/
typedef struct
{
	unsigned char R;	/*红色分量，RED缩写*/
	unsigned char G;	/*绿色分量，GREEN缩写*/
	unsigned char B;	/*蓝色分量，BLUE缩写*/
} COLORS;

/*24位bmp图颜色结构*/
typedef struct
{
	unsigned char B;	/*蓝色分量，BLUE缩写*/
	unsigned char G;	/*绿色分量，GREEN缩写*/
	unsigned char R;	/*红色分量，RED缩写*/
} COLORS24;

/*bmp位图颜色表颜色结构*/
typedef struct tagRGBQUAD
{
    unsigned char b;	/*蓝色分量，RED缩写*/
	unsigned char g;	/*绿色分量，GREEN缩写*/
	unsigned char r;	/*红色分量，BLUE缩写*/
	unsigned char reserved;		/*保留字*/
} RGBQUAD;

/*bmp位图信息头数据用于说明位图的尺寸等信息*/
typedef struct tagBITMAPINFOHEADER
{
	unsigned long int biSize;	/*本结构所占用字节数（15-18字节）*/
	long int biWidth;			/*位图的宽度，以像素为单位（19-22字节）*/
	long int biHeight;			/*位图的高度，以像素为单位（23-26字节）*/
	unsigned int biPlanes;		/*目标设备的级别，必须为1(27-28字节）*/
	unsigned int biBitCount;	/*每个像素所需的位数，必须是1（双色），4(16色），8(256色）16(高彩色)或24（真彩色）之一（29-30字节）*/
	unsigned long int biCompression;	/*位图压缩类型，必须是0（不压缩），1(BI_RLE8压缩类型）或2(BI_RLE4压缩类型）之一（31-34字节）*/
	unsigned long int biSizeImage;		/*位图的大小(其中包含了为了补齐行数是4的倍数而添加的空字节)，以字节为单位（35-38字节）*/
	long int biXPelsPerMeter;			/*位图水平分辨率，每米像素数（39-42字节）*/
	long int biYPelsPerMeter;			/*位图垂直分辨率，每米像素数（43-46字节)*/
	unsigned long int biClrUsed;		/*位图实际使用的颜色表中的颜色数（47-50字节）*/
	unsigned long int biClrImportant;	/*位图显示过程中重要的颜色数（51-54字节）*/
} BITMAPINFOHEADER;

/**********************************************************
Function：		SetSVGA256

Description：	SVGA显示模式设置函数，设为0x105

Calls：			int86
				delay
				printf
				exit

Called By：		AutoSimulate
				HandOperate
				
Input：			None

Output：		错误信息

Return：		None				
Others：		None
**********************************************************/
extern void SetSVGA256(void);

/**********************************************************
Function：		SetSVGA64k

Description：	SVGA显示模式设置函数，设为0x117

Calls：			int86
				delay
				printf
				exit

Called By：		AutoSimulate
				HandOperate
				
Input：			None

Output：		错误信息

Return：		None				
Others：		None
**********************************************************/
extern void SetSVGA64k(void);

/**********************************************************
Function：		GetSVGA

Description：	获取SVGA显示模式号bx。摘录常用的模式号如下：
				模式号		分辨率		颜色数		颜色位定义
				0x101		640*480		256				-
				0x103		800*600		256				-
				0x104		1024*768	16				-
				0x105		1024*768	256				-
				0x110		640*480		32K			1:5:5:5
				0x111		640*480		64K			5:6:5
				0x112		640*480		16.8M		8:8:8
				0x113		800*600		32K			1:5:5:5
				0x114		800*600		64K			5:6:5
				0x115		800*600		16.8M		8:8:8
				0x116		1024*768	32K			1:5:5:5
				0x117		1024*768	64K			5:6:5
				0x118		1024*768	16.8M		8:8:8

Calls：			int86
				delay
				printf
				exit

Called By：		Unknown
Input：			None

Output：		初始化失败时会屏幕输出错误号。

Return：		unsigned int graph_regs.x.bx	显示模式号

Others：		None
**********************************************************/
extern unsigned int GetSVGA(void);

/**********************************************************
Function：		Selectpage

Description：	带判断功能的换页函数，解决读写显存时跨段寻址问题

Calls：			int86

Called By：		Putpixel256
				Putpixel64k
				Xorpixel
				Horizline
				Getpixel64k
				
Input：			register char page		需要换到的页面号

Output：		None

Return：		None
Others：		None
**********************************************************/
extern void Selectpage(register char page);

/**********************************************************
Function：		Putpixel256

Description：	画点函数，其他画图函数的基础，仅适用于0x105模式！

Calls：			Selectpage

Called By：		Putbmp256
				Line
				Circle
				
Input：			int x					像素横坐标，从左到右增加，0为最小值（屏幕参考系）
				int y					像素纵坐标，从上到下增加，0为最小值（屏幕参考系）
				unsigned char color		颜色数，共有256种

Output：		在屏幕上画指定颜色的点

Return：		None
Others：		None
**********************************************************/
extern void Putpixel256(int x, int y, unsigned char color);

/**********************************************************
Function：		Putpixel64k

Description：	画点函数，其他画图函数的基础，仅适用于0x117模式！

Calls：			Selectpage

Called By：		Putbmp64k
				MousePutBk
				MouseDraw
				
Input：			int x					像素横坐标，从左到右增加，0为最小值（屏幕参考系）
				int y					像素纵坐标，从上到下增加，0为最小值（屏幕参考系）
				unsigned int color		颜色数，共有64k种

Output：		在屏幕上画指定颜色的点

Return：		None
Others：		None
**********************************************************/
extern void Putpixel64k(int x, int y, unsigned int color);
extern void XORPutpixel64k(int x, int y, unsigned int color);
/**********************************************************
Function：		Putbmp256

Description：	8位非压缩bmp图定位显示函数。
				只支持8位非压缩bmp图，宽度像素最大允许为1024！
				其余bmp类型均不支持！
				仅在0x105模式下使用！
				为了简化，没有设置文件类型检测功能检测功能，请勿读入不合要求的文件！
				此函数适合在不换位面条件下读取大型图片。
				虽然能设置了读取颜色表功能，并能兼容实际使用颜色表数不足最大数的图片，
				但统一要求使用Windows默认颜色表，否则影响其他图片显示！

Calls：			Putpixel256

				fseek
				fread
				fclose
				outportb
				malloc
				free

Called By：		AutoSimulate
				HandOperate
				
Input：			int x		图片左上角的横坐标（屏幕参考系）
				int y		图片左上角的纵坐标（屏幕参考系）
				const char * path	bmp图片路径

Output：		屏幕上显示图片

Return：		0	显示成功
				-1	显示失败
				
Others：		None
**********************************************************/
extern int Putbmp256(int x, int y, const char * path);

/**********************************************************
Function：		Putbmp64k

Description：	24位非压缩bmp图定位显示函数。
				只支持24位非压缩bmp图，宽度像素最大允许为1024！
				其余bmp类型均不支持！
				仅在0x117模式下使用！
				为了简化，没有设置文件类型检测功能检测功能，请勿读入不合要求的文件！

Calls：			Putpixel64k

				fseek
				fread
				fclose
				outportb
				malloc
				free

Called By：		AutoSimulate
				HandOperate
				Menu
				
Input：			int x		图片左上角的横坐标（屏幕参考系）
				int y		图片左上角的纵坐标（屏幕参考系）
				const char * path	bmp图片路径

Output：		屏幕上显示图片

Return：		0	显示成功
				-1	显示失败
				
Others：		None
**********************************************************/
extern int Putbmp64k(int x, int y, const char * path);
extern int Putbmp64k2(int x, int y, const char * path);
extern int Putbmp64k3(int x, int y, const char * path);
extern int XORPutbmp64k(int x, int y, const char * path);

/**********************************************************
Function：		Xorpixel

Description：	按位异或画点函数

Calls：			Selectpage

Called By：		XorCarBmp
				
Input：			int x					像素横坐标，从左到右增加，0为最小值（屏幕参考系）
				int y					像素纵坐标，从上到下增加，0为最小值（屏幕参考系）
				unsigned char color		颜色数，共有256种

Output：		在屏幕上画异或点

Return：		None
Others：		None
**********************************************************/
extern void Xorpixel(int x, int y, unsigned int color);

/**********************************************************
Function：		Horizline

Description：	画水平线函数
				可以接收超出屏幕范围的数据，只画出在屏幕内部分
				因为没有防止整型变量溢出的判断，画超出屏幕的线时应防止输入特大数据

Calls：			Selectpage

Called By：		Line
				Bar
				Circlefill

Input：			int x					起始点横坐标，从左到右增加，0为最小值（屏幕参考系）
				int y					起始点纵坐标，从上到下增加，0为最小值（屏幕参考系）
				int width				水平长度，为正向右延伸，为负向左延伸
				unsigned char color		颜色数，共有256种

Output：		屏幕上画出水平线

Return：		None
Others：		None
**********************************************************/
extern void Horizline(int x, int y, int width, unsigned int color);

/**********************************************************
Function：		Line

Description：	画一般直线函数
				可以接收超出屏幕范围的数据，只画出在屏幕内部分
				因为没有防止整型变量溢出的判断，画超出屏幕的线时应防止输入特大数据

Calls：			Putpixel256
				
				abs

Called By：		LightSW
				LightNE
				LightNW
				LightSE

Input：			int x1					起始点横坐标，从左到右增加，0为最小值（屏幕参考系）
				int y1					起始点纵坐标，从上到下增加，0为最小值（屏幕参考系）
				int x2					终止点横坐标（屏幕参考系）
				int y2					终止点纵坐标（屏幕参考系）
				unsigned char color		颜色数，共有256种

Output：		屏幕上画出直线

Return：		None
Others：		None
**********************************************************/
extern void Line(int x1, int y1, int x2, int y2, unsigned int color);

/**********************************************************
Function：		Bar
Description：	画矩形块函数
				可以接收超出屏幕范围的数据，只画出在屏幕内部分
				因为没有防止整型变量溢出的判断，画超出屏幕的部分时应防止输入特大数据

Calls：			Horizline

Called By：		LightSW
				LightNE
				LightNW
				LightSE

Input：			int x1					对角点1的横坐标，从左到右增加，0为最小值（屏幕参考系）
				int y1					对角点1的纵坐标，从上到下增加，0为最小值（屏幕参考系）
				int x2					对角点2的横坐标，从左到右增加，0为最小值（屏幕参考系）
				int y2					对角点2的纵坐标，从上到下增加，0为最小值（屏幕参考系）
				unsigned char color		颜色数，共有65536种

Output：		屏幕上画出矩形块

Return：		None
Others：		None
**********************************************************/
extern void Bar(int x1, int y1, int x2, int y2, unsigned int color);

/**********************************************************
Function：		Circle
Description：	画圆圈函数
				可以接收超出屏幕范围的数据，只画出在屏幕内部分
				因为没有防止整型变量溢出的判断，画超出屏幕的部分时应防止输入特大数据

Calls：			Putpixel256

Called By：		LightSW
				LightNE
				LightNW
				LightSE

Input：			int xc					x_center的缩写，圆心横坐标（屏幕参考系）
				int yc					y_center的缩写，圆心纵坐标（屏幕参考系）
				int radius				半径，必须为正
				unsigned char color		颜色数，共有65536种

Output：		屏幕上画出圆圈

Return：		None
Others：		None
**********************************************************/
extern void Circle(int xc, int yc, int radius, unsigned int color);

/**********************************************************
Function：		Circlefill
Description：	画实心圆函数
				可以接收超出屏幕范围的数据，只画出在屏幕内部分
				因为没有防止整型变量溢出的判断，画超出屏幕的部分时应防止输入特大数据

Calls：			Horizline

Called By：		LightColorR
				LightColorY
				LightColorG
				LightColor1
				LightColor2
				LightColor3
				LightColor4
				LightColorD1
				LightColorD2
				LightColorD3
				TrafficLight

Input：			int xc					x_center的缩写，圆心横坐标（屏幕参考系）
				int yc					y_center的缩写，圆心纵坐标（屏幕参考系）
				int radius				半径，必须为正
				unsigned char color		颜色数，共有256种

Output：		屏幕上画出圆圈

Return：		None
Others：		None
**********************************************************/
extern void Circlefill(int xc, int yc, int radius, unsigned int color);
int Imagesize(int xmin,int ymin,int xmax,int ymax);
unsigned char Getpixel256(int x, int y);
int Getpixel64k(int x, int y);
void Get_image(int xmin,int ymin,int xmax,int ymax,unsigned char* bufer);//得到每一个像素点的颜色
void Put_image(int xmin,int ymin,int xmax,int ymax,const unsigned char* bufer);//输出像素点
#endif