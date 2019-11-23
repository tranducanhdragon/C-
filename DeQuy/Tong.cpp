#include<iostream>
#include<math.h>
using namespace std;
int Tong( int a[], int n){
	if(n == 1){
		return a[0];
	}
	else{
		return a[n-1]+Tong(a, n-1);
	}
}
int main(){
	int a[4] = {1,2,3,4};
	cout<<Tong(a, 4);
	return 0;
}
