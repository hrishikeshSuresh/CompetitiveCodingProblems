#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	if(b == 0)	return a;
	return gcd(b, a%b);
}

int gcd_array(int arr[], int n){
	int result = arr[0];
	for(int i=1; i<n ; i++){
		result = gcd(result, arr[1]);
	}
	return result;
}

int main(int argc, const char *argv[]){
	int arr[] = {2, 3, 9} ;
	sort(arr, arr+n);
	cout << gcd_array(arr, 3) << endl;
}
