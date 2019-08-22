#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]){
	int M, N;
	cin >> M >> N;
	int L = M*N;
	vector<int> arr(L, 0);
	for(int i=0; i<L; i++){
		cin >> arr[i];
	}
	int k;
	// find minimum row value
	vector<int> minRowEle(M, 0);
	k = 0;
	for(int i=0; i<L; i+=N){
		if(i+N-1>L)
			minRowEle[k] = *min_element(arr.begin()+i, arr.end());
		else
			minRowEle[k] = *min_element(arr.begin()+i, arr.begin()+i+N);
		//cout << minRowEle[k] << "\n";
		k++;
	}
	// find minimum column value
	vector<int> minColEle(N, 0);
	k = 0;
	for(int i=0; i<N; i++){
		int minEle = arr[i];
		for(int j=i+N; j<L; j+=N){
			if(minEle > arr[j])
				minEle = arr[j];
		}
		minColEle[k] = minEle;
		//cout << minColEle[k] << "\n";
		k++;
	}

	// printing sums
	int rowSum = 0;
	for(int i=0; i<M; i++)
		rowSum += minRowEle[i];
	int colSum = 0;	
	for(int i=0; i<N; i++)
		colSum += minColEle[i];
	cout << rowSum << "\n" << colSum << "\n";
	return 0;
}
