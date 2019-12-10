#include<iostream>
using namespace std;

void Merge(int a[], int l, int r, int t){
	int i = l;
	int j = t+1;
	int p = l;
	int c[5];
	while(i <= t && j<=r){
		if(a[i] < a[j]){
			c[p] = a[i];
			i++;
		}
		else{
			c[p] = a[j];
			j++;
		}
		p++;
	}
	while(i<=t){
		c[p] = a[i];
		i++;
		p++;
	}
	while(j <= r){
		c[p] = a[j];
		j++;
		p++;
	}
	for(int i=l; i<=r; i++){
		a[i] = c[i];
	}
}

void MergeSort(int a[], int l, int r){
	
	if(l == r){
		return 0;
	}
	else{
		int t = (l+r)/2;
		MergeSort(a, l, t);
		MergeSort(a, t+1, r);
		Merge(a, l, r, t);
	}
}

int main(){
	int a[5] = {0,1,6,3,4};
	MergeSort(a, 0, 4);
	for(int i = 0; i< 5; i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
