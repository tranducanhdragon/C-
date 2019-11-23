#include<iostream>
using namespace std;

int TKNhiPhan(int a[], int x, int left, int right){
	int key = (left+right)/2;
	if(left == right){
		if(x == a[left]){
			return a[left];
		}
		else{
			return 0;
		}
	}
	else if(x == a[key]){
		return a[key];
	}
	else{
		if(x > a[key]){
			TKNhiPhan(a, x, key+1, right);
		}
		else if(x < a[key]){
			TKNhiPhan(a, x, left, key);
		}
	}
}

int main(){
	int a[5] = {1,2,3,4,5};
	cout<<TKNhiPhan(a,2,0,4);
	return 0;
}
