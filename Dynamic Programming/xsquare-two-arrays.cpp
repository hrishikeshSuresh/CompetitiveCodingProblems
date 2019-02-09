#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]){
    long long int N, Q, arr_choice, lower, upper, sum=0;
    scanf("%llu %llu", &N, &Q);
    long long int *A = (long long int*)malloc(sizeof(long long int)*N);
    for(long long int i=0; i<N; i++){
        scanf("%llu", &A[i]);
    }
    long long int *B = (long long int*)malloc(sizeof(long long int)*N);
    for(long long int i=0; i<N; i++){
        scanf("%llu", &B[i]);
    }
    while(Q--){
        scanf("%llu %llu %llu", &arr_choice, &lower, &upper);
        sum = 0;
        for(long long int j=lower-1; j<upper; j++){
            if(arr_choice == 1){
                sum += A[j];
                arr_choice++;
            }
            else{
                sum += B[j];
                arr_choice--;
            }
        }
        printf("%llu\n", sum);
    }
    return 0;
}
