#include"func.h"


using namespace std;

/******************************************************OUTLINE FUNCTIONS****************************************************************/
calendar cal;

inline void calendar::setpos()								//Function to give a horizontal tab while printing tabular calendar
	{
		if(s<3)								/*This if-else construct checks for
											 the month and sets the ouput position to print 
											 the calendar in the tabular format*/
		gotoxy(28*s+q,w+2);					
		else if (s>=3 && s<6)
		gotoxy(28*(s-3)+q,13+w);
		else if (s>=6 && s<9)
		gotoxy(28*(s-6)+q,24+w);
		else if (s>=9 && s<12)
		gotoxy(28*(s-9)+q,35+w);
	}

/***************************************************************************************************************************************/
inline void calendar::newline()					//Function for nextline ("\n") while printint tabular calendar		
	{	
		if(s<3)								//This if-else construct checks for the month and prints the newline  
		gotoxy(28*s+1,u);					//and redirects the cursor to set proper alignment
		else if (s>=3 && s<6)
		gotoxy(28*(s-3)+1,u);
		else if (s>=6 && s<9)
		gotoxy(28*(s-6)+1,u);
		else if (s>=9 && s<12)
		gotoxy(28*(s-9)+1,u);
	}
/*************************Function Related to user Registration and login***************************************************************/
struct usr{				//structure to store username and password in Calendar App
		char namew[33];
		char passw[33];		
	}usacc[10],uracc[10];		//usacc-get registration data from user
								//uracc-get registration already present
	
char * calendar::inpass()		//Function to Read the password from the user
{
	
	MD5 md5;	
	char c[14];
		for(w=0;w<10;w++){pchk[w]='\0';} 
		while(i!=13)		//loop until 'Enter' is pressed
		{
			c [i]= GetCh();
			if(c[i]==13)	//to end the input process on hitting return
				{
    				break;
				}
			if(c[i]!=13 && c[i]!=0 && c[i]!=9 && c[i]!=27 && c[i]!=32 && c[i]!=18 && c[i]!=-32 )	//condition to prevent the special character to be inputted into password
				{
					if (c[i]==8)																	//Condition to erase password if backspace is pressed
						{
					
							coord = getxy();
							kl= coord.X-1;
							if(coord.X>cor)
							{
							gotoxy(kl,coord.Y);
							putchar('\0')   ;i--;													//putting a null character
							}
							coord = getxy();
		
							if(coord.X<cor+1)
								gotoxy(cor+1,14) ;
							coord = getxy();
							kl= coord.X-1;
							gotoxy(kl,coord.Y);
							continue;														//After erasing sending the control to input handle again
						}
					else
						{
							putchar('*');															//Masking an '*' over the password characters
							if (i<20)
								pchk[i]=c[i];
							coord = getxy();
							i=coord.X-cor;						
						}
				}
		}
		gotoxy(0,29);
		char *passstr=md5.digestString(pchk);
		return passstr;
}


int calendar::login()			//Function to manage sign-in in calendar App
{
	
   //----------------------------Local Identifiers for digesMD5()----------------------//
	char getusrn2str [33], getpass2str [33];
   //---------------------------------------------------------------------------------//
	MD5 md4;
	int siz=0,size=0;	
	//-----
	TCHAR spth[MAX_PATH],kpth[MAX_PATH];
	SHGetFolderPath(NULL,CSIDL_LOCAL_APPDATA|CSIDL_FLAG_CREATE,NULL, 0,spth); //function to find local applaction directory
	SHGetFolderPath(NULL,CSIDL_LOCAL_APPDATA|CSIDL_FLAG_CREATE,NULL, 0,kpth);		
	PathAppend(spth, TEXT("Calendar\\acc.cdb"));	//function to edit stored path
	PathAppend(kpth, TEXT("Calendar\\accname.cdb"));
	fstream fin; fstream fpin;
	fpin.open (kpth , ios::in|ios :: app);
	fpin.seekg(0, std::ios_base::end);siz= fpin.tellg();fpin.seekg(0, std::ios_base::beg);
	//char yt[siz];
	char *yt;
	yt = (char*)malloc(sizeof(char)*siz);

	while (fpin.good())     // loop while extraction from file is possible
  		{yt[i]= fpin.get(); if (yt[i]=='*') cnty++; i++;}
  	fin.open(spth, ios::in|ios :: app);
	fin.seekg(0, std::ios_base::end);
	size = fin.tellg();fin.seekg(0, std::ios_base::beg);
	
	if(size==0)
	{clrline();gotoxy(5,23);setclr(14);cout<<"You need to create an account";gotoxy(10,24);cout<<"Wait!!!"; Sleep(2000); return 7;}
	
	//char gt[size];
	char* gt;
	gt = (char*)malloc(sizeof(char)*size);
	int ry=0;
	i=0; 
	while (fin.good())     // loop while extraction from file is possible
  	{gt[i]= fin.get();   i++; }			
	i=0;j=0;	
	for(j=0;j<cnty;j++)
	{
		for(i=(0+66*j),w=0;i<=(31+j*66),w<32;i++,w++)
			{uracc[j].namew[w]=gt[i];}
	
	for(ry=(33+66*j),w=0;ry<=(64+j*66),w<32;ry++,w++)
			{	
			uracc[j].passw[w]=gt[ry];				
			}
	}	
// test to check the username and password hashes
/*	gotoxy(0,23);
	for(j=0;j<cnty;j++)
	{
		cout<<uracc[j].namew;
		cout<<"\n";
	
		cout<<uracc[j].passw;
		cout<<"\n";

	}*/
	
	setclr(14);
	gotoxy(50,11);	scanf("%s", usrn);
	char* usrstr  = md4.digestString(usrn);
	strcpy(getusrn2str, usrstr);		//saving hash in char array;
	for(i=0;i<cnty;i++)
	{
		if(strncmp(getusrn2str,uracc[i].namew,33)==0)	{nmtch=i; break;}		
	}
	gotoxy(5,23);
	i=0;
	gotoxy(50,14);
	cor=50;	
	strcpy(getpass2str,inpass());		//inputting the password
	
			if(!strncmp(getpass2str,uracc[nmtch].passw,33) && !strncmp(getusrn2str,uracc[nmtch].namew,33))
      			acc=0;
			if(strncmp(getpass2str,uracc[nmtch].passw,33) || strncmp(getusrn2str,uracc[nmtch].namew,33))
      			acc=1; 
				   
      if(acc==1)   	return 1;
      else		   	return 5;			//returning something !=1
}

int calendar::regusr()					/**
										Function to manage user registration.
								    	*/
{
	int i=1;
	TCHAR spth[MAX_PATH],kpth[MAX_PATH];
	SHGetFolderPath(NULL,CSIDL_LOCAL_APPDATA|CSIDL_FLAG_CREATE,NULL, 0,spth); /*function to find local applaction directory*/		
	SHGetFolderPath(NULL,CSIDL_LOCAL_APPDATA|CSIDL_FLAG_CREATE,NULL, 0,kpth);		
	PathAppend(spth, TEXT("Calendar\\acc.cdb"));	//function to edit stored path
	PathAppend(kpth, TEXT("Calendar\\accname.cdb"));
	char* namestrn;
	cal.setclr(14);	
	char tname[15]; 
	struct uname{char pname[33];}sth[10];	
  	fstream fout,fp; ifstream fch; 
  	fout.open (spth , ios::out|ios :: app);
  	fp.open (kpth , ios::out|ios :: app);
	fch.open (kpth , ios::in | ios :: app );
	fch.seekg(0, std::ios_base::end);int siz= fch.tellg();fch.seekg(0, std::ios_base::beg);

	//char qt[siz];
	char* qt;
	qt = (char*)malloc(sizeof(char)*siz);

	gotoxy(9,11); scanf("%s",tname);
	//-----variables
	MD5 md4,md3;	int cntn=0,yui;		i=0;	
	//-----
	namestrn  = md4.digestString(tname);	
	while (fch.good())     // loop while extraction from file is possible
  		{   qt[i]= fch.get(); if (qt[i]=='*') cntn++; i++;}
	for(i=1;i<=cntn;i++)
		{
			char* tch;					//pointer to store token from the string
			tch = strtok(qt, "*");		//tokenizing string - * is the dilimiter
			while (tch != NULL)		
			{
			strcpy(sth[i-1].pname, md3.digestString(tch));	//storing MD5 hash of username
			tch = strtok(NULL, "*");	//putting null character at the end of token
			i++;	
			}
			gotoxy(5,23);
		}	
	for( yui=0; yui<cntn; yui++)
	{	
	if(!strcmp(namestrn,sth[yui].pname)) //condition to check if similar username exists
		{
		clrline();		gotoxy(5,23);	cout<<"Username already exists";
		gotoxy(10,24);	cout<<"Wait!!!";
		Sleep(2000);
		return 2;
		}
	}
	fp<<tname; fp<<"*";
	strcpy(usacc[i].namew,namestrn);
	fout<<usacc[i].namew;
	gotoxy(9,14);	cor=9;	i=0;
	strcpy(usacc[i].passw,inpass()); //inputting the password			
	fout<<"*";
	fout<<usacc[i].passw;
	fout<<"*";	
  	fout.close();

	return 0;		
}

int calendar::passscr()				/**
										Function for managing the login menu for the Calendar APP.
								    	*/
{	ket=1;	int cond=1;
	while(cond==1)
	{
		docls();
		setclr(14);		//Function to change the colour of output handle in the console
		if (ket==0 && w!=7)
		{
			clrline();gotoxy(10,23);cout<<"Your account has been created";gotoxy(10,24);cout<<"Sign-in now";
		}
		ket=0;
		setclr(2);		//Function to change the colour of output handle in the console
		gotoxy(0,6);		cout<<"________________________________________________________________________________";
		gotoxy(0,20);		cout<<"________________________________________________________________________________"; 
		for(int yt=0;yt<16;yt++)
		{
			gotoxy(39,6+yt);	cout<<"|"; //xB3 is ascii hex for vertical bar character
		}
		setclr(15);
		gotoxy(15, 6);		cout<<"Sign-up";
		gotoxy(56, 6);		cout<<"Sign-in";
		gotoxy(36, 2);	    std::cout << "CALENDAR";
		gotoxy( 9,10);		cout<<"Enter the username\n";
		gotoxy( 9,13);		cout<<"Enter the password\n";
		gotoxy(50,10);		cout<<"Enter the username\n";
		gotoxy(50,13);		cout<<"Enter the password\n";
		setclr(12);
		gotoxy(12,6);		putchar (mark);
		bool passchoice=true;
		while (passchoice==true)
		{
			INPUT_RECORD keys=readkeys(); //reading keyboard input
			if(keys.Event.KeyEvent.wVirtualKeyCode==VK_RIGHT) //Right key
			{									
			cal.setclr(2);cal.gotoxy(12,6); cout<<"__"; cal.gotoxy(53,6);cal.setclr(12); putchar (mark); //moving marker
			}
			else if(keys.Event.KeyEvent.wVirtualKeyCode==VK_LEFT) //Left key
			{									
			cal.setclr(2);cal.gotoxy(53,6); cout<<"__"; cal.gotoxy(12,6);cal.setclr(12); putchar (mark); //moving marker
			}
			else if(keys.Event.KeyEvent.wVirtualKeyCode==VK_RETURN)	//ending loop on return(enter)
			{		 					
			passchoice=false;											//assigning false value to bool running to end the loop
			}
		}
		
		 //finding position of cursor from the buffer
			coord = cal.getxy();
		setclr(14);	
		if (coord.X==13 || coord.X==12) {gotoxy(12, 6); cal.setclr(2);	cout<<"__"; ket=regusr(); continue;}
		else if (coord.X==54 || coord.X==53) {gotoxy(53, 6); cal.setclr(2);	cout<<"__";	w=login();
		if (w==1) return 1; else if (w==7) continue; else if (w==5) return 0;}
	}
	
}
/***************************************************************************************************************************************/
void calendar::chkdate()					/**
										Function to check if the date entered by the user is correct
										and also check if the date is of the past or a future date 
										or it is today's date
										(works on system date)(uses SYSTEMTIME class in WINDOWS.H)
								    	*/
{
	again=0;
    
	if (year%4 == 0 && (year %100 != 0 || year%400 == 0))//Updation of the array containing no of days in a month, if leap year is detected
	{
  	daysInMonth[1] 	  = 29;								//updation of days in feb in Gregorian calendar
  	month[0]		  = 5;								//updating the month no for january
    month[1]          = 1;								//updating the month no for febuary
	}
	else
	{
 	daysInMonth[1]    = 28;								//updation of days in feb in Gregorian calendar
 	month[0]		  = 6;								//updating the month no for january
	month[1]          = 2;								//updating the month no for febuary
	}
		
	SYSTEMTIME ChkDate;             /*SYSTEMTIME is a structure in Windows Library 
									used to access Windows Time of the System clock*/
    GetLocalTime(&ChkDate);
	if(ChkDate.wYear > year)		//Checking if the date is of the past or a future date 
		flag = 0;					//or it is Today's date	
	else if(ChkDate.wYear < year)
		flag = 1;
	else if(ChkDate.wYear == year)
	{
		if(ChkDate.wMonth > mon)
			flag = 0;
		else if(ChkDate.wMonth < mon)
			flag = 1;
		else if(ChkDate.wMonth == mon)
		{
			if(ChkDate.wDay > date)
				flag = 0;
			else if(ChkDate.wDay < date)
				flag = 1;
			else if(ChkDate.wDay == date)	
				flag = 2;
		}
	 }
	
	if(fla==2 || mon > 12)														//checking if the month is not correct
	{
		setclr(10);	
		gotoxy(26, 4);	cout<<"Enter month correctly--WAIT";
		again=1 ;
		Sleep(2000);
		return;
	}
	else if(date>daysInMonth[mon-1] || date <1 )								//checking if the date is not correct
	{
		setclr(10);	
		gotoxy(27, 4);	cout<<"Wrong date entered--WAIT";
		again=1 ;
		Sleep(2000);
	}
	else if(year<1752 || year>9999)										//checking if the year is not between (1700-2300)
	{ 
		setclr(10);		
		gotoxy(24, 4);	cout<<"Enter year from 1753-9999--WAIT";       /*In 1752 some days in sept were omitted as per the calendar change which creates 
																	     wrong display of calendar before sept 1752 from the algoritm used.*/  
		Sleep(2000);
		again=1	;
	}
	else if(daynum>7)										//checking if the year is not between (1700-2300)
	{ 
		setclr(10);		
		gotoxy(24, 4);	cout<<"Enter DAY correctly--WAIT";
		Sleep(2000);
		again=1	;
	}	
}
/***************************************************************************************************************************************/

void calendar::chkstr()				/**
									function to read day name or month name from the user 
									and assign a number to it for identification
									*/
{
	fla=0;
	if(isdigit(str[0])==0)							
	{
		for(i=0;i<=lim;i++)
		{
			if(isupper(str[i]))
			str[i] = tolower(str[i]);
		}
		if(isupper(str[0])==0)			
			str[0]-=32;					//making the string title case
	}
	strno = 4; 
	for(i=0;i<=lim;i++)	//loop to recognise a string and assign a number to it													
		{	
			fla = 0;
			if(strcase == 'm')
				ret=strncmp(str,months[i],3);																		
			else if(strcase == 'd')
				ret=strncmp(str,week[i],3);
			if(ret == 0)
				{
					if(strcase == 'm')
					{
						strno = i+1;				//storing the string code
						break;
					}
					else if(strcase == 'd')
					{
						strno = i; 
						break;
					}
				}
			else if (strcase == 'm') fla = 2;
		}		

}

/***************************************************************************************************************************************/

void calendar::calmenu()			//function to operate main menu to the calendar app		
{
	cal.gotoxy(3,4); cal.setclr(12); putchar (mark);	//prinying initial cursor
  	bool running = true;		//condition for input loop
  					//structure to store coordinates of the output cursor
	HANDLE hanInput = GetStdHandle(STD_INPUT_HANDLE);		//handle to store keyboard input
    DWORD InputsReads = 0;		//long int variable to store number of inputs
  	INPUT_RECORD irkInput;  		//store keyboard input
  	int keyr;
	Sleep(300);
	while(running)				//loop to take keyboard input to operate menu
	{ 
		 //finding position of cursor from the buffer
		coord = getxy();
		
		if (coord.Y%2!=0 && keyr==VK_DOWN)	
		{
	 	cal.clr_mrks(); gotoxy(3,coord.Y+1); putchar (mark); 
		}
		if (coord.Y%2!=0 && keyr==VK_UP)	
		{
	 	cal.clr_mrks();  gotoxy(3,coord.Y-1); putchar (mark); 
		}
			
		FlushConsoleInputBuffer(hanInput);					//flushing input buffer
		ReadConsoleInput(hanInput, &irkInput, 1, &InputsReads);	//reading new input
		keyr=irkInput.Event.KeyEvent.wVirtualKeyCode;
		
		if(keyr==VK_DOWN && coord.Y<=13) //Down key 
		{									
		cal.clr_mrks(); cal.gotoxy(3,coord.Y+1);cal.setclr(12); putchar (mark); //moving marker
		}

		if(keyr==VK_UP && coord.Y>4 ) //Up key
		{		 					
		cal.clr_mrks(); cal.gotoxy(3,coord.Y-1); cal.setclr(12); putchar (mark);//moving marker		
		}
		if(keyr==0x31 || keyr==0x61 ) //1 key
		{		 					
		cal.clr_mrks(); cal.gotoxy(3,4); cal.setclr(12); putchar (mark);			//moving marker		
		}
		if(keyr==0x32 || keyr==0x62) //2 key
		{		 					
		cal.clr_mrks(); cal.gotoxy(3,6); cal.setclr(12); putchar (mark);			//moving marker		
		}
		if(keyr==0x33 || keyr==0x63) //3 key
		{		 					
		cal.clr_mrks(); cal.gotoxy(3,8); cal.setclr(12); putchar (mark);			//moving marker		
		}
		if(keyr==0x34 || keyr==0x64) //4 key
		{		 					
		cal.clr_mrks(); cal.gotoxy(3,10); cal.setclr(12); putchar (mark);		//moving marker		
		}
		if(keyr==VK_RETURN)	//ending loop on return(enter)
		{		 					
		running=false;											//assigning false value to bool running to end the loop
		}
		if(keyr==VK_ESCAPE) //ending app on Escape
		{						 					
		exit(0);
		}
		if(keyr==VK_F10) //showing about info
		{						 					
		cal.gotoxy(0,12);
		running=false;
		}

	}
			//finding position of cursor from the buffer
	coord = getxy();
	if(coord.Y==4) kvt=1;if(coord.Y==6) kvt=2;if(coord.Y==8) kvt=3;if(coord.Y==10) kvt=4; if(coord.Y==12) kvt=5; if(coord.Y==14) kvt = 6;

}
/***************************************************************************************************************************************/

void calendar::printAll()	//Function to print the calendar of year to console screen
{
	ri=77;		bt=50;		setscr();	// setting width of the screen
				/*COORD is a structure in Windows library
							  storing coordinates of Output cursor*/ 
  	if(ch==3)
	{
		for(m=0;m<5;m++)					//Loop of print lines to give a Tubular look
			{
				gotoxy(0,m*11);
				setclr(8);	
				cout<<"_______________________________________________________________________________";
			}
	}
	date=1;		mon=counter;	startDOW = dayno() ;	wrap = startDOW;		s=counter-1;
	q=0;		w=0;	     	setpos();
	setclr(2);	
	cout << "---------------------";
	
	coord = getxy();
	setclr(15);	
	gotoxy((coord.X-17)+((9-(strlen(months[counter-1])))/2),coord.Y);cout <<months[counter-1]<<" "<<year;
 	q=0;		w=1;			setpos();
	setclr(12);	
	cout << "  S  M  T  W  T  F  S" ;		//printing the days
 	q=0;		w=2;			setpos();
	setclr(2);	
	cout << "---------------------";
    for (loopCount = 0; loopCount < startDOW; loopCount++)
 	{
 		if(loopCount==0)
			{
				q=3;	w=3;	setpos();
			}
		else
				cout << "   ";				// how many space to indent new month
 	}
	cout<<" ";
 	for (dayCounter=1;dayCounter<=daysInMonth[counter-1]; dayCounter++)
 	{	
		if (wrap == 7)						//if Saturday, next line
 			 {
 			 
			 coord = getxy();
			 u=coord.Y+1;
			 newline();
			 wrap = 0;						//resets day of week counter
 			 weekNumber++;												
 			 }
	 	if(wrap==0) 
		setclr(14);	
		else
		setclr(15);		 
		date=1;		mon=counter;	 startDOW = dayno() ;					   
		 if (dayCounter<10 && startDOW!=0)	//adds space in front for single digit dates
			 cout <<" "<< dayCounter << " ";	
		 else if (dayCounter<10 && startDOW==0)
		 {	  
			 if (dayCounter==1) 
				{
					
					coord = getxy();
					u=coord.Y+1;
					newline();
				}
			 cout <<" "<< dayCounter << " ";		//printing the dates
		 }	
		 else
			 cout << dayCounter << " ";				//printing the dates
			 wrap++;
 	}
		 
		 coord = getxy();
		 gotoxy(coord.X,coord.Y+4);
}
/***************************************************************************************************************************************/
void calendar:: printcaltofile()								//function to print the calendar of a month
{
	ofstream fout;
	fout.open(name,ios::app);
	date=1;		mon=counter;	startDOW = dayno() ;	wrap = startDOW;		s=counter-1;
    fout << "-----------------------------------------\n";
	coord = getxy();i=(37-(strlen(months[counter-1])))/2; while(i){fout<<" ";i--;}
	fout <<months[counter-1]<<" "<<year;
 	fout << "\n\n Sun   Mon   Tue   Wed   Thu   Fri   Sat" ;		//printing the days
	fout << "\n-----------------------------------------\n";
    for (loopCount = 0; loopCount < startDOW; loopCount++)
 	{
				fout << "      ";				// how many space to indent new month
 	}
	fout<<" ";
 	for (dayCounter=1;dayCounter<=daysInMonth[counter-1]; dayCounter++)
 	{	
	
		if (wrap == 7)						//if Saturday, next line
 			 {
			 wrap = 0;						//resets day of week counter
 			 weekNumber++; 
			  fout<<"\n\n ";												
 			 }
	 	date=1;		mon=counter;	 startDOW = dayno() ;					   
		if (dayCounter<10)
		   fout <<"  ";
		else
			fout << " ";
			fout << dayCounter << "   ";				//printing the dates
			wrap++;
	 	
 	}
fout<<" \n\n\n\n";
fout.close();
}
/***************************************************************************************************************************************/

void calendar::monthcal()								//function to print the calendar of a month
{
	
  	date=1;		mon=counter; 	startDOW = dayno() ;	wrap = startDOW;
	setclr(2);
	ri=57;		bt=30;		setscr();	// setting width of the screen	
	cout<<"\n\n\n";
	cout << "-----------------------------------------";
	
	coord = getxy();
	setclr(15);	
	gotoxy((37-(strlen(months[counter-1])))/2,coord.Y);cout <<months[counter-1]<<" "<<year;
  	setclr(12);	
	cout << "\n\n Sun   Mon   Tue   Wed   Thu   Fri   Sat" << endl;				//printing the days
 	setclr(2);	
	cout << "\n-----------------------------------------\n" << endl;
    setclr(15);	
	for (loopCount = 0; loopCount < startDOW; loopCount++)
 	{
 		cout <<"      ";						// how many space to indent new month
 	}
		cout<<" ";
 	for (dayCounter=1;dayCounter<=daysInMonth[counter-1]; dayCounter++)
 	{
		 if (wrap == 7)						//if Saturday, next line
 			 {
 			 cout << "\n\n ";
 			 wrap = 0;						//resets day of week counter
 			 weekNumber++;											
 			 }
		 if(wrap==0) 
		 setclr(14);	
		 else
		 setclr(15);	
 		 if (dayCounter<10)					//adds space for single digit dates
 			 cout << "  ";
 		 else 
 			 cout << " ";					//adds space for double digit dates
 			 cout << dayCounter << "   ";	//prints the date
			 wrap++;
 	}
 					cout << "\n\n";
}

/***************************************************************************************************************************************/

void calendar::day2date ()							//Function to print dates of the given day in a month.
{	
	if(ket!=0)
	{
	if(isdigit(day[0])==0) 
	{	
		strcpy(str,day);	lim=7;		strcase='d';	chkstr(); daynum=strno;
	}
	else 
		daynum=atoi(day);
	}
	setclr(2);	
	gotoxy(28, 6);   	cout<<"_____________________";
	gotoxy(28,17);   	cout<<"_____________________\n";
	setclr(15);	
	gotoxy(30, 6);		cout<<week[daynum]<<" lies on";
	setclr(15);	
	gotoxy(28, 6);
	for(j=1;j<=daysInMonth[mon-1];j++)								//loop to check for each day
		{
			date=j;
			wrap=dayno();
			if(daynum==wrap)
			{
			if(j<10)
			  	{
					coord = getxy();
					gotoxy(28,(coord.Y+2));	
					cout<<bul<<"\t"<<"0"<<j<<" "<<months[mon-1]<<" "<<year;	//printing the dates < 10
				}
			else
         		{
					
					coord = getxy();
					gotoxy(28,(coord.Y+2));	cout<<bul<<"\t"<<j<<" "<<months[mon-1]<<" "<<year;		//printing dates > 10
				}
			}
		}
}
	
/***************************************************************************************************************************************/
