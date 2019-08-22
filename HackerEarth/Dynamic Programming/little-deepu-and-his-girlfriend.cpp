#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<unordered_set>

typedef long long int lli;

#define loop(i, a, b) \
for(lli i=a; i<b; i++)

//Calculate Mex
lli calculateMex(std::unordered_set<lli> Set){
    lli mex = 0;
    while(Set.find(mex)!=Set.end())
        mex++;
    return mex;
}

//Calculate Grundy number
lli calculateGrundyNumber(lli n, lli grundy[], lli pos[]){
    grundy[0] = 0;
    grundy[1] = 1;
    grundy[2] = 2;
    grundy[3] = 3;

    if(grundy[n] != -1)
        return grundy[n];
    std::unordered_set<lli> Set;
    for(lli i=0; i<3; i++)
        Set.insert(calculateGrundyNumber(n-pos[i], grundy, pos));
    grundy[n] = calculateMex(Set);
    return grundy[n];
}

//Sprague-Grundy Theorem
int main(int argc, const char *argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    lli T, M, N;
    lli *S;
    scanf("%llu", &T);
    while(T--){
        scanf("%llu %llu", &M, &N);
        S = (lli*)malloc(sizeof(lli)*N);
        memset(S, 0, sizeof(lli)*N);
        loop(i, 0, N)
            scanf("%llu", &S[i]);
        // Little Deepu is the first player
        // Kate is the second player
        lli *grundy;
        grundy = (lli*)malloc(sizeof(lli)*(N+1));
        memset(grundy, 0, sizeof(lli)*(N+1));
        lli choice = calculateGrundyNumber(N, grundy, S);
        if(choice == 2 || choice ==0)
            printf("Kate\n");
        else
            printf("Little Deepu\n");
    }
    return 0;
}
