#include <bits/stdc++.h>

using namespace std;

// Complete the powerSum function below.
int powerSum(int X, int N, int S) {
    if(X == 0) return 1;
    if(X < 0) return 0;
    int counter = 0;
    for(int i=S+1; pow(i, N) <= X; ++i){
        int j = X - pow(i, N);
        counter += powerSum(j, N, i);
    }
    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N, 0);

    fout << result << "\n";

    fout.close();

    return 0;
}

