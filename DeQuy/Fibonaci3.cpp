#include<iostream>
using namespace std;


int Fibonaci3(int n){
	if(n == 1){
		return 1;		
	}
	else if( n == 2){
		return 2;
	}
	else if(n == 3){
		return 4;
	}
	else if(n>3){
		
		return Fibonaci3(n-1)+Fibonaci3(n-2)+Fibonaci3(n-3);
	}
	
}


int main(){
	int n = 0;
	cin>>n;
	for(int i=1; i<n; i++){
		cout<<Fibonaci3(i);
		cout<<"\n";
	}
	return 0;
}
