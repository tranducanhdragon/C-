#include<iostream>
#include<malloc.h>
using namespace std;

int* Nhan1so(int a[100], int &b, int &n ){
	static int c[101] = {};
	int t = 0;
	n = 100;
	for(int i = 99; i>=0; i--){
		
		c[n] = a[i]*b + t;
		if(c[n] >= 10){
			t = c[n]/10;
			c[n] = c[n]%10;
		}
		else{
			t = 0;
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
int* Cong(int a[202], int b[202]){
	static int c[203] = {};

	int t = 0;
	for(int i = 201; i>=0; i--){
		c[i] = a[i] + b[i] + t;
		if(c[i] >= 10){
			t = c[i]/10;
			c[i] = c[i]%10;
		}
		else{
			t = 0;
		}
		
	}
	if(a[0] + b[0] +t >=10 ){
		c[0] = (a[0] + b[0] +t);
	}
    return c;
}
int* ThemSo0(int a[101], int &so_0){
	static int c[202] = {};

	for(int i = 0; i<101; i++){

		c[i+101-so_0] = a[i];
		
	}
	for(int i = 201; i>201-so_0; i--){
		c[i] = 0;
	}
	return c;

}
int main(){
	
	int a[100] = {};
	int *c;
	int  *c1 , *c2 ;
	c2 = (int *) malloc(203*sizeof( int ));
	for(int i=0; i<203; i++){
		c2[i] = 0;
	}
	int n;
	int b[100];
	int t = 0;//So so 0 can them vao ben phai
	int it = 97;//Vi tri hien tai cua so a va b
	int k = 201;
	int ti = 99;// Vi tri cuoi cung
	int do_dai = ti-it;//Do dai cua chuoi so a va b
	for(int i = 99; i>=it; i--){
		cin>>a[i];
	}
	for(int i = 99; i>=it; i--){
		cin>>b[i];
	}
	
	k = k - do_dai;
	
	while((ti+1) != it){
	
		c = Nhan1so(a, b[ti], n);
//	    cout<<"\nn = "<<n<<"\n";
//	    for(int i = 0; i<101; i++){
//		    cout<<c[i];
//        }
        
        //c1 la day c da them so 0 dang sau
        c1 = ThemSo0(c, t);
        k--;
//        cout<<"\nc1 = ";
//        for(int i = 0; i<202; i++){
//		    cout<<c1[i];
//        }
//		cout<<"\n";
        
        c2 = Cong(c2, c1);
//        cout<<"\nc2 = ";
//		for(int i = 0; i<202; i++){
//    	    cout<<c2[i];
//	    }
//	    cout<<"\n";
        
        t++;
        ti--;
	
    }
    cout<<"\n k = "<<k;
    cout<<"\nc2 = ";
    for(int i = k-1; i<202; i++){
    	    cout<<c2[i];
	    }
    
	return 0;
}
