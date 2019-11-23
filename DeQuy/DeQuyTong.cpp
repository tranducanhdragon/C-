#include<iostream>
using namespace std;

int TimTong(int a[], int l, int r){
	if(l >= r){
		return a[l];
	}
	else{
		int key = (l+r)/2;
		if(l < r){
			int tong1 = TimTong(a, l, key);
			l++;
			int tong2 = TimTong(a, key+1, r);
			r--;
			return tong1+tong2;
		}
	}
}

int main(){
	int a[] = {0,1,2,3,4};
	cout<<TimTong(a, 0, 4);
}
