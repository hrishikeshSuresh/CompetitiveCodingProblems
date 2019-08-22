#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long binomialCoeff(long n, long k) {
  long C[k + 1];
  memset(C, 0, sizeof(C));

  C[0] = 1; // nC0 is 1

  for (long i = 1; i <= n; i++) {
    // Compute next row of pascal triangle using
    // the previous row
    for (long j = min(i, k); j > 0; j--)
      C[j] = C[j] + C[j - 1];
  }
  return C[k];
}

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
  unordered_map<long, long> left, right;
  long n = arr.size();
  for (long i = 0; i < n; i++) {
    right[arr[i]]++;
  }
  long no_of_triplets = 0;
  if (r == 1) {
    for (auto i : right) {
      no_of_triplets += binomialCoeff(i.second, 3);
    }
    return no_of_triplets;
  }
  for (long i = 0; i < n; i++) {
    long c1 = 0, c2 = 0;
    if (arr[i] % r == 0)
      c1 = left[arr[i] / r];
    c2 = right[arr[i] * r];
    right[arr[i]]--;
    no_of_triplets += (c1 * c2);
    left[arr[i]]++;
  }
  return no_of_triplets;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nr_temp;
  getline(cin, nr_temp);

  vector<string> nr = split(rtrim(nr_temp));

  int n = stoi(nr[0]);

  long r = stol(nr[1]);

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<long> arr(n);

  for (int i = 0; i < n; i++) {
    long arr_item = stol(arr_temp[i]);

    arr[i] = arr_item;
  }

  long ans = countTriplets(arr, r);

  fout << ans << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(s.begin(),
          find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}

