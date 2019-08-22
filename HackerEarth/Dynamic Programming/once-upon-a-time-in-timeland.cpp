#include<bits/stdc++.h>
#include<map>

using namespace std;

int main(int argc, const char *argv[]){
    long long int T, N, K, x;
    std::map<long long int, long long int> om;
    scanf("%llu", &T);
    while(T--){
        scanf("%llu %llu", &N, &K);
        for(long long int i=0; i<N; i++){
            scanf("%llu", om[i]);
        }
        std::sort(om.begin(), om.end());
        std::map<long long int, long long int>::iterator itr;
        for(itr=om.begin(); itr!=om.end(); itr++){
            printf("%llu %llu", itr->first, om[itr->first]);
        }
    }
    return 0;
}
