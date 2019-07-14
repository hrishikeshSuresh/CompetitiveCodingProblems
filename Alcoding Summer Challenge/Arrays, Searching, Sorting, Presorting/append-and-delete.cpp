#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k){
    int common_length = 0;
    int n = min(s.length(), t.length());
    int s_len = s.length();
    int t_len = t.length();
    for(int i=0; i<n; i++){
        if(s[i] == t[i]) common_length++;
        else break;
    }
    if(s_len + t_len - k < 0) return "Yes";
    if(s_len + t_len - 2*common_length > k ) return "No";
    if((s_len + t_len - 2*common_length)%2 == k%2) return "Yes";
    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

