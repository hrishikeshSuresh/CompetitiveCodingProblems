#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    int red, blue;
    cin >> T;
    while(T--){
        string S;
        red = 0;
        blue = 0;
        cin >> S;
        for(int i=0; i<S.length(); i++){
            if(S[i] == 'R' && S[i+1] == 'e' && S[i+2] == 'd'){
                red++;
                i+=2;
            }
            else if(S[i] == 'B' && S[i+1] == 'l' && S[i+2] == 'u' && S[i+3] == 'e'){
                blue++;
                i+=3;
            }
        }
        if(red > blue)
            cout << "Red\n";
        else if(red == blue)
            cout << "Tie\n";
        else
            cout << "Blue\n";
    }
    return 0;
}

