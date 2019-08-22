#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool comp(pair<int, int> &l, pair<int, int> &r){
    return l.first>r.first;
}

// Complete the lilysHomework function below.
int lilysHomework(vector<int> arr) {
  int n = arr.size();
  vector<pair<int, int>> A(n);
  for (int i = 0; i <n; i++){
      A[i].first = arr[i];
      A[i].second = i;
  }
  sort(A.begin(), A.end());
  int no_of_swaps = 0;
  vector<int> visited(n, 0);
  for(int i=0; i<n; i++){
      if(visited[i] || A[i].second == i)
        continue;
      int cycle_size = 0;
      int j = i;
      while(!visited[j]){
          visited[j] = 1;
          cycle_size++;
          j = A[j].second;
      }
      if(cycle_size > 0)
        no_of_swaps += (cycle_size - 1);
  }
  sort(A.begin(), A.end(), comp);
  int no_of_swaps_reverse = 0;
  vector<int> visited_1(n, 0);
  for (int i = 0; i < n; i++) {
    if (visited_1[i] || A[i].second == i)
      continue;
    int cycle_size = 0;
    int j = i;
    while (!visited_1[j]) {
      visited_1[j] = 1;
      cycle_size++;
      j = A[j].second;
    }
    if (cycle_size > 0)
      no_of_swaps_reverse += (cycle_size - 1);
  }
  return max(no_of_swaps, no_of_swaps_reverse);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

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

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

