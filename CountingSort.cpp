#include<bits/stdc++.h>
using namespace std;
// C++ Program for counting sort 

void countSort(int arr[], vector<int> &output){
	int storeArr[10];
	memset(storeArr, 0, sizeof(storeArr));
	//Check how many times arr[i] appears
	for(int i = 0; i< sizeof(arr); i++){
		storeArr[arr[i]]++;
	}
	//Sum of previous
	for(int i = 0; i< 9; i++){
		storeArr[i+1] = storeArr[i]+storeArr[i+1];	
	}
	//Build the output array
	output = vector<int>(sizeof(arr));
	for(int i = 0; i< sizeof(arr); i++){
		output[storeArr[arr[i]]-1] = arr[i];
		storeArr[arr[i]]--;
	}
} 

int main(){
	int arr[8] = {0,2,4,1,5,3,6,9};
	vector<int> s;
	countSort(arr, s);
	for(int i = 0; i< s.size(); i++){
		cout<<" "<<s[i];
	}
	return 0;
}
