#include<bits/stdc++.h>

using namespace std;

bool isValid(int N){
	int prevBit = 0;

	while(N){
		// check if previous and current
		// bits are 1
		if((N&1) && prevBit) return false;
		prevBit = N&1;
		N = N >> 1;
	}
	return true;
}

int main(int argc, const char *argv[]){
	int T;
	cin >> T;
	while(T--){
		int K;
		cin >> K;
		vector<int> arr;
		int i = 1;
		while(arr.size() != K+1){
			if(isValid(i)) arr.push_back(i);
			i++;
		}
		cout << arr[K-1] << "\n";
	}
	return 0;
}
