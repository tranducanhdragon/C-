#include<iostream>
#include<math.h>
using namespace std;

const int size = 20;

bool DaDi[size];
int BangGiaTri[size][size];
int DuongDi[size];
int chiphi = 0;
int n = 0;

void KhoiTao(){
	for(int i = 0; i< size; i++){
		for(int j = 0; j< size; j++){
			BangGiaTri[i][j] = 0;
		}
		DaDi[i] = false;
	}
	
}
void Input(){
	n = 0;// so dinh
	cout<<"Nhap so dinh: "; cin>>n;
	cout<<"Nhap vao bang gia tri: ";
	for(int i = 0; i< n; i++){
		for(int j = 0; j< n; j++){
		
			cout<<"Gia tri di tu dinh "<<i<<" den dinh "<<j<<" la: ";
			cin>>BangGiaTri[i][j];
			BangGiaTri[j][i] = BangGiaTri[i][j];
		}
	}
	DaDi[0] = true;//Xuat phat tu dinh 0
	DuongDi[n] = 0;
}
int TimMin(int a[], int& t){
	
	int min = 0;
	for(int i = 1; i< n; i++){
		if( DaDi[i] == false){
			min = a[i];
			t = i;
			break;
		}
	}
	for(int i = 1; i< n; i++){
		if( DaDi[i] == false && a[i] < min){
			min = a[i];
			t = i;
		}
	}
	return min;
}

void TimDuong(int hang, int tongsodinh){
	int t = 0;//Vi tri co trong so la min
	
	for(int i = 1; i< n; i++){
		
		chiphi += TimMin(BangGiaTri[hang], t);
		DaDi[t] = true;//Danh dau da di dinh co trong so min
		DuongDi[tongsodinh-1] = t;
		break;

	}
	if(tongsodinh <= 1){
		return ;
	}
	TimDuong( t, tongsodinh-1);//Xet dinh co trong so min do
	
}
int main(){
	KhoiTao();
	Input();
	TimDuong( 0, n);
	for(int i = n; i> 0; i--){
		cout<<DuongDi[i]<<"-";
	}
	cout<<"0";
}
