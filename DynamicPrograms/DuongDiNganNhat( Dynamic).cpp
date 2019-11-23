#include<iostream>
using namespace std;

void Floyd(int d[][4], int p[][4], int a[][4], int n){
	int i, j, k;
	//Khoi tao ma tran d va p
	for(int i = 0; i< n; i++){
		for(int j = 0; j < n; j++){
			d[i][j] = a[i][j];
			p[i][j] = 0;
		}
	}
	
	for(int k = 0; k < n; k++){//Lap cac ma tran d va p o buoc lap k
	
		for(int i = 0; i < n; i++){
			if(d[i][k] > 0 && d[i][k] < INT_MAX){
				for(int j = 0; j< n; j++){
					if(d[k][j] > 0 && d[k][j] < INT_MAX){
						if(d[i][k] + d[k][j] < d[i][j]){
							d[i][j] = d[i][k] + d[k][j];
							p[i][j] = k+1;
						}
					}
				}
			}
		}
	}
	
	
	//in ra ma tran p
	for(int i = 0; i< n; i++){
		for(int j = 0; j < n; j++){
			cout<<" "<<p[i][j];
		}
		cout<<"\n";
	}
}

int main(){
	int n = 4;//So dinh
	int d[4][4], p[4][4];
	int a[4][4];// ma tran trong so
	for(int i = 0; i< n; i++){
		for(int j = 0; j < n; j++){
			cout<<"[ "<<i<<", "<<j<<"] ";cin>>a[i][j];
		}
	}
	Floyd(d, p, a, n);
	return 0;
}
