#include<bits/stdc++.h>

using namespace std;

int numberOfSuperBalancedBrackets(string S){
    int ans = 0;
    int x = 0;
	int y = S.length() - 1;
	while(y - x != -1){
		if(x == y){
			break;
		}
		if(S[x] == '('){
			if(S[y] == ')'){
				ans++;
				x++, y--;
			}
			else{
				y--;
			}
		}
		else{
			x++;
		}
	}
	return 2*ans;
}

int main(int argc, const char *argv[]){
    int T;
    cin >> T;
    while(T--){
        string S;
        cin >> S;
        int output = numberOfSuperBalancedBrackets(S);
        cout << output << "\n";
    }
    return 0;
}
