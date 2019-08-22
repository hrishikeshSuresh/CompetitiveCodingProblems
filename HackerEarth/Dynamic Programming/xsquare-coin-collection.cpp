#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]){
    long long int T, N, K, count_coins;
    long long int *H, *ndp;
    scanf("%llu", &T);
    while(T--){
        scanf("%llu %llu", &N, &K);
        count_coins = 0;
        H = (long long int*)malloc(sizeof(long long int)*N);
        ndp = (long long int*)malloc(sizeof(long long int)*N);
        memset(ndp, 0, sizeof(long long int)*N);
        for(long long int i=0; i<N; i++){
            scanf("%llu", &H[i]);
            if(H[i] <= K){
                count_coins += H[i];
            }
        }
        printf("%llu\n", count_coins);
    }
    return 0;
}
