#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<string>> generateStringPermutations(vector<string> arr){
        int n = arr.size();
        vector<vector<string>> permutations;
        for(int i=0; i<n; i++){
                vector<string> inter;
                for(int j=0; j<n; j++){
                        inter.push_back(arr[(i+j)%n]);
                }
                permutations.push_back(inter);
        }
        /*
        cout << "All permutations : \n";
        for(u_int i=0; i<permutations.size(); i++){
                for(u_int j=0; j<permutations[i].size(); j++){
                        cout << permutations[i][j] << " ";
                }
                cout << "\n";
        }
        */
        return permutations;
}

int main() {
    int N;
    u_int M;
    cin >> N >> M;
    string s;
    vector<string> P(M);
    cin >> s;
    for(u_int i=0; i<M; i++)
        cin >> P[i];
    int no_of_century_permutations = 0;
    vector<vector<string>> permutations = generateStringPermutations(P);
    for(u_int i=0; i<permutations.size(); i++){
        vector<u_int> indices;
        //cout << i << " ";
        int index = 0;
        for(u_int j=0; j<permutations[i].size(); j++){
                u_int found = s.find(permutations[i][j], index);
                if(found != string::npos){
                        //cout << permutations[i][j] << " " << found << "; ";
                        if(indices.size() == 0) indices.push_back(found);
                        else if(indices[indices.size()-1] < found) indices.push_back(found);
                        else break;
                }
                else break;
                index = found;
        }
        //cout << "\n";
        if(indices.size() == M)
            no_of_century_permutations++;
    }
    cout << no_of_century_permutations << "\n";
    return 0;
}
