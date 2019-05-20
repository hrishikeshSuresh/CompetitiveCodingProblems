#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(int argc, const char *argv[]){
    int t;
    cin >> t;
    string S;
    lli f;
    while(t--){
        map<vector<lli>, lli> sub_strings;
        cin >> S;
        lli N = S.length();
        for(int i=0; i<N; i++){
            vector<lli> fre(26, 0);
            for(int j=i; j<N; j++){
                fre[S[j] - 'a']++;
                sub_strings[fre]++;
            }
        }
        lli result = 0;
        for(auto i: sub_strings){
            result += (i.second*(i.second-1))/2;
        }
        cout << result << endl;
    }
    return 0;
}
