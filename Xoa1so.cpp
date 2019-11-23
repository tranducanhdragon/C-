#include<bits/stdc++.h>
#include<sstream>

using namespace std;

int deleteDigit(int n) {
	stringstream ss;
	ss<<n;
    string s = ss.str();
    vector<int>r;
	for(int i = s.length()-1; i>= 0; i--){

		string str = s.erase(i, 1);
		int k;
		istringstream(str)>>k;
		r.push_back(k);
		s.clear();
		s = ss.str();	
	}
	sort(r.begin(), r.end());
	return r[s.length()-1];
}
int main(void) 
{ 
    int res = deleteDigit(17911112);
    cout<<res;
	return 0; 
} 
