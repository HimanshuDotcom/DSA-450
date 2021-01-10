#include<stack>
void inOrderNonRecursive(TreeNode* root) {
	if(root == NULL) {
		cout << "No Nodes" << endl;
		return;
	}
	stack<TreeNode*> s;
	while(1) {
		while(root) {
			s.push(root);
			root = root -> left;
		}
		if(s.empty()) break;
		root = s.top();
		cout << s -> data << " ";
		root = root -> right;
		s.pop();
	}
}
