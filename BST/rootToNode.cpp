


vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    vector<int>* res = new vector<int>;
    if(root == NULL)
        return res;  // empty vector
    if(root -> data == data) {
        res -> push_back(root -> data);
        return res;
    }
    if(data < root -> data) {
        vector<int> *leftAns = getPath(root -> left, data);
        if(leftAns->empty() == false)
            leftAns->push_back(root -> data);
        return leftAns;
    }
    else {
        vector<int> *rightAns = getPath(root -> right, data);
        if(rightAns->empty() == false)
            rightAns->push_back(root -> data);
        return rightAns;
    }
}
