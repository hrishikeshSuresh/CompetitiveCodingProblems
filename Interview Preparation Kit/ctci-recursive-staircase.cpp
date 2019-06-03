#include <bits/stdc++.h>

using namespace std;

// recursive
int recursive_stepPerms(int n) {
  if (n == 0 || n == 1)
    return 1;
  if (n == 2)
    return 2;
  return stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3);
}

// Complete the stepPerms function below.
int stepPerms(int n) {
  int res[n+1];
  res[0] = 1;
  res[1] = 1;
  res[2] = 2;
  for(int i=3; i<=n; i++){
      res[i] = res[i-1] + res[i-2] + res[i-3];
  }
  return res[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int res = stepPerms(n);
        fout << res << "\n";
    }

    fout.close();

    return 0;
}

