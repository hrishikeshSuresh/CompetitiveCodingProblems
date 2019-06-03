#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    vector<long> all_minimums;
    long n = arr.size();
    // for window size = 1
    all_minimums.push_back(*max_element(arr.begin(), arr.end()));
    // for window size = 2....n
    for (long c_window = 2; c_window <= n; c_window++) {
        deque<long> window;
        vector<long> inter_min;
        for (long i = 0; i < n; i++) {
            if (window.size() == c_window) {
                inter_min.push_back(*min_element(window.begin(), window.end()));
                window.pop_front();
            }
            window.push_back(arr[i]);
        }
        if(window.size() > 0){
            inter_min.push_back(*min_element(window.begin(), window.end()));
            window.pop_front();
        }
        all_minimums.push_back(*max_element(inter_min.begin(), inter_min.end()));
    }
    return all_minimums;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split_string(arr_temp_temp);

  vector<long> arr(n);

  for (int i = 0; i < n; i++) {
    long arr_item = stol(arr_temp[i]);

    arr[i] = arr_item;
  }

  vector<long> res = riddle(arr);

  for (int i = 0; i < res.size(); i++) {
    fout << res[i];

    if (i != res.size() - 1) {
      fout << " ";
    }
  }

  fout << "\n";

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

