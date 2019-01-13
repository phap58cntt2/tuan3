#include<conio.h>
#include<stdio.h>
#include<winbgim.h>
#include<iostream>
#include<fstream>
using namespace std;
ifstream fi("text.txt");
void Ve_HCN(int x1, int y1, int x2, int y2)
{
    setfillstyle(0,5);
    line(x1,y1,x1,y2);
    line(x1,y1,x2,y1);
    line(x2,y2,x2,y1);
    line(x2,y2,x1,y2);
}

main()
{	int i=12;
    initwindow(800,80);
    Ve_HCN(20,20,750,35);
   	char key[50];
   	fi>>key;
   	char c[0];
   	char d;
   	int vl;
   	int vt;
//   	cout<<"Nhap vi tri:";
//    cin>>vt;
   //	outtextxy(22,22,key);
    while(1)
    {	
    	
    	
        d=getch();
        c[0]=d;
        vl=d;
        if(vl==27)
    		break;
    	if(vl==KEY_HOME)
    			outtextxy(22,22,"_");
	 	if(vl==KEY_END)
			outtextxy(i,22,"_");
		else{
			i=i+10;
	    	outtextxy(i,22,c);
			outtextxy(i+10,22,"_");
		}
    	cout<<c;
    	fflush(stdin);
    	
    }
//    
//    outtextxy(vt+22,22,"_");
	getch();
}
