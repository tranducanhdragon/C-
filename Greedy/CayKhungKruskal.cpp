#include<iostream>
using namespace std;

struct Diem{
	int ten_diem;
	int cay;
};
struct Canh{
	Diem bat_dau;
	Diem ket_thuc;
	int do_dai;
};

int bangtrongso[20][20] = {
	{0,3,0,1,0,3,0},
	{3,0,4,0,0,6,0},
	{0,4,0,3,7,0,5},
	{1,0,3,0,6,2,0},
	{0,0,7,6,0,5,0},
	{3,0,0,2,5,0,1},
	{0,0,5,0,0,1,0},
};

Diem V[20];// Mang V[] chua tat ca cac dinh
int sodinh = 7;//Chi so cua mang V

Canh sapxep[50];
int t = 0;//Chi so cua mang sap xep

Canh ketqua[20];
int so_canh = 0;//Chi so cua mang ketqua[]

void KhoiTao(){
//	for(int i = 0; i< sodinh; i++){
//		for(int j = 0; j < sodinh; j++){
//			cout<<endl<<"Tu dinh "<<i<<" den dinh "<<j<<" :"; cin>>bangtrongso[i][j];
//			
//		}
//	}

	for(int i = 0; i< sodinh; i++){
		V[i].ten_diem = i;
		V[i].cay = i;
	}
}

void SapXep(){

	for(int i = 0; i< sodinh; i++){
		for(int j = i+1; j< sodinh; j++){
		    if(bangtrongso[i][j] != 0){
			    sapxep[t].do_dai = bangtrongso[i][j];
			    sapxep[t].bat_dau.ten_diem = i;
			    sapxep[t].bat_dau.cay = i;
			    sapxep[t].ket_thuc.ten_diem = j;
			    sapxep[t].ket_thuc.cay = j;
			    t++;		    	
			}			

		}
	}
	
	for(int i = 0; i< t-1; i++){
		for(int j = i+1; j< t; j++){			
			if(sapxep[i].do_dai > sapxep[j].do_dai){
				Canh temp = sapxep[i];
				sapxep[i] = sapxep[j];
				sapxep[j] = temp;
			}
		}
	}
}

void Kruskal(){
    int luu_cay = 0;
	//Mang sapxep[] bao gom cac canh co diem batdau, diem ketthuc va dodai cua canh do
	//Duyet mang sapxep[] bat dau tu canh nho nhat
	for(int i = 0; i< t; i++){

	    //Duyet tat ca cac dinh, chuyen cac dinh ve mot cay sao cho ko tao chu trinh
		for(int j = 0; j< sodinh; j++){
			
			if(( sapxep[i].bat_dau.cay == V[j].cay || sapxep[i].ket_thuc.cay == V[j].cay)
			&& ( V[sapxep[i].bat_dau.ten_diem].cay != V[sapxep[i].ket_thuc.ten_diem].cay || V[sapxep[i].bat_dau.ten_diem].cay != V[j].cay)){
				
				V[j].cay = V[sapxep[i].bat_dau.ten_diem].cay;
				ketqua[so_canh] = sapxep[i];
				so_canh++;
			}
		}
		if(so_canh == (sodinh - 1)*2 ){
			break;
		}
	}
	
}
int main(){
	KhoiTao();
	SapXep();
	Kruskal();
	//Hien thi cay khung Kruskal
	for(int i = 0; i< so_canh; i = i+2){
		cout<<ketqua[i].bat_dau.ten_diem<<"->( "<<ketqua[i].do_dai<<") "<<ketqua[i].ket_thuc.ten_diem<<endl;
	}
	return 0;
}
