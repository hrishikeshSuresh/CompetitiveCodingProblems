#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
typedef long long int lli;

// Complete the gridlandMetro function below.
lli gridlandMetro(lli n, lli m, lli k, vector<vector<lli>> track) {
  vector<vector<lli>> grid(n, vector<lli>(m, 0));
  for (lli i = 0; i < track.size(); i++) {
    lli row = track[i][0] - 1;
    lli col1 = track[i][1] - 1;
    lli col2 = track[i][2] - 1;
    if (col1 < col2) {
      for (lli j = col1; j <= col2; j++)
        grid[row][j] = 1;
    }
    else if(col1 == col2)
        grid[row][col1] = 1;
    else{
        for(lli j=col2; j<=col1; j++)
            grid[row][j] = 1;
    }
  }
  lli result = 0;
  for (lli i = 0; i < n; i++) {
    for (lli j = 0; j < m; j++) {
      cout << grid[i][j] << " ";
      if (grid[i][j] == 0)
        result++;
    }
    cout << "\n";
  }
  return result;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nmk_temp;
  getline(cin, nmk_temp);

  vector<string> nmk = split_string(nmk_temp);

  lli n = stoi(nmk[0]);

  lli m = stoi(nmk[1]);

  lli k = stoi(nmk[2]);

  vector<vector<lli>> track(k);
  for (lli i = 0; i < k; i++) {
    track[i].resize(3);

    for (lli j = 0; j < 3; j++) {
      cin >> track[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  lli result = gridlandMetro(n, m, k, track);

  fout << result << "\n";

  fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}

