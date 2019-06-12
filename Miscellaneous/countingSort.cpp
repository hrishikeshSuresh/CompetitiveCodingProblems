#include<bits/stdc++.h>

using namespace std;

vector<int> countingSort(vector<int> arr) {
    int max_value = *max_element(arr.begin(), arr.end());
    int min_value = *min_element(arr.begin(), arr.end());
    vector<int> fre(max_value - min_value + 1, 0);
    for(int i=0; i<arr.size(); i++)
        fre[arr[i]-min_value]++;
    vector<int> sorted;
    for (int i = 0; i < max_value - min_value + 1; i++) {
      while (fre[i] > 0) {
        sorted.push_back(i + min_value);
        fre[i]--;
      }
    }
    return sorted;
}

int main(int argc, const char *argv[]){
	vector<int> arr = {10, 1, 1, 4, 3};
	vector<int> sorted = countingSort(arr);
	for(auto i : sorted)
		cout << i << " ";
	cout << endl;
	return 0;
}
