

/* ----------------- iteratively -------------------- */

Node<int>* reverse(Node<int> *head) {
	Node<int> *prev = NULL, *curr = head;
	while(curr && curr -> next) {
		Node *next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}
	return prev;	
}


/* --------------- recursively --------------- */
Node<int>* reverse2(Node<int> *head) {
	if(!head || head -> next == NULL) return head;
	Node<int> *rec = reverse2(head -> next);
	head -> next -> next = head;
	head -> next = NULL;
	return rec;
}
