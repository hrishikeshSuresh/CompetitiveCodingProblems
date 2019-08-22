#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]){
    int M, N;
    cin >> M >> N;
    string x;
    unordered_map<string, int> magazine, note;
    for(int i=0; i<M; i++){
        cin >> x;
        magazine[x]++;
    }
    for(int i=0; i<N; i++){
        cin >> x;
        note[x]++;
    }
    for(auto i: note){
        if(find(magazine.begin(), magazine.end(), i) == magazine.end()){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
