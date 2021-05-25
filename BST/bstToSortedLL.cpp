

/* ------ In pair class first refers to head, and second refers to tail ------ */

pair< Node<int>*, Node<int>*> bstToSortedLL(BinaryTreeNode<int> *root) {
	pair< Node<int>*, Node<int>*> result;
	if(root == NULL) {
		result.first = NULL;
		result.second = NULL;
		return result;
	}
	
	pair< Node<int>*, Node<int>*> leftAns = bstToSortedLL(root -> left);
	pair< Node<int>*, Node<int>*> rightAns = bstToSortedLL(root -> right);
	
	Node<int>* rootNode = new Node<int>(root -> data);
	rootNode -> next = rightAns.first; 
	if(leftAns.first != NULL) {
        result.first = leftAns.first;
		leftAns.second -> next = rootNode;
	}
    else {
        result.first = rootNode;
    }
    if(rightAns.first != NULL)
        result.second = rightAns.second;
    else
        result.second = rootNode;
	return result;
		
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    return bstToSortedLL(root).first;
}
