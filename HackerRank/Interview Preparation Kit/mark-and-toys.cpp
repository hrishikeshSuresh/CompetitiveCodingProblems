#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main(int argc, const char *argv[]){
    int n, k;
    cin >> n >> k;
    int prices[n];
    int no_of_toys = 0;
    for(int i=0; i<n; i++)
        cin >> prices[i];
    sort(prices, prices+n);
    int diff;
    for(int i=0; i<n; i++){
        diff = k - prices[i];
        if(diff<0)
            break;
        else{
            no_of_toys++;
            k = diff;
        }
    }
    cout << no_of_toys << endl;
    return 0;
}
