#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]){
    long long int N;
    scanf("%llu", &N);
    long long int *health_score, *tablet_cache;
    health_score = (long long int*)malloc(sizeof(long long int)*N);
    tablet_cache = (long long int*)malloc(sizeof(long long int)*N);  //dynamic programming approach
    memset(tablet_cache, 0, sizeof(long long int)*N);
    for(long long int i=0; i<N; i++){
        scanf("%llu", &health_score[i]);
        tablet_cache[i] = 1;
    }
    for(long long int j=1; j<N; j++){
        if(health_score[j] > health_score[j-1]){
            tablet_cache[j] += tablet_cache[j-1];
        }
    }
    for(long long int j=N-2; j>=0; j--){
        if((tablet_cache[j]>tablet_cache[j+1]) && (tablet_cache[j+1]>tablet_cache[j])){
            tablet_cache[j] = tablet_cache[j+1] + 1;
        }
    }
    long long int sum = 0;
    for(long long int j=0; j<N; j++){
        sum += tablet_cache[j];
    }
    printf("%llu\n", sum);
    return 0;
}
