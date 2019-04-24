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

void deletion(int c)  //common delete func()
{
ofstream ofl2(“temp1.txt”,ios::binary);
if(!ofl2)
cout<<”Error While Opening File”;
ifstream ifl4(“PersonalDetails.txt”,ios::binary);
if(!ifl4)
cout<<”Error While Opening File”;
ifl4.read((char*)&pob,sizeof(pob));
while(!ifl4.eof())
{
if(pob.givecode()!=c)
{
ofl2.write((char*)&pob,sizeof(pob));
}
ifl4.read((char*)&pob,sizeof(pob));
}
remove(“PersonalDetails.txt”);
rename(“temp1.txt”,”PersonalDetails.txt”);
ofl2.close();
ifl4.close();
ofstream ofl3(“temp2.txt”,ios::binary);
if(!ofl3)
cout<<”\nError While Opening File”;
ifstream ifl5(“TravelDetails.txt”,ios::binary);
if(!ifl5)
cout<<”\nError While Opening File”;
ifl5.read((char*)&tob,sizeof(tob));
while(!ifl5.eof())
{
if(tob.gtcode()!=c)
{
ofl3.write((char*)&tob,sizeof(tob));
}
ifl5.read((char*)&tob,sizeof(tob));
}
ofl3.close();
ifl5.close();
remove(“TravelDetails.txt”);
rename(“temp1.txt”,”TravelDetails.txt”);
cout<<”\n\n\t\tDeletion Completed!”;
getch();
}
void travdetails::compute()   //compution+bill generation
{
long int gttl=0,hr,dcst,dck,cabn,swpool=5000,gm=2000,spfts=7500,slon=6000,sp=20000,ttr=500;
switch(go_pt)
{
case 1:;
case 2:;
case 3:hr=30*24;
dcst=250000;
break;
case 4:;
case 5:;
case 6:hr=7*24;
dcst=75000;
break;
case 7:;
case 8:;
case 9:hr=24*24;
dcst=130000;
break;
case 10:;
case 11:;
case 12:hr=15*24;
dcst=100000;
break;
case 13:;
case 14:;
case 15:hr=12*24;
dcst=120000;
break;
}
switch(deck)
{
case 1:dck=7500;
break;
case 2:dck=5000;
break;
case 3:dck=1000;
}
switch(cabin)
{
case 1:cabn=5000;
break;
case 2:cabn=2000;
break;
}
clrscr();
cout<<”\n\n\t\t:::::::::::::::::::::: BILL ::::::::::::::::::::::::::”;
cout<<”\n\n\t\tBoarding point:\t\t “;
boardpt(bdg_pt);
cout<<”\n\n\t\tDestination:\t\t “;
dest(go_pt);
cout<<”\n\n\t\tDate of Departure: “;
cout<<day<<”/”<<month<<”/”<<year;
hr=hr/24;         //to calculate date of arrival
day=day+hr;
if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
{
if(day>31)
{
month=month+1;
day=day%31;
}
}
if(month==4||month==6||month==9||month==11)
{
if(day>30)
{
month=month+1;
day=day%30;
}
}
if(month==2)
