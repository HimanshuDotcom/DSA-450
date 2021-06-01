


// --------- Find midpoint of Single Linked list 

Node* midpoint(node *head) {
	if(head == NULL || head -> next == NULL)
		return head;
	Node *slow = head, *fast = head -> next;  // hare and tortoise
	
	while(fast && fast -> next) {
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	return slow;
}
