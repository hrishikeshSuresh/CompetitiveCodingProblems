#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findHighestVolume(vector<int> arr, int N){
    int left[N], right[N];
    left[0] = arr[0];
    right[N-1] = arr[N-1];
    for(int i=1; i<N; i++)
        left[i] = max(left[i-1], arr[i]);
    for(int i=N-2; i>=0; i--)
        right[i] = max(right[i+1], arr[i]);
    int ans = 0;
    for(int i=0; i<N; i++){
        ans += (min(left[i], right[i]) - arr[i]);
    }
    return ans;
}

int main() {
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        int ans = findHighestVolume(arr, N);
        cout << ans << "\n";
    }
    return 0;
}
