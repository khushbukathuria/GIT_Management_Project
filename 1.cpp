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


