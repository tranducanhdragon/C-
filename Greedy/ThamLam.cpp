#include<iostream>
using namespace std;

struct DoVat{
	int giatri;
	int cannang;
};

void doicho(DoVat &a, DoVat &b){
	DoVat temp = b;
	b = a;
	a = temp;
}

void SapXep(DoVat a[], int n){
	for(int i = 0; i< n-1; i++){
		for(int j = i+1; j < n; j++){
			if((a[i].giatri/a[i].cannang) < (a[j].giatri/a[j].cannang)){
				doicho(a[i], a[j]);
			}
		}
	}
}

void Chon(DoVat a[], int khoiluong, int n){
	DoVat b[n];
	int t = 0;
	for(int i = 0; i< n; i++){
		if(a[i].cannang < khoiluong){
			b[t] = a[i];
			t++;
			khoiluong = khoiluong - a[i].cannang;
		}
	}
	for(int i = 0; i<t; i++){
		cout<<"\ndo vat gia tri: "<<b[i].giatri <<"co can nang"<<b[i].cannang;
	}
}

int main(){
	DoVat a[4];
	for(int i = 0; i<4; i++){
		cin>>a[i].giatri;
		cin>>a[i].cannang;
	}
	Chon(a, 10, 4);
}
