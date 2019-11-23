#include<bits/stdc++.h>
using namespace std;

vector<string> XauChungMax(string x[], string y[], int m, int n){
	int c[m][n];
	for(int i = 0; i< m; i++){
		c[i][0] = 0;
	}
	for(int i = 0; i< n; i++){
		c[0][i] = 0;
	}
	
	for(int i = 1; i<m; i++){
		for(int j = 1; j<n; j++){
			if(x[i] == y[j]){
				c[i][j] = c[i-1][j-1]+1;
			}
			else{
				c[i][j] = max(c[i][j-1], c[i-1][j]);
			}
		}
	}
	//truy vet
	vector<string> kq;
	for(int i = m-1; i >= 0; i--){
		for(int j = n-1; j >= 0; j--){
			if(c[i][j] != c[i][j-1] && c[i][j] != c[i-1][j]){
				kq.push_back(x[i]);
				i--;
			}			    
		}
	}
	return kq;
}

int main(){
	string x[7];
	x[0]="T"; x[1]="O"; x[2] = "A"; x[3]="N"; x[4]="H"; x[5]="O"; x[6]="C";
	string y[7];
	y[0]="K"; y[1]="H"; y[2] = "O"; y[3]="N"; y[4]="H"; y[5]="O"; y[6]="C";	
	vector<string> kq = XauChungMax(x, y, 7, 7);
	for(int i = kq.size()-1; i >= 0; i--){
		cout<<kq[i];
	}
	return 0;
}
