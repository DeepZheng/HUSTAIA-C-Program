/*本函数为外源代码，不计入代码量，感谢姜君学长提供*/
/**********************************************************
Copyright (C) 2015 姜君 王鹏晖.
File name:		SVGAmode.c
Author:			姜君
Version：		2.1
Date：			2015/8/11
Description：	SVGA显示模式实现文件，包括该模式下基本的初始化函数、操作函数、画图函数、读图函数等的实现。
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
		Modification：文件多处重大修改，版本号升为2.0，文件名改为SVGAmode.c
	
	2.	Date：2015/8/14
		Author：姜君
		Version：2.0
		Modification：宏定义部分和预处理部分分出为新文件SVGAmode.h，预处理只需包含该文件
						
	3.	Date：2015/8/14
		Author：姜君
		Version：2.0
		Modification：添加下列函数：
						int Putbmp(int x, int y, const char * path)
	
	4.	Date：2015/8/14
		Author：姜君
		Version：2.0
		Modification：去掉原来的输入形参unsigned int graphmode即SVGA显示模式设置值，
					  强制设置为1024*768*256色模式，
					  错误信息不再包含错误码，而是输出文字提示
					  
	5.	Date：2015/8/14
		Author：姜君
		Version：2.0
		Modification：以下函数：
						Putpixel
						Xorpixel
						Horizline
					  中的表达式
						page = (unsigned long int)y * SCR_WIDTH + x;
					  替换为
						page = ((unsigned long int)y << 10) + x;
					  以提高运算速度
					  
	6.	Date：2015/9/2
		Author：姜君
		Version：2.1
		Modification：文件多处修改，版本号升为2.1
		
	7.	Date：2015/9/2
		Author：姜君
		Version：2.1
		Modification：8位bmp读图函数Putbmp将固定的颜色表数组
					  RGBQUAD clr [256]
					  改为指针
					  RGBQUAD * clr
					  并动态开辟储存空间，兼容不足256种颜色表的图片
					  
	8.	Date：2015/9/2
		Author：姜君
		Version：2.1
		Modification：8位bmp读图函数Putbmp为行像素数据指针buffer动态开辟存储空间
	
	9.	Date：2015/9/3
		Author：姜君
		Version：2.1
		Modification：部分函数做以下更名：
					  SetSVGA改为SetSVGA256
					  Putbmp改为Putbmp256
					  Putpixel改为Putpixel256
					  
	10.	Date：2015/9/3
		Author：姜君
		Version：2.1
		Modification：8位读图函数Putbmp256
					  以行扫描形式读取图片数据并显示的外层循环
					  for (i = height; i > -1; i--)
					  更正为
					  for (i = height - 1; i > -1; i--)
		
	11.	Date：2015/9/3
		Author：姜君
		Version：2.1
		Modification：添加以下函数：
					  SetSVGA64k
					  Putpixel64k
					  Putbmp64k
					  设置SVGA模式可以有256色和64k色两种选择，
					  后者仅配有24位bmp转16位读图函数和画点函数，其他基本画图函数一律不适用！
					  
	12.	Date：2015/11/5
		Author：姜君
		Version：2.1
		Modification：删去14个无用函数和精简注释，本文件基本定稿
**********************************************************/

#include "SVGAmode.h"
#include"DRAW.H"
#include"color.h"
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
void SetSVGA256(void)
{
	/*****************************************************
	在dos.h中REGS的定义如下：
	struct WORDREGS
	{
		unsigned int ax, bx, cx, dx, si, di, cflag, flags;
	};
	
	struct BYTEREGS
	{
		unsigned char al, ah, bl, bh, cl, ch, dl, dh;
	};
	
	union REGS
	{
		struct WORDREGS x;
		struct BYTEREGS h;
	};
	这样al对应ax的低八位，ah对应ax的高八位，以此类推。
	调用时需要查表决定各入口参数取值,获取返回值表示的信息。
	*****************************************************/
	union REGS graph_regs;
	
	/*设置VESA VBE模式的功能号*/
	graph_regs.x.ax = 0x4f02;
	graph_regs.x.bx = 0x105;
	int86(0x10, &graph_regs, &graph_regs);
	
	/*ax != 0x004f意味着初始化失败，输出错误信息见上,下同*/
	if (graph_regs.x.ax != 0x004f)
	{
		printf("Error in setting SVGA mode!\nError code:0x%x\n", graph_regs.x.ax);
		delay(5000);
		exit(1);
	}
}

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
void SetSVGA64k(void)
{
	/*REGS联合体见上*/
	union REGS graph_regs;
	
	/*设置VESA VBE模式的功能号*/
	graph_regs.x.ax = 0x4f02;
	graph_regs.x.bx = 0x117;
	int86(0x10, &graph_regs, &graph_regs);
	
	/*ax != 0x004f意味着初始化失败，输出错误信息见上,下同*/
	if (graph_regs.x.ax != 0x004f)
	{
		printf("Error in setting SVGA mode!\nError code:0x%x\n", graph_regs.x.ax);
		delay(5000);
		exit(1);
	}
}

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
unsigned int GetSVGA(void)
{
	/*REGS联合体见上*/
	union REGS graph_regs;
	
	/*获取当前VESA VBE模式的功能号*/
	graph_regs.x.ax = 0x4f03;
	int86(0x10, &graph_regs, &graph_regs);
	
	/*显示错误信息*/
	if (graph_regs.x.ax != 0x004f)
	{
		printf("Error in getting SVGA mode!\nError code:0x%x\n", graph_regs.x.ax);
		delay(5000);
		exit(1);
	}
	
	return graph_regs.x.bx;
}

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
void Selectpage(register char page)
{
	/*REGS含义同上*/
	union REGS graph_regs;
	
	/*上一次的页面号,用于减少切换次数,是使用次数很多的重要变量*/
	static unsigned char old_page = 0;
	
	/*标志数，用于判断是否是第一次换页*/
	static int flag = 0;
	
	/*窗口页面控制功能号*/
	graph_regs.x.ax = 0x4f05;
	graph_regs.x.bx = 0;
	
	/*如果是第一次换页*/
	if (flag == 0)
	{
		old_page = page;
		graph_regs.x.dx = page;
		int86(0x10, &graph_regs, &graph_regs);
		flag++;
	}
	
	/*如果和上次页面号不同，则进行换页*/
	else if (page != old_page)
	{
		old_page = page;
		graph_regs.x.dx = page;
		int86(0x10, &graph_regs, &graph_regs);
	}
}

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
void Putpixel256(int x, int y, unsigned char color)
{
	/*显存指针常量，指向显存首地址，指针本身不允许修改*/
	unsigned char far * const video_buffer = (unsigned char far *)0xa0000000L;
	
	/*要切换的页面号*/
	unsigned char new_page;
	
	/*对应显存地址偏移量*/
	unsigned long int page;
	
	/*判断点是否在屏幕范围内，不在就退出*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return;
	}
	
	/*计算显存地址偏移量和对应的页面号，做换页操作*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 16;	/*64k个点一换页，除以64k的替代算法*/
	Selectpage(new_page);
	
	/*向显存写入颜色，对应点画出*/
	video_buffer[page] = color;	
}

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
void Putpixel64k(int x, int y, unsigned int color)
{
		/*显存指针常量，指向显存首地址，指针本身不允许修改*/
	unsigned int far *const video_buffer = (unsigned int far *)0xa0000000L;
	
	/*要切换的页面号*/
	unsigned char new_page;
	
	/*对应显存地址偏移量*/
	unsigned long int page;
	
	/*判断点是否在屏幕范围内，不在就退出*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return;
	}
	
	/*计算显存地址偏移量和对应的页面号，做换页操作*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 15;	/*32k个点一换页，除以32k的替代算法*/
	Selectpage(new_page);
	
	/*向显存写入颜色，对应点画出*/
	video_buffer[page] = color;	
}

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
int Putbmp256(int x, int y, const char * path)
{
	/*指向图片文件的文件指针*/
	FILE * fpbmp;
	
	/*bmp颜色表结构指针*/
	RGBQUAD * pclr, *clr;
	
	/*行像素缓存指针*/
	unsigned char * buffer;
	
	/*实际使用的颜色表中的颜色数*/
	unsigned long int clr_used;
	
	/*图片的宽度、高度、一行像素所占字节数（含补齐空字节）*/
	long int width, height, linebytes;
	
	/*循环变量*/
	int i, j;
	
	/*图片位深*/
	unsigned int bit;
	
	/*压缩类型数*/
	unsigned long int compression;
	
	/*打开文件*/
	if ((fpbmp = fopen(path, "rb")) == NULL)
	{
		return -1;
	}
	
	/*读取位深*/
	fseek(fpbmp, 28L, 0);
	fread(&bit, 2, 1, fpbmp);
	
	/*非8位图则退出*/
	if (bit != 8U)
	{
		return -1;
	}
	
	/*读取压缩类型*/
	fseek(fpbmp, 30L, 0);
	fread(&compression, 4, 1, fpbmp);
	
	/*采用压缩算法则退出*/
	if (compression != 0UL)
	{
		return -1;
	}
	
	/*读取宽度、高度*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);
	
	/*宽度超限则退出*/
	if (width > SCR_WIDTH)
	{
		return -1;
	}

	/*计算一行像素占字节数，包括补齐的空字节*/
	linebytes = width % 4;
	
	if(!linebytes)
	{
		linebytes = width;
	}
	else
	{
		linebytes = width + 4 - linebytes;
	}
	
	/*读取实际使用的颜色表中的颜色数*/
	fseek(fpbmp, 46L, 0);
	fread(&clr_used, 4, 1, fpbmp);
	
	/*若颜色数为0，则使用了2的bit次方种颜色*/
	if (clr_used == 0L)
	{
		clr_used = 1U << bit;
	}
	
	/*开辟颜色表动态储存空间*/
	if ((clr = (RGBQUAD *)malloc(4L * clr_used)) == 0)
	{
		return -1;
	}
	
	/*颜色表工作指针初始化*/
	pclr = clr;
	
	/*读取颜色表*/
	fseek(fpbmp, 54L, 0);
	
	if ((fread((unsigned char *)pclr, 4L * clr_used, 1, fpbmp)) != 1)
	{
		return -1;
	}
	
	/*按照颜色表设置颜色寄存器值*/
	for (i = 0; i < clr_used; i++, pclr++) 
	{
		outportb(0x3c8, i);				/*设置要改变的颜色号*/
		outportb(0x3c9, pclr->r >> 2);
		outportb(0x3c9, pclr->g >> 2);
		outportb(0x3c9, pclr->b >> 2);
	}
	
	free(clr);
	
	/*开辟行像素数据动态储存空间*/
	if ((buffer = (unsigned char *)malloc(linebytes)) == 0)
	{
		return -1;
	}
	
	/*行扫描形式读取图片数据并显示*/
	fseek(fpbmp, 54L + 4L * clr_used, 0);
	for (i = height - 1; i > -1; i--)
	{
		fread(buffer, linebytes, 1, fpbmp);	/*读取一行像素数据*/
		
		for (j = 0; j < width; j++)
		{
			Putpixel256(j + x, i + y, buffer[j]);
		}
	}
	
	free(buffer);	
	fclose(fpbmp);
	
	return 0;	
}

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
int Putbmp64k(int x, int y, const char * path)
{
	/*指向图片文件的文件指针*/
	FILE * fpbmp;
	
	/*行像素缓存指针*/
	COLORS24 * buffer;
	
	/*图片的宽度、高度、一行像素所占字节数（含补齐空字节）*/
	long int width, height, linebytes;
	
	/*循环变量*/
	int i, j;
	
	/*图片位深*/
	unsigned int bit;
	
	/*压缩类型数*/
	unsigned long int compression;
	
	/*打开文件*/
	if ((fpbmp = fopen(path, "rb")) == NULL)
	{
		return -1;
	}
	
	/*读取位深*/
	fseek(fpbmp, 28L, 0);
	fread(&bit, 2, 1, fpbmp);
	
	/*非24位图则退出*/
	if (bit != 24U)
	{
		return -1;
	}
	
	/*读取压缩类型*/
	fseek(fpbmp, 30L, 0);
	fread(&compression, 4, 1, fpbmp);
	
	/*采用压缩算法则退出*/
	if (compression != 0UL)
	{
		return -1;
	}
	
	/*读取宽度、高度*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);
	
	/*宽度超限则退出*/
	if (width > SCR_WIDTH)
	{
		return -1;
	}

	/*计算一行像素占字节数，包括补齐的空字节*/
	linebytes = (3 * width) % 4;
	
	if(!linebytes)
	{
		linebytes = 3 * width;
	}
	else
	{
		linebytes = 3 * width + 4 - linebytes;
	}

	/*开辟行像素数据动态储存空间*/
	if ((buffer = (COLORS24 *)malloc(linebytes)) == 0)
	{
		return -1;
	}
	
	/*行扫描形式读取图片数据并显示*/
	fseek(fpbmp, 54L, 0);
	for (i = height - 1; i > -1; i--)
	{
		fread(buffer, linebytes, 1, fpbmp);	/*读取一行像素数据*/
		
		/*一行像素的数据处理和画出*/
		for (j = 0; j < width; j++)
		{
			/*0x117模式下，原图红绿蓝各8位分别近似为5位、6位、5位*/
			buffer[j].R >>= 3;
			buffer[j].G >>= 2;
			buffer[j].B >>= 3;
			Putpixel64k(j + x, i + y,
			((((unsigned int)buffer[j].R) << 11)
			| (((unsigned int)buffer[j].G) << 5)
			| ((unsigned int)buffer[j].B)));	/*计算最终颜色，红绿蓝从高位到低位排列*/
		}
	}
	
	free(buffer);	
	fclose(fpbmp);
	
	return 0;	
}
int Putbmp64k3(int x, int y, const char * path)
{
	/*指向图片文件的文件指针*/
	FILE * fpbmp;
	
	/*行像素缓存指针*/
	COLORS24 * buffer;
	
	/*图片的宽度、高度、一行像素所占字节数（含补齐空字节）*/
	long int width, height, linebytes;
	
	/*循环变量*/
	int i, j;
	
	/*图片位深*/
	unsigned int bit;
	
	/*压缩类型数*/
	unsigned long int compression;
	
	/*打开文件*/
	if ((fpbmp = fopen(path, "rb")) == NULL)
	{
		return -1;
	}
	
	/*读取位深*/
	fseek(fpbmp, 28L, 0);
	fread(&bit, 2, 1, fpbmp);
	
	/*非24位图则退出*/
	if (bit != 24U)
	{
		return -1;
	}
	
	/*读取压缩类型*/
	fseek(fpbmp, 30L, 0);
	fread(&compression, 4, 1, fpbmp);
	
	/*采用压缩算法则退出*/
	if (compression != 0UL)
	{
		return -1;
	}
	
	/*读取宽度、高度*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);
	
	/*宽度超限则退出*/
	if (width > SCR_WIDTH)
	{
		return -1;
	}

	/*计算一行像素占字节数，包括补齐的空字节*/
	linebytes = (3 * width) % 4;
	
	if(!linebytes)
	{
		linebytes = 3 * width;
	}
	else
	{
		linebytes = 3 * width + 4 - linebytes;
	}

	/*开辟行像素数据动态储存空间*/
	if ((buffer = (COLORS24 *)malloc(linebytes)) == 0)
	{
		return -1;
	}
	
	/*行扫描形式读取图片数据并显示*/
	fseek(fpbmp, 54L, 0);
	for (i = height - 1; i > -1; i--)
	{
		fread(buffer, linebytes, 1, fpbmp);	/*读取一行像素数据*/
		
		/*一行像素的数据处理和画出*/
		for (j = 0; j < width; j++)
		{
			/*0x117模式下，原图红绿蓝各8位分别近似为5位、6位、5位*/
			buffer[j].R >>= 3;
			buffer[j].G >>= 2;
			buffer[j].B >>= 3;
			Putpixel64k(j + x-width/2, i + y-height/2,
			((((unsigned int)buffer[j].R) << 11)
			| (((unsigned int)buffer[j].G) << 5)
			| ((unsigned int)buffer[j].B)));	/*计算最终颜色，红绿蓝从高位到低位排列*/
		}
	}
	
	free(buffer);	
	fclose(fpbmp);
	
	return 0;	
}
int Putbmp64k2(int x, int y, const char * path)
{
	/*指向图片文件的文件指针*/
	FILE * fpbmp;
	
	/*行像素缓存指针*/
	COLORS24 * buffer;
	
	/*图片的宽度、高度、一行像素所占字节数（含补齐空字节）*/
	long int width, height, linebytes;
	
	/*循环变量*/
	int i, j;
	
	/*图片位深*/
	unsigned int bit;
	
	/*压缩类型数*/
	unsigned long int compression;
	  unsigned  int color;

	/*打开文件*/
	if ((fpbmp = fopen(path, "rb")) == NULL)
	{
		return -1;
	}

	/*读取位深*/
	fseek(fpbmp, 28L, 0);
	fread(&bit, 2, 1, fpbmp);

	/*非24位图则退出*/
	if (bit != 24U)
	{
		return -1;
	}

	/*读取压缩类型*/
	fseek(fpbmp, 30L, 0);
	fread(&compression, 4, 1, fpbmp);

	/*采用压缩算法则退出*/
	if (compression != 0UL)
	{
		return -1;
	}

	/*读取宽度、高度*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);

	/*宽度超限则退出*/
	if (width > SCR_WIDTH)
	{
		return -1;
	}

	/*计算一行像素占字节数，包括补齐的空字节*/
	linebytes = (3 * width) % 4;

	if(!linebytes)
	{
		linebytes = 3 * width;
	}
	else
	{
		linebytes = 3 * width + 4 - linebytes;
	}

	/*开辟行像素数据动态储存空间*/
	if ((buffer = (COLORS24 *)malloc(linebytes)) == 0)
	{
		return -1;
	}

	/*行扫描形式读取图片数据并显示*/
	fseek(fpbmp, 54L, 0);
	for (i = height - 1; i > -1; i--)
	{
		fread(buffer, linebytes, 1, fpbmp);	/*读取一行像素数据*/

		/*一行像素的数据处理和画出*/
		for (j = 0; j < width; j++)
		{
			/*0x117模式下，原图红绿蓝各8位分别近似为5位、6位、5位*/
			buffer[j].R >>= 3;
			buffer[j].G >>= 2;
			buffer[j].B >>= 3;
						color=((((unsigned int)buffer[j].R) << 11)
			| (((unsigned int)buffer[j].G) << 5)
			| ((unsigned int)buffer[j].B));
					  if(color<=40000)
			Putpixel64k(j + x, i + y,
			((((unsigned int)buffer[j].R) << 11)
			| (((unsigned int)buffer[j].G) << 5)
			| ((unsigned int)buffer[j].B)));	/*计算最终颜色，红绿蓝从高位到低位排列*/
		}
	}

	free(buffer);
	fclose(fpbmp);

	return 0;
}
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
void Xorpixel(int x, int y, unsigned int color)
{
	/*显存指针常量，指向显存首地址，指针本身不允许修改*/
	unsigned char far * const video_buffer = (unsigned char far *)0xa0000000L;
	
	/*要切换的页面号*/
	unsigned char new_page;
	
	/*对应显存地址偏移量*/
	unsigned long int page;
	
	/*判断点是否在屏幕范围内，不在就退出*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return;
	}
	
	/*计算显存地址偏移量和对应的页面号，做换页操作*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 16;
	Selectpage(new_page);
	
	/*按位异或方式向显存写入颜色，对应点画出*/
	video_buffer[page] ^= color;	
}

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
void Horizline(int x, int y, int width, unsigned int color)
{
	/*显存指针常量，指向显存首地址，指针本身不允许修改*/
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;
	
	/*要切换的页面号*/
	unsigned char new_page;
	
	/*对应显存地址偏移量*/
	unsigned long int page;
	
	/*i是x的临时变量，后作循环变量*/
	int i;
	
	/*判断延伸方向，让起始点靠左*/
	if (width < 0)
	{
		x = x + width;
		width = -width;
	}
	
	i = x;
	
	/*省略超出屏幕左边部分*/
	if (x < 0)
	{
		x = 0;
		width += i;
	}
	
	/*整条线在屏幕外时退出*/
	if (x >= SCR_WIDTH)
	{
		return;
	}
	
	/*整条线在屏幕外时退出*/
	if (y < 0 || y >= SCR_HEIGHT)
	{
		return;
	}
	
	/*省略超出屏幕右边部分*/
	if (x + width > SCR_WIDTH)
	{
		width = SCR_WIDTH - x;
	}
	
	/*计算显存地址偏移量和对应的页面号，做换页操作*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 16;
	Selectpage(new_page);
	
	/*向显存写入颜色，水平线画出*/
	for (i = 0; i < width; i++)
	{
		*(video_buffer + page + i) = color;
	}
}

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
				unsigned char color		颜色数，共有65536种

Output：		屏幕上画出直线

Return：		None
Others：		None
**********************************************************/
void Line(int x1, int y1, int x2, int y2, unsigned int color)
{
	int	dx, dy;			/*直线x、y坐标差值*/
	int dx2, dy2;		/*加快运算速度的中间值*/
	int xinc, yinc;		/*判断想、y增加方向的符号值*/
	int d, dxy;			/*决策变量*/
	int i;
	/*计算坐标差值和中间变量*/
	dx = abs(x2 - x1);
	dx2 = dx << 1;
	dy = abs(y2 - y1);
	dy2 = dy << 1;
	
	/*判断直线x坐标增加方向*/
	if (x2 > x1)
	{
		xinc = 1;
	}
	
	/*如果是竖直线*/
	else if (x2 == x1)
	{
		/*y坐标排序*/
		if (y1 > y2)
		{
			dx = y1;
			y1 = y2;
			y2 = dx;
		}
		
		/*画竖直线*/
		for (dx = y1; dx <= y2; dx++)
		{
			Putpixel64k(x1, dx, color);
		}
		
		return;
	}
	
	else
	{
		xinc = -1;
	}
	
	/*判断直线y坐标增加方向*/
	if (y2 > y1)
	{
		yinc = 1;
	}
	
	/*如果是水平线*/
	else if (y2 == y1)
	{
		for(i=x1;i<=x2;i++)
		{
			Putpixel64k(i,y1,color);
		}
		return;
	}
	
	else
	{
		yinc = -1;
	}
	
	/*******************************
	以下运用Bresenham算法生成直线。
	该算法是得到公认的成熟的快速算法。
	具体细节略去。
	*******************************/
	Putpixel64k(x1, y1, color);
	
	if (dx >= dy)
	{
		d = dy2 - dx;
		dxy = dy2 - dx2;
		
		while (dx--)
		{
			if (d <= 0)
			{
				d += dy2;
			}
			
			else
			{
				d += dxy;
				y1 += yinc;
			}
			
			x1 += xinc;
			Putpixel64k(x1, y1, color);
		}
	}
	
	else
	{
		d = dx2 - dy;
		dxy = dx2 - dy2;
		
		while (dy--)
		{
			if (d <= 0)
			{
				d += dx2;
			}
			
			else
			{
				d += dxy;
				x1 += xinc;
			}
			
			y1 += yinc;
			Putpixel64k(x1, y1, color);
		}
	}
}

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
void Bar(int x1, int y1, int x2, int y2, unsigned int color)
{
	/*temp为临时变量和循环变量*/
	/*width为矩形长*/
	int temp, width;
	int i,j;
	/*x坐标排序*/
	if (x1 > x2)
	{
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	
	/*y坐标排序*/
	if (y1 > y2)
	{
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	
	
	/*逐行扫描画出矩形*/
	for(i=x1;i<=x2;i++)
	{
			for(j=y1;j<=y2;j++)
			{
					Putpixel64k(i,j,color);
			}
	}
}

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
void Circle(int xc, int yc, int radius, unsigned int color)
{
		/*画圆圈的定位变量和决策变量*/
	int x, y, d;
	
	/*半径必须为正，否则退出*/
	if (radius <= 0)
	{
		return;
	}
	
	/************************************
	以下运用Bresenham算法生成圆圈。
	该算法是得到公认的成熟的快速算法。
	具体细节略去。
	************************************/
	y = radius;
	d = 3 - radius << 1;
	
	for (x = 0; x <= y; x++)
	{
		Putpixel64k(xc + x, yc + y, color);
		Putpixel64k(xc + x, yc - y, color);
		Putpixel64k(xc - x, yc - y, color);
		Putpixel64k(xc - x, yc + y, color);
		Putpixel64k(xc + y, yc + x, color);
		Putpixel64k(xc + y, yc - x, color);
		Putpixel64k(xc - y, yc - x, color);
		Putpixel64k(xc - y, yc + x, color);
		
		if (d < 0)
		{
			d += x * 4 + 6;
		}
		
		else
		{
			d += (x - y) * 4 + 10;
			y--;
		}
	}
}

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
void Circlefill(int xc, int yc, int radius,unsigned int color)
{
		/*画圆圈的定位变量和决策变量*/
	int x = 0,
		y = radius,
		dx = 3,
		dy = 2 - radius - radius,
		d = 1 - radius;
	
	/*半径必须为正，否则退出*/
	if (radius <= 0)
	{
		return;
	}
	
	/************************************
	以下运用Bresenham算法生成实心圆。
	该算法是得到公认的成熟的快速算法。
	具体细节略去。
	************************************/
	while (x <= y)
	{
	
		Line(xc - x, yc - y, xc + x, yc - y, color);
		Line(xc - y, yc - x, xc + y, yc - x, color);
		Line(xc - y, yc + x, xc + y, yc + x, color);
		Line(xc - x, yc + y, xc + x, yc + y, color);

        if (d < 0)
        {
            d += dx;
            dx += 2;
        }
        
        else
        {
            d += (dx + dy);
            dx += 2;
            dy += 2;
            y--;
		}

        x++;
	}
}


int Getpixel64k(int x, int y)
{
	/*显存指针常量，指向显存首地址，指针本身不允许修改*/
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;
	
	/*要切换的页面号*/
	unsigned char new_page;
	
	/*对应显存地址偏移量*/
	unsigned long int page;
	
	/*判断点是否在屏幕范围内，不在就退出*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return 0;
	}
	
	/*计算显存地址偏移量和对应的页面号，做换页操作*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 15;	/*32k个点一换页，除以32k的替代算法*/
	Selectpage(new_page);
	
	/*返回颜色*/
	return video_buffer[page];	
}

unsigned char Getpixel256(int x, int y)
{
	/*显存指针常量，指向显存首地址，指针本身不允许修改*/
	unsigned char far * const video_buffer = (unsigned char far *)0xa0000000L;

	/*要切换的页面号*/
	unsigned char new_page;

	/*对应显存地址偏移量*/
	unsigned long int page;

	/*判断点是否在屏幕范围内，不在就退出*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return 0;
	}

	/*计算显存地址偏移量和对应的页面号，做换页操作*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 16;	/*64k个点一换页，除以64k的替代算法*/
	Selectpage(new_page);


	return video_buffer[page];
}

int Imagesize(int xmin,int ymin,int xmax,int ymax)//计算像素点个数，方便开内存
{
	return abs(xmax-xmin+1)*abs(ymax-ymin+1);
}

void Get_image(int xmin,int ymin,int xmax,int ymax,unsigned char* buffer)//得到每一个像素点的颜色
{
	int i,j,dx,dy;
	//char s1[5],s2[5],s3[5];
	if(xmin>xmax||ymin>ymax)return;

	dx=xmax-xmin;
	dy=ymax-ymin;
	buffer = (unsigned char *) malloc (Imagesize(xmin,ymin,xmax,ymax));
	//itoa(dx,s1,10);//
	//itoa(dy,s2,10);//
	//put_asc(400,100,s1,0,2,2);//第i行
	//put_asc(400,200,s2,0,2,2);//第j列
	for(i=0;i<=dx;i++)
		for(j=0;j<=dy;j++)
		{	
			//itoa(i,s1,10);//
			//itoa(j,s2,10);//
			//itoa((int)(bufer+i*(dy+1)+j),s3,16);//
			*(buffer+i*(dy+1)+j)=Getpixel64k(i+xmin,j+ymin);//将二维数组降维存储
			//put_asc(i*30,j*30,s1,0,2,2);//第i行
			//put_asc(i*30+20,j*30,s2,0,2,2);//第j列
			//put_asc(i*30+200,j*30,s3,0,2,2);//地址变化
			//delay(500);
		}


	return;
}
void Put_image(int xmin,int ymin,int xmax,int ymax,const unsigned char* buffer)//输出像素点
{
	int i,j,dx,dy;

	if(xmin>xmax||ymin>ymax)return;

	dx=xmax-xmin;
	dy=ymax-ymin;
	for(i=0;i<=dx;i++)
		for(j=0;j<=dy;j++)
			 Putpixel64k(i+xmin,j+ymin,*(buffer+i*(dy+1)+j));
	return;
	free(buffer);
}