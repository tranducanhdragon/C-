#include<iostream>

using namespace std;

int Max(int a[], int n){
	if(n == 1){
		return a[0];
	}
	else{
		int t = Max(a, n-1);
		if(a[n-1]<t){
			return t;
		}
		else{
			return a[n-1];
		}
	}
}

int main(){
	int a[] = {0,1,2,3};
	cout<<Max(a, 4);
}
