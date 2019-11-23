#include<iostream>

using namespace std;
int* Nhan1so(int a[3], int &b, int &n ){
	static int c[6] = {};
	int t = 0;
	n = 5;
	for(int i = 2; i>=0; i--){
		
		c[n] = a[i]*b + t;
		if(c[n] > 10){
			t = c[n]/10;
			c[n] = c[n]%10;
		}
		n--;
		
	}
	if(t>0){
		c[n] = t;
	}
	else{
		c[n] = 0;
	}
	
	return c;
}
int* ThemSo0(int a[6], int &so_0){
	static int c[12] = {};
	
	for(int i = 0; i<6; i++){
//		if(so_0 == 0){
//			break;
//		}
		c[i+6-so_0] = a[i];
		
	}
	for(int i = 11; i>11-so_0; i--){
		c[i] = 0;
	}
	return c;

}
int main(){ 

	int a[3] = {};
	int *c;
	int *c1, *c2;
	int n ;
	int b[3];
	int t = 0;//So so 0 can them vao ben phai
	int it = 0;//Vi tri hien tai cua so a va b
	int ti = 2;// Vi tri cuoi cung
	for(int i = 2; i>=it; i--){
		cin>>a[i];
	}
	for(int i = 2; i>=it; i--){
		cin>>b[i];
	}
	
	while((ti+1) != it){
	
		c = Nhan1so(a, b[ti], n);
	    cout<<"\nn = "<<n<<"\n";
	    for(int i = 0; i<6; i++){
		    cout<<c[i];
        }
        c1 = ThemSo0(c, t);
        cout<<"\nc1 = ";
        for(int i = 0; i<12; i++){
		    cout<<c1[i];
        }
		cout<<"\n";
        
        t++;
        ti--;
	
    }

	
	return 0;
}
