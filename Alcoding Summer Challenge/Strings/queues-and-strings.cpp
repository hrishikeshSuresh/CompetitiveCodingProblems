#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <set>
using namespace std;
typedef long long int lli;

const lli m = 1000000007;

lli no_of_distinct_substrings(string s){
    set<string> u;
    lli n = s.length();
    for (lli len = 1; len <= n; len++){ 
        for (lli i = 0; i <= n - len; i++){
            lli j = i + len - 1;
            string inter = "";
            for (lli k = i; k <= j; k++)  
                inter += s[k]; 
            u.insert(inter);  
        }
    }
    return u.size();
}

int main() {
    lli N;
    char sign, value;    
    cin >> N;
    deque<char> d;
    lli ans = 0;
    for(lli j=0; j<N; j++){
        cin >> sign;
        if(sign == '+'){
			cin >> value;
			cout << sign << " " << value << "\n";
            d.push_back(value);
        }
        else{
            d.pop_front();
        }
        string s = "";
        for(u_int i=0; i<d.size(); i++)
            s += d[i];
        //cout << "OP. " << j+1 << " " << s << " " << no_of_distinct_substrings(s) << "\n";
        ans = (ans + no_of_distinct_substrings(s)%m)%m;
    }
    cout << ans << "\n";
    return 0;
}
