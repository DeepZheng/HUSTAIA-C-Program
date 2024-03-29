#ifndef _HANZI_H_
#define _HANZI_H_

#include<dos.h>
#include<stdio.h>
#include"SVGAmode.H"
#include<process.h>


void printHZ12(int x,int y,char *s,int color
             ,int dx,int dy,int space);       /*12*12�����ֵ���ʾ*/
void printHZ16(int x,int y,char *s,int color
             ,int dx,int dy,int space);       /*16*16�����ֵ���ʾ*/
void printHZ24F(int x,int y,char *s,int color
             ,int dx,int dy,int space);   		/*24*24������κ��ֵ���ʾ*/
void printHZ24H(int x,int y,char *s,int color
             ,int dx,int dy,int space);  			/*24*24������庺�ֵ���ʾ*/
void printHZ24K(int x,int y,char *s,int color
             ,int dx,int dy,int space);    		/*24*24�����庺�ֵ���ʾ*/
void printHZ24S(int x,int y,char *s,int color
             ,int dx,int dy,int space);   		/*24*24�������庺�ֵ���ʾ*/
void printHZ32S(int x,int y,char *s,int color
             ,int dx,int dy,int space);   		/*32*32�������庺�ֵ���ʾ*/
void printHZ48K(int x,int y,char *s,int color
             ,int dx,int dy,int space);    		/*48*48�����庺�ֵ���ʾ*/
void Put_Asc16(int cx, int cy, char key, char fcolor);
void Put_Asc16_Size(int cx, int cy, int xsize, int ysize, char key, char fcolor);
void put_asc(int cx, int cy,char *s, char color,int xsize, int ysize);
#endif