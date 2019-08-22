#include<bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]){
    char tmp[100001];
    scanf("%100000s", tmp);
    string S = tmp;
    set<char> pali_strings;
    pali_strings.insert("H");
    for(int i=0; S[i]!='\0'; i++){
        cout << S[i] << endl;
        pali_strings.insert(tmp[i]);
    }
    return 0;
}
