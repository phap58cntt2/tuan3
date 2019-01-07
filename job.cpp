#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int n,tre;
struct job{
	int no;// so thu tu
	int work;// thoi gian sua
	int end;// thoi diem ban giao
};
vector <job> JOB;//vector sua chua nhap tu file
vector <int> kq;// vector thu tu sua chua
vector <job> KQ;// vector ket qua
ifstream fi("job.in");
ofstream fo("job.out");
//Doc bang sua chua viec tu file
void DocFile(){
	job j;
	fi>>n;// doc so luong oto
	for(int i=0;i<n;i++){
		j.no=i+1;
		JOB.push_back(j);// danh so thu tu cho oto
	}
	for(int i=0;i<n;i++)
		fi>>JOB[i].work;// doc thoi gian sua oto
	for(int i=0;i<n;i++)
		fi>>JOB[i].end;// doc diem ban giao 
}
//Sap xep theo thoi diem ban giao
void SapXep(){
	for(int i=0;i<n;i++)    
        for(int j=i+1;j<n;j++)
        	if(JOB[i].end>JOB[j].end)
        		swap(JOB[i],JOB[j]);
}
//Xuat bang sua chua
void Xuat(){
	cout<<"-----------------------------------------"<<endl;
	for(int i=0;i<n;i++)
		cout<<"|"<<JOB[i].no<<"\t";
	cout<<"|"<<endl;
	cout<<"-----------------------------------------";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<"|"<<JOB[i].work<<"\t";
	cout<<"|"<<endl;
	cout<<"-----------------------------------------";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<"|"<<JOB[i].end<<"\t";
	cout<<"|"<<endl;
	cout<<"-----------------------------------------";
}
//Xuat bang phan cong sua chua
void XuatKQ(){
	cout<<"-----------------------------------------"<<endl;
	for(int i=0;i<n;i++)
		cout<<"|"<<KQ[i].no<<"\t";
	cout<<"|"<<endl;
	cout<<"-----------------------------------------";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<"|"<<KQ[i].work<<"\t";
	cout<<"|"<<endl;
	cout<<"-----------------------------------------";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<"|"<<KQ[i].end<<"\t";
	cout<<"|"<<endl;
	cout<<"-----------------------------------------";
}
//Chon oto sua chua theo thu tu tot nhat cho vao vector
void ChoseJob(){
	int t;
	int kt=0;
	tre=0;
	t=JOB[0].work;
	kq.push_back(JOB[0].no);
	for(int i=1;i<n;i++)
		if((t+JOB[i].work)<=JOB[i].end)// thoi gian sua cac oto truoc + thoi gian sua oto hien tai <= thoi diem ban giao
		{
			t+=JOB[i].work;
			kq.push_back(JOB[i].no);// dua vao vector thu tu sua chua
		}
	tre=n-kq.size();// tinh so oto bi qua han
	//dua cac oto con lai vao vector thu tu
	for(int i=1;i<=n;i++){
		for(int j=0;j<kq.size();j++)
			if(i==kq[j])
				kt=1;
		if(kt==0)
			kq.push_back(i);
		kt=0;			
	}
	//dua vao vector thu tu, lay cac oto theo thu tu cho vao vector ket qua
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(kq[i]==JOB[j].no)// thu tu = so thu tu oto
				KQ.push_back(JOB[j]);
}
void XuatFile(){
	fo<<"Thu tu oto sua chua:"<<endl;
	for(int i=0;i<n;i++)
		fo<<kq[i]<<"\t";
	fo<<endl;
	fo<<"Ket qua:"<<endl;
	fo<<"-----------------------------------------"<<endl;
	for(int i=0;i<n;i++)
		fo<<"|"<<KQ[i].no<<"\t";
	fo<<"|"<<endl;
	fo<<"-----------------------------------------";
	fo<<endl;
	for(int i=0;i<n;i++)
		fo<<"|"<<KQ[i].work<<"\t";
	fo<<"|"<<endl;
	fo<<"-----------------------------------------";
	fo<<endl;
	for(int i=0;i<n;i++)
		fo<<"|"<<KQ[i].end<<"\t";
	fo<<"|"<<endl;
	fo<<"-----------------------------------------";
	fo<<endl<<"So oto bi qua han: "<<tre;
}
int main(){
	DocFile();
	cout<<"Bang sua chua: "<<endl;
	Xuat();
	SapXep();
	cout<<endl<<"Sap xep:"<<endl;
	Xuat();
	ChoseJob();
	cout<<endl<<"Ket qua: "<<endl;
	XuatKQ();
	XuatFile();
	cout<<endl<<"Thu tu oto sua chua: "<<endl;
	for(int i=0;i<n;i++)
		cout<<kq[i]<<"\t";
	cout<<endl<<"So oto bi qua han: "<<tre;
	
}
