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
	if(root == nullptr)
		root = getNewTrieNode();
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
	}
	return temp->isEndOfWord;
}

void print(Trie *root, char st[], int level){
	if(root->isEndOfWord){
		st[level] = '\0';
		cout << st << "\n";
	}
	unordered_map<char, Trie*>::iterator itr;
	char next;
	for(itr = root->uMap.begin(); itr != root->uMap.end(); itr++){
		next = itr->first;
		st[level] = itr->first;
		print(root->uMap[next], st, level+1);
	}
}

int main(int argc, const char *argv[]){
	Trie *root = nullptr;
	insert(root, "geeks");
	insert(root, "for");
	insert(root, "gee");
	char st[1000];
	cout << search(root, "gee") << "\n";
	print(root, st, 0);
}
