#include<iostream>
#include<Math.h>
using namespace std;

int indexML = 0;
int indexMR = 0;


int MaxRight(int a[], int i, int j, int &index){
	int max = a[i];
	int tong = a[i];
	index = i;
	for(int t = i+1; t<= j; t++){
		tong+= a[t];
		if(tong > max){
			max = tong;
			index = t;
		}
		
	}
	return max;
}

int MaxLeft(int a[], int i, int j, int &index){
	int max = a[j];
	int tong = a[j];
	index = j;
	for(int t = j-1; t>=i; t--){
		tong+= a[t];
		if(tong > max){
			max = tong;
			index = t;
		}
//		else{
//			index = j-1;
//		}
	}
	return max;
}

int MaxSubVector(int a[], int i, int j, int& indexL, int& indexR){
	if(i == j){
		indexL = indexR = i;
		return a[i];
	}
	else{
		int indexLL = 0;
        int indexLR = 0;
        int indexRL = 0;
        int indexRR = 0;
		int m = (i+j)/2;
		int maxL = MaxSubVector(a, i, m, indexLL, indexLR);
		int maxR = MaxSubVector(a, m+1, j, indexRL, indexRR);
		int maxM = MaxLeft(a, i, m, indexML) + MaxRight(a, m+1, j, indexMR);
		if(maxM > max(maxL, maxR)){
			indexL = indexML;
			indexR = indexMR;
		}
		else{
			if(maxL > maxR){
				indexL = indexLL;
				indexR = indexLR;
			}
			else{
				indexL = indexRL;
				indexR = indexRR;
			}
		}
		return max(maxM, max(maxL, maxR));
	}
}

int main(){
	int a[] = {12 ,-10 ,15, -8, -10, -11, -9, -7, -6, -5};
	int indexL, indexR;
	cout<<MaxSubVector(a, 0, 9, indexL, indexR);
	cout<<"\nIndexL "<<indexL<<" IndexR "<<indexR;
	return 0;
}
