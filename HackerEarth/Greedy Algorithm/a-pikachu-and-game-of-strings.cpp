#include<bits/stdc++.h>

typedef long long int lli;

#define loop(i, a, b) \
for(lli i=a; i<b; i++)

int main(int argc, const char *argv[]){
    lli N;
    scanf("%llu", &N);
    char tmp[100001];
    //scanf("%100000s", tmp);
    std::string s = "ABCT";
    //scanf("%100000s", tmp);
    std::string t = "PBDI";
    int curr_diff;
    lli total_days = 0, hidden_moves, normal_moves;
    loop(i, 0, N){
        curr_diff = 0;
        hidden_moves = 0;
        normal_moves = 0;
        curr_diff = (t[i] - '0') - (s[i] - '0');
        printf("curr_diff : %lld\n", curr_diff);
        if(curr_diff == 0)
            continue;
        if(curr_diff < 0){
            printf("in here\n");
            char A = t[i];
            while(A!=s[i]){
                if(A == 'Z')
                    A = 'A';
                int tmp = int(A) + 1;
                A = char(tmp);
                std::cout << "curr_diff" << A << std::endl;
            }
        }
        hidden_moves = lli(curr_diff/13);
        normal_moves = lli(curr_diff%13);
        total_days += (hidden_moves + normal_moves);
    }
    printf("%llu\n", total_days);
    return 0;
}
