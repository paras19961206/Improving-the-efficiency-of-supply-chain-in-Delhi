#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;


void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

//Interface
void interfac()
{
	int i;
	gotoxy(10,5);

	for(i=1;i<=100;i+=2)
	{
		cout<<"#";
		gotoxy(10+i,5);
	}
	
	for(i=1;i<=20;i++)
	{
		cout<<"#";
		gotoxy(10,5+i);
	}
	
	for(i=1;i<=100;i+=2)
	{
		cout<<"#";
		gotoxy(10+i,25);
	}
	cout<<"#";
	
	for(i=1;i<=20;i++)
	{
		cout<<"#";
		gotoxy(110,4+i);
	}
	cout<<"#";
	
	
	gotoxy(44,3);
	
	cout<<"RELEVANT COURIERS PRIVATE LIMITED";
	//getchar();
	
	gotoxy(53,7);
	cout<<"DATA MIXER";
}


int main()
{
	
	ifstream inFile;
	ofstream oFile;
	
	string not_glass[50],glass[50];
	
	interfac();
	
	int g=0,ng=0,i,ig=0,ing=0;
	
	inFile.open("output.csv");

	ofstream out("mixer.csv");
	
	string sno,awbno,pcs,wt,desc,cnr,gstin,gstinv,invno,val,port,cnee;
	
	while (!inFile.eof()) {
	 
    getline ( inFile, sno, ',' );
    getline ( inFile, awbno, ',' );
    getline ( inFile, pcs, ',' );
    getline ( inFile, wt, ',' );
    getline ( inFile, desc, ',' );
    getline ( inFile, cnr, ',' );
    getline ( inFile, gstin, ',' );
    getline ( inFile, gstinv, ',' );
    getline ( inFile, invno, ',' );
    getline ( inFile, val, ',' );
    getline ( inFile, port, ',' );
    getline ( inFile, cnee, '\n' );


    if(inFile.eof()) break;
        
    if(cnee[cnee.length()-1] == '/')
    cnee = cnee.substr(0,cnee.length()-1);
    
    size_t found = desc.find("GLASS");
    string str;
    
    if(found == string::npos)
    {
    str = sno+","+awbno+","+pcs+","+wt+","+desc+","+cnr+","+gstin+","+gstinv+","+invno+","+val+","+port+","+cnee;
    not_glass[ng++] = str;
    }
    
    else
    {
     glass[g++] = sno+","+awbno+","+pcs+","+wt+","+desc+","+cnr+","+gstin+","+gstinv+","+invno+","+val+","+port+","+cnee;
    }
 }
 
	while(ig<g && ing < ng)
	{
	  out<<not_glass[ing++]<<endl;
 	  out<<glass[ig++]<<endl;
    }
 
	while(ig<g)
 	{
 	  out<<glass[ig++]<<endl;
 	}
 
	while(ing<ng)
    {
 	  out<<not_glass[ing++]<<endl;
    }

	inFile.close();
	out.close();

	gotoxy(45,10);
	cout<<"Mixing the Data. Please wait."<<endl;

	gotoxy(40,12);
	for(i=0;i<38;i++)
    {
	  Sleep(50);
	  cout<<"*";
    } 

	gotoxy(40,14);
	cout<<"Data Mixing Done. Press Enter to exit.";

	getch();
	
	gotoxy(0,26);
}
