#include<bits/stdc++.h>

using namespace std;

int findMaxPoint(int N, vector<int> A, vector<int> B){
	int goalPoints = 20, foulPoints = 10;
	vector<int> pointsTable(N, 0);
	for(int i=0; i<N; i++){
		pointsTable[i] = max(A[i]*goalPoints - B[i]*foulPoints, 0);
	}
	return *max_element(pointsTable.begin(), pointsTable.end());
}

int main(int argc, const char *argv[]){
	int T, N;
	cin >> T;
	while(T--){
		cin >> N;
		vector<int> A(N);
		vector<int> B(N);
		for(int i=0; i<N; i++)
			cin >> A[i];
		for(int i=0; i<N; i++)
			cin >> B[i];
		int maxPoints = findMaxPoint(N, A, B);
		cout << maxPoints << "\n";
	}
	return 0;
}
