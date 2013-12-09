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
#include "entity.h"

#pragma once

using namespace std;


class calendar	
{
	/** 
	This is the Main class of the Calendar Program
	it contains all the member functions required to
	perform all the calender related tasks in this calender
	appication.
	*/ 
/***************************************************************************************************************************************/	
private:

int  regusr(); //유저 등록
int  login(); //로그인
int  passscr(); //
char* inpass(); 
void setpos();
void newline();

/***************************************************************************************************************************************/
inline void cls( HANDLE hConsole )//HANDLE은 
{
   COORD coordScreen = { 0, 0 };
   DWORD cCharsWritten;//DWARD는 4바이트 정수로 unsigned long이다.
   CONSOLE_SCREEN_BUFFER_INFO csbi;//문서 참고
   DWORD dwConSize;
   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
         return;
   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
   if( !FillConsoleOutputCharacter( hConsole,(TCHAR)' ',dwConSize,coordScreen,&cCharsWritten ))
         return;
   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
         return;
   if( !FillConsoleOutputAttribute(hConsole,csbi.wAttributes,dwConSize,coordScreen,&cCharsWritten )) 
         return;
   SetConsoleCursorPosition( hConsole, coordScreen );
}

/***************************************************************************************************************************************/
public:	

void chkdate();			// function to check if date entered is valid. 유효한 날짜인지 체크하는 함수
void chkstr();			// function to check for a correct string while taking input. 인풋하는 동안에 스트링이 맞는 치 확인하는 함수
void calmenu();	        // function to control key input in options menu. 옵션 메뉴를 컨트롤하는 함수.
void day2date ();		// function to dates from a day in a month of an year. 
void printAll();		// function to print calendar of an year on console screen.
void monthcal();		// function to print calendar of a month on console screen.
void printcaltofile();	// function to print calendar of an year to a .txt file.
/***************************************************************************************************************************************/	
inline void roadblock()					/**
									Accessor Function to access the private member funtion digestMD5
									and store a value to be used to verify if the credentials enterted match.
									*/
{
	a = passscr();
}
/***************************************************************************************************************************************/	
inline void setscr()	//Function to set the size of the console screen using standard windows functions
{
	HANDLE hOut;
    CONSOLE_SCREEN_BUFFER_INFO SBInfo;
    SMALL_RECT DisplayArea = {0, 0, 0, 0}; /*Structure in windows library
										Defines the coordinates of the 
										upper left and lower right corners of a rectangle.*/
   
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hOut,&SBInfo);
    DisplayArea.Right = ri;		// ri is the variable for storing width of console
	DisplayArea.Bottom = bt;	// bt is the variable for storing height of console
    SetConsoleWindowInfo(hOut,TRUE,&DisplayArea);
}
/***************************************************************************************************************************************/	
void clrline()
{
	for(i=23;i<25;i++)
	{
		for(j=0;j<70;j++)
		{
		gotoxy(j,i);//좌표 이동 함수
		putchar('\0');
		}
	}
}

/***************************************************************************************************************************************/	
	
CONSOLE_SCREEN_BUFFER_INFO csbi;	/*Function to go to any point
 									of the console screen
									*Taken from CONIO library for Windows)*/
inline void gotoxy ( short x, short y )
{  COORD coord = {x, y};
   SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), coord ); 
   //SetConsoleCursorPosition--A COORD structure that contains the column and row coordinates of the cursor in the console screen buffer.
}
/***************************************************************************************************************************************/

inline COORD getxy ()		//Function to get the position of the cursor the screen
{	
	CONSOLE_SCREEN_BUFFER_INFO csbi;	
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	COORD coord = csbi.dwCursorPosition;	
	return coord;
}
/***************************************************************************************************************************************/

char GetCh()	//Function to accept a character from the keyboard(Taken from CONIO library fow Windows)
{
	HANDLE hStdin = GetStdHandle (STD_INPUT_HANDLE);
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;
	char cChar;

  while(ReadConsoleInputA (hStdin, &irInputRecord, 1, &dwEventsRead)) // Read key press 
    if	(
		irInputRecord.EventType == KEY_EVENT
		&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_SHIFT	
		&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_MENU
		&&irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_CONTROL
		)
			{
				cChar = irInputRecord.Event.KeyEvent.uChar.AsciiChar;
				ReadConsoleInputA (hStdin, &irInputRecord , 1, &dwEventsRead);   //Read key release 
				return cChar;
			}
	return EOF;
}

INPUT_RECORD readkeys()			//Function to read all types of special keys
{

	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);		//handle to store keyboard input
    DWORD InputsRead = 0;		//long int variable to store number of inputs
  	INPUT_RECORD irInput;  		//store keyboard input
  	FlushConsoleInputBuffer(hInput);					//flushing input buffer
	ReadConsoleInput(hInput, &irInput, 2, &InputsRead);	//reading new input
	return irInput;
}
/***************************************************************************************************************************************/

inline void docls()	//user defined function to clear the screen using Windows library
{
    HANDLE hStdout;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    cls(hStdout); 
}
/***************************************************************************************************************************************/
inline void setclr(int clrcode)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),clrcode);
}
/***************************************************************************************************************************************/
inline void clr_mrks()
{
	int hy;
	for(hy=4;hy<11;hy++)
	{
	gotoxy(3,hy); putchar ('\0');
	}
}
/***************************************************************************************************************************************/
inline void infl(char o)
{
	cin >>numstr; cin.ignore(10000, '\n');
	switch(o)
	{
	case 'm':		{if(isdigit(numstr[0])==0) {strcpy(str,numstr); lim=12;	strcase='m';chkstr(); mon=strno;} else mon=atol(numstr); break;}
	case 'y':		{if(isdigit(numstr[0])==0) {again=1;} else year=atol(numstr); break;}
	case 'd':		{if(isdigit(numstr[0])==0) {again=1;} else date=atol(numstr); break;}
	case 'f':		{if(isdigit(numstr[0])==0) {strcpy(str,numstr);lim=6;strcase='d';chkstr();daynum=strno;}else{if (atol(numstr)<8){daynum=atol(numstr);ket=0;}else if(strno>7 || atol(numstr)>7){again=1;}}break;}
	}
}
/***************************************************************************************************************************************/
inline void showinfo()
{
		docls();
		setclr(14);
		gotoxy(35,1);	cout<<"Calendar About\n\n\n";
		setclr(10);
		cout<<"\t<CALENDAR-Tool To Perform Calendar Related Functions>\n\tVersion - "<<ver.c_str()<<"\n\tCopyright (C) <2011-13> under GNU Affero General Public License\n\n\t";
		cout<<"compiled using "; setclr(15); cout<<"GCC 4.6.1\n\n\t"; setclr(10);
		cout<<"This Calendar app has been created by "; setclr(15);cout<<"Shivam Mathur"; setclr(10);cout<<"\n\t you can reach him here\n\n\t";
		cout<<"Email \t\t : \t "; setclr(15); cout<<"shivam_jpr@hotmail.com\n\n\t";setclr(10);
		cout<<"Facebook \t : \t"; setclr(15); cout<<" https://facebook.com/SHIVAMROCKZ\n\n\t";setclr(10);
		cout<<"Twitter \t : \t "; setclr(15); cout<<"http://twitter.com/SAM_mathur\n\n\t"; setclr(10);
		cout<<"This App is hosted at - Sourceforge\n\t";setclr(15); cout<<"https://sourceforge.net/projects/c-cpp-calender\n\n\t";setclr(10);
		cout<<"Licence\n\t";setclr(15); cout<<"https://sourceforge.net/projects/c-cpp-calender/files/licence.txt";
		repeat(8);
}
/***************************************************************************************************************************************/
inline int dayno()										/**
													Function to give the dayno of any date 
													For eg if day is Sunday on a date, dayno is '0'
												*/
{	
	return (((cenno[((year/100)%4)]+((short)((year%100)+double(year%100)/4)%7)+month[mon-1])%7)+date)%7;	//returing day no
}
/***************************************************************************************************************************************/
inline void logcal(char bi)
{
		TCHAR pth[MAX_PATH];			//variable to store file name
		SHGetFolderPath(NULL,CSIDL_LOCAL_APPDATA|CSIDL_FLAG_CREATE,NULL, 0,pth); /*function to find local applaction directory*/				
		PathAppend(pth, TEXT("Calendar\\cal.log"));	//function to edit stored path
																		
		ofstream fout;	fout.open(pth, ios::app );	
	
		SYSTEMTIME tm;             		/*SYSTEMTIME is a structure in Windows Library 
										used to access Windows Time of the System clock*/
    	GetLocalTime(&tm);				//function ti get local timr of a country as per system clock
		if	(bi=='l')
			fout<<"\nlogin-failure\t\t\t"<<tm.wDay<<"/"<<tm.wMonth<<"/"<<tm.wYear<<" "<<tm.wHour<<":"<<tm.wMinute<<":"<<tm.wSecond;
		else if (bi=='s')
			fout<<"\nlogin-success\t\t\t"<<tm.wDay<<"/"<<tm.wMonth<<"/"<<tm.wYear<<" "<<tm.wHour<<":"<<tm.wMinute<<":"<<tm.wSecond;
		else if (bi=='d')
			fout<<"\nDay Finder launched\t\t"<<tm.wDay<<"/"<<tm.wMonth<<"/"<<tm.wYear<<" "<<tm.wHour<<":"<<tm.wMinute<<":"<<tm.wSecond;
		else if (bi=='m')
			fout<<"\nMonth Calendar\t\t\t"<<tm.wDay<<"/"<<tm.wMonth<<"/"<<tm.wYear<<" "<<tm.wHour<<":"<<tm.wMinute<<":"<<tm.wSecond;
		else if (bi=='y')
			fout<<"\nYear Calendar\t\t\t"<<tm.wDay<<"/"<<tm.wMonth<<"/"<<tm.wYear<<" "<<tm.wHour<<":"<<tm.wMinute<<":"<<tm.wSecond;
		else if (bi=='f')
			fout<<"\nYear Calendar printed to file\t"<<tm.wDay<<"/"<<tm.wMonth<<"/"<<tm.wYear<<" "<<tm.wHour<<":"<<tm.wMinute<<":"<<tm.wSecond;
		else if (bi=='t')
			fout<<"\nDate finder launched\t\t"<<tm.wDay<<"/"<<tm.wMonth<<"/"<<tm.wYear<<" "<<tm.wHour<<":"<<tm.wMinute<<":"<<tm.wSecond;
		fout.close();
}

/***************************************************************************************************************************************/
inline int repeat(int kvt)																//Function to repeat parts of program
{ 

	int fixl=0;
	if(kvt==3) {
		gotoxy(0,47);
		fixl=22;
	} else {
		gotoxy(0,25);
	}
	setclr(14);      	  cout<<"\tDo you want to go to Options Menu Again\n\n";	//Asking the user if he wants to repeat the program	
	setclr(15);		  cout<<"\t   YES\t\t\t\tNO:EXIT";	  
	bool repin=true;

	setclr(2);gotoxy(8,27+fixl); setclr(12); putchar (mark);
	while(repin)
	{
		INPUT_RECORD keym=readkeys(); //reading keyboard input
		if(keym.Event.KeyEvent.wVirtualKeyCode==VK_RIGHT) //Right key
		{									
			setclr(2); gotoxy(8,27+fixl); putchar ('\0'); gotoxy(37,27+fixl); setclr(12); putchar (mark); //moving marker
		}
		if(keym.Event.KeyEvent.wVirtualKeyCode==VK_LEFT) //Left key
		{									
			setclr(2); gotoxy(37,27+fixl); putchar ('\0'); gotoxy(8,27+fixl); setclr(12); putchar (mark); //moving marker
		}
		if(keym.Event.KeyEvent.wVirtualKeyCode==VK_RETURN)	//ending loop on return(enter)
			repin=false;								//assigning false value to bool running to end the loop			
	}

	COORD coort=getxy();		

	if(coort.X==37 )
		exit(0);

}
};

extern calendar cal;