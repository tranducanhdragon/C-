#include<bits/stdc++.h>
using namespace std;
int b = 20;//Suc chua cua tui la 19
int w[7];//Mang khoi luong cua cac vat, so do vat la 6
int c[7];//Mang gia tri cua cac vat
/*Do hang dau tien va cot dau tien la 0( vi neu ko co tui thi lay bao nhieu cung bang 0 va nguoc lai)
Do do b phai thua ra 1 cot, so do vat cung thua ra 1 cot
*/
void ProcedureBag(int MaxV[7][20]){
	for(int L = 0; L< b; L++)
	    MaxV[0][L] = 0;
	for(int i = 0; i< 7; i++)
	    MaxV[i][0] = 0;
	    
	for(int i = 1; i< 7; i++){
		for(int L = 1; L < 20; L++){
			
			if(L >= w[i] && ((MaxV[i-1][L-w[i]]+ c[i])> MaxV[i-1][L]))
			    MaxV[i][L] = MaxV[i-1][L- w[i]]+ c[i];
			else
			    MaxV[i][L] = MaxV[i-1][L];
		}
	}
	
}
int main(){
	c[0] = 0, w[0] = 0;
	for(int i = 1; i < 7; i++){
		cout<<"Can nang vat "<<i<<" :";cin>>w[i];
		cout<<"Gia tri vat "<<i<<" :";cin>>c[i];
	}
	int MaxV[7][20] ;
	//Khoi tao gia tri cho mang MaxV
	for(int i = 0; i<7; i++){
		for(int j = 0; j< 20; j++){
			MaxV[i][j] = 0;
		}
		cout<<endl;
	}
	ProcedureBag(MaxV);
	for(int i = 0; i<7; i++){
		for(int j = 0; j< 20; j++){
			cout<<"\t"<<MaxV[i][j];
		}
		cout<<endl;
	}
	return 0;
}
