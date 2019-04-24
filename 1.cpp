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

void travdetails::t_output()  //output func()-class2
{
clrscr();
cout<<”\n\n\t*******************§ TRAVEL DETAILS §*********************”;
cout<<”\n\n\t\tBoarding Point: “;
boardpt(bdg_pt);
cout<<”\n\n\t\tDestination: “;
dest(go_pt);
cout<<”\n\n\t\tDate of departure: “;
cout<<day<<”/”<<month<<”/”<<year;
cout<<”\n\n\t\tDeck: “;
switch(deck)
{
case 1:cout<<”Top Deck”;
break;
case 2:cout<<”Middle Deck”;
break;
case 3:cout<<”Bottom Deck”;
break;
}

cout<<”\n\n\t\tCabin: “;
switch(cabin)
{
case 1:cout<<”AC cabin”;
break;
case 2:cout<<”Non-AC cabin”;
break;
}
cout<<”\n\n\n\tFacilities availed for are:”;
if(pool==1)
cout<<”\n\t\t\t\t    Swimming Pool”;
if(gym==1)
cout<<”\n\t\t\t\t    Gymnasuim”;
if(sports==1)
cout<<”\n\t\t\t\t    Sports Facilities”;
if(spa==1)
cout<<”\n\t\t\t\t    Spa and Ayurvedic Treatment”;
if(salon==1)
cout<<”\n\t\t\t\t    Beauty Salon”;
if(theatre==1)
cout<<”\n\t\t\t\t    Theatre”;
getch();
}
void family(int c,int&flag)  //to display familyname+to check for record
{
flag=0;
clrscr();
ifstream ifl(“PersonalDetails.txt”,ios::binary);
if(!ifl)
cout<<”\nError”;
ifl.read((char*)&pob,sizeof(pob));
while(!ifl.eof())
{
if(pob.givecode()==c)
{
flag=1;
break;
}
ifl.read((char*)&pob,sizeof(pob));
}
if(flag==1)
{
cout<<”\n\n\t\t ****** “;
pob.givefam();
cout<<”‘s FAMILY DATABASE ******”;
}
else
{
cout<<”\nError in locating record!!”;
}

ifl.close();
}
void editp(int c)  //to edit persdetails
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
if(pob.givecode()==c)
{
clrscr();
cout<<”Please Enter the New details of the record”<<endl;
pob.p_input(c);
ofl2.write((char*)&pob,sizeof(pob));
cout<<”\n\t\t\tModification Succesful!!!”;
ifl4.read((char*)&pob,sizeof(pob));
}
else
{
ofl2.write((char*)&pob,sizeof(pob));
ifl4.read((char*)&pob,sizeof(pob));
}
}
remove(“PersonalDetails.txt”);
rename(“temp1.txt”,”PersonalDetails.txt”);
ifl4.close();
ofl2.close();
getch();
}
void editt(int c)  //to edit travdetails
{
ofstream ofl2(“temp1.txt”,ios::binary);
if(!ofl2)
cout<<”Error While Opening File”;
ifstream ifl4(“TravelDetails.txt”,ios::binary);
if(!ifl4)
cout<<”Error While Opening File”;
ifl4.read((char*)&tob,sizeof(tob));
while(!ifl4.eof())
{
if(tob.gtcode()==c)
{
clrscr();
cout<<”Please Enter the New details of the record”<<endl;
tob.t_input(c);
ofl2.write((char*)&tob,sizeof(tob));
cout<<”\n\t\t\tModification Succesful!!!”;
ifl4.read((char*)&tob,sizeof(tob));
}
else
{
ofl2.write((char*)&tob,sizeof(tob));
ifl4.read((char*)&tob,sizeof(tob));
}
}
remove(“TravelDetails.txt”);
rename(“temp1.txt”,”TravelDetails.txt”);
ifl4.close();
ofl2.close();
getch();
}


