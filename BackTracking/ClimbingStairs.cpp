#include<bits/stdc++.h>
using namespace std;

void Xuat(vector<int> a){
	for(int i = 0; i< a.size(); i++){
		cout<<" "<<a[i];
	}
}
void Try(int i, int n, int k, vector<int> & a, vector<vector<int> > & result){
	
	for(int t = 0; t < k; t++){
		a.push_back(t+1);		
		if(i == n - 1){
			Xuat(a);
			result.push_back(a);
			cout<<"\n";
		}
		else if(i < n - 1){
			Try(i + 1, n, k, a, result);
		}
		a.pop_back();
		n--;		
	}
}
vector<vector<int> > climbingStaircase(int n, int k) {
	vector<vector<int> > result;
	vector<int> a;
	Try(0, n, k, a, result);
	return result;
}
int main(){
	vector<vector<int> > result;
	vector<int> a;
	Try(0, 4, 2, a, result);
	return 0;
}
