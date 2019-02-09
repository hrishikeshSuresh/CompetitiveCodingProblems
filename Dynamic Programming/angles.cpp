#include<bits/stdc++.h>
#include<vector>

typedef long long int lli;

#define loop(i, a, b) \
for(lli i=a; i<b; i++)

int main(int argc, const char *argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    lli N, K;
    lli angles[4] = {0, 90, 180, 270, 360}
    lli *ram, *rani;
    scanf("%llu %llu", &N, &K);
    ram = (lli*)malloc(sizeof(lli)*N);
    rani = (lli*)malloc(sizeof(lli)*K);
    loop(i, 0, N)
        scanf("%llu", &ram[i]);
    loop(i, 0, K)
        scanf("%llu", &rani[i]);
    loop(i, 0, N){
        loop(j, 0, K){

        }
    }
    return 0;
}
