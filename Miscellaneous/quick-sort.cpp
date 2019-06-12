#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
	int t=*a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;
	for(int j=low; j<=high-1; j++){
		if(pivot > arr[j]){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return i+1;
}

void quickSort(int arr[], int low, int high){
	if(low<high){
		int pivot_point = partition(arr, low, high);
		quickSort(arr, low, pivot_point-1);
		quickSort(arr, pivot_point+1, high);
	}
}

int main(int argc, const char *argv[]){
	int arr[] = {2, 33, 12, 5, 1};
	quickSort(arr, 0, 4);
	for(int i=0; i<5; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
