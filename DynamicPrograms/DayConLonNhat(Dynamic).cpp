#include<bits/stdc++.h>
using namespace std;

void subMax(int a[], int n, int &s, int &e){
	int MaxS = a[0], MaxE = a[0];//MaxS tong cua day con thu i-1, MaxE tong cua day con thu i
	s = 0, e = 0;//s chi so dau, e chi so cuoi
	int s1 = 0;//s1 chi so dau tam
	for(int i = 1; i < n; i++){
		if(MaxE > 0){
			MaxE = MaxE + a[i];
		}
		else{
			MaxE = a[i];
			s1 = i;
		}
		if(MaxE > MaxS){
			MaxS = MaxE;
			e = i;
			s = s1;
		}
	}
}
int main(){
	int a[9];
	for(int i = 0; i< 9; i++){
		cin>>a[i];
	}
	int start = 0, end = 0;
	subMax(a, 9, start, end);
	for(int i = start; i<= end; i++){
		cout<<" "<<a[i];
	}
	return 0;
}
