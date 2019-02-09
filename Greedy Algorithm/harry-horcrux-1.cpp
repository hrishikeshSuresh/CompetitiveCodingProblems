#include<bits/stdc++.h>

typedef long long int lli;

lli mod = 1000000007;

int main(int argc, const char *argv[]){
    int T;
    std::cin >> T;
    while(T--){
        lli N, x;
        std::cin >> N;
        std::vector<lli> A;
        lli cost = 0;
        for(lli i=0; i<N; i++){
            std::cin >> x;
            A.push_back(x);
        }
        lli j = 1;
        std::sort(A.begin(), A.end());
        //std::reverse(A.begin(), A.end());
        cost = A[0];
        for(lli i=1; i<N; i++){
            j = (j*(i+1))%mod;
            A[i] = (j*A[i])%mod;
            cost = (cost + A[i])%mod;
        }
        //std::cout << A[0] << std::endl;
        std::cout << cost << std::endl;
    }
    return 0;
}
