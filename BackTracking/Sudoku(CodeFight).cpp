#include<bits/stdc++.h>
using namespace std;
bool CheckNgang(vector<vector<char> > grid, int x, int y, int k){
    for(int i = 0; i< 9; i++){
    	
        if(grid[x][i] - '0' == k ){
            return false;
        }
    }
    return true;
}
bool CheckDoc(vector<vector<char> > grid, int x, int y, int k){
    for(int i = 0; i< 9; i++){
        if(grid[i][y] - '0' == k ){
            return false;
        }
    }
    return true;
}
bool CheckVung(vector<vector<char> > grid, int x, int y, int k){
    int a = (x/3)*3, b = (y/3)*3;
    for(int i = a; i < a+3; i++){
        for(int j = b; j < b+3; j++){
            if(grid[i][j] - '0' == k ){
                return false;
            }
        }
    }
    return true;
}
void Try(int i, vector<vector<char> > grid, int& N, vector<string> & result){
    int x = i/9, y = i%9;
    if(grid[x][y] != '0' && N != 0){
		if(x * y == (N-1)*(N-1)){
			N = 0;
		}
		else{
			Try(i+1, grid, N, result);
		}
	}
	else{
		for(int k = 1; k <= 9; k++){
			if(CheckDoc(grid, x, y, k) && CheckNgang(grid, x, y, k) && CheckVung(grid, x, y, k) && N!= 0){
				grid[x][y] = (char)k + '0';
				if(x*y < (N-1)*(N-1)){
					Try(i+1, grid, N, result);
				}
				else{
					for(int i = 0; i< 9; i++){
						
                        for(int j = 0; j < 9; j++){
                            result[i] += grid[i][j];
                        }
                    }
					N = 0;
				}
				if(N != 0){
					grid[x][y] = 0;
					
				}
				
			}
	    }
	}
}
std::vector<std::string> sudokuSolve(std::vector<std::string> matrix)
{
    vector<vector<char> > grid(9);
    for(int i = 0; i< 9; i++){
        grid[i].resize(9);
        copy( matrix[i].begin(), matrix[i].end(), grid[i].begin());
    }
    int N = 9;
    vector<string> result(9);
    Try(0, grid, N, result);
    
    return result;
}
int main(){
	vector<string> a = {
		{'.', '4', '2', '.'},
	    {'1', '.', '.', '3'},
	    {'4', '3', '1', '.'},
	    {'2', '1', '3', '4'},
	};
	vector<string> c = {"123456789", "000000000", "000000000", "000000000","000000000", "000000000", "000000000","000000000", "000000000"};
	vector<string> b = sudokuSolve(c);
	for(int i = 0; i< b.size(); i++){
		cout<<b[i]<<"\n";
	}
	return 0;
}
