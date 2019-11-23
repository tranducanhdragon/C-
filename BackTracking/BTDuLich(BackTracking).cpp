#include<bits/stdc++.h>
using namespace std;
#define n 5

int b[n] = {0};//Mang cac dinh cua duong di do
vector<int> a;//Mang luu cac dinh da di qua

int minGiaTri = 1000;
int trongSo[n][n] = {
	 {0, 1, 2, 7, 5},
	 {1, 0, 4, 4, 3},
	 {2, 4, 0, 1, 2},
	 {7, 4, 1, 0, 3},
	 {5, 3, 2, 3, 0}
	};

void Xuat(){
	for(int i = 0; i< n; i++){
		cout<<" "<<a[i];
	}
}
void Try(int i, int& sum){
	for(int k = 1; k < n; k++){
		if(b[k] == 0 ){

			sum += trongSo[a.back()][k];
			a.push_back(k);
			b[k] = 1;
			
			if(i == n - 2 && sum < minGiaTri){
			    Xuat();
			    cout<<"\nGia tri: "<<sum;
			    minGiaTri = sum;
			    cout<<"\n\n";
		    }
		    else if(i < n - 2 && sum < minGiaTri){
			    Try(i+1, sum);
		    }
		    b[k] = 0;
		    a.pop_back();
		    sum -= trongSo[a.back()][k];
		    
		}
	}
}

int main(){
    b[0] = 1;
    a.push_back(0);
    int sum = 0, s_index = 0, start = 0, end = 0;
	Try(0, sum);
	return 0;
}
