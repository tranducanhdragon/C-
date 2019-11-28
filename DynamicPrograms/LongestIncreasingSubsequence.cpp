#include<bits/stdc++.h>
using namespace std;
/*
example: 1  7  3  5  4  2
length:  1  2  2  3  3  2
trace:   0  0  0  2  2  0
*/
//Dynamic programming approach
int longestSequence(vector<int> a) {
	int n = a.size();
	//Initialize vector length with all elements are 1
	vector<int> length(n, 1);
	
	for(int i = 1; i < n; i++){
    	for(int j = 0; j < i; j++){
		    if(a[j] < a[i]){
		    	length[i] = max(length[i], length[j]+1);
			}
		}
    }
	return *max_element(length.begin(), length.end());
}
int main(){
	vector<int> a = {1, 7, 3, 5, 4, 2};
	int x = longestSequence(a);
	cout<<x;
    
	return 0;
}
