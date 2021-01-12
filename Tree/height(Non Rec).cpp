#include<queue>
void height(TreeNode* root) {
	if(root == NULL) return 0;
	int level = 0;
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		root = q.front();
		q.pop();
		if(root == NULL) {
			level++;
			if(!q.empty())
				q.push(NULL); // marker for next level
		}
		else {
			if(root -> left) q.push(root -> left);
			if(root -> right) q.push(root -> right); 
		}
	}
	return level;
}
