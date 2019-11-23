#include<bits/stdc++.h>
using namespace std;

#define N 9

int A[N][N] = {0};

void Xuat(){
	for(int i = 0; i< N; i++){
		for(int j = 0; j< N; j++){
			cout<<" "<<A[i][j];
		}
		cout<<"\n";
	}
}

bool CheckRow(int x, int k){
	for(int j = 0; j < 9; j++){
		if(A[x][j] == k){
			return false;
		}  
	}
	return true;
}

bool CheckColumn(int y, int k){
	for(int j = 0; j < 9; j++){
		if(A[j][y] == k){
			return false;
		}   
	}
	return true;
}

bool CheckVung(int x, int y, int k){
	//a va b la toa do vung cua x, y
	int a = x/3, b = y/3;
	//c va d la toa do cua vi tri dau tien trong vung do
	int c = a * 3, d = b * 3;
	for(int i = c; i < c + 3; i++){
		for(int j = d; j < d + 3; j++){
			if(A[i][j] == k){
				return false;
			}    
		}
	}
	return true;
}
void Try(int i){
	int x = i/9, y = i%9;
	if(A[x][y] != 0){
		if(x * y == (N-1)*(N-1)){
			Xuat();
		}
		else{
			Try(i+1);
		}
	}
	else{
		for(int k = 1; k <= 9; k++){
			if(CheckColumn(y, k) && CheckRow(x, k) && CheckVung(x, y, k)){
				A[x][y] = k;
				if(x*y < (N-1)*(N-1)){
					Try(i+1);
				}
				else{
					Xuat();
				}
				A[x][y] = 0;
			}
	    }
	}
}

int main(){
	A[0][0] = 3; A[0][4] = 5; A[0][8] = 2;
	A[1][1] = 9; A[1][3] = 4; A[1][7] = 5;
	A[2][2] = 8; A[2][6] = 1;
	A[3][1] = 5; A[3][4] = 4;
	A[4][0] = 1; A[4][3] = 7; A[4][5] = 3; A[4][8] = 9;
	A[5][4] = 6; A[5][7] = 7;
	A[6][2] = 1; A[6][6] = 3;
	A[7][1] = 8; A[7][5] = 4; A[7][7] = 2;
	A[8][0] = 9; A[8][4] = 8; A[8][8] = 1;
//    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3; A[0][3] = 4;
//    A[0][4] = 5; A[0][5] = 6; A[0][6] = 7; A[0][7] = 8; A[0][8] = 9;
	Try(0);
	return 0;
}
