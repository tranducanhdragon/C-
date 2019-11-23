#include<iostream>
using namespace std;


int TimMax( int a[], int l, int r){
	if(l >= r){
		return a[l];
	}
	else{
		int key = (l+r)/2;
		int max = a[key];
			
		int max1 = TimMax(a, l, key);
		int max2 = TimMax(a, key+1, r);
		if(max1 < max2){
			return max2;
		}
		else{
			return max1;
		}
	}
}

int main(){
	int a[10] = {9,1,2,3,4,5,6,10,8,11};
	cout<<TimMax(a, 0, 9);
}
