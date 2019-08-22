#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int squareSubmatrix(int **arr, int n, int m){
    int cache[n][m];
    //memset(cache, 0, n*sizeof(bool*));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cache[i][j] = 0;
    //memset(cache[i], 0, m+*sizeof(bool));
    int max_size = 1;
    cout << cache[n-1][m-2] << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 || j==0)
                cache[i][j] = arr[i][j]?1:0;
            else if(arr[i][j]){
                cache[i][j] = min(min(cache[i-1][j], cache[i][j-1]), cache[i-1][j-1]) + 1;
            }
            cout << cache[i][j] << endl;
            if(cache[i][j] > max_size)
                max_size = cache[i][j];
        }
    }
    cout << max_size << endl;
    return max_size;
}

int main(int argc, char const *argv[]){
    int n, m, x;
    scanf("%d %d", &n, &m);
    //int arr[n][m];
    int **arr;
    //printf("SUCCESS\n");
    arr = (int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++){
        arr[i] = (int*)malloc(sizeof(int)*m);
        for(int j=0; j<m; j++){
            scanf("%d", &x);
            arr[i][j] = x;
        }
    }
    cout << "OUTPUTS" << endl;
    int k = squareSubmatrix(arr, n, m);
    //printf("%d\n", k);
    return 0;
}
