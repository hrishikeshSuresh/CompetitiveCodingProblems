#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]){
    string S, O;
    cin >> S;
    bool flag = true;
    for(int i=0; i< S.length(); i++){
        if(S[i] == S[i+1]){
            S.erase(i+1, 1);
            S.erase(i, 1);
            i = -1;
        }
    }
    if(S.length() > 0)
        cout << S << endl;
    else
        cout << "Empty String" << endl;
    return 0;
}
