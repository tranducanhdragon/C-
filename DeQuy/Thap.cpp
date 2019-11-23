#include<iostream>
using namespace std;

void Thap(int n, string x, string y, string z){
	if(n == 1){
		cout<<"Chuyen tu thap "<<x<<" sang "<<y<<"\n";
	}
	else{
		Thap(n-1, x, z, y);
		cout<<"Chuyen tu thap "<<x<<" sang "<<y<<"\n";
		Thap(n-1, z, y, x);
	}
}

int main(){
	Thap(3, "X", "Y", "Z");
	return 0;
}
