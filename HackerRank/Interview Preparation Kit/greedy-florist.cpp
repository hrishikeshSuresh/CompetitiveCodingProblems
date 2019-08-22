#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(int argc, const char *argv[]){
    lli n, k;
    cin >> n >> k;
    lli C[n];
    for(lli i=0; i<n; i++)
        cin >> C[i];
    sort(C, C+n);
    lli p = 0, sum = 0;
    lli m = n;
    for(lli i=n-1; i>=0; i--){
        sum += ((p+1)*C[i]);
        if(m-i == k){
            p++;
            m = i;
        }
    }
    cout << sum << endl;
    return 0;
}
