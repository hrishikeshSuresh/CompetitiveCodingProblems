#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int coins[] = {1, 5, 10, 25};
int m = sizeof(coins)/sizeof(coins[0]);

int makeChangeBruteForce(int sum){
    if(sum == 0) return sum;
    int minCoins = INT_MAX;
    for(int i = 0; i<m; i++){
        if(sum - coins[i] >= 0){
            int currCoins = makeChangeBruteForce(sum - coins[i]);
            if(currCoins < minCoins)
                minCoins = currCoins;
        }
    }
    return minCoins + 1;
}

int makeChangeDynamic(int sum){
    int cache[sum+1];
    memset(cache, 0, (sum+1)*sizeof(int));
    for(int i=0; i<=sum; i++){
        int minCoins = INT_MAX;
        for(int j=0; j<m; j++){
            if(i-coins[j] >=0){
                int currCoins = cache[i-coins[j]] + 1;
                if(currCoins < minCoins){
                    minCoins = currCoins;
                }
            }
        }
        cache[i] = minCoins;
    }
    return cache[sum];
}

int main(int argc, char const *argv[]){
    int sum;
    scanf("%d", &sum);
    int ans1 = makeChangeBruteForce(sum);
    printf("Brute-Force\n%d\n", ans1);
    int ans2 = makeChangeDynamic(sum);
    printf("Dynamic Programming\n%d\n", ans2);
    return 0;
}
