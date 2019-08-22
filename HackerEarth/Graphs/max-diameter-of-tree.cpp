#include<bits/stdc++.h>

typedef long long int lli;

const lli m = 2E3 + 5;
lli diameter = 0, start;
bool visited[m];
std::list<lli> adj_list[m];
std::set<lli> max_nodes;

void maxDiameter(lli index, lli &max_diameter){
    diameter++;
    visited[index] = true;
    if(diameter > max_diameter){
        max_diameter = diameter;
        start = index;
        max_nodes.insert(index);
    }
    for(auto i: adj_list[index]){
        if(!visited[i]){
            maxDiameter(i, max_diameter);
        }
    }
    diameter--;
    return;
}

int main(int argc, const char *argv[]){
    lli N, u, v;
    std::cin >> N;
    for(lli i=1; i<N; i++){
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    lli max_diameter = INT_MIN;
    memset(visited, false, sizeof(visited));
    maxDiameter(1, max_diameter);
    /*for(auto i: max_nodes)
        std::cout << i << "\t";*/
    memset(visited, false, sizeof(visited));
    diameter = 0, max_diameter = 0;
    maxDiameter(start, max_diameter);
    /*for(auto i: max_nodes)
        std::cout << i << "\t";*/
    std::cout << --max_diameter << std::endl;
    for(lli i=1; i<=N; i++){
        if(max_nodes.find(i) == max_nodes.end()){
            std::cout << i << " is not part of diameter" << std::endl;
        }
        else if(max_nodes.find(i) != max_nodes.end()){
            std::cout << i << " is part of diameter" << std::endl;
        }
    }
    for(auto i: max_nodes)
        std::cout << i << "\t";
    return 0;
}
