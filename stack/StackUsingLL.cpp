template<typename T>
class stackNode {
	T data;
	stackNode* next;
	
	public:
		stackNode(int data) {
			this -> data = data;
			next = NULL;
		}
		
		~stackNode() {
			delete next;
		}
		
};

template<typename T>
class Stack {
	T* head;
	int size;
	
	public:
		Stack() {
			head = NULL;
			size = 0;
		}
		
		int getSize() {
			return size;
		}
		
		void push(int data) {
			stackNode<T> *newnode = new stackNode<T>(data);
			newnode -> next = head;
			head = newnode;
			size++;
		}
		
		void pop() {
			if(head == NULL) {
				cout << "Stack is empty" << endl;
				return;
			}
			stackNode<T> *temp = head;
			head = head -> next;
			delete head;
			size--;
		}
		
		
};
