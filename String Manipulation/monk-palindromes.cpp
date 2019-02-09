#include<bits/stdc++.h>

typedef long long int lli;

int main(int argc, const char *argv[]){
    int T;
    std::cin >> T;
    while(T--){
        std::string S;
        std::cin >> S;
        bool flag = true;
        for(lli i=0, j=S.length()-1; i<S.length() && j>=0; i++, j--){
            //std::cout << S[i] << " " << S[j] << std::endl;
            if(S[i] != S[j]){
                flag = false;
                break;
            }
            if(i==j){
                flag = true;
                break;
            }
        }
        if(flag == true && S.length()&1) std::cout << "YES ODD\n";
        else if(flag == false) std::cout << "NO\n";
        else std::cout << "YES EVEN\n";
    }
    return 0;
}
