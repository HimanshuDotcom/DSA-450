
Node<int>* appendlastNToFirst(Node<int> *head, int n) {
	Node<int> *curr = head, *prev = head;
	if(n == 0) return head;
	while(curr -> next && curr) {
		if(n == 0)
			prev =  prev -> next;
		else
			--n;
		curr = curr -> next;
	}
	if(prev == head) return head;
	Node *newhead = prev -> next;
	prev -> next = NULL;
	curr -> next = head;
	return newhead;
	
	
	
}
