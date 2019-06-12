#include<bits/stdc++.h>

using namespace std;

vector<int> findPrimeFactors(int n){
	vector<int> pf;
	while(n%2 == 0){
		pf.push_back(2);
		n = n/2;
	}
	for(int i=3; i<=sqrt(n); i+=2){
		while(n%i == 0){
			pf.push_back(i);
			n = n/i;
		}
	}
	if(n>2)
		pf.push_back(n);
	return pf;
}

int main(int argc, const char *argv[]){
	vector<int> ans = findPrimeFactors(100);
	for(auto i : ans){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
