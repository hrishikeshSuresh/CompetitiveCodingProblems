#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--){
        int N, K, L;
        cin >> N >> K;
        vector<string> words(N);
        for(int i=0; i<N; i++)
            cin >> words[i];
        vector<int> s_count(N, 0);
        for(int i=0; i<K; i++){
            cin >> L;
            vector<string> sentence(L);
            for(int j=0; j<L; j++){
                cin >> sentence[j];
            }
            for(int k=0; k<N; k++){
                if(find(sentence.begin(), sentence.end(), words[k]) != sentence.end()){
                    s_count[k]++;
                }
            }
        }
        for(int i=0; i<N; i++){
            if(s_count[i] > 0)
                cout << "YES ";
            else
                cout << "NO ";
        }
        cout << "\n";
    }
    return 0;
}
