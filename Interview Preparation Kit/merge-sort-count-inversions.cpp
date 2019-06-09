#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long merge(vector<int> arr, int l, int mid, int r){
    int inverses = 0;
    int i, j, k;
    int n1 = mid + 1 - l;
    int n2 = r - mid;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++)
        L[i] = arr[l+i];
    for(int i=0; i<n2; i++)
        R[i] = arr[mid + 1 + i];
    i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else{
            arr[k++] = R[j++];
            inverses = mid - i;
        }
    }
    while(i<n1)
        arr[k++] = L[i++];
    while(j<n2)
        arr[k++] = R[i++];
    return inverses;
}

long merge_sort(vector<int> arr, int l, int r){
    int inverses = 0;
    if(l<r){
        int mid = l + (r-l)/2;
        inverses += merge_sort(arr, l, mid);
        inverses += merge_sort(arr, mid + 1, r);
        inverses += merge(arr, l, mid, r);
    }
    return (long)inverses;
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) {
    long inverses = merge_sort(arr, 0, arr.size()-1);
    for(auto i: arr)
        cout << i << " ";
    cout << endl;
    cout << "Number of inverses " << inverses << endl;
    return inverses;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

