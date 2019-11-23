#include<bits/stdc++.h>
using namespace std;

#define N 5
pair<int, int> duongdi[8] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
int h[N][N] = {0};
int dem = 0;

void Xuat(){
	for(int i = 0; i< N; i++){
		for(int j = 0; j < N; j++){
			cout<<" "<<h[i][j];
		}
		cout<<"\n";
	}
}

void Try(int i, int x, int y){
	for(int k = 0; k< 8; k++){
		int u = x + duongdi[k].first;
		int v = y + duongdi[k].second;
		if(u >= 0 && v >= 0 && u < N && v < N && h[u][v] == 0){
			h[u][v] = i;
			if(i < N*N){
				Try(i+1, u, v);
			}
			else{
				cout<<"Phuong an: "<<++dem<<"\n";
				Xuat();
			}
			h[u][v] = 0;
		}
		 	
    }
}

int main(){
	h[0][0] = 1;
	Try(2, 0, 0);
	return 0;
}
