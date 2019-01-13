#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <windows.h> 
using namespace std;
int jp[7]={12,32,25,45,35,17,5};
int pl[6];
//Doi mau chu
void SetColor(int ForgC) { 
	WORD wColor; 
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 
    CONSOLE_SCREEN_BUFFER_INFO csbi; 
	if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) { 
    	wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F); 
    	SetConsoleTextAttribute(hStdOut, wColor); 
	} 
	return; 
} 
//Tao ket qua xo so ngau nhien
void TaoKQ(){
	int a[55];
	for(int i=0;i<55;i++)
		a[i]=i+1;
	srand(time(NULL));
	random_shuffle(a,a+55);
	for(int i=0;i<7;i++){
		jp[i]=a[i];
	}		
}
//Sap xep mang xo so
void SapXep(int a[]){
	int sx;
	for( int i = 0 ; i < 6 ; i++ )    
        for( int j = i+1 ; j < 6 ; j++ )     
            if(a[i] > a[j] ){
                swap(a[i],a[j]);
            }
}
//Nhap cac so trong to ve so
void NhapXS(){
	int x,y,kt;
	int i=0;
	cout<<"\t\t\t\t\tNhap cac so trong to ve so cua ban"<<endl;
	cout<<"\t\t\t\t\tSo thu "<<i+1<<" : ";
	cin>>x;
	while(x>55 || x<1){
		cout<<"\t\t\t\t\tNhap sai!!"<<endl;
		cout<<"\t\t\t\t\tNhap lai so thu "<<i+1<<" : ";
		cin>>x;	
	}
	pl[i]=x;
	for(i=1;i<6;i++){
		cout<<"\t\t\t\t\tSo thu "<<i+1<<" : ";
		cin>>x;
		kt=1;
		while(kt==1){
			kt=0;
			for(int j=0;j<=i;j++)
				if(x==pl[j])
					kt=1;
			if(x>56 || x<1) 
					kt=1;
			if(kt==1){
				cout<<"\t\t\t\t\tNhap sai!!"<<endl;
				cout<<"\t\t\t\t\tNhap lai so thu "<<i+1<<" : ";
				cin>>x;	
			}
		}
		pl[i]=x;
	}
	cout<<"\t\t\t\t\tCac so trong ve so cua ban: "<<endl;
	SapXep(pl);
	cout<<"\t\t\t\t\t";
	for(int i=0;i<6;i++)
		cout<<setw(2)<<setfill('0')<<pl[i]<<" ";
//		if(pl[i]>9)
//			cout<<pl[i]<<" ";
//		else
//			cout<<"0"<<pl[i]<<" ";	
	cout<<endl<<"\t\t\t\t\t-------------------------"<<endl;
}
void XuatXS(){
	SapXep(jp);
	SetColor(12);
	cout<<"\t\t\t\t\t\t\tVietLot"<<endl;
	SetColor(15);
	cout<<"\t\t\t\t*-----------------------------------------------------------*"<<endl;
	cout<<"\t\t\t\t|\t\tKet Qua Xo So Ngay Hom Nay:\t\t    |"<<endl;
	cout<<"\t\t\t\t|\t\t";
	SetColor(12);
	for(int i=0;i<6;i++)
		cout<<setw(2)<<setfill('0')<<jp[i]<<" ";
//		if(jp[i]>9)
//			cout<<jp[i]<<" ";
//		else
//			cout<<"0"<<jp[i]<<" ";
	SetColor(15);
	cout<<" | ";
	SetColor(14);
	if(jp[6]>9)
		cout<<jp[6];
	else
		cout<<"0"<<jp[6];
	SetColor(15);
	cout<<"\t\t\t    |";
	cout<<endl<<"\t\t\t\t*-----------------------------------------------------------*"<<endl;
}
void KetQua(){
	int kt=0;
	int phu=0;
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			if(pl[i]==jp[j])
				kt++;
	SetColor(12);
	cout<<"\t\t\t\t\tVe so cua ban trung "<<kt<<" so so voi ket qua cua chung toi"<<endl;
	cout<<"\t\t\t\t\t-------------------------"<<endl;
	switch (kt){
		case 6:{
			cout<<"\t\t\t\t\tChuc mung ban da trung giai Jackpot 1";
			break;
		}
		case 5:{
			for(int i=0;i<6;i++)
				if(pl[i]==jp[6])
					phu=1;
			if(phu==1)
				cout<<"\t\t\t\t\tChuc mung ban da trung giai Jackpot 2";
			else
				cout<<"\t\t\t\t\tChuc mung ban da trung giai Nhat";
			break;
		}
		case 4:{
			cout<<"\t\t\t\t\tChuc mung ban da trung giai Nhi";
			break;
		}
		case 3:{
			cout<<"\t\t\t\t\tChuc mung ban da trung giai Ba";
			break;
		}
		default:{
			cout<<"\t\t\t\t\tChuc ban may man lan sau";
			break;
		}
	}
//	if(kt==6)
//		cout<<"Chuc mung ban da trung giai Jackpot 1";
//	if(kt==5){
//		for(int i=0;i<6;i++)
//			if(pl[i]==jp[6])
//				phu=1;
//		if(phu==1)
//			cout<<"Chuc mung ban da trung giai Jackpot 2";
//		else
//			cout<<"Chuc mung ban da trung giai Nhat";
//	}
//	if(kt==4)
//		cout<<"Chuc mung ban da trung giai Nhi";
//	if(kt==3)
//		cout<<"Chuc mung ban da trung giai Ba";
//	if(kt<3)
//		cout<<"Chuc ban may man lan sau";
}
int main(){
	
	TaoKQ();
	XuatXS();
	SetColor(2);
	NhapXS();
	KetQua();
	SetColor(0);
	
}
