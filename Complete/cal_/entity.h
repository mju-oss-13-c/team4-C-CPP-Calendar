#include <iostream>   				//For all the console stream input-output operations �ܼ� ��ɾ� �����
#include <fstream> 					//For all the file stream input-output operations ���� �����
#include <string>					//For all the string related functions ���ڿ�
#include <stdio.h>					//For all the standard input/output functions ���Ĵٵ� ������� ����.
#include <windows.h>				//For all the functions required to access WINDOWS API ������ api�� ���� �ޱ� ���� �ʿ��� ��
#include <ctype.h>					//For all the character related functions ��� �ɸ��Ϳ� ���õ� ���
#include <stdlib.h>					//For all the Standard Library Functions (such as atoi)  atoi���� ���Ĵٵ� ���̺귯��
#include <math.h>					//For all the standard mathematical functions ������ ��� ����.
#include <Shlobj.h> 				//For all the functions related to windows shell objects ������ �� ������Ʈ ���� ���
#include <Shlwapi.h>				//For all the Shell Registry Handling Functions �� ������Ʈ�� ���� ���
#include "md5.h"
#pragma once




extern int  a, i, j, m, q, s, u, w, x, y, z, ri, bt, kl, date, mon, year, daynum, again, met, ket, kvt, cor, cnty, mark, ln, ret,
	 counter, wrap, startDOW, weekNumber, dayCounter, loopCount, flag, acc, lim, strno, fla, ch, clrcode, nmtch,
	 cenno[4],
	 month		[12],  
	 daysInMonth[12];
	
extern char uchk[25],pchk[25],bul, ch1, day[10], usrn[25], pass[25], pchoice, bi, numstr[15], str[15], strcase, name[25], fl[3], o,
	 week	[ 7][10],
	 months [12][10];

extern std::string ver;

extern TCHAR spth[MAX_PATH]; //to store path

extern COORD coord;//��ǥ�踦 ��Ÿ�� �� ���� �Լ�. 
