#include<bits/stdc++.h>

using namespace std;

struct Trie{
        bool isEndOfWord;
        unordered_map<char, Trie*> uMap;
};

Trie *getNewTrieNode(){
        Trie *node = new Trie;
        node->isEndOfWord = false;
        return node;
}

void insert(Trie *&root, const string &s){
        if(root == nullptr) root = getNewTrieNode();
        Trie *temp = root;
        for(u_int i=0; i<s.length(); i++){
                char x = s[i];
                if(temp->uMap.find(x) == temp->uMap.end())
                        temp->uMap[x] = getNewTrieNode();
                temp = temp->uMap[x];
        }
        temp->isEndOfWord = true;
}

bool search(Trie *root, const string &s){
        if(root == nullptr) return false;
        Trie *temp = root;
        for(u_int i=0; i<s.length(); i++){
                temp = temp->uMap[s[i]];
                if(temp == nullptr) return false;
                cout << s[i];
        }
        //cout << s << "\n";
        return true;
}

void printTrie(Trie *root, char st[], int level){
        if(root->isEndOfWord){
                st[level] = '\0';
                cout << st << "\n";
        }
        unordered_map<char, Trie*>::iterator itr;
        char next;
        for(itr = root->uMap.begin(); itr != root->uMap.end(); itr++){
                next = itr->first;
                st[level] = itr->first;
                printTrie(root->uMap[next], st, level+1);
        }
}

int numberOfPalindromePairs(vector<string> vect){
        struct Trie *root = getNewTrieNode();
        for(u_int i=0; i<vect.size(); i++){
                string s = vect[i];
                reverse(s.begin(), s.end());
                insert(root, s);
        }
        int ans = 0;
        for(u_int i=0; i<vect.size(); i++){
                cout << vect[i] << endl;
                if(search(root, vect[i])) ans++;
        }
        return ans;
}

int main(int argc, const char *argv[]){
        vector<string> vect = {"a", "ab", "abb"};
        cout << numberOfPalindromePairs(vect) << endl;
}
