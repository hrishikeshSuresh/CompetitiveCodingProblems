#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(int argc, const char *argv[]){
    lli n, x;
    cin >> n;
    lli arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    lli curr_abs_diff = 0;
    lli min_abs_diff = abs(arr[1] - arr[0]);
    for(lli i=0; i<n; i++){
        curr_abs_diff = abs(arr[i+1]-arr[i]);
        if(min_abs_diff > curr_abs_diff) min_abs_diff = curr_abs_diff;
    }
    cout << min_abs_diff << endl;
    return 0;
}
