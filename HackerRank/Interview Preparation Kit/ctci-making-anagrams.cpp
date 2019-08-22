#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    unordered_map<char, int> fre;
    for(auto i: a){
        ++fre[i];
    }
    for(auto i: b) {
        --fre[i];
    }
    int numbers_to_be_removed = 0;
    for(auto i: fre){
        numbers_to_be_removed += abs(i.second);
    }
    return numbers_to_be_removed;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

