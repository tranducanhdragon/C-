#include <iostream>
#define n 10
#define b 27
using namespace std;

int x[n], luu[n], gt=0;
struct DoVat{
	int c, w;
};
DoVat dv[n];

int khoiluong(){
	int kl = 0;
	for(int i = 0; i < n; i++)
		if(x[i]!=0){ 
		    kl+= dv[i].w;
		}
	return kl;
}

int giatri(){
	int gt = 0;
	for(int i = 0; i < n; i++)
	    if(x[i] != 0){
		    gt += dv[i].c;
		}
	return gt;
}

void luukq(){
	for(int i = 0; i < n; i++)
	    luu[i] = x[i];
}

void xuat(){
	for(int i = 0; i < n; i++)
	if(luu[i] == 1)
	cout<<"Chon vat thu "<<i<<"\t"<<dv[i].c<<"\t"<<dv[i].w<<"\n";
}

void Try(int i){
	int j;
	for(j = 0; j <= 1; j++){
		x[i] = j;
		if(i < n-1) Try(i+1);
		else if((giatri()>gt)&&(khoiluong()<=b)){
			gt = giatri();
			luukq();
		}
	}
}

int main(){
	int i;
	cout<<"Nhap gia tri va trong luong tuong ung cac tui:\n";
	for(i = 0; i <n; i++)
	cin>>dv[i].c>>dv[i].w;
	Try(0);
	cout<<"Gia tri toi uu:"<<gt<<endl;
	xuat();
}
