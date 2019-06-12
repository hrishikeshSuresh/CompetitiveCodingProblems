#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

// Complete the candies function below.
lli candies(lli n, vector<lli> arr) {
    lli ltor[n];
    memset(ltor, 0, sizeof(ltor));
    ltor[0] = 1;
    cout << arr[0] << " ";
    for(lli i=1; i<arr.size(); i++){
        cout << arr[i] << " ";
        if(arr[i] > arr[i-1])
            ltor[i] = ltor[i-1] + 1;
        else
            ltor[i] = 1;
    }
    cout << endl;
    lli rtol[n];
    memset(rtol, 0, sizeof(rtol));
    rtol[n-1] = 1;
    for(lli i=n-2; i>=0; i--){
        if(arr[i+1] < arr[i])
            rtol[i] = rtol[i+1] + 1;
        else
            rtol[i] = 1;
    }
    lli sum = 0;
    for(lli i=0; i<n; i++){
        cout << ltor[i] << " " << rtol[i] << endl;
        sum = (sum + ((ltor[i]>rtol[i])? ltor[i]:rtol[i]));
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    lli n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<lli> arr(n);

    for (lli i = 0; i < n; i++) {
        lli arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    lli result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

