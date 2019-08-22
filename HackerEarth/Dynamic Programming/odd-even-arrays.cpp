#include<bits/stdc++.h>
#include<tr1/unordered_map>

using namespace std;

int main(int argc, const char *argv[]){
    long long int N, x, curr_sum;
    scanf("%llu", &N);
    std::tr1::unordered_map<long long int, long long int> um;
    for(long long int i=0; i<N; i++){
        scanf("%llu", &x);
        x = (x%2==0)?1:-1;
        curr_sum += x;
        um[curr_sum]++;
        //printf("%d\n", x);
    }
    long long int count_val = 0;
    std::tr1::unordered_map<long long int, long long int>::iterator itr;
    for(itr = um.begin(); itr!=um.end(); itr++){
        if(itr->second > 1)
            count_val += (((itr->second)*(itr->second-1))/2);
    }
    if(um.find(0) != um.end())
        count_val += um[0];
    printf("%llu", count_val*2);
    return 0;
}
