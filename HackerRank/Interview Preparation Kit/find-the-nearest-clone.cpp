#include <bits/stdc++.h>

using namespace std;

int findClone(list<int> *adj_list, int start, int nodes, vector<int> colors) {
  vector<int> distances(nodes, -1);
  vector<bool> visited(nodes, false);
  list<int>::iterator itr;
  queue<int> q;
  q.push(start);
  distances[start] = 0;
  visited[start] = true;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (itr = adj_list[curr].begin(); itr != adj_list[curr].end(); ++itr) {
      // cout << *itr << endl;
      if (!visited[*itr]) {
        visited[*itr] = true;
        q.push(*itr);
        distances[*itr] = distances[curr] + 1;
      }
    }
  }
  int target = colors[start];
  vector<pair<int, int>> d(nodes);
  for (int i = 0; i < nodes; i++) {
    d[i].first = distances[i];
    d[i].second = colors[i];
  }
  sort(d.begin(), d.end());
  for (int i = 1; i < nodes; i++) {
    if (d[i].first > 0 && target == d[i].second)
      return d[i].first;
  }  
  return -1;
}

int main(int argc, const char *argv[]) {
  int nodes, edges, from, to, color;
  cin >> nodes >> edges;
  list<int> *adj_list;
  adj_list = new list<int>[nodes];
  for (int i = 0; i < edges; i++) {
    cin >> from >> to;
    from--, to--;
    adj_list[from].push_back(to);
    adj_list[to].push_back(from);
  }
  vector<int> colors;
  for (int i = 0; i < nodes; i++) {
    cin >> color;
    colors.push_back(color);
  }
  int start;
  cin >> start;
  start--;
  int distance_to_clone = findClone(adj_list, start, nodes, colors);
  cout << distance_to_clone << endl;
  return 0;
}
