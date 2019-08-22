#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>> grid, int row, int col,
            vector<vector<bool>> visited) {
    int N = grid.size();
    return (row >= 0) && (row < N) && (col >= 0) && (col < N) &&
         (!visited[row][col] && grid[row][col]);
}

int dfs(vector<vector<int>> grid, int row, int col,
        vector<vector<bool>> &visited) {
    int no_of_nodes = 1;
    static int nrow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int ncol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    visited[row][col] = true;
    for (int k = 0; k < 8; k++) {
        if (isSafe(grid, row + nrow[k], col + ncol[k], visited)) {
            no_of_nodes += dfs(grid, row + nrow[k], col + ncol[k], visited);
        }
    }
    return no_of_nodes;
}

// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
  vector<int> no_of_nodes_in_each_component;
  int n = grid.size();
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j] && grid[i][j]) {
        no_of_nodes_in_each_component.push_back(
            dfs(grid, i, j, visited));
      }
    }
  }
  cout << "Number of regions = " << no_of_nodes_in_each_component.size()
       << endl;
  if(no_of_nodes_in_each_component.size() == 0) return 0;
  int max_nodes = *max_element(no_of_nodes_in_each_component.begin(),
                               no_of_nodes_in_each_component.end());
  cout << "Max. number of nodes in a region " << max_nodes << endl;
  return max_nodes;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int m;
  cin >> m;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<vector<int>> grid(n);
  for (int i = 0; i < n; i++) {
    grid[i].resize(m);

    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int res = maxRegion(grid);

  fout << res << "\n";

  fout.close();

  return 0;
}

