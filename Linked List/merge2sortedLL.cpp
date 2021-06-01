
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    Node *head = new Node(1), 
    	*tail = new Node(1);  // dummy nodes
    head = tail;
    Node *curr1 = head1, *curr2 = head2;
    
    while(curr1 && curr2) {
        if(curr1 -> data < curr2 -> data) {
            tail -> next = curr1;
            tail = curr1;
            curr1 = curr1 -> next;
        }
        else {
            tail -> next = curr2;
            tail = curr2;
            curr2 = curr2 -> next;
        }
    }
    
    while(curr1) {      // if element remains in 1st LL
        tail -> next = curr1;
        tail = curr1;
        curr1 = curr1 -> next;
    }
     while(curr2) {    // if element remians in 2nd LL
        tail -> next = curr2;
        tail = curr2;
        curr2 = curr2 -> next;
    }
    
    Node *res = head -> next;
    // free dummy nodes
    head -> next = NULL;
    tail = NULL;
    delete head;
    delete tail;
    
    return res;
}
