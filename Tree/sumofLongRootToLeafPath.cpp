void helper(Node *root, int len, int &maxLen, int sum, int &resSum) {
    if(root == NULL) return;
    len++;
    sum += root -> data;
    if(!root -> left && !root -> right) {
        if(len > maxLen) {
            resSum = sum;
            maxLen = len;
        }
        else if (len == maxLen && sum > resSum) {
            resSum = sum;
        }
    return;
    }
    else {
        helper(root -> left, len, maxLen, sum, resSum);
        helper(root -> right, len, maxLen, sum, resSum);
    }
}
int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	int res = 0;
	int maxLen = 0;
	helper(root,0,maxLen,0,res);
	return res;
}
