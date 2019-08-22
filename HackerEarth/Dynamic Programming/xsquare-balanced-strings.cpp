#include<bits/stdc++.h>
#include<tr1/unordered_map>

using namespace std;

int main(int argc, const char *argv[]){
    long long int T;
    char tmp[1000001];
    string s;
    std::tr1::unordered_map<char, long long int> um;
    scanf("%llu", &T);
    while(T--){
        bool flag = true;
        scanf("%1000000s", tmp);
        s = tmp;
        for(long long int i=0; i<s.length(); i++){
            um[s[i]]++;
        }
        std::tr1::unordered_map<char, long long int>::iterator itr;
        for(itr=um.begin(); itr!=um.end(); itr++){
            if(um[itr->first]%2!=0){
                flag =  false;
            }
        }
        if(flag){
            printf("1\n");
        }
        else{
            printf("-1\n");
        }
        //printf("%s\n", s.c_str());
        um.clear();
    }
    return 0;
}
