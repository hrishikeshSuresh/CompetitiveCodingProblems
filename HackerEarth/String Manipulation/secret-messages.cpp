#include<bits/stdc++.h>

typedef long long int lli;

int main(int argc, const char *argv[]){
    lli ascii[26], ASCII[26], numbers[10];
    for(lli i=65; i<=90; i++){
        ASCII[i-65] = i;
    }
    for(lli i=97; i<=122; i++){
        ascii[i-97] = i;
    }
    for(lli i=48;i<=57; i++){
        numbers[i-48] = i;
    }
    int T;
    lli N, K;
    std::cin >> T;
    std::string S;
    while(T--){
        std::cin >> N >> K;
        std::cin >> S;
        for(lli i=0; i<N; i++){
            if(int(S[i])>=65 && int(S[i])<=90){
                std::cout << char(ASCII[(int(S[i])+K-65)%26]);
            }
            else if(int(S[i])>=97 && int(S[i])<=122){
                std::cout << char(ascii[(int(S[i])+K-97)%26]);
            }
            else if(int(S[i])>=48 && int(S[i])<=57){
                std::cout << char(numbers[(int(S[i])+K-48)%10]);
            }
            else{
                std::cout << S[i];
            }
        }
        std::cout << std::endl;
     }
    return 0;
}
