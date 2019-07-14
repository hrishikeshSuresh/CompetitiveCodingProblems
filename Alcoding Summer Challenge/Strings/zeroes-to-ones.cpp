#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--){
        string D, H;
        cin >> D >> H;
        if(D == H)
            cout << "yes\n";
        else{
            stack<char> d, h;
            for(int i=D.length()-1; i>=0; i--){
                d.push(D[i]);
            }
            for(int i=H.length()-1; i>=0; i--){
                h.push(H[i]);
            }
            bool flag = true;
            while(!h.empty() && !d.empty()){
                char n = d.top();
                char m = h.top();
                if(n == m){
                    h.pop();
                    d.pop();
                }
                else if(m == '0' && n == '1'){
                    break;
                }
                else if(n == '0' && m == '1'){
                    d.pop();
                    h.pop();
                    if(d.empty())
                        break;
                    char s = d.top();
                    d.pop();
                    if(s == '0')
                        continue;
                    else
                        break;
                }
            }
            if(d.empty() && h.empty())
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }
    return 0;
}
