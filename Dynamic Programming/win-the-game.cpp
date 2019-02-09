#include<bits/stdc++.h>

double dp[10001];

double computeProbability(double R, double G){
    if (dp[(int)G]!=0)
        return dp[(int)G];
    if (G>2)
        dp[(int)G] = R/(R+G)+(G/(R+G))*((G-1)/(R+G-1))*computeProbability(R, G-2);
    else
        dp[(int)G] = R/(R+G);
    return dp[(int)G];
}

int main(int argc, const char* argv[]){
    double t;
    std::cin >> t;
    while (t--){
        memset(dp, 0, sizeof(double)*10000);
        double G, R;
        std::cin >> R >> G;
        if (R==0)
            printf ("1.000000\n");
        else
            printf ("%0.6lf\n", computeProbability(R, G));
    }
}
