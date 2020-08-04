#ifndef_DRAW_H_
#define_DRAW_H_
#include"svgamode.h"
#define LENGTH 1024
#define WIDTH  768
void Linex(int x1,int y1,int x2,int y2,unsigned char color);//平行x轴直线
void Liney(int x1,int y1,int x2,int y2,unsigned char color);//平行y轴直线
void Tri_R(int x,int y,int color);//右边三角形
void LineThick(int x1,int y1,int x2,int y2,unsigned char color,int thick,int mode);//平行四边形
void Barshadow(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor);//矩形加影子
void LineThickSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick,int mode);//平行四边形加影子
void FrameSha(int x1,int y1,int x2,int y2,unsigned char precolor,unsigned char shacolor,int thick);//框加影子
void CirclefillSha(int x,int y,int r,unsigned char precolor,unsigned char shacolor);//圆形加影子
void People(int x,int y,unsigned char color,char mode,float size);
void Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned char color);//3d长方体，对角坐标，右后下角坐标
void Frame(int x1,int y1,int x2,int y2,unsigned char color,int thick);//框
void Arrow(int x,int y,unsigned char color,int mode);//各种箭头
#endif