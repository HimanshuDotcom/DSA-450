struct output {
    int min;
    int max;
    bool isBST;
};
output helper(Node *root) {
     if(root == NULL) {
        output res;
        res.min = INT_MAX;
        res.max = INT_MIN;
        res.isBST = true;
        return res;
    }
    output left = helper(root -> left);
    output right = helper(root -> right);
    int minimum = min(root -> data, min(left.min, right.min));
    int maximum = max(root -> data, max(left.max, right.max));
    bool res = (root -> data > left.max) && (root -> data <= right.min) && left.isBST && right.isBST;
    output finalRes;
    finalRes.min = minimum;
    finalRes.max = maximum;
    finalRes.isBST = res;
    return finalRes;
}
bool isBST(Node* root) {
    // Your code here
    return helper(root).isBST;
    
}
