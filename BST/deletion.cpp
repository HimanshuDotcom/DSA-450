Node *getSucc(Node *root) {
    Node *temp = root;
    while(temp -> left != NULL) temp = temp -> left;
    return temp;
}
Node *deleteNode(Node *root,  int X)
{
    // your code goes here
    if(root == NULL) return root;
    if(root -> data == X) {
        if(root -> left == NULL) {
            Node *temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL) {
            Node *temp = root -> left;
            free(root);
            return temp;
        }
       Node *temp = getSucc(root -> right);
       root -> data = temp -> data;
       root -> right = deleteNode(root -> right, temp -> data);
    }
    else if( X > root -> data) root -> right = deleteNode(root -> right, X);
    else root -> left = deleteNode(root -> left, X);
    return root;
}
