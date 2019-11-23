#include<bits/stdc++.h>
using namespace std;
string classifyStrings(string s) {
	int n = s.length();
	vector<int> check(n), vowel(n), consonant(n);
    bool isMixed = false;
    int indexHoiVowel = -1, indexHoiConsonant = -1;
	//Initial check_string
	for(int i = 0; i< n; i++){
		if(isalpha(s[i])){
			if(s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' || s[i] == 'i'){
				check[i] = 1;
			}
			else{
				check[i] = 0;
			}
		}
		else{
			check[i] = -1;
		}
	}
	//Start the dynamic-programming approach
	if(check[0] == 0){
		consonant[0] = 1;
		vowel[0] = 0;
	}
	else if(check[0] == 1){
		consonant[0] = 0;
		vowel[0] = 1;
	}
	else if(check[0] == -1){
		consonant[0] = 1;
		vowel[0] = 1;
	}
	for(int i = 1; i< n; i++){
		if(check[i] == 0){
			consonant[i] = consonant[i-1] + 1;
			vowel[i] = 0;
		}
		else if(check[i] == 1){
			vowel[i] = vowel[i-1] + 1;
			consonant[i] = 0;
		}
		//In case of question mark “?” add one to both consonant and vowel array
		else if(check[i] == -1){
			consonant[i] = consonant[i-1] + 1;
			vowel[i] = vowel[i-1] + 1;
		}
		//check if there is no "?" in vowel[i] or cosonant[i]
		if(vowel[i] >= 3){
			int vt = *find(check.begin()+i-2, check.begin()+i, -1);
			auto vit = find(check.begin()+i-2, check.begin()+i, -1);
			indexHoiVowel = distance(check.begin(), vit);
	        if(vt != -1 ){//No "?" in vowel
	        	return "bad";
			}
			else{
				isMixed = true;
			}
			vt = 0;
		}
		if(consonant[i] >= 5){
			int ct = *find(check.begin()+i-4, check.begin()+i, -1);
			auto cit = find(check.begin()+i-2, check.begin()+i, -1);
			indexHoiConsonant = distance(check.begin(), cit);
	        if(ct != -1 ){//No "?" in consonant
	        	return "bad";
			}
			else{
				isMixed = true;
			}
			ct = 0;
		}
		//Check the difference between indexHoiVowel and indexHoiConsonant
		if(abs(indexHoiVowel - indexHoiConsonant) <= 7 && indexHoiVowel != -1 && indexHoiConsonant != -1){
			return "bad";
		}
	}
	if(isMixed){
		return "mixed";
	}
	else{
		return "good";
	}
	
}

int main(){
    string s = classifyStrings("xnifpse???bggpirro");
    cout<<s;
	return 0;
}
