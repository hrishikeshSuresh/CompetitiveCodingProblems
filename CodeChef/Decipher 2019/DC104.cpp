#include<bits/stdc++.h>

using namespace std;

int decimal1(char c) {
	if((c>='0') && (c<='9')) {
		//cout << "RETURN decimal val " << c-'0' << "\n";
		return c-'0';
	}
	//cout << "RETURN decimal val " << c-'a'+10 << "\n";
	return c-'a'+10;
}

int main(int argc, const char *argv[]){
	string cipherText, key;
	cin >> cipherText >> key;
	vector<int> keyInBit(128, 0);
	int tmp, j=0, tmp1;
	for(int i=0; i<16; i++){
		tmp = key[i];
		j = i*8 + 7;
		for(int k=0; k<8; k++, j--){
			keyInBit[j] = tmp%2;
			tmp/=2;
		}
	}
	int start = 0;
	u_int i = 0;
	while(i<cipherText.length()){
		int index_tmp = start;
		for(int k=0; k<16; k++){
			tmp = 0;
			for(int p=0; p<2; p++){
				tmp = tmp*16 + decimal1(cipherText[i]);
				i+=1;
				//cout << "INSIDE TMP : " << tmp << "\n";
			}
			tmp1 = 0;
			for(int p=0; p<8; p++){
				tmp1 = tmp1*2 + keyInBit[index_tmp];
				index_tmp = (index_tmp+1)%128;
			}
			//cout << tmp1 << " " << tmp << "\n";
			printf("%c", tmp1^tmp);
		}
		tmp1 = 0;
		for(int p=0; p<6; p++){
			tmp1 = tmp1*2 + keyInBit[start];
			start = (start+1)%128;
		}
		start -=6;
		if(start<128)
			start += 128;
		start = (start+tmp1)%128;
	}
	return 0;
}
