#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T, N, x;
    cin >> T;
    while(T--){
        cin >> N;
        int red_sum = 0, blue_sum = 0;
        for(int i=0; i<N; i++){
            cin >> x;
            red_sum += x;
        }
        for(int i=0; i<N; i++){
            cin >> x;
            blue_sum += x;
        }
        if(red_sum > blue_sum)
            cout << "Red\n";
        else if(red_sum == blue_sum)
            cout << "Tie\n";
        else
            cout << "Blue\n";
    }
    return 0;
}
