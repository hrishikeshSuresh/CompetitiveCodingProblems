#include<bits/stdc++.h>

int main(int argc, const char *argv[]){
    int T;
    std::cin >> T;
    while(T--){
        std::string S;
        std::cin >> S;
        std::map<char, int> M;
        for(int i=0; i<S.length(); i++){
            M[S[i]]++;
        }
        /*std::map<char, int>::iterator itr;
        for(itr = M.begin(); itr!=M.end(); itr++){
            std::cout << itr->first << " " << itr->second << std::endl;
        }*/
        int count_parenthesis = 0;
        if(M[')']>0 && M['(']>0)
            count_parenthesis += (2*std::min(M['('], M[')']));
        if(M['[']>0 && M[']']>0)
            count_parenthesis += (2*std::min(M['['], M[']']));
        if(M['{']>0 && M['}']>0)
            count_parenthesis += (2*std::min(M['{'], M['}']));
        std::cout << count_parenthesis << std::endl;
    }
    return 0;
}
