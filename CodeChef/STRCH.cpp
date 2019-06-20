#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli sumN(lli n){
	return (n*(n+1))/2;
}

lli solve(int N, string S, char X){
	lli missing_substrings = 0;
	lli length_of_non_matching_substring = 0;
	for(lli i=0; i<N; i++){
		if(S[i] == X){
			missing_substrings += sumN(length_of_non_matching_substring);
			length_of_non_matching_substring = 0;
			continue;
		}
		length_of_non_matching_substring++;
	}
	missing_substrings += sumN(length_of_non_matching_substring);
	return sumN(N) - missing_substrings;
}

int main(int argc, const char *argv[]){
		lli T, N;
    	string S;
		char X;
    	cin >> T;
    	while(T--){
        	cin >> N;
        	cin >> S >> X;
        	cout << solve(N, S, X) << endl;
    	}
	return 0;
}

