#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxProfit(vector<int> arr, int N){
    vector<int> dp(N);
    dp[0] = arr[0];
    dp[1] = arr[1] + arr[0];
    dp[2] = max(dp[1], max(arr[2] + arr[0], arr[2] + arr[1]));
    for(int i=3; i<N; i++)
        dp[i] = max(dp[i-1], max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i]));
    return dp[N-1];
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++)
        cin >> arr[i];
    int ans = maxProfit(arr, N);
    cout << ans << "\n";
    return 0;
}
