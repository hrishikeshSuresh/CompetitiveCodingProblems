#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]){
    int N;
    string S;
    cin >> N;
    cin >> S;
    set<char> S = {'a', 'e', 'i', 'o', 'u'};
    for(auto i : S){
        if(S.find(i) != S.end())
            S.erase()
    }
    return 0;
}
