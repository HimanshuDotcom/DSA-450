// Search a node with value k in bst

bool search(Node* root, int k)
{
    //Your code here
    if(root == NULL) return false;
    if(root -> data == k) return true;
    if(k > root -> data) return search(root -> right, k);
    else if(k < root -> data) return search(root -> left, k);
}
