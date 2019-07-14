#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli T, N;
    cin >> T;
    while(T--){
        cin >> N;
        vector<pair<lli, lli>> arr;
        lli t1, t2;
        for(lli i=0; i<N; i++){
            cin >> t1 >> t2;
            arr.push_back(make_pair(t1+t2, i+1));
        }
        stable_sort(arr.begin(), arr.end());
        for(auto i : arr)
            cout << i.second << " ";
        cout << "\n";
    }
    return 0;
}
