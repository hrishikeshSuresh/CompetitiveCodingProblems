#include<bits/stdc++.h>

using namespace std;

int multiply_without_star(int num, int times){
	if(num == 0)	return 0;
	int n = num;
	for(int i=1; i<times; i++){
		num += n;	
	}
	return num;
}

int main(int argc, const char *argv[]){
	int num = -3;
	int times = 8;
	int ans = multiply_without_star(num, times);
	cout << ans << endl;
	return 0;
}
