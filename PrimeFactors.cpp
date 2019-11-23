// C++ program to print all prime factors 
#include <bits/stdc++.h> 
using namespace std; 

// A function to print all prime 
// factors of a given number n 
std::vector<int> primeFactors(int n) 
{ 
    vector<int> result;
	// Print the number of 2s that divide n
	bool factor2 = false, factor = false; 
	while (n % 2 == 0) 
	{ 
		//cout << 2 << " "; 
		n = n/2; 
		factor2 = true;
	}
	if(factor2)
	    result.push_back(2); 

	// n must be odd at this point. So we can skip 
	// one element (Note i = i +2) 
	for (int i = 3; i <= sqrt(n); i = i + 2) 
	{ 
		// While i divides n, print i and divide n 
		while (n % i == 0) 
		{ 
			//cout << i << " "; 
			n = n/i; 
			factor = true;
		} 
		if(factor){
			result.push_back(i);
			factor = false;	
		}
	} 

	// This condition is to handle the case when n 
	// is a prime number greater than 2 
	if (n > 2) 
		result.push_back(n);
		
	return result; 
} 

int main() 
{ 
	int n = 999999997; 
	vector<int> x = primeFactors(n); 
	for(int i = 0; i< x.size(); i++){
		cout<<x[i]<<endl;
	}
	return 0; 
} 

