#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <ctime>
#include<iomanip>
using namespace std;
int jp[7]={12,32,25,45,35,17,5};
int pl[6];
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
void SapXep(int a[]){
	int sx;
	for( int i = 0 ; i < 6 ; i++ )    
        for( int j = i+1 ; j < 6 ; j++ )     
            if(a[i] > a[j] ){
                swap(a[i],a[j]);
            }
}
void NhapXS(){
	int x,y,kt;
	int i=0;
	cout<<"Nhap cac so trong to ve so cua ban"<<endl;
	cout<<"So thu "<<i+1<<" : ";
	cin>>x;
	while(x>55 || x==0){
		cout<<"Nhap sai!!"<<endl;
		cout<<"Nhap lai so thu "<<i+1<<" : ";
		cin>>x;	
	}
	pl[i]=x;
	for(i=1;i<6;i++){
		cout<<"So thu "<<i+1<<" : ";
		cin>>x;
		kt=1;
		while(kt==1){
			kt=0;
			for(int j=0;j<=i;j++)
				if(x==pl[j])
					kt=1;
			if(x>56 || x==0) 
					kt=1;
			if(kt==1){
				cout<<"Nhap sai!!"<<endl;
				cout<<"Nhap lai so thu "<<i+1<<" : ";
				cin>>x;
				
			}
			else
				kt=0;
		}
		pl[i]=x;
	}
	cout<<"Cac so trong ve so cua ban: "<<endl;
	SapXep(pl);
	for(int i=0;i<6;i++)
		cout<<setw(2)<<setfill('0')<<pl[i]<<" ";
//		if(pl[i]>9)
//			cout<<pl[i]<<" ";
//		else
//			cout<<"0"<<pl[i]<<" ";	
	cout<<endl<<"-------------------------"<<endl;
}
void XuatXS(){
	SapXep(jp);
	cout<<"Ket Qua Xo So Ngay Hom Nay:"<<endl;
	for(int i=0;i<6;i++)
		cout<<setw(2)<<setfill('0')<<jp[i]<<" ";
//		if(jp[i]>9)
//			cout<<jp[i]<<" ";
//		else
//			cout<<"0"<<jp[i]<<" ";
	if(jp[6]>9)
		cout<<" | "<<jp[6];
	else
		cout<<" | 0"<<jp[6];
	cout<<endl<<"-------------------------"<<endl;
}
void KetQua(){
	int kt=0;
	int phu=0;
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			if(pl[i]==jp[j])
				kt++;
	cout<<"Ve so cua ban trung "<<kt<<" so so voi ket qua cua chung toi"<<endl;
	cout<<"-------------------------"<<endl;
	switch (kt){
		case 6:{
			cout<<"Chuc mung ban da trung giai Jackpot 1";
			break;
		}
		case 5:{
			for(int i=0;i<6;i++)
				if(pl[i]==jp[6])
					phu=1;
			if(phu==1)
				cout<<"Chuc mung ban da trung giai Jackpot 2";
			else
				cout<<"Chuc mung ban da trung giai Nhat";
			break;
		}
		case 4:{
			cout<<"Chuc mung ban da trung giai Nhi";
			break;
		}
		case 3:{
			cout<<"Chuc mung ban da trung giai Ba";
			break;
		}
		default:{
			cout<<"Chuc ban may man lan sau";
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
	NhapXS();
	TaoKQ();
	XuatXS();
	KetQua();
	
}
