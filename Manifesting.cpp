#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

//User Defined gotoxy() function
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
    
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}


//Interface
void interf()
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
	
	gotoxy(53,7);
	
	cout<<"MANIFEST CREATOR";
}

//Username and Password Validation
void validate()
{
	gotoxy(40,12);
	
	string pass,user;
	int len=0;
	char a;
	
	cout<<"Enter Username : ";
	cin>>user;
	
	gotoxy(40,13);
	
	cout<<"Enter Password : ";
	fflush(stdin);
	
	a = 'a';
	
	while(a != 13)
	{
		a = getch();
		if(a == 13)
        {
        	break;
		 cout<<"\b \b";
		 len--;
	    }    
	    
	    else if(a == '\b')
	    {
	    	cout<<"\b \b";
	    	pass = pass.substr(0,pass.size()-1);
		}
		
		else
		{
		 cout<<"*";
		 pass.push_back(a);
	    }
	    
	}
	
	gotoxy(40,14);
	
	if(user != "relevant")
	{
	 cout<<"Invalid Username. Press any key to enter the user details again.";
	 
	 getchar();	
	 system("cls");
	 
	 interf();
	 validate();
	}
	
	if(pass == "relevant")
	{
	 cout<<"Success. Press any key to continue";
	 getchar();
    }
    
    else
	{
	 cout<<"Invalid Password. Press any key to enter the user details again.";
	 
	 getchar();	
	 system("cls");
	 
	 interf();
	 validate();
    }
	 
}


int main()
{
  interf();
  validate();
  
  ifstream inFile;
  ofstream oFile;

  system("CLS"); 
  interf();

  gotoxy(44,12);
  
  cout<<"Press ENTER to create the manifest";
  
  getchar();
  gotoxy(24,13);
  
  cout<<"output.txt Manifest created. Please convert the file to .csv after exiting";

  string awbno,pcs,wt,descr,cnrna,gstin,gstin2,ogstin,val,cnena,temp,cnr_name,cnr_address,cnr_city,cne_name,cne_address,cne_city,
  cne_state,cne_postalcode,cne_country,cne_tele;
  int i,pinin,sno;
  sno=1;
  
  inFile.open("input.csv");
  ofstream out("output.txt");


   while (!inFile.eof()) {
	 
    getline ( inFile, awbno, ',' );  
    getline ( inFile, pcs, ',' );     
    getline ( inFile, wt, ',' );
    getline ( inFile, descr, ',' );
    getline ( inFile, cnr_name, ',' );
    getline ( inFile, cnr_address, ',' );
    getline ( inFile, cnr_city, ',' );
    getline ( inFile, cne_name, ',' );
    getline ( inFile, cne_address, ',' );
    getline ( inFile, cne_city, ',' );
    getline ( inFile, cne_state, ',' );
    getline ( inFile, cne_postalcode, ',' );
    getline ( inFile, cne_country, ',' );
    getline ( inFile, cne_tele, ',' );
    getline ( inFile, val, '-' );
    
    if(inFile.eof()) break;
    
    if(awbno[0] == '\n')
    {
    	temp = "";
    	for(i=1;i<awbno.length();i++)
    	temp += awbno[i];	
		awbno = temp;
		
	}
    out<<sno++<<","<<awbno<<","<<pcs<<","<<wt<<","<<descr<<","<<cnr_name+"/"+cnr_address+"/"+cnr_city<<","
	<<" "<<","<<"NA,NA,"<<val<<", ,"<<cne_name+"/"+cne_address+"/"+cne_city+"/"+cne_state+" - "+cne_postalcode+"/"+cne_tele<<endl;
    
   }
   
   
  inFile.close();
  out.close();

  gotoxy(0,26);
  getch();
  return 0;
} 
