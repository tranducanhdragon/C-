#include<bits/stdc++.h>
using namespace std;
//Check if s1 and s2 has only one different character
bool onlyOneDifference(string s1, string s2){
	int count = 0;
	for(int i = 0; i< s1.length(); i++){
		if(s1[i] != s2[i])
		    count++;
	}
	if(count == 1)
	    return true;
	else
	    return false;
}
//BackTracking approach
void recursionString(int i, vector<string> &input, vector<bool> &b, int &count, vector<int> &res){
	for(int k = 0; k < input.size(); k++){
		if(onlyOneDifference(input[i], input[k]) && b[k] == false){
			b[k] = true;
			if(count == input.size()-1){
				res.push_back(1);
			}
			else{
				count++;
				recursionString(k, input, b, count, res);
			}
			b[k] = false;
			count--;
		}
	}
}
bool stringsRearrangement(vector<string> inputArray) {
    vector<bool> b(inputArray.size(), false);
    vector<int> res;
    int count = 1;
    //Try from every possible element
    for(int i = 0; i < inputArray.size(); i++){
    	b[i] = true;
    	recursionString(i, inputArray, b, count, res);
    	b[i] = false;
	}
    
    vector<int>::iterator it = find(res.begin(), res.end(), 1);
    if(it != res.end())
        return true;
    else
        return false;
}
int main(){
	vector<string> a = {"ab", "bb", "aa"};
	cout<<stringsRearrangement(a);

	return 0;
}
