#include"entity.h"


 int  a, i = 0, j, m, q, s, u, w, x, y, z, ri, bt, kl, date=0,mon=0, year =0, daynum = 0, again = 0, met, ket, kvt, cor, cnty, mark=178, ln, ret,
	 counter = 1, wrap = 0, startDOW = 0, weekNumber = 0, dayCounter = 1, loopCount = 0, flag, acc, lim, strno, fla = 0, ch = 0, clrcode, nmtch,
	 cenno[4]={0,5,3,1},
	 month		[12] = {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 },  
	 daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
char uchk[25],pchk[25],bul=16,ch1='y',day[10],usrn[25],pass[25],pchoice,bi,numstr[15],str[15],strcase,name[25],fl[3],o,
	 week	[ 7][10] = {"Sunday", "Monday","Tuesday", "Wednesday","Thursday","Friday","Saturday"},
	 months [12][10] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

 std::string ver = "4.1";

 TCHAR spth[MAX_PATH]; //to store path

 COORD coord;//좌표계를 나타낼 때 쓰는 함수.
 