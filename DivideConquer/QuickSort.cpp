#include<iostream>
using namespace std;

void swap(int &a, int &b){
	int tem = 0;
	tem = a;
	a = b;
	b = tem;
}

int Partition(int a[], int l, int r){
	int i = l+1;
	int j = r;
	int x = a[l];
	while(i < j){
	    while(a[i] <= x){
		    i++;
	    }
	    while(a[j] > x){
		    j--;
	    }
	    if(i < j){
		    swap(a[i], a[j]);
	    }	
	}
	swap(a[l], a[j]);
	return j;
}
void QuickSort(int a[], int l, int r){
	if(l >= r){
		return ;
	}
	else{
		int t = Partition(a, l, r);
		QuickSort(a, l, t-1);
		QuickSort(a, t+1, r);
	}
}

int main(){
	int a[] = {2,1,5,4,3,6,7,9,8};
	QuickSort(a, 0, 8);
	for(int i = 0; i< 9; i++){
		cout<<" "<<a[i];
	}
	return 0;
}
