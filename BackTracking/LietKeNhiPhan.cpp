#include<bits/stdc++.h>
using namespace std;
#define n 3
int a[n];

void Xuat(){
	for(int i = 0; i< n; i++){
		cout<<" "<<a[i];
	}
}
void Try(int i){
	for(int k= 0; k <= 1; k++){
		a[i] = k;
		if(i == n-1){
			Xuat();
			cout<<"\n";
		}
		else{
			Try(i+1);
		}
	}
}

int main(){
	Try(0);
	return 0;
}
