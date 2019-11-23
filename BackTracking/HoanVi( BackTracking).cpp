#include<bits/stdc++.h>
using namespace std;
//N la chieu dai cua so can tim hoan vi
#define N 3
int a[N];
int b[N] = {0};//mang b de danh dau cac so da dc chon hay ko

void Xuat(){
	for(int i = 0; i< N; i++){
		cout<<a[i];
	}
}

void Try(int i){
	for(int k = 0; k < 3; k++){
		if(b[k] == 0){
			a[i] = k+1 ;
		    b[k] = 1;
		    if(i == N-1){
		        Xuat();
		        cout<<"\n";
	        }
		    else{
			    Try(i+1);       
		    }
			b[k] = 0;
	    }    		
	}
}

int main(){
	Try(0);
	return 0;
}
