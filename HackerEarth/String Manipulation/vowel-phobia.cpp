#include<bits/stdc++.h>

typedef long long int lli;

int main(int argc, const char *argv[]){
    lli T;
    std::string S;
    std::cin >> T;
    while(T--){
        lli count_vowels = 0;
        std::cin >> S;
        for(lli i=0; i<S.length(); i++){
            if(S[i]=='a' || S[i]=='e' || S[i]=='i' || S[i]=='o'||S[i]=='u')
                count_vowels++;
        }
        std::cout << count_vowels << std::endl;
    }
    return 0;
}
