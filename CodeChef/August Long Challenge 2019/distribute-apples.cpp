#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

string isOrderingDifferent(lli N, lli K){
	lli y = N/K;
	if(N == 1 && K > 1)
		return "YES";
	if(K == 1)
		return "NO";
	if(N == K)
		return "YES";
	if(y == K)
		return "NO";
	if(y % K == 0)
		return "NO";
	else
		return "YES";
	/*	
	vector<int> arr(K, 0);
	int j = 0;	
	while(N){
		arr[j] += K;
		N -= K;
		j = (j+1)%K;
	}
	unordered_map<lli, lli> hash;
	for(int i=0; i<K; i++)
		hash[arr[i]]++;
	if(hash[0] > 0)
		return "YES";
	for(auto i : hash){
		if(i.first == y && i.second == K)
			return "NO";
	}
	return "YES";
	*/
}

int main(int argc, const char *argv[]){
	lli T, N, K;
	cin >> T;
	while(T--){
		cin >> N >> K;
		string ans = isOrderingDifferent(N, K);
		cout << ans << "\n";
	}
	return 0;
}
