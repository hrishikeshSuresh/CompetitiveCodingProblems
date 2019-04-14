#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(int argc, const char *argv[]){
    int t;
    cin >> t;
    lli n;
    while(t--){
        cin >> n;
        lli A[n];
        for(lli i=0; i<n; i++)
            cin >> A[i];
        lli bribes = 0, bribes_per_person = 0;
        bool chaotic = false;
        for(lli i=0; i<n; i++){
            bribes_per_person = 0;
            for(lli j=i; j<n; j++){
                if(A[i] > A[j]){
                    bribes_per_person++;
                }
                if(bribes_per_person > 2){
                    chaotic = true;
                    break;
                }
            }
            //cout << bribes_per_person << endl;
            bribes += bribes_per_person;
            if(chaotic) break;
        }
        if(chaotic) cout << "Too chaotic\n";
        else        cout << bribes << endl;
    }
    return 0;
}
