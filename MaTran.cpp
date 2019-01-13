#include <iostream>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <fstream>
using namespace std;
ofstream fo ("input2.txt");
ofstream fkq ("output2.txt");
#define max 100
int A[max][max]={0};
int B[max][max]={0};
int C[max][max]={0};
int D[max][max]={0};
int n,m,p,lc;
int lan=0;
// nhap ma tran de tinh tong hieu
void NhapMaTranTH(int m,int n){
	cout<<"Nhap ma tran A:"<<endl;
	for(int i = 0; i<m ; i++)
   		for(int j = 0; j<n ; j++){
      		cout<<"A["<<i<<"]["<<j<<"]=";
      		cin>>A[i][j];
   		}
   	cout<<"Nhap ma tran B:"<<endl;
	for(int i = 0; i<m ; i++)
   		for(int j = 0; j<n ; j++){
      		cout<<"B["<<i<<"]["<<j<<"]=";
      		cin>>B[i][j];
   		}
}
// nhap ma tran de tinh tich
void NhapMaTranTich(int m,int n,int p){
	int i, j;
	cout<<"Nhap ma tran A:"<<endl;
	for (i =0; i < m; i++)
    for (j =0; j < n; j++){
        cout << "a[" << i << "," << j << "] = " ;
        cin >> A[i][j] ;
    }
   	cout<<"Nhap ma tran B:"<<endl;
	for (i = 0; i < n; i++)
    for (j = 0; j < p; j++){
        cout << "b[" << i << "," << j << "] = " ;
        cin >> B[i][j];
    }
}
// xuat file ma tran
void XuatFile1(int a[max][max],int m, int n){
	for(int i = 0; i<m ; i++){
   		for(int j = 0; j<n ; j++)
      		fo<<a[i][j]<<" ";
		fo<<endl;
    }
}
// xuat file ket qua
void XuatFile2(int a[max][max],int m, int n){
	for(int i = 0; i<m ; i++){
   		for(int j = 0; j<n ; j++)
      		fkq<<a[i][j]<<" ";
		fkq<<endl;
    }
}
// xuat ma tran ra man hinh
void XuatMaTran(int a[max][max],int m, int n){
	for(int i = 0; i<m ; i++){
   		for(int j = 0; j<n ; j++)
      		cout<<a[i][j]<<" ";
		cout<<endl;
    }
}
// tinh tong 2 ma tran
void TongMaTran(){
	for(int i = 0; i<m ; i++)
   		for(int j = 0; j<n ; j++)
   			C[i][j]=A[i][j]+B[i][j];
}
// tinh hieu 2 ma tran
void HieuMaTran(){
	for(int i = 0; i<n ; i++)
   		for(int j = 0; j<n ; j++)
   			C[i][j]=A[i][j]-B[i][j];
}
// tinh tich 2 ma tran
void TichMaTran(){
    for(int i = 0; i<m; i++)
	  	for(int k = 0; k<p; k++) {
	   		C[i][k]=0;
	   		for(int j = 0; j<n; j++)
	   			C[i][k] = C[i][k]+A[i][j]*B[j][k];
		}
}
// hien thi menu
void Menu(){
	cout<<"         MENU"<<endl;
	cout<<"1: Tinh tong 2 ma tran"<<endl;
	cout<<"2: Tinh hieu 2 ma tran"<<endl;
	cout<<"3: Tinh tich 2 ma tran"<<endl;
	cout<<"0: Ket thuc!"<<endl;
	cout<<"Nhap lua chon cua ban: "<<endl;
	cin>>lc;
}
// chon menu
int MenuOption(){
	int kt;
	lan++;
	Menu();
	switch (lc){
		case 1:{
			system("cls");
			cout<<"Nhap m: ";
			cin>>m;
			cout<<"Nhap n: ";
			cin>>n;
			NhapMaTranTH(m,n);
			system("cls");
			cout<<"Ma tran A:"<<endl;
			XuatMaTran(A,m,n);
			fo<<"Nhap lan thu "<<lan<<endl;
			fo<<"Ma tran A:"<<endl;
			XuatFile1(A,m,n);
			cout<<"Ma tran B:"<<endl;
			XuatMaTran(B,m,n);
			fo<<"Ma tran B:"<<endl;
			XuatFile1(B,m,n);
			TongMaTran();
			cout<<"Tong 2 ma tran:"<<endl;
			XuatMaTran(C,m,n);
			fkq<<"Xuat lan thu "<<lan<<endl;
			fkq<<"Tong 2 ma tran:"<<endl;
			XuatFile2(C,m,n);
			cout<<"Ban co muon tiep tuc khong?"<<endl;
			cout<<"1: Co"<<endl<<"0: Khong"<<endl;
			cin>>kt;
			if(kt==1){
				system("cls");
				MenuOption();		
			}
			break;
		}
		case 2:{
			system("cls");
			cout<<"Nhap m: ";
			cin>>m;
			cout<<"Nhap n: ";
			cin>>n;
			NhapMaTranTH(m,n);
			system("cls");
			cout<<"Ma tran A:"<<endl;
			XuatMaTran(A,m,n);
			fo<<"Nhap lan thu "<<lan<<endl;
			fo<<"Ma tran A:"<<endl;
			XuatFile1(A,m,n);
			cout<<"Ma tran B:"<<endl;
			XuatMaTran(B,m,n);
			fo<<"Ma tran B:"<<endl;
			XuatFile1(B,m,n);
			HieuMaTran();
			cout<<"Hieu 2 ma tran:"<<endl;
			XuatMaTran(C,m,n);
			fkq<<"Xuat lan thu "<<lan<<endl;
			fkq<<"Hieu 2 ma tran:"<<endl;
			XuatFile2(C,m,n);
			cout<<"Ban co muon tiep tuc khong?"<<endl;
			cout<<"1: Co"<<endl<<"0: Khong"<<endl;
			cin>>kt;
			if(kt==1){
				system("cls");
				MenuOption();		
			}
			break;
		}
		case 3:{
			system("cls");
			cout<<"Nhap m: ";
			cin>>m;
			cout<<"Nhap n: ";
			cin>>n;
			cout<<"Nhap p: ";
			cin>>p;
			NhapMaTranTich(m,n,p);
			system("cls");
			cout<<"Ma tran A:"<<endl;
			XuatMaTran(A,m,n);
			fo<<"Nhap lan thu "<<lan<<endl;
			fo<<"Ma tran A:"<<endl;
			XuatFile1(A,m,n);
			cout<<"Ma tran B:"<<endl;
			XuatMaTran(B,n,p);
			fo<<"Ma tran B:"<<endl;
			XuatFile1(B,n,p);
			TichMaTran();
			cout<<"Tich 2 ma tran:"<<endl;
			XuatMaTran(C,m,p);
			fkq<<"Xuat lan thu "<<lan<<endl;
			fkq<<"Tich 2 ma tran:"<<endl;
			XuatFile2(C,m,p);
			cout<<"Ban co muon tiep tuc khong?"<<endl;
			cout<<"1: Co"<<endl<<"0: Khong"<<endl;
			cin>>kt;
			if(kt==1){
				system("cls");
				MenuOption();		
			}
			break;
		}
		case 0:{
			break;
		}
		default:{
			system("cls");
			cout<<"Nhap sai!!"<<endl;
			cout<<"Moi nhap lai:"<<endl;
			MenuOption();
			break;
		}
	}
	
}
int main(){
	MenuOption();
}
