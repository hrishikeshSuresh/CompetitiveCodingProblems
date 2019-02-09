#include<bits/stdc++.h>

typedef long long int lli;

int main(int argc, const char *argv[]){
    lli N, x, expected, actual=0;
    scanf("%llu", &N);
    expected = 2*(N-1);
    for(lli i=0; i<N; i++){
        scanf("%llu", &x);
        actual += x;
    }
    if(actual == expected)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
