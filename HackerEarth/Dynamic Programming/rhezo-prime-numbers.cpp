#include<bits/stdc++.h>

using namespace std;

int isPrime(long long int N){
    int isPrimeNumber = 1;
    if(N == 1){
        return 0;
    }
    else{
        for(long long int i=2; i<=N/2; i++){
            if(N%i==0){
                isPrimeNumber = 0;
                return isPrimeNumber;
            }
        }
    }
    return 1;
}

int main(int argc, const char *argv[]){
    long long int N;
    bool prime = false;
    scanf("%llu", &N);
    long long int prime_sum = 0;
    if(isPrime(N) == 1){
        prime = true;
        //printf("It is a prime number\n");
    }
    long long int *arr = (long long int*)malloc(sizeof(long long int)*N);
    long long int *cache = (long long int*)malloc(sizeof(long long int)*N);
    for(long long int i=0; i<N; i++){
        scanf("%llu", &arr[i]);
        if(prime)
            prime_sum += arr[i];
        if(i==0)
            cache[0] = arr[0];
        else
            cache[i] = cache[i-1] + arr[i];
    }
    if(prime){
        printf("%llu", cache[N-1]);
        return 0;
    }
    else{
        printf("%llu", cache[N-2]);
        return 0;
    }
    return 0;
}
