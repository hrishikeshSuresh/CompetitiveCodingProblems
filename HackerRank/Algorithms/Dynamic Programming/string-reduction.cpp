#include <bits/stdc++.h>

using namespace std;

// Complete the stringReduction function below.
int stringReduction(string s) {
    unordered_map<char, int> umap;
    for(int i=0; i<s.length(); i++)
        umap[s[i]]++;
    int counter = 0;
    cout << umap['a'] << " " << umap['b'] << " " << umap['c'] << "\n";
    for(auto i : umap){
        if(i.second == 0)
            counter++;
    }
    if(counter == 2)
        return s.length();
    int m = umap['a']%2;
    int n = umap['b']%2;a
    int o = umap['c']%2;
    if(m == n && n == o)
        return 2;
    else
        return 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        int result = stringReduction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

