#include<bits/stdc++.h>
// Merge-sort

using namespace std;

void merge(int arr[], int l, int m, int r){
	int n1, n2;
	n1 = m + 1 - l;
	n2 = r - m;
	int L[n1], R[n2];
	int i, j=0, k=l;
	for(i=0; i<n1; i++)
		L[i] = arr[l+i];
	for(j=0; j<n2; j++)
		R[j] = arr[m+1+j];
	i=0;
	j=0;
	while(i<n1 && j<n2){
		if(L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while(i<n1)
		arr[k++] = L[i++];
	while(j<n2)
		arr[k++] = R[j++];
}

void mergesort(int arr[], int l, int r){
	if(l<r){
		int mid = l+(r-l)/2;
		mergesort(arr, l, mid);
		mergesort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

int main(int argc, const char *argv[]){
	int arr[] = {3, 2, 5, 6, 1};
	for(auto i: arr)
		cout << i << " ";
	cout << endl;
	mergesort(arr, 0, 4);
	for(auto i: arr)
		cout << i << " ";
	cout << endl;
	return 0;
}
