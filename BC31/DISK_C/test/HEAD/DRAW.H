#ifndef_DRAW_H_
#define_DRAW_H_
#include"svgamode.h"
#define LENGTH 1024
#define WIDTH  768
void Linex(int x1,int y1,int x2,int y2,unsigned int color);//平行x轴直线
void Liney(int x1,int y1,int x2,int y2,unsigned int color);//平行y轴直线
void Tri_R(int x,int y,int color);//右边三角形
void LineThick(int x1,int y1,int x2,int y2,unsigned int color,int thick,int mode);//平行四边形
void Barshadow(int x1,int y1,int x2,int y2,unsigned int precolor,unsigned int shacolor);//矩形加影子
void LineThickSha(int x1,int y1,int x2,int y2,unsigned int precolor,unsigned int shacolor,int thick,int mode);//平行四边形加影子
void FrameSha(int x1,int y1,int x2,int y2,unsigned int precolor,unsigned intshacolor,int thick);//框加影子
void CirclefillSha(int x,int y,int r,unsigned int precolor,unsigned int shacolor);//圆形加影子
void Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned int color);//3d长方体，对角坐标，右后下角坐标
void Frame(int x1,int y1,int x2,int y2,unsigned int color,int thick);//框
void Arrow(int x,int y,unsigned int color,int mode);//各种箭头
void save_bk(int x1,int y1,int x2,int y2);//存背景
void put_bk(int x1,int y1,int x2,int y2);//取背景
void Rectangle(int left,int right,int top,int bottom,unsigned int color);//画三角形
#endif