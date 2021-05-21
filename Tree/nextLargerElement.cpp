
/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int x) {
	if(root == NULL) return NULL;
	TreeNode<int>* ans = NULL;
	if(root -> data > x) ans = root;
	for(int i = 0; i < root -> children.size(); i++) {
		TreeNode<int>* temp = nextLargerElement(root -> children[i], x);
		if(temp) {
			if(!ans) ans = temp;
			else 
				ans = temp -> data < ans -> data ? temp : ans; 
		}
	}
	return ans;
}
