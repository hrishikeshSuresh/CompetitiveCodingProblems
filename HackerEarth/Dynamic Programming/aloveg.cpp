#include<bits/stdc++.h>
#include<string>

typedef long long int lli;

#define loop(i, a, b) \
for(lli i=a; i<b; i++)

//Kadane's Algorithm

int main(int argc, const char *argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    lli T;
    char tmp[1000001];
    scanf("%llu", &T);
    while(T--){
        scanf("%1000000s", tmp);
        std::string str = tmp;
        // A will be -1 and G will be 1
        lli total_A_count = 0, curr_max = 0, max_diff = 0, zero = 0;
        loop(i, 0, str.length()){
            if(str[i] == 'A')
                total_A_count++;
            lli val = (str[i]=='A')? -1:1;
            curr_max = std::max(val, curr_max+val);
            max_diff = std::max(curr_max, max_diff);
        }
        max_diff = std::max(max_diff, zero);
        if(total_A_count == str.length()){
            printf("%llu\n", total_A_count+max_diff-1);
            continue;
        }
        printf("%llu\n", max_diff+total_A_count);
    }
    return 0;
}
