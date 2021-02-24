template<typename T>
class stackNode {
	public:
		
	T data;
	stackNode<T>* next;
	
		stackNode(T data) {
			this -> data = data;
			next = NULL;
		}
		
		~stackNode() {
			delete next;
		}
		
};

template<typename T>
class Stack {
	stackNode<T>* head;
	int size;
	
	public:
		Stack() {
			head = NULL;
			size = 0;
		}
		
		int getSize() {
			return size;
		}
		
		void push(T data) {
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
			delete temp;
			size--;
		}
};
