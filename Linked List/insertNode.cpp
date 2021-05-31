
template<typename T>
class Node {
	T data;
	Node<T> *next;
	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};

void insertNode(Node *head, int i) {
	if(head == NULL) return;
	
	Node<int> *prev = NULL, curr = head;
	for(int j = 0; j < i; j++) {
		prev = curr;
		curr = curr -> next;
	}
	if(prev == NULL)
		return new Node<int>(data);
	else {
		Node *newnode = Node<int>(data);
		prev -> next = newnode;
		newnode -> next = prev -> next;
	}
	return head;			

}
