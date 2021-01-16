int height(Node *root) {
    if(root == NULL) return 0;
    return max(height(root -> left), height(root -> right)) + 1;
}
bool isBalanced(Node *root)
{
    if(root == NULL) return true;
    int res = abs(height(root -> left) - height(root -> right));
    return (res <= 1) && isBalanced(root -> left) && isBalanced(root -> right);
}
