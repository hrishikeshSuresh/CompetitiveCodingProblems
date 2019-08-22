#include<bits/stdc++.h>

using namespace std;

int root(int *arr, int i){
	while(arr[i]!=i)
		i = arr[i];
	return i;
}

int *union(int *arr, int a, int b){
	int root_a = root(arr, a);
	int root_b = root(arr, b);
	// set parent of root_a as root_p
	arr[root_a] = root_b;
	return arr;
}

bool find(int *arr, int a, int b){
	if(root(arr, a) == root(arr, b))
		return true;
	return false;
}

int main(int argc, const char *argv[]){

	return 0;
}
