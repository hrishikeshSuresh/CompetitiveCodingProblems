#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]){
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N, P, x;
        int training_time = 0;
        cin >> N >> P;
        training_time = 0;
        vector<int> S(N), chosen(P);
        for(int j=0; j<N; j++){
            cin >> S[j];
        }
        if(P == N){
            int max_val = *max_element(S.begin(), S.end());
            chosen = S;
            for(int j=0; j<N; j++){
                training_time += (max_val - S[j]);
            }
        }
        else{
            sort(S.begin(), S.end());
            int min_val = INT_MAX;
            int curr_val = 0;
            for(int j=0; j<N-P+1; j++){
                curr_val = 0;
                vector<int> tmp(P);
                for(int k=j; k<j+P-1; k++){
                    //cout << S[k+1] << " - " << S[k] << endl;
                    curr_val += (S[k+1] - S[k]);
                    tmp[k-j] = S[k];
                    //cout << "Curr val " << curr_val << endl;
                }
                tmp[P-1] = S[j+P-1];
                min_val = min(min_val, curr_val);
                if(min_val == curr_val)
                    chosen = tmp;
                //for(auto i: chosen)
                    //cout << i << endl;
                //cout << "Diffferences " << min_val << " " << curr_val << endl;
            }
            //for(auto i: chosen)
            //    cout << i << endl;
            int max_val = *max_element(chosen.begin(), chosen.end());
            //cout << "Maximum value found = " << max_val << endl;
            for(int j=0; j<P; j++){
                training_time += (max_val - chosen[j]);
            }
        }
        cout << "Case #" << i+1 << ": " << training_time << endl;
    }
    return 0;
}
