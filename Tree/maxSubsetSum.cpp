pair<int,int> maxSubsetSum(Node *root) {
	if(root == NULL) {
		pair<int,int> ans;
		ans.first = 0;
		ans.second = 0;
		return ans;
	}
	pair<int,int> leftAns = maxSubsetSum(root -> left);
	pair<int,int> rightAns = maxSubsetSum(root -> right);
	pair<int,int> finalAns;
	finalAns.first = root -> data + leftAns.second + rightAns.second;
	finalAns.second = max(leftAns.first,leftAns.second) + max(rightAns.first,rightAns.second);
	return finalAns;
}
