#include<bits/stdc++.h>
#include<sstream>
using namespace std;

bool isMagicSquareOf3(vector<int> v){

    //First convert v to 2 dimension vector
    int vConvert[3][3];
    for(int i = 0; i< 3; i++){
    	for(int j = 0; j< 3; j++){
    		vConvert[i][j] = v[3*i+j];
		}
	}
    //Test row and column is 15 or not
    for(int i = 0; i<3; i++){
    	int sumRow = 0, sumColumn = 0;
        for(int j = 0; j< 3; j++){
            sumRow += vConvert[i][j];
            sumColumn += vConvert[j][i];
        }
        if(sumRow != 15 || sumColumn != 15 )
            return false;
    }
    //Test 2 diagonals is 15 or not
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for(int i = 0; i< 3; i++){
    	sumDiagonal1 += vConvert[i][i];
        sumDiagonal2 += vConvert[i][3-i-1];
	}
	if(	sumDiagonal1 != 15 || sumDiagonal2 != 15)
	    return false;
    return true;
}
void addMagicSquare(vector<vector<int> > &v){
    
    //Initial permutate
    vector<int> permutateVector;
    for(int i = 0; i< 9; i++){
    	permutateVector.push_back(i+1);
	}
    
    //Start permutate
    while(next_permutation(permutateVector.begin(), permutateVector.end())){
    	
        if(isMagicSquareOf3(permutateVector)){
        	v.push_back(permutateVector);
		}
    }
}
int cost(vector<int> a, vector<int> b){
	int res = 0;
	for(int i = 0; i< 9; i++){
		res += abs(a[i]-b[i]);
	}
	return res;
}
int formingMagicSquare(vector<vector<int> > s) {
	vector< vector<int> > magicSquare;
	addMagicSquare(magicSquare);
	//Convert s into 1 dimension vector
	vector<int> sConvert;
	for(int i = 0; i< 3; i++){
		for(int j = 0; j< 3; j++){
			sConvert.push_back(s[i][j]);
		}
	}
	//Compare the cost
	vector<int> bestcost;
	for(int i = 0; i< magicSquare.size(); i++){
		bestcost.push_back(cost(magicSquare[i], sConvert));
	}
	sort(bestcost.begin(), bestcost.end());
	return bestcost[0];
}
int main() 
{
	vector<vector<int> > s(3);
	for(int i = 0; i<3; i++){
		s[i].resize(3);
		for(int j = 0; j< 3; j++){
			int temp;
			cin>>temp;
			s[i][j] = temp;
		}
	}
	int t = formingMagicSquare(s);
	cout<<t;
    
	return 0; 
} 
