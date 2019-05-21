#include<bits/stdc++.h>

typedef long long int lli;
using namespace std;

int main(){
	int T,N;
	cin >> T;
	while(T--){
	    cin >> N;
	    int count = 0;
	    while(N){
	        N&=(N-1);
	        count++;
	    }
	    cout << count << endl;
	}
}
