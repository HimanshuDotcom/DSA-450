struct pair1 {
  int height;
  int diameter;
};

pair1 helper(Node* root) {
    if(root == NULL) {
        pair1 p;
        p.height = 0;
        p.diameter = 0;
        return p;
    }
    pair1 leftans = helper(root -> left);
    pair1 rightans = helper(root -> right);
    pair1 ans;
    ans.height = max(leftans.height, rightans.height) + 1;
    ans.diameter = max(leftans.height + rightans.height + 1, max(leftans.diameter, rightans.diameter));
    return ans;
}
int diameter(Node* root) {
    if(root == NULL) return 0;
    return helper(root).diameter;
}
