#include<iostream>
#include<math.h>
using namespace std;

int Mu(int x, int n){
	if(n == 0){
		return 1;
	}
	else{
		
		if(n%2 == 0){
			return Mu(x*x, n/2);
		}
		else{
			return x*Mu(x*x, n/2);
		}
	}
}

int main(){
	cout<<Mu(2, 4);
	return 0;
}
