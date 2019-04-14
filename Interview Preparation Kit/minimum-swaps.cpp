#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]){
    int n, x;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++){
        cin >> x;
        arr[i].first = x;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    int no_of_swaps = 0;
    for(int i=0; i<n; i++){
        if(arr[i].second == i)
            continue;
        else{
            swap(arr[i].first, arr[arr[i].second].first);
            swap(arr[i].second, arr[arr[i].second].second);
        }
        if(i!=arr[i].second)
            i--;
        no_of_swaps++;
    }
    cout << no_of_swaps << endl;
    return 0;
}
