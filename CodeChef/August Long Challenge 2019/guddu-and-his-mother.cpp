#include<bits/stdc++.h>

using namespace std;

vector<int> findBitwiseXor(vector<int> A, int N){	
	
}

int main(int argc, const char *argv[]){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> A(N);
		for(int i=0; i<N; i++)
			cin >> A[i];
		vector<int> triples = findBitwiseXor(vector<int> A, int N);
		for(int i=0; i<triples.size(); i++)
			cout << triples[i] << " ";
		cout << "\n";
	}
	return 0;
}
