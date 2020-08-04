#ifndef _MOUSE_H_
#define _MOUSE_H_
#include"draw.h"
#include"svgamode.h"
#include<dos.h>

void Cursor(int x,int y,int color);
int Initmouse(int xmi,int xma,int ymi,int yma);
int Readmouse(void);
void Newxy(void);
void Mouse_savebk(int x,int y);
void Mouse_putbk(int x,int y);
int Mouse_press(int x1,int y1,int x2,int y2);
int Mouse_pressother(int x1, int y1, int x2, int y2);
int Mouse_above(int x1,int y1,int x2,int y2);
int Mouse_aboveother(int x1, int y1, int x2, int y2);
int Button(void);
void Mouse_press_getxy(int *x,int *y);

#endif