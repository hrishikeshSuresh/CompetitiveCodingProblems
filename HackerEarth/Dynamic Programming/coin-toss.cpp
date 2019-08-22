#include<bits/stdc++.h>

using namespace std;

//long long int mod_7 = 1000000007;

int main(int argc, const char *argv[]){
    long long int T, N, combination_ways, k;
    scanf("%llu", &T);
    while(T--){
        scanf("%llu", &N);
        k = N - 2;
        combination_ways = 0;
        //printf("%llu %llu\n", N, k);
        while(k>0){
            combination_ways += k;
            k--;
        }
        combination_ways = std::pow(2, N) - combination_ways;
        printf("%llu\n", combination_ways);
    }
    return 0;
}
