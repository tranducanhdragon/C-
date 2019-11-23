#include<bits/stdc++.h>
using namespace std;
void Xuat(vector<int> &result ){
	for(int i = 0; i< result.size(); i++){
		cout<<" "<<result[i];
	}
	cout<<"\n";
}

void Try(int i, vector<int> arr, int num, vector<int> &result, vector<vector<int> > &lastResult, vector<int> &b, int &index){
    for(int k = index; k < arr.size(); k++){
    	if(b[k] == 0 ){
    		result.push_back(arr[k]);
    		b[k] = 1;
    		//Sum of all elements in result
    		int sum = accumulate(result.begin(), result.end(), 0);
            if(sum == num){
            	sort(result.begin(), result.end());
                lastResult.push_back(result);
            }
            else if(sum <= num ){
                Try(i+1, arr, num, result, lastResult, b, index);
            }
            b[k] = 0;
            //Save the index which is erased from the last backtracking
            index = k+1;
            result.erase(remove(result.begin(), result.end(), arr[k]), result.end());
            if(sum >= num){
            	break;
			}
        }
    }
}
vector<vector<int> > sumSubsets(vector<int> arr, int num) {
	//This is the possible element in arr - Ung vien duoc chon trong mang arr
	vector<int> b(arr.size());
	fill(b.begin(), b.end(), 0);
	
	vector<int> result;
	vector<vector<int> > lastResult;
	if(arr.size() == 0 || num == 0){
		arr.clear();
	    lastResult.push_back(arr);	
	}
	int index = 0;
    Try(0, arr, num, result, lastResult, b, index);
    //Remove duplicated vector from lastResult
    sort(lastResult.begin(), lastResult.end());
    lastResult.erase( unique( lastResult.begin(), lastResult.end()), lastResult.end());
    return lastResult;
}
int main(){
	vector<int> arr = {1, 2, 4};
	
	vector<vector<int> > result = sumSubsets(arr, 0);
	for(int i = 0; i< result.size(); i++){
		for(int j = 0; j < result[i].size(); j++){
			cout<<" "<<result[i][j];
		}
		cout<<"\n";
	}
	
	return 0;
}
