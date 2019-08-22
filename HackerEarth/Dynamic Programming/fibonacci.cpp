#include<bits/stdc++.h>
#include<iostream>

using namespace std;

//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……

int fibonacciRecursive(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibonacciRecursive(n-1)+fibonacciRecursive(n-2);
}

int fibonacciDynamic(int n){
    if(n<2) return n;
    int *cache = (int*)malloc(sizeof(int)*(n+1));
    cache[0] = 0;
    cache[1] = 1;
    for(int i = 2; i<=n; i++){
        cache[i] = cache[i-1] + cache[i-2];
    }
    return cache[n];
}

int fibonacciOptimized(int n){
    if(n<2) return n;
    int n1 = 0, n2 = 1;
    int n0;
    for(int i = 2; i<=n; i++){
        n0 = n1 + n2;
        n2 = n1;
        n1 = n0;
    }
    return n1 + n2;
}

int main(int argc, char const *argv[]){
    int n;
    scanf("%d", &n);
    int ans1 = fibonacciRecursive(n);
    printf("Recursive Method\n%d\n", ans1);
    int ans2 = fibonacciDynamic(n);
    printf("Dynamic Method\n%d\n", ans2);
    int ans3 = fibonacciOptimized(n);
    printf("Optimized Dynamic Programming\n%d\n", ans3);
    return 0;
}
