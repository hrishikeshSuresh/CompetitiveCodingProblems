#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj_list;
    public:
        Graph(int n) {
            this->V = n;
            adj_list = new list<int>[V];
        }
    
        void add_edge(int u, int v) {
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
            
        }
    
        vector<int> shortest_reach(int start) {
        	// bfs implementation
            vector<int> distances(V, -1);
            bool *visited = (bool*)malloc(sizeof(bool)*V);
            for(int i=0; i<V; i++){
                visited[i] = false;
            }
            queue<int> q;
            q.push(start);
            distances[start] = 0;
            visited[start] = true;
            list<int>::iterator itr;
            while (!q.empty()){
              int curr = q.front();
              q.pop();
              for(itr = adj_list[curr].begin(); itr!=adj_list[curr].end(); ++itr){
                if(!visited[*itr]){
                    q.push(*itr);
                    visited[*itr] = true;
                    distances[*itr] = distances[curr] + 6;
                } 
              }
            }
            return distances;
        }
    };

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

