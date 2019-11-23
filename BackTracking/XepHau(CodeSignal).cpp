#include<bits/stdc++.h>
using namespace std;

//int viTri[N][N] = {0};//vi tri quan hau co the dat
//int ungVien[N] = {0};//gia tri gom 1, 2, 3,....,8

void Them(vector<vector<int> > &viTri, int N){

	for(int k = 0; k< N; k++){
		for(int t = 0; t < N; t++){
			cout<<" "<<viTri[k][t];
		}
		cout<<"\n";
	}
}
bool checkHang(vector<vector<int> > &viTri, int x, int N){
	for(int i = 0; i< N; i++){
		if(viTri[x][i] != 0){
			return false;
		}
	}
	return true;
}
bool checkCot(vector<vector<int> > &viTri, int y, int N){
	for(int i = 0; i< N; i++){
		if(viTri[i][y] != 0){
			return false;
		}
	}
	return true;
}
bool checkCheo(vector<vector<int> > &viTri, int x, int y, int N){

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i + j == x + y){
				if(viTri[i][j] != 0){
					return false;
				}
			}
			if(i - j == x - y){
				if(viTri[i][j] != 0){
					return false;
				}
			}
		}
	}
	return true;
}
void Try(vector<vector<int> > &viTri, vector<int> &ungVien, int i, int x , int N, vector<vector<int> > &result, vector<int> &a){
	
	for(int k = 0; k < N; k++){
		
		if(checkHang(viTri, x, N) && checkCot(viTri, k, N) && checkCheo(viTri, x, k, N) && ungVien[i] == 0 && viTri[x][k] == 0){
			
			viTri[x][k] = k+1;
			a.push_back(k+1);
			ungVien[i] = 1;
			if(i == N-1){
				result.push_back(a);
				Them(viTri, N);
				cout<<"\n";
			}
			else if (i < N-1){
				Try(viTri, ungVien, i+1, x + 1, N, result, a);
			}
			ungVien[i] = 0;
			viTri[x][k] = 0;
			if (!a.empty()){
				a.pop_back();
			}
		}
	}
}
vector<vector<int> > nQueens(int n) {
	vector<vector<int> > result;
	vector<int> a;
    vector<vector<int> > viTri(n);
    //Initial
	for(int i = 0; i< viTri.size(); i++){
		viTri[i].resize(n);
		fill(viTri[i].begin(), viTri[i].end(), 0);
	}
	vector<int> ungVien(n);
	fill(ungVien.begin(), ungVien.end(), 0);
	//Run
	Try(viTri, ungVien, 0, 0, n, result, a);
	sort(result.begin(), result.end());
	return result;
}
int main(){
	vector<vector<int> > a = nQueens(5);
	for(int i = 0; i< a.size(); i++){
		for(int j = 0; j< a[i].size(); j++){
			cout<<" "<<a[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
