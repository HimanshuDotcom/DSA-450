
// insert a node in bst

Node* insert(Node* root, int key)
{
    // Your code here
    if(root == NULL) return new Node(key);
    if(key > root -> data)
        root -> right = insert(root -> right, key);
    else if(key < root -> data)
        root -> left = insert(root -> left, key);
    return root;
}
