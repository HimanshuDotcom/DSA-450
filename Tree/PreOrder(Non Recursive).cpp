#include<stack>
void PreOrderNonRecursive(TreeNode *root) {
	if(root == NULL) {
		cout << "No nodes" << endl;
		return;
	}
	
	stack<TreeNode*> s1;
	while(1) {
		while(root) {
			cout << root -> data << " ";
			s1.push(root);
			s1 = s1 -> left;
		}
		if(s1.empty())
			break;
		root = s1.top();
		s1.pop();
		root = root -> right;
	}
	
}
