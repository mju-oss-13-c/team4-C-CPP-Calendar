#include <iostream>   				//For all the console stream input-output operations 콘솔 명령어 입출력
#include <fstream> 					//For all the file stream input-output operations 파일 입출력
#include <string>					//For all the string related functions 문자열
#include <stdio.h>					//For all the standard input/output functions 스탠다드 입출력을 위함.
#include <windows.h>				//For all the functions required to access WINDOWS API 윈도우 api를 승인 받기 위해 필요한 것
#include <ctype.h>					//For all the character related functions 모든 케릭터와 관련된 펑션
#include <stdlib.h>					//For all the Standard Library Functions (such as atoi)  atoi같은 스탠다드 라이브러리
#include <math.h>					//For all the standard mathematical functions 수학적 계산 위함.
#include <Shlobj.h> 				//For all the functions related to windows shell objects 윈도우 쉘 오브젝트 관련 펑션
#include <Shlwapi.h>				//For all the Shell Registry Handling Functions 쉘 레지스트리 관리 펑션
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

extern COORD coord;//좌표계를 나타낼 때 쓰는 함수. 
