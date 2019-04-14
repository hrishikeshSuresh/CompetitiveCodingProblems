#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(int argc, const char *argv[]){
    lli n, d;
    cin >> n >> d;
    lli a[n], f[n];
    for(lli i=0; i<n; i++)
        cin >> a[i];
    for(lli i=0; i<n; i++){
        f[i] = a[(i+d)%n];
        cout << f[i] << " ";
    }
    return 0;
}
