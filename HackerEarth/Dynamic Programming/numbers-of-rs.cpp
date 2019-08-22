#include<bits/stdc++.h>
#include<iostream>
#include<string>

typedef long long int lli;

#define loop(i, a, b) \
for(lli i=a; i<b; i++)

int main(int argc, const char *argv[]){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    lli T, zero = 0;
    char tmp[1000001];
    scanf("%llu", &T);
    while(T--){
        scanf("%1000000s", tmp);
        std::string S = tmp;
        lli curr_max = 0, max_diff = 0, original_zero_count = 0;
        loop(i, 0, S.length()){
            if(S[i]=='R')
                original_zero_count++;
            lli val = (S[i]=='K')? 1:-1;
            //printf("%s %llu\n", S[i], val);
            curr_max = std::max(val, curr_max + val);
            max_diff = std::max(max_diff, curr_max);
        }
        max_diff = std::max(max_diff, zero);
        //if all are R, then only one R is inverted to K
        if(original_zero_count == S.length()){
            printf("%llu\n", max_diff + original_zero_count-1);
            continue;
        }
        printf("%llu\n", max_diff + original_zero_count);
    }
    return 0;
}
