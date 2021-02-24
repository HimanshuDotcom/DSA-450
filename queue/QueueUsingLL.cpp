#include<iostream>
using namespace std;

template <typename T>
class QueueNode {
	public:
		
	T data;
	QueueNode* next;
	
		QueueNode(T data) {
			this -> data = data;
			next = NULL;
		}
};
template<typename T>
class Queue {
	QueueNode<T> *head;
	QueueNode<T> *tail;
	int size;
	
	public:
		Queue() {
			head = tail = NULL;
			size = 0;
		}
		
		int getSize() {
			return size;
		}
		
		bool isEmpty() {
			return size == 0;
		}
		
		// add data to queue
		void enqueue(T data) {
			QueueNode<T> *newnode = new QueueNode<T>(data);
			if(head == NULL) {
				head = tail = newnode;
			}
			else {
				tail -> next = newnode;
				tail = newnode;
			}
			size++;
		}
		
		// remove front data
		void dequeue() {
			if(isEmpty()) {
				cout << "Queue is empty" << endl;
				return;
			}
			QueueNode<T> *temp = head;
			head = head -> next;
			delete temp;
			size--;
		}
		
		// read front data
		T front() {
			if(isEmpty()) {
				cout << "Queue is empty" << endl;
				return -1;
			}
			return head -> data;
		}
};

