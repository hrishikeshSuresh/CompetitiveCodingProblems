#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
vector<pair<int, int>> loc = {make_pair(0, 1), make_pair(0, -1),
                              make_pair(1, 0), make_pair(-1, 0)};

bool isSafe(vector<string> grid, vector<vector<bool>> visited, int currX, int currY){
    return (currX>=0) && (currX<grid.size()) && (currY>=0) && (currY<grid.size()) && (!visited[currX][currY] && grid[currX][currY] != 'X');
}

int bfs(vector<string> grid, vector<vector<bool>> visited,int startX, int startY, int goalX, int goalY){
  queue<pair<int, int>> q; 
  queue<int> distance;
  distance.push(0);
  visited[startX][startY] = 0;
  q.push(make_pair(startX, startY));
  int currX, currY;
  while(!q.empty()){
      currX = q.front().first;
      currY = q.front().second;
      if(currX == goalX && currY == goalY)
        return distance.front(); 
      for (int k = 0; k < 4; k++) {
        int newX = currX + loc[k].first;
        int newY = currY + loc[k].second;
        while(isSafe(grid, visited, newX, newY)){
          visited[newX][newY] = true;
          distance.push(distance.front()+1);
          q.push(make_pair(newX, newY));
          newX += loc[k].first;
          newY += loc[k].second;
        }
      }
      q.pop();
      distance.pop();
  }
  return -1;
}

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    if(grid[goalX][goalY] == 'X')
        return -1; 
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    return bfs(grid, visited, startX, startY, goalX, goalY);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);
	cout << result << "\n";
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

