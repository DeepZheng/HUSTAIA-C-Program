#ifndef_DRAW_H_
#define_DRAW_H_
#include"svgamode.h"
#define LENGTH 1024
#define WIDTH  768
void Linex(int x1,int y1,int x2,int y2,unsigned int color);//ƽ��x��ֱ��
void Liney(int x1,int y1,int x2,int y2,unsigned int color);//ƽ��y��ֱ��
void Tri_R(int x,int y,int color);//�ұ�������
void LineThick(int x1,int y1,int x2,int y2,unsigned int color,int thick,int mode);//ƽ���ı���
void Barshadow(int x1,int y1,int x2,int y2,unsigned int precolor,unsigned int shacolor);//���μ�Ӱ��
void LineThickSha(int x1,int y1,int x2,int y2,unsigned int precolor,unsigned int shacolor,int thick,int mode);//ƽ���ı��μ�Ӱ��
void FrameSha(int x1,int y1,int x2,int y2,unsigned int precolor,unsigned intshacolor,int thick);//���Ӱ��
void CirclefillSha(int x,int y,int r,unsigned int precolor,unsigned int shacolor);//Բ�μ�Ӱ��
void Bar3d(int x1,int y1,int x2,int y2,int x3,int y3,unsigned int color);//3d�����壬�Խ����꣬�Һ��½�����
void Frame(int x1,int y1,int x2,int y2,unsigned int color,int thick);//��
void Arrow(int x,int y,unsigned int color,int mode);//���ּ�ͷ
void save_bk(int x1,int y1,int x2,int y2);//�汳��
void put_bk(int x1,int y1,int x2,int y2);//ȡ����
void Rectangle(int left,int right,int top,int bottom,unsigned int color);//��������
#endif