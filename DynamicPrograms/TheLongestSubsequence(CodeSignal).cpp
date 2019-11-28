#include<bits/stdc++.h>
using namespace std;

//Dynamic programming approach(from the longest increasing subsequence)
int FindSub(vector<int> a, float d) {
	//d is the difference of 2 element in athrimetic progression subsequence
    
	int n = a.size(), m, t = d;
    
    //initialize all elements are 1, vector length is the length of each athrimetic progression subsequence
    vector<int> length(n, 1);
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] - a[j] == d){
            	length[i] = max(length[i], length[j] + 1);
            	d /= 2;
			}   
        }
		d = t; 
    }
    return *max_element(length.begin(), length.end());
}
int longestSequence(vector<int> a){
	int n = a.size();
	vector<int> res;
    if(n < 3) return n;
    
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			int d = a[i] - a[j];
			//Try with every d of each element
			int x = FindSub(a, d);
			res.push_back(x);
		}
	}
	return *max_element(res.begin(), res.end());
}

int longestSequence2(vector<int> a) {
    int n = a.size(), m = 1, d;
    int t[n][n];
    for (int i = 0; i < n; i++) 
    {
        t[i][i] = 1;
        for (int j = i + 1; j < n; j++) 
        {
            t[i][j] = 2;
            d = a[j] - a[i];
            for (int k = i - 1; k >= 0; k--)
                if (a[i] - a[k] == d) 
                {
                    t[i][j]= max(t[i][j], t[k][i] + 1);
                    break;
                }
            m = max(m, t[i][j]);
        }
    }
    return m;
}
int main(){
	vector<int> a = {4, 1, 2, 4, 3, 5, 4, 6};
	int x = longestSequence(a);
	cout<<x;
	return 0;
}
