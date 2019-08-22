#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void Depth_First_Search(vector<vector<int>> adj_list, bool *visited, int n,
                        int i, long &no_of_nodes) {
  visited[i] = true;
  no_of_nodes++;
  vector<int>::iterator itr;
  for (itr = adj_list[i].begin(); itr != adj_list[i].end(); ++itr) {
    if (!visited[*itr])
      Depth_First_Search(adj_list, visited, n, *itr, no_of_nodes);
  }
}

long Depth_First_Search_Util(vector<vector<int>> adj_list, int n, int c_road,
                             int c_lib) {
  bool *visited = (bool *)malloc(sizeof(bool) * n);
  for (int i = 0; i < n; i++)
    visited[i] = false;
  long no_of_connected_components = 0;
  long no_of_nodes = 0;
  long total_number_of_edges = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      Depth_First_Search(adj_list, visited, n, i, no_of_nodes);
      total_number_of_edges += (no_of_nodes - 1);
      no_of_nodes = 0;
      no_of_connected_components++;
    }
  }
  long cost;
  long road = (long)c_road;
  long lib = (long)c_lib;
   cost =
      min(no_of_connected_components * lib + (total_number_of_edges) * road,
          n * lib);
  return cost;
}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road,
                       vector<vector<int>> cities) {
  if(c_road > c_lib){
    return (long)(n * c_lib);
  }
  // n -  number of cities/vertices
  // create adjacency list
  // pointer to an array containing adjacency list
  vector<vector<int>> adj_list(n);
  for (unsigned int i = 0; i < cities.size(); i++) {
    adj_list[cities[i][0] - 1].push_back(cities[i][1] - 1);
    adj_list[cities[i][1] - 1].push_back(cities[i][0] - 1);
  }
  long no_of_connected_components =
      Depth_First_Search_Util(adj_list, n, c_road, c_lib);
  return no_of_connected_components;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string nmC_libC_road_temp;
    getline(cin, nmC_libC_road_temp);

    vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

    int n = stoi(nmC_libC_road[0]);

    int m = stoi(nmC_libC_road[1]);

    int c_lib = stoi(nmC_libC_road[2]);

    int c_road = stoi(nmC_libC_road[3]);

    vector<vector<int>> cities(m);
    for (int i = 0; i < m; i++) {
      cities[i].resize(2);

      for (int j = 0; j < 2; j++) {
        cin >> cities[i][j];
      }

      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = roadsAndLibraries(n, c_lib, c_road, cities);

    fout << result << "\n";
  }

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

