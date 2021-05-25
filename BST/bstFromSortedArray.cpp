

/*  ---- Construct BST from a Sorted Array ---- */

BinaryTreeNode<int>* constructTree(int *arr, int start, int end) {
	if(start > end)
		return NULL;
	int mid = (start + end) / 2;
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
	root -> left = constructTree(arr, start, mid-1);
	root -> right = constructTree(arr, mid+1, end);
	return root;
}

BinaryTreeNode<int>* constructTree(int *arr, int n) {
	return constructTree(arr, 0, n-1);
}
