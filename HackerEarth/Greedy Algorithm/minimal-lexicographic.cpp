#include<bits/stdc++.h>

typedef long long int lli;

#define loop(i, a, b) \
for(lli i=a; i<b; i++)

int main(int argc, const char *argv[]){
    lli T, N, K;
    std::cin >> T;
    while(T--){
        std::cin >> N >> K;
        lli *A;
        lli pos;
        A = (lli*)malloc(sizeof(lli)*N);
        loop(i, 0, N){
            std::cin >> A[i];
        }
        for(lli i=0; i<N && K>0; i++){
            pos = i;
            loop(j, i+1, N){
                if((j-i)>K)
                    break;
                if(A[pos] > A[j])
                    pos = j;
            }
            lli temp;
            for(lli j=pos; j>i; j--){
                // swap arr[j] and arr[j-1]
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                K--;
            }
        }
        loop(h, 0, N){
            std::cout << A[h] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
