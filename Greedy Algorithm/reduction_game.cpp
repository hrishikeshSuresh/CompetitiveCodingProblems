#include<bits/stdc++.h>

typedef long long int lli;

#define loop(i, a, b) \
for(lli i=a; i<b; i++)

lli countOnes(lli n){
    lli count_one  = 0;
    while(n){
        n&=(n-1);
        count_one++;
    }
    return count_one;
}

int main(int argc, const char *argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    lli N, C1, C2;
    std::cin >> T;
    while(T--){
        std::cin >> N;
        lli *A;
        A = (lli*)malloc(sizeof(lli)*N);
        std::cin >> C1 >> C2;
        loop(i, 0, N)
            std::cin >> A[i];

    }
    return 0;
}
