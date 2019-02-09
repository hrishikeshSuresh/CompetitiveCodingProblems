#include<bits/stdc++.h>

typedef long long int lli;

const lli m = 2E3 + 5;
lli diameter;
lli max_diameter;
lli start;
bool visited[m];
lli path[m];
std::set<lli> nodes;
std::list<lli> adj_list[m];

void findDiameter(lli index){
    diameter++;
    visited[index] = true;
    if(max_diameter < diameter){
        max_diameter = diameter;
        start = index;
    }
    for(auto i : adj_list[index]){
        if(!visited[i])
            findDiameter(i);
    }
    diameter--;
    return;
}

void allPathsTraversed(lli index){
    diameter++;
    visited[index] = true;
    path[diameter] = index;
    if(diameter == max_diameter){
        for(int i=1; i<=diameter; i++)
            nodes.insert(path[i]);
    }
    for(auto i: adj_list[index])
        if(!visited[i])
            allPathsTraversed(i);
    diameter--;
    return;
}

int main(int argc, const char *argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::cin >> T;
    while(T--){
        lli N, S, u, v;
        std::cin >> N >> S;
        for(lli i=1; i<N; i++){
            std::cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        //std::cout << "Inputs Read\n";
        diameter = max_diameter = 0;
        memset(visited, false, sizeof(visited));
        findDiameter(1);
        diameter = max_diameter = 0;
        memset(visited, false, sizeof(visited));
        findDiameter(start);
        //std::cout << "Found max_diameter\n";
        //std::cout << max_diameter << std::endl;
        for(lli i=1; i<=N; i++){
            diameter = 0;
            memset(visited, false, sizeof(visited));
            allPathsTraversed(i);
        }
        for(auto i: nodes){
            std::cout << i << "\t";
        }
        std::cout << "\n";
        bool not_found = false;
        for(lli i=1; i<=N; i++){
            if(nodes.find(i) != nodes.end()){
                not_found = true;
                break;
            }
        }
        lli ans = 0;
        if(!not_found){
            ans = S/(N-1);
            if(S%(N-1) != 0)
                ans++;
        }
        std::cout << ans << std::endl;
        nodes.clear();
        for(int i=1; i<=N; i++)
            adj_list[i].clear();
    }
    return 0;
}
