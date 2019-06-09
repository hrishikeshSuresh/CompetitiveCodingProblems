#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(string s) {
    long n = s.length();
    long i=0;
    long result = 0;
    long *count_array = (long*)malloc(sizeof(long)*n);
    for(long z=0; z<n; z++){
        count_array[i] = 0;
    }
    // two cases
    // CASE 1 : only aaa, aa, a...
    while(i<n){
      long sameCharCount = 1;
      long j = i + 1;
      while (s[i] == s[j] && j < n)
        sameCharCount++, j++;
      result = result + (sameCharCount * (sameCharCount + 1)) / 2;
      count_array[i] = sameCharCount;
      i = j;
    }
    // CASE 2 : only aabaa, aba,...
    for(long j=1; j<n; j++){
        if(s[j] == s[j-1])
            count_array[j] = count_array[j-1];
        if(j>0 && j<(n-1) && s[j-1] == s[j+1] && s[j]!=s[j-1])
            result += min(count_array[j-1], count_array[j+1]);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

