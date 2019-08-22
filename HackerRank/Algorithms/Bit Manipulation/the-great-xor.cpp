#include <bits/stdc++.h>

using namespace std;

// Complete the theGreatXor function below.
long theGreatXor(long x) {
    long t = x;
    int c = 0;
    while(x){
        c++;
        x = x>>1;
    }
    return pow(2, c) - t -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long x;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = theGreatXor(x);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

