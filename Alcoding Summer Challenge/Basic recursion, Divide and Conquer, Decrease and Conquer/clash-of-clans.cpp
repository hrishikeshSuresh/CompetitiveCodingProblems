#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T, R, B;
    cin >> T;
    while(T--){
        cin >> R >> B;
        cout << gcd(R, B) << endl;
    }
    return 0;
}
