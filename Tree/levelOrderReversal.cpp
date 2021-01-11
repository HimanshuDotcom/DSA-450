#include<stack>
#include<queue>
#include<vector>
vector<int> levelOrderReverse(TreeNode* root) {
	queue<TreeNode*> q;
	stack<int> s;
	q.push(root);
	while(!q.empty()) {
		root = q.top();
		if(root -> left) q.push(root -> left);
		if(root -> right) q.push(root -> right);
		s.push(root -> data);
	}
	while(!s.empty()) {
		root = s.top();
		v.push_back(root -> data);
		s.pop();
	}
	return v;
}
