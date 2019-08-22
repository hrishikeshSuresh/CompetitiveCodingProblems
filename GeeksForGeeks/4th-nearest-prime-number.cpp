#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n){
	if(n<=1) return false;
	if(n<=3) return true;
	if(n%2==0 || n%3==0) return false;
	for(int i=5; i*i<=n; i=i+6)
		if(n%i == 0 || n%(i+2)== 0) return false;
	return true;
}

int main(int argc, const char *argv[]){
    int N;
    cin >> N;
    bool flag = true;
    int lowerVal = N-1;
    int higherVal = N+1;
    int left = 0, right = 0;
	vector<int> leftPrimeVals, rightPrimeVals;
    while(flag){
        if(left == 4 || lowerVal<=0){
            flag = false;
            continue;
        }
        if(isPrime(lowerVal--)){
            left++;
			leftPrimeVals.push_back(lowerVal+1);
        }
	}
	flag = true;
	while(flag){
		if(right == 4){
            flag = false;
            continue;
        }
        if(isPrime(higherVal++)){
            right++;
			rightPrimeVals.push_back(higherVal-1);
        }
    }
	if(leftPrimeVals.size() == 4 && rightPrimeVals.size() == 4){
		/*
		cout << "Left Prime Values\n";
		for(auto i :leftPrimeVals)
			cout << i << "\n";
		cout << "Right Prime Values\n";
		for(auto i : rightPrimeVals)
			cout << i << "\n";
		cout << lowerVal << " " << higherVal << "\n";
		*/
		int ldist = leftPrimeVals[3] - N;
		int rdist = N - rightPrimeVals[3];
		if(rdist < ldist)
			cout << rightPrimeVals[3] << "\n";
		else if(ldist < rdist)
			cout << leftPrimeVals[3] << "\n";
		else{
			if(leftPrimeVals[3] < rightPrimeVals[3])
				cout << rightPrimeVals[3] << "\n";
			else
				cout << leftPrimeVals[3] << "\n";
		}
	}
	// add case where there's no 4th prime number
	else{
		cout << rightPrimeVals[3] << "\n";
	}
	return 0;
}
