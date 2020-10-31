#ifndef _CHANGE_H_
#define _CHANGE_H_
#include "public.h"
#include "seller.h"


int changeinfo(SELLER *s);

void draw_changeinfo(void);

int input_changeinfo(SELLER *s,char *newac,char *newp,char *newpn);
#endif