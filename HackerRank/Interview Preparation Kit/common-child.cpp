#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2, int m, int n) {
    vector<vector<int>> table(m+1, vector<int>(n+1, 0));
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0)
                table[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                table[i][j] = 1 + table[i-1][j-1];
            else
                table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
    }
    return table[m][n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2, s1.length(), s2.length());

    fout << result << "\n";

    fout.close();

    return 0;
}

