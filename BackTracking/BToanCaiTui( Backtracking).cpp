#include<bits/stdc++.h>
using namespace std;

int n = 3;//so loai do vat
int b = 19;//Kich thuoc cua tui

struct Tui{
	int giaTri;
	int canNang;
};

int a[3];//mang cac do vat
Tui dovat[3];
int maxgiatri = 0;
int maxG = 0;
int cannang = 0;

void Xuat(){
	for(int i = 0; i< n; i++){
		if(a[i] == 1){
			cout<<"\nChon do vat co gia tri: "<<dovat[i].giaTri<<" can nang: "<<dovat[i].canNang;
		}
	}
}
void ChonVat(int a[], int &cannang, int &giatri){
	cannang = 0;
	giatri = 0;
	for(int i = 0; i< n; i++){
		if(a[i] == 1){
			cannang += dovat[i].canNang;
			maxgiatri += dovat[i].giaTri;
		}
	}
}

void Try(int i){
	for(int k = 0; k < 2; k++){
		a[i] = k;
		if(i < n-1){
			Try(i+1);
		}
		else{
			cout<<"\n";
			ChonVat(a, cannang, maxgiatri);
			if(cannang <= b){
				if(maxgiatri >= maxG){
					Xuat();
					maxG = maxgiatri; 
				}	
			}
				
			cout<<"\n";
		}	
	}
}
int main(){
	for(int i = 0; i< n; i++){
		cout<<"\nNhap gia tri va can nang cua vat: ";
		cin>>dovat[i].giaTri>>dovat[i].canNang;
	}
	Try(0);
	return 0;
}
