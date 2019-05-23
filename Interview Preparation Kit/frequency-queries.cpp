#include <bits/stdc++.h>

using namespace std;

int search_for_item(unordered_map<int, int> db, int n){
    for(auto i : db){
        if(i.second == n)
            return 1;
    }
    return 0;
}

int main(int argc, const char *argv[]){
    int q, query_type, i;
	cin >> q;
	unordered_map<int, int> db;
	while(q--){
		cin >> query_type >> i;
		if (query_type == 1){
			db[i]++;
		} 
		else if (query_type == 2){
			if (search_for_item(db, i) == 1) {
				db[i]--;
			}
	    }
		else{
			if(search_for_item(db, i) == 1)
				cout << 1 << endl;
			else
				cout << 0 << endl;
	    }
	}
	return 0;
}

