/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    void checkBSTUtil(Node *root, vector<int> &elements){
        if(root == NULL)    return;
        checkBSTUtil(root->left, elements);
        elements.push_back(root->data);
        checkBSTUtil(root->right, elements);
    }

	bool checkBST(Node* root) {
        vector<int> elements;
		checkBSTUtil(root, elements);
        for(int i=0; i<elements.size()-1; i++){
            if(elements[i+1] > elements[i])
                continue;
            else
                return false;
        }
        return true;
	}
