#include<bits/stdc++.h>

int main(int argc, const char *argv[]){
    int N;
    std::string S;
    std::cin >> N;
    std::set<std::string> passwords;
    for(int i=0; i<N; i++){
        std::cin >> S;
        if(passwords.find(S) == passwords.end()){
            passwords.insert(S);
            std::reverse(S.begin(), S.end());
            if(passwords.find(S) != passwords.end()){
                std::cout << S.length() << " " << S[S.length()/2] << std::endl;
            }
        }
    }
    return 0;
}
