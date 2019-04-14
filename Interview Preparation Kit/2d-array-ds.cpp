#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]){
    int A[6][6];
    int sum[16];
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            cin >> A[i][j];
        }
    }
    int k = 0;
    for(int i=1; i<5; i++){
        for(int j=1; j<5; j++){
            sum[k] = A[i][j] + A[i-1][j] + A[i+1][j] + A[i-1][j-1] + A[i-1][j+1] + A[i+1][j+1] + A[i+1][j-1];
            k++;
        }
    }
    /*for(auto i : sum){
        cout << i;
    }*/
    cout << *max_element(sum, sum+16);
    return 0;
}
