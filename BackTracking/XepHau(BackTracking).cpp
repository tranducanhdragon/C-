#include<bits/stdc++.h>
using namespace std;

#define N 4

int viTri[N][N] = {0};//vi tri quan hau co the dat
int ungVien[N] = {0};//gia tri gom 1, 2, 3,....,8

void Xuat(){
	for(int k = 0; k< N; k++){
		for(int t = 0; t < N; t++){
			cout<<" "<<viTri[k][t];
		}
		cout<<"\n";
	}
}
bool checkHang(int x){
	for(int i = 0; i< N; i++){
		if(viTri[x][i] != 0){
			return false;
		}
	}
	return true;
}
bool checkCot(int y){
	for(int i = 0; i< N; i++){
		if(viTri[i][y] != 0){
			return false;
		}
	}
	return true;
}
bool checkCheo(int x, int y){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i + j == x + y){
				if(viTri[i][j] != 0){
					return false;
				}
			}
			if(i - j == x - y){
				if(viTri[i][j] != 0){
					return false;
				}
			}
		}
	}
	return true;
}
void Try(int i, int x ){
	
	for(int k = 0; k < N; k++){
		
		if(checkHang(x) && checkCot(k) && checkCheo(x, k) && ungVien[i] == 0 && viTri[x][k] == 0){
			
			viTri[x][k] = i+1;
			ungVien[i] = 1;
			if(i == N-1){
				cout<<"\n";
				Xuat();
			}
			else{
				Try(i+1, x + 1);
			}
			ungVien[i] = 0;
			viTri[x][k] = 0;
		}
	}
}
int main(){
	Try(0, 0);
	return 0;
}
