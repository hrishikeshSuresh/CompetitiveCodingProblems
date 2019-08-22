#include <bits/stdc++.h>

using namespace std;

int countSetBits(long n){
    int counter = 0;
    while(n){
        n = n&(n-1);
        counter++;
    }
    return counter;
}

// Complete the counterGame function below.
string counterGame(long n) {
    int m = countSetBits(n-1);
    return (m&1)? "Louise":"Richard";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

