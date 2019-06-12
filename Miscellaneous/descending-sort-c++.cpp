#include<bits/stdc++.h>

using namespace std;

bool comp(const int &l, const int &r){
	return (l>r);
}

int main(int argc, const char *argv[]){
	int arr[] = {54, 21, 3, 4, 10, 23};
	sort(arr, arr+6, comp);
	for(auto i : arr)
		cout << i << " ";
	return 0;
}
