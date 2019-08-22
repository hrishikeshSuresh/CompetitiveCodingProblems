#include<bits/stdc++.h>

typedef long long int lli;
const lli m = 2E3 + 5;

#define loop(i, a, b) \
for(lli i=a; i<b; i++)

lli n_cycles = 0;

void DFS(int graph[][m], bool visited[], lli N, lli length, lli vertex, lli start){
    visited[vertex] = true;
    if(length == 0){
        visited[vertex] = false;
        if(graph[vertex][start]){
            n_cycles++;
            return;
        }
        else{
            return;
        }
    }
    for(lli i=1; i<N; i++){
        if(!visited[i] && graph[vertex][i])
            DFS(graph, visited, N, length-1, i, start);
    }
    visited[vertex] = false;
    return;
}

void countCycle(int graph[][m], bool visited[], lli N, lli length){
    loop(i, 0, N){
        DFS(graph, visited, N, length-1, i, i);
        visited[i] = true;
    }
    return;
}

int main(int argc, const char *argv[]){
    lli N;
    std::cin >> N;
    int graph[m][m];
    loop(i, 1, N+1){
        loop(j, 1, N+1){
            std::cin >> graph[i][j];
        }
    }
    bool visited[m];
    memset(visited, false, sizeof(visited));
    countCycle(graph, visited, N+1, 4);
    std::cout << n_cycles/2 << std::endl;
    return 0;
}
