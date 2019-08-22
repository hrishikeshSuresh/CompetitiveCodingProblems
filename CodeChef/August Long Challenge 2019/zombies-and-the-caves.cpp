#include<bits/stdc++.h>

using namespace std;

string isItPossibleToKill(int N, vector<int> C, vector<int> H){
	vector<int> arr(N, 0);
	for(int i=0; i<N; i++){
		int low = max(i - C[i], 0);
		int high = min(i + C[i], N-1);
		arr[low]++;
		if(high+1 < N)
			arr[high+1]--;
	}
	for(int i=1; i<N; i++)
		arr[i] += arr[i-1];
	sort(arr.begin(), arr.end());	
	sort(H.begin(), H.end());
	for(int i=0; i<N; i++){
		if(arr[i] != H[i])
			return "NO";
	}
	return "YES";
}

int main(int argc, const char *argv[]){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> C(N);
		vector<int> H(N);
		for(int i=0; i<N; i++)
			cin >> C[i];
		for(int i=0; i<N; i++)
			cin >> H[i];
		string outcome = isItPossibleToKill(N, C, H);
		cout << outcome << "\n";
	}
	return 0;
}
