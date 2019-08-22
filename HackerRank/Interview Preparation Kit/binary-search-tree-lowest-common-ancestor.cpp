#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    bool findPath(Node *root, vector<Node*> &path, int key){
        if(root == NULL)    return false;
        path.push_back(root);
        if(root->data == key)   return true;
        if((root->left && findPath(root->left, path, key)) || (root->right && findPath(root->right, path, key)))
            return true;
        
        // if not present in sub-tree
        path.pop_back();
        return false;

    }

    Node *lca(Node *root, int v1,int v2) {
		vector<Node*> path1, path2;
        if(!findPath(root, path1, v1) || !findPath(root, path2, v2))    return NULL;
        int i = 0;
        for(; i<min(path1.size(), path2.size()); i++){
            if(path1[i]->data != path2[i]->data)
                break;
        }
        return path1[i-1];
    }

}; //End of Solution
