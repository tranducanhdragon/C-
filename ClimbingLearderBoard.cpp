#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> &v, int x, int& end){
	int start = 0;
    while(start <= end){
        int key = (start + end)/2;
        if(x == v[key]){
        	v.resize(key+1);
            return key;
        }
        else if(x > v[key] && x < v[key-1]){
        	v.resize(key+1);
        	return key ;
		}
		else if(x < v[key] && x > v[key+1]){
			v.resize(key+2);
			return key + 1;
		}
		else if(x > v[key]){
			v.resize(key);
            end = key - 1;
        }
        else if(x < v[key]){
            start = key + 1;
        }    
    }
    return -1;
}
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    //Remove duplicate elements from vector scores
    scores.erase( unique( scores.begin(), scores.end() ), scores.end() );
    //s is start, e is end , index is index of alice[i]
    int s = 0, e = scores.size(), index = 0;
    vector<int> result(alice.size());
    vector<int> rank(e);
    int a = alice.size();
    rank[0] = 1;
    for (int i = 1; i < e; i++) {
        rank[i] = rank[i - 1] + 1;
	}
    for(int i = 0; i < a; i++){
        if(alice[i] < scores[e-1]){
            result[i] = rank[e-1]+1;
        }
        else if(alice[i] > scores[0]){
            result[i] = 1;
        }
        else{
            index = BinarySearch(scores, alice[i], e);
            result[i] = rank[index];
        }    
    }
    return result;
}
int main(){
	vector<int> scores = {100, 100, 50, 40, 40, 20, 10};
	vector<int> alice = {5, 25, 50, 120};
	vector<int> a = climbingLeaderboard(scores, alice);
	for(int i = 0; i< a.size(); i++){
		cout<<" "<<a[i];
	}
	return 0;
}
