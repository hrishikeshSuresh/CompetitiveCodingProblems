#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]){
	string cipherText, key;
	cin >> cipherText;
	cin >> key;
	
	int cipherChar, keyChar, count;
	int keyLength = key.length();
	u_int i = 0;
	int j;
	count = 0, i=0, j=0;
	while(i<cipherText.length()){
		cipherChar = 0;
		while(i<cipherText.length() && cipherText[i] != ','){
			cipherChar = cipherChar * 10;
			cipherChar += cipherText[i] - '0';
			i += 1;
		}
		keyChar = key[j];
		j = (j+1)%keyLength;
		keyChar = keyChar ^ count;
		count = (count+1)%256;
		printf("%c", (keyChar^cipherChar));
		i+=1;
	}
	return 0;
}
