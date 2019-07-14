#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int npaths(int M, int N){
    if(M <= 0 || N <= 0)
        return 0;
    if(M == 1 || N == 1)
        return 1;
    return npaths(M-1, N) + npaths(M, N-1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T, M, N; 
    // M x N
    cin >> T;
    while(T--){
        cin >> M >> N;
        cout << npaths(M, N) << endl;
    }
    return 0;
}
