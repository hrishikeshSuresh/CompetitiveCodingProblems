#include <bits/stdc++.h>

template <typename T> void printArray(std::vector<T> const &v) {
  for (auto i : v)
    std::cout << i << " ";
  std::cout << "\n";
}

template <typename T>
std::vector<T> slice(std::vector<T> const &v, int m, int n) {
  auto first = v.cbegin() + m;
  auto end = v.cbegin() + n + 1;
  std::vector<T> vec(first, end);
  return vec;
}

float countingSortAndMedian(std::vector<int> arr, int d, int p, int flag) {
  int max_value = *std::max_element(arr.begin(), arr.end());
  int min_value = *std::min_element(arr.begin(), arr.end());
  int n = max_value - min_value + 1;
  float *fre = (float *)malloc(sizeof(float) * n);
  memset(fre, 0, sizeof(float) * n);
  for (u_int i = 0; i < arr.size(); i++)
    fre[arr[i] - min_value]++;
  std::vector<float> sorted;
  for (int i = 0; i < n; i++) {
    while (fre[i] > 0) {
      sorted.push_back(i + min_value);
      fre[i]--;
    }
  }
  return (flag) ? (sorted[p] + sorted[p - 1]) / 2 : sorted[p];
}

// Complete the activityNotifications function below.
int activityNotifications(std::vector<int> expenditure, int d) {
  int notifications = 0;
  int p = d/2;
  int flag = (d % 2 == 0);
  for (u_int i = 0; i < expenditure.size() - d; i++) {
    std::vector<int> curr = slice(expenditure, i, i + d - 1);
    float median = countingSortAndMedian(curr, d, p, flag);
    if (expenditure[d + i] >= 2 * median) {
      notifications++;
    }
  }
  return notifications;
}

using namespace std;
std::vector<string> split_string(string);

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nd_temp;
  getline(cin, nd_temp);

  vector<string> nd = split_string(nd_temp);

  int n = stoi(nd[0]);

  int d = stoi(nd[1]);

  string expenditure_temp_temp;
  getline(cin, expenditure_temp_temp);

  vector<string> expenditure_temp = split_string(expenditure_temp_temp);

  vector<int> expenditure(n);

  for (int i = 0; i < n; i++) {
    int expenditure_item = stoi(expenditure_temp[i]);

    expenditure[i] = expenditure_item;
  }

  int result = activityNotifications(expenditure, d);

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

