#include <bits/stdc++.h>

using namespace std;

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {
    unordered_map<char, int> all_chars;
    string least_lexicographic_string = "";
    for(int i=0; i<s.length(); i++){
        all_chars[s[i]]++;
    }
    for(auto i: all_chars){
        i.second = i.second/2;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

