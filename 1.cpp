#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<ctype.h>
#include<stdlib.h>
#include<iomanip.h>
long int code;

//class for collecting the personal details
class persdetails  
{
int trvlcode;
int  age[20];
char name[20][20];
char add[50];
char phnum[15];
char sex[20];
char passnum[10][10];
char familyname[30];
int num;
int numppl;
public:
void p_input(int);
void p_output();
void givefam();
int givecode();
int give();
}pob;

//declaring functions for cruise management system
int persdetails::give()
{
return num;
}
void persdetails::givefam()
{
cout<<familyname;
}
int persdetails::givecode()
{
return trvlcode;
}

//inputting personal Details
void persdetails::p_input(int cd)  //input func() of class1
{
trvlcode=cd;
num=0;
clrscr();
cout<<”\n\n\t:::::::::::::::::::::: PERSONAL DETAILS ::::::::::::::::::::::\n”;
cout<<”\t\t\t\t~~~~~~~~~~~~~~\n”;
cout<<”\n\t\t* Please fill in the details:\n\n\n\t\t\t1.Family Name: “;
gets(familyname);
cout<<”\n\t\t\t2.Address: “;
gets(add);
cout<<”\n\t\t\t3.Contact Number(10 Digit Mobile Number) : “;
gets(phnum);
cout<<”\n\n\n\t\tEnter The No of People Travelling: “;
cin>>numppl;
clrscr();
if(numppl>0)
{
cout<<”\n\t\tPlease Enter The Details of each Member/Members: “<<endl;
cout<<”\t\t\n”;
for(int i=0;i<numppl;i++)
{
cout<<endl<<”\n\t\tMember “<<i+1;
cout<<”\n\t\t~~~~~~~~”;
cout<<”\n\n\t\tFirst Name: “;
gets(name[i]);
cout<<”\n\t\tAge: “;
cin>>age[i];
cout<<”\n\t\tSex (M/F): “;
cin>>sex[i];
cout<<”\n\t\tPassport Number: “;
gets(passnum[i]);
if(age[i]>5)
{
num++;    //to calculate no of travellers below 5 yrs
}
}
}
}

//output personal details
void persdetails::p_output() //output func() of class1
{
clrscr();
cout<<”\n\n\t********************§ PERSONAL DETAILS §********************”<<endl;
cout<<”\n\n\t\t\tFamily Name:\t “<<familyname<<endl;
cout<<”\t\t\tAddress:\t “<<add<<endl;
cout<<”\t\t\tPhone Number:\t “<<phnum<<endl;
cout<<”\n\n\tName\t\tAge\t\tSex\t\tPassport Number\n”<<endl;
for(int i=0;i<numppl;i++)
{
cout<<”\t”<<name[i]<<”\t\t”<<age[i]<<”\t\t”<<sex[i]<<”\t\t”<<passnum[i]<<endl;
}
getch();
}

class travdetails   //class which holds the travel details
{
int trvtcode;
int day;
int month;
int year;
int num1;
int bdg_pt;
int go_pt;
int deck;
int cabin;
int pool;
int gym;
int sports;
int salon;
int spa;
int theatre;
public:
void initial();
void t_input(int);
void t_output();
void compute();
int gtcode();
void accept(int);
}tob;
void travdetails::initial()
{
pool=gym=theatre=sports=salon=0;
}
void travdetails::accept(int c)
{
num1=c;
}
int travdetails::gtcode()
{
return trvtcode;
}
void travdetails::t_input(int cd) //input func()-class2
{
tob.initial();
trvtcode=cd;
int i=1,opt;
clrscr();
do
{
clrscr();
cout<<endl;
cout<<”\n\n\t\t\t\t_||__TRAVEL DETAILS__”;
cout<<”\n\t\t\t\t\\___________________/”;
cout<<”\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~”;
cout<<”\n\n\t\tPlease enter the following details for your journey:”;
cout<<”\n\n\t\t*Note:Options marked with ‘*’ are compulsory.\n\t\t\tPlease do select them.”;
cout<<”\n\n\n\t\t\t\t*1.Boarding Point\n\t\t\t\t*2.Destination\n\t\t\t\t*3.Date of Departure\n\t\t\t\t*4.Deck\n\t\t\t\t 5.Cabin\n\t\t\t\t 6.Swimming Pool\n\t\t\t\t 7.Gymnasuim\n\t\t\t\t 8.Sports\n\t\t\t\t 9.Salon\n\t\t\t\t 10.Spa\n\t\t\t\t 11.Theatre\n\t\t\t\t 12.Back\n\n\t\t\t\t “;
cin>>opt;
switch(opt)
{
case 1:clrscr();
cout<<”\n\n\n\t\t\tSelect Boarding point:\n\n\t\t\t1.Mumbai\n\n\t\t\t2.Cochin\n\n\t\t\t3.Chennai\n\n\t\t\t “;
cin>>bdg_pt;
break;
case 2:clrscr();
cout<<”\n\n\t\t\t****** Select Destination ******\n\n\n”;
cout<<”\t 1.New York\t\t6.Dubai\t\t\t11.Antananariv”;
cout<<”\n\n\t 2.Miami\t\t7.Lisbon\t\t12.Cairo\n\n”;
cout<<”\t 3.Rio De Janeiro\t8.London\t\t13.Perth”;
cout<<”\n\n\t 4.Colombo\t\t9.Copenhagen\t\t14.Sydney”;
cout<<”\n\n\t 5.Hong Kong\t\t10.Cape Town\t\t15.Wellington\n\n\n\n\n\t\t\t\t “;
cin>>go_pt;
break;
case 3:clrscr();
cout<<”\n\n\t Date of Departure ”;
cout<<”\n\n   * Note:Format for entering:Day(press enter)Month(press enter)Year *”;
cout<<”\n\n\t\tEnter your preferred date of departure: “;
cin>>day;
gotoxy(59,7);   //to create a paricular format for entry
cout<<”/”;
cin>>month;
gotoxy(62,7);
cout<<”/”;
cin>>year;
break;
case 4:clrscr();
cout<<”\n\n\t\t\tEnter The Choice OF Deck\n\n\t\t\t1.Top Deck\n\n\t\t\t2.Middle Decks\n\n\t\t\t3.Bottom Deck\n\n\t\t\t “;
cin>>deck;
break;
case 5:clrscr();
cout<<”\n\n\t\t\tEnter The Choice Of Cabin\n\n\t\t\t1.AC\n\n\t\t\t2.Non AC\n\n\t\t\t “;
cin>>cabin;
break;
case 6:clrscr();
cout<<”\n\n\t\tDo You Like To Avail The Facility Of A Swimming Pool\n\n\t\t\t1.No\n\n\t\t\t2.Yes\n\n\t\t\t “;
cin>>pool;
pool–;
break;
