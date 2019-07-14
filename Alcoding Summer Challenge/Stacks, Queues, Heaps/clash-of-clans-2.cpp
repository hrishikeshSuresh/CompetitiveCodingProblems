#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, N, K, x;
    cin >> T;
    while(T--){
        cin >> N >> K;
        vector<int> arr;
        for(int i=0; i<N; i++){
            cin >> x;
            arr.push_back(x);
        }
        int red_score = 0, blue_score = 0;
        for(int i=0; i<K; i++){
            red_score+=arr[i];
            blue_score+=arr[N-1-i];
        }
        if(red_score > blue_score)
            cout << "Red\n";
        else if(blue_score > red_score)
            cout << "Blue\n";
        else
            cout << "Perfect\n";
    }
    return 0;
}
