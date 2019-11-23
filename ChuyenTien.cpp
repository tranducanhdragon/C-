#include<iostream>
#include<math.h>
using namespace std;

const string tienchan[] = {"muoi nghin ","hai muoi nghin ","nam muoi nghin ", "tram nghin "," trieu "};
const string donvi[] = {"mot ","hai ","ba ", "bon ","nam ","sau ","bay ","tam ","chin "};

void DonVi(int &n){
	int so = (int)n;
	switch(so){

    	case 1:{
    		cout<<donvi[so-1];
			break;
		}
		case 2:{
			cout<<donvi[so-1];
			break;
		}
		case 3:{
			cout<<donvi[so-1];
			break;
		}
		case 4:{
			cout<<donvi[so-1];
			break;
		}
		case 5:{
			cout<<donvi[so-1];
			break;
		}
		case 6:{
			cout<<donvi[so-1];
			break;
		}
		case 7:{
			cout<<donvi[so-1];
			break;
		}
		case 8:{
			cout<<donvi[so-1];
			break;
		}
		case 9:{
			cout<<donvi[so-1];
			break;
	    }
	}
}
void Tien(int &n){
	int t = 0;
	t = n/1000;
	if(t>=1&& t<10){
		
		DonVi(t);
		cout<<"trieu ";
	}
	int t1 = n - t*1000;
	t1 = t1/100;
	if(t1>=1 && t1<10){
		DonVi(t1);
		cout<<"tram ";
	}
	int t2 = n - t*1000 - t1*100;
	t2 = t2/10;
	if(t2>1 && t2<10){
		DonVi(t2);
		cout<<"muoi ";
	}
	else if(t2 == 1){
		cout<<"muoi ";
	}
	int t3 = n - t*1000 - t1*100 - t2*10;
	t3 = t3/1;
	if(t3>=1 && t3<10){
		DonVi(t3);
	}
	cout<<"nghin dong ";
}
int main(){
	int n = 0;
	cin>>n;
	Tien(n);
	return 0;
}
