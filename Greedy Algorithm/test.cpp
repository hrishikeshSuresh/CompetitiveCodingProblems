#include<bits/stdc++.h>

typedef long long int lli;

#define loop(i, a, b) \
for(lli i=a; i<b; i++)

int main(int argc, const char *argv[]){
     std::string s = "ABCT";
 std::string t = "PBDI";
 long long int curr_diff;
 for(lli i=0; i<4; i++){
       curr_diff = (t[i] - '0') - (s[i] - '0');
       if(curr_diff < 0)
            printf("Hello\n");
       printf("Current value : %lld\n", curr_diff);
 }
    return 0;
}
