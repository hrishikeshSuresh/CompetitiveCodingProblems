#include<bits/stdc++.h>

using namespace std;

template<class Num> Num mod(Num x, Num divisor){
	Num m = x%divisor;
	return m + (m<0? divisor : 0);
}

int multiplicativeInverse(int a, int m){
	a = mod(a, m);
	for(int x=1; x<m; x++)
		if(mod(a*x, m) == 1) return x;
	return a;
}

int main(int argc, const char *argv[]){
	int k1, k2;
	string plainText;
	cin >> plainText;
	cin >> k1 >> k2;
	string cipherText = "";
	for(u_int i=0; i<plainText.length(); i++){
		int C = plainText[i] - 'A';
		int P = mod((C-k1)*multiplicativeInverse(k2, 26), 26);
		cipherText += P+'A';
	}
	cout << cipherText << "\n";
	return 0;
}
