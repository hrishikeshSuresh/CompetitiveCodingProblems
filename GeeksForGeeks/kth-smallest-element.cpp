#include<bits/stdc++.h>

typedef long long int lli;
using namespace std;

int main(){
	lli T, K, N;
    scanf("%lld", &T);
	while(T--){
	    scanf("%lld", &N);
	    lli arr[N];
	    for(lli i=0; i<N; i++)
	        scanf("%lld", &arr[i]);
	    sort(arr, arr+N);
	    scanf("%lld", &K);
	    cout << arr[K-1] << endl;
	}
}
