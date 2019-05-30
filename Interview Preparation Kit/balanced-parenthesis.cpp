#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    if(s.length()%2 != 0){
        return "NO";
    }
    stack<char> p;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            p.push(s[i]);
        else if(s[i] == ')'){ 
            if(p.top() != '(' || p.empty())
                return "NO";
            else
                p.pop();
        }
        else if(s[i] == ']'){
            if(p.top() != '[' || p.empty())
                return "NO";
            else
                p.pop();
        }
        else if(s[i] == '}'){
            if(p.top() != '{' || p.empty())
                return "NO";
            else
                p.pop();
        }
    }
    return "YES";
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

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

