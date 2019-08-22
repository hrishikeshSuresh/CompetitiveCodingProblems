#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string S){
	int low = 0, high = S.length()-1;
	while(high > low){
		if(S[low++] != S[high--])
			return 0;
	}
	return 1;
}

int noOfFlips(string S){
	int c = 0;
	char curr = S[0];
	for(u_int i=1; i<S.length(); i++){
		if(S[i] != curr){
			c++;
			curr = S[i];
		}
	}
	return c;
}

string chefGame(string S){
	int flips = noOfFlips(S);
	unordered_map<char, int> fre;
	for(u_int i=0; i<S.length() ; i++)
		fre[S[i]]++;
	if(S.length() % 2 == 0){
		if(fre['0'] == fre['1'])
			return (isPalindrome(S))? "WIN":"LOSE";
		else
			return "LOSE";
	}
	else{
		if(fre['1'] - 1 == fre['0'] || fre['0'] - 1 == fre['0'])
			return (isPalindrome(S))? "WIN":"LOSE";
		else
			return "LOSE"; 
	}
	return (isPalindrome(S))? "WIN":"LOSE";
}

int main(int argc, const char *argv[]){
	int T;
	cin >> T;
	while(T--){
		string S;
		cin >> S;
		string decision = chefGame(S);
		cout << decision << "\n";
	}
	return 0;
}
