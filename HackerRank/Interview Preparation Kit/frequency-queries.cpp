#include <bits/stdc++.h>

int search_for_item(std::unordered_map<int, int> db, int n) {
  for (auto i : db) {
    if (i.second == n)
      return 1;
  }
  return 0;
}

int main(int argc, const char *argv[]) {
  int q, query_type, i;
  std::cin >> q;
  std::unordered_map<int, int> db;
  while (q--) {
    std::cin >> query_type >> i;
    if (query_type == 1) {
        db[i]++;
    } else if (query_type == 2) {
        if(db[i] > 0)
            db[i]--;
    } else {
      (search_for_item(db, i)) ? std::cout << 1 << "\n" : std::cout << 0 << "\n";
    }
  }
  return 0;
}

