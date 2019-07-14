#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    string X;
    cin >> T;
    while(T--){
        cin >> X;
        stack<int> S;
        int ans = 0;
        for(int i=0; i<X.length(); i++){
            if(X[i] == '<'){
                S.push(X[i]);
            }
            else if(!S.empty()){
                if(S.top() == '<' && X[i] == '>')
                    S.pop();
                    ans+=2;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
