#include<iostream>
using namespace std;

struct congviec{
	int dau;
	int cuoi;
};
void SapXepCuoi(congviec c[], int n){
	for(int i = 0; i< n-1; i++){
		for(int j = 1; j< n; j++){
			if(c[i].cuoi > c[j].cuoi){
				congviec temp = c[j];
				c[j] = c[i];
				c[i] = temp;
			}
		}
	}
}
void Chon(congviec c[], int n, congviec update[]){
	int dem = 0;
	for(int i = 0; i< n; i++){
		if(c[i].cuoi < c[i+1].dau){
			update[dem] = c[i];
			dem++;
		}
	}
}
int main(){
	congviec c[5];
	congviec up[5];
	for(int i = 0; i< 5; i++){
		cout<<"Cong viec bat dau tu: ",cin>>c[i].dau;
		cout<<"Cong viec ket thuc tai: ",cin>>c[i].cuoi;
	}
	SapXepCuoi(c, 5);
	Chon(c, 5, up);
	for(int i = 0; i< 5; i++){
		cout<<"Cong viec: "<<up[i].dau;
	}
	return 0;
}
