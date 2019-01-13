#include <iostream>
#include <ctime>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <conio.h>
using namespace std;
ifstream fi("nhanvien.txt");
ofstream fo;
int n;
class NV{
	public: 
		string hoten,gt;
		char nvl[10];
		float hsl;
		int socon;
		int loainv;
		static int luongcb;
		void TinhLuong();
		void TinhTroCap();
		int NamLamViec(){
			time_t now = time(0);
			tm *ltm = localtime(&now);
			int namht;
			namht=1900 + ltm->tm_year;
			int a=(nvl[6]-48)*1000+(nvl[7]-48)*100+(nvl[8]-48)*10+(nvl[9]-48);
			int b=namht-a;
			return b;
		}
		int TienThuong(){
		return NamLamViec()*1000;
		}
		void NhapNVF(){
//			string c;
//			getline(fi,hoten);
//			getline(fi,gt);
//			fi>>nvl;	
//			getline(fi,c); hsl=atoi(c.c_str());
//			getline(fi,c); socon=atoi(c.c_str());
			fi>>hoten;
			fi>>gt;
			fi>>nvl;
			fi>>hsl;
			fi>>socon;
		}
		void NhapNV(){
			string c;
			fflush(stdin);
			cout<<"Ten nhan vien: ";
			getline(cin,hoten);
			cout<<"Gioi tinh: ";
			cin>>gt;
			cout<<"Ngay vao lam: ";
			cin>>nvl;
			cout<<"He so luong: ";
			cin>>hsl;
			cout<<"So con: ";
			cin>>socon;
		}
		void XuatNV(){
			cout<<hoten<<"\t\t";
		}
		void XuatNVF(){
			fo<<loainv<<endl;
			fo<<hoten<<endl;
			fo<<gt<<endl;
			fo<<nvl<<endl;
			fo<<hsl<<endl;
			fo<<socon<<endl;
		}
		
};
int NV::luongcb=3000;
class NVVP:public NV{
	int snvang;
	static int dmv ;
	static int dgp ;
	public:
		int TienPhat(){
			if(NVVP::snvang>dmv)
				return NVVP::snvang*dgp;
			else 
				return 0;
		}
		int TroCap(){
			if(NV::gt=="nu")
				return 200*NV::socon*1.5;
			else
				return 200*NV::socon;
		}
		int LuongNVVP(){
			return NV::luongcb*NV::hsl-TienPhat();
		}
		void NhapNVVPF(){
			NV::NhapNVF();
			fi>>snvang;
		}
		void NhapNVVP(){
			NV::NhapNV();
			cout<<"So ngay vang: ";
			cin>>snvang;
		}
		void XuatNVVP(){
			NV::XuatNV();
			cout<<LuongNVVP()<<"\t\t";
			cout<<NVVP::TroCap()<<"\t\t";
			if(TienPhat()!=0)
				cout<<TienPhat()<<"\t\t";
			else
				cout<<"Nhan vien khong bi phat"<<endl;
		}
		void XuatNVVPF(){
			NV::XuatNVF();
			fo<<snvang<<endl;
		}
};
int NVVP::dmv=3;
int NVVP::dgp=100;
class NVSX:public NV{
	int sosp;
	static int dmsp ;
	static int dgsp ;
	public:
		int TienThuong(){
			int t=0;
			if(sosp>dmsp)
				t=(sosp-dmsp)*dgsp*0.03;
			return NV::TienThuong()+t;
		}
		int TroCap(){
			return NV::socon*120;
		}
		int LuongNVSX(){
			return sosp*dgsp+TienThuong()+NV::TienThuong();
		}
		void NhapNVSXF(){
			NV::NhapNVF();
			fi>>sosp;
		}
		void NhapNVSX(){
			NV::NhapNV();
			cout<<"So san pham: ";
			cin>>sosp;
		}
		void XuatNVSX(){
			NV::XuatNV();
			cout<<LuongNVSX()<<"\t\t";
			cout<<TienThuong()<<"\t\t\t";
			cout<<TroCap()<<"\t\t"<<endl;		
		}
		void XuatNVSXF(){
			NV::XuatNVF();
			fo<<sosp<<endl;
		}
};
int NVSX::dmsp=100;
int NVSX::dgsp=50;
int main(){
	vector <NVVP> VP;
	vector <NVSX> SX;
	vector <NVVP> VPF;
	vector <NVSX> SXF;
	NVVP a;
	NVSX b;
	int t;
	float luongtb;
	int luong=0;
	int loai;
	int kt,cn;
	cout<<"Ban muon nhap them hay lay thong tin tu file?"<<endl;
	cout<<"1: Nhap them"<<endl;
	cout<<"2: Lay tu file"<<endl;
	cin>>cn;
	system("cls");
	if(cn==1){
		fi>>n;
		for(int i=0;i<n;i++){
			fi>>loai;
			if(loai==1){
				a.loainv=loai;
				a.NhapNVVPF();
				VP.push_back(a);
				VPF.push_back(a);
			}
			else{
				b.loainv=loai;
				b.NhapNVSXF();
				SX.push_back(b);
				SXF.push_back(b);
			}
		}
		do{
			cout<<"Buoc tiep theo:"<<endl;
			cout<<"1: Nhap thong tin nhan vien"<<endl;
			cout<<"0: Ket thuc"<<endl;
			cin>>kt;
			system("cls");
			if(kt==1){
				cout<<"Nhap loai nhan vien: ";
				cin>>loai;
				if(loai==1){
					a.loainv=loai;
					a.NhapNVVP();
					VP.push_back(a);
					VPF.push_back(a);
					cout<<"____________________________"<<endl;
				}
				else{
					b.loainv=loai;
					b.NhapNVSX();
					SX.push_back(b)	;
					SXF.push_back(b);
					cout<<"____________________________"<<endl;
				}
			}
		}
		while(kt!=0);
	}
	else if(cn==2){
		fi>>n;
		for(int i=0;i<n;i++){
			fi>>loai;
			if(loai==1){
				a.loainv=loai;
				a.NhapNVVPF();
				VP.push_back(a);
				VPF.push_back(a);
			}
			else{
				b.loainv=loai;
				b.NhapNVSXF();
				SX.push_back(b);
				SXF.push_back(b);
			}
		}
	}
	fi.close();
	cout<<"Nhan vien van phong: "<<endl;
	cout<<"Ten\t\tLuong\t\tTro cap\t\tTien phat"<<endl;
	for(int i=0;i<VP.size();i++){
//		cout<<"Nhan vien van phong "<<i+1<<" :"<<endl;
		VP[i].XuatNVVP();
		cout<<endl<<"________________________________________________________"<<endl;
	}
	cout<<"Nhan vien san xuat: "<<endl;
	cout<<"Ten\t\tLuong\t\tTien thuong\t\tTro cap"<<endl;
	for(int i=0;i<SX.size();i++){
//		cout<<"Nhan vien san xuat "<<i+1<<" :"<<endl;
		SX[i].XuatNVSX();
		cout<<"________________________________________________________"<<endl;
	}
	if(VP.size()!=0){
		for(int i=0;i<VP.size();i++)
			luong+=VP[i].LuongNVVP();
		luongtb=1.0*luong/VP.size();
	}
	else 
		luongtb=0;
	cout<<"____________________________"<<endl;
	cout<<"Tong luong nvvp:"<<luong<<endl;
	cout<<"Luong trung binh cua nhan vien van phong: "<<luongtb;
	t=VPF.size()+SXF.size();
	fo.open("nhanvien.txt");
	fo<<t<<endl;
	for(int i=0;i<VPF.size();i++){
		VPF[i].XuatNVVPF();
	}
	for(int i=0;i<SXF.size();i++){
		SXF[i].XuatNVSXF();
	}
	getch();
}

