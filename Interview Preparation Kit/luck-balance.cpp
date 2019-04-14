#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(int argc, const char *argv[]){
    lli n, k, l, x, win_sum = 0, sum = 0;
    cin >> n >> k;
    vector<lli> imp;
    for(lli i=0; i<n; i++){
        cin >> l >> x;
        if(x == 1)
            imp.push_back(l);
        else
            sum += l;
    }
    lli j = imp.size();
    for(lli i=0; i<(j-k); i++){
        auto m = min_element(imp.begin(), imp.end());
        win_sum += (*m);
        //cout << *m << endl;
        imp.erase(m);
    }
    for(auto i : imp){
        sum += i;
    }
    cout << sum - win_sum << endl;
    return 0;
}
