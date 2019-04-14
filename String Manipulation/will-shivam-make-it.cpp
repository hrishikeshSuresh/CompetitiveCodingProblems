#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main(int argc, const char *argv[]){
    int T;
    string text, pattern;
    cin >> T;
    while(T--){
        cin >> text >> pattern;
        lli n = text.length();
        lli m = pattern.length();
        lli min_d = n, d = 0, i = 0, j = 0, k = 0;
        for(i=0; i<n-m+1; i++){
            if(text[i] == pattern[0]){
                k = 0;
                d = 0;
                for(j=i; j<n; j++){
                    if(text[j] == pattern[k]){
                        k++;
                        if(k == m){
                            if(d < min_d){
                                min_d = d;
                                break;
                            }
                        }
                    }
                    else{
                        d++;
                    }
                }
            }
        }
        if(min_d == n)
            cout << "NO\n";
        else
            cout << "YES " << min_d  << endl;
    }
    return 0;
}
