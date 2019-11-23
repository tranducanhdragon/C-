#include<iostream>
#include<list>
using namespace std;

int banggiatri[20][20] = {
    	{0,1,0,4,0,0,0},
    	{1,0,2,6,6,0,0},
    	{0,2,0,0,0,0,0},
    	{4,6,0,0,3,0,4},
    	{0,6,0,3,0,8,7},
    	{0,0,0,0,8,0,3},
    	{0,0,0,4,7,3,0},
	};
bool dadi[20];
int sapxep[50];
int k = 0; //Chi so cua mang sap xep
int duongdi[20];
int h = 0; //Chi so cua mang duong di
int quangduongdi[20];

void KhoiTao( int n){
	for(int i = 0; i< n; i++){
		for(int j = 0; j < n; j++){
			banggiatri[i][j] = 0;
		}
		dadi[i] = false;
		duongdi[i] = 0;
	}
}

void Input( int n){
	for(int i = 0; i< n; i++){
		for(int j = 0; j < n; j++){
			cout<<"\nNhap gia tri tu "<<i<<" den "<<j<<" ";
			cin>>banggiatri[i][j];
		}

	}
}
int SapXepTrongSo( int n){
	

	//Luu cac trong so khac 0 vao mang sapxep[]
	for(int i = 0; i< n; i++){
		for(int j = i+1; j< n; j++){
			if( banggiatri[i][j] != 0){
				sapxep[k] = banggiatri[i][j];
			    k++;	
			}
		}
	}
	k--;
	
	//Sap xep theo gia tri trong so
	for(int i = 0; i< k-1; i++){
		for(int j = i+1; j< k; j++ ){
			
			if(sapxep[i] >= sapxep[j]){
				int temp = sapxep[i];
				sapxep[i] = sapxep[j];
				sapxep[j] = temp;
			}
		}
	}
	
}
void Prim(int n){
	
	dadi[0] = true;
	duongdi[0] = 0;
	h = 1;
	
	for(int i = 0; i< n ; ){
		for(int j = 0; j < n; j++){
			
			for(int t = 0; t < k; t++){
				if(banggiatri[i][j] == sapxep[t] && ((dadi[i] == true && dadi[j] == false) || (dadi[i] == false && dadi[j] == true))){
					
					if(dadi[i] == false){
						duongdi[h] = i;
						dadi[i] = true;
						quangduongdi[h-1] = sapxep[t];
					}
					else if(dadi[j] == false){
						duongdi[h] = j;
						dadi[j] = true;
						quangduongdi[h-1] = sapxep[t];
						i = j;
						j = 0;
					}
					h++;
					break;
				}
			}
			if(banggiatri[i][j] == 0 && dadi[j] == false){
			    if(j == n-1){
				    i--;
			    }
		    }
		}
		
		if(h == n ){
			break;
		}
	}
}
int main(){

	int n = 0;
	cout<<"\nNhap so dinh: "; cin>>n;
//	KhoiTao(n);
//	Input(n);

	SapXepTrongSo(n);
	Prim(n);
	
	for(int i = 0; i< h; i++){
		cout<<duongdi[i]<<"("<<quangduongdi[i]<<")->";
	}
}
