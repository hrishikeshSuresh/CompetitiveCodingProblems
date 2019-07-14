#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int ans = 0;
        int n = s.length();
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                ans += (n - i);
            else if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                ans += (n - i);
        }
        cout << ans << "\n";
    }
    return 0;
}
