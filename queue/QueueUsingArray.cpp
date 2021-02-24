#include<iostream>
using namespace std;
template<typename T>
class Queue {
	T *arr;
	int frontIndex;
	int nextIndex;
	int capacity;
	int size;
	
	public:
		
		Queue() {
			capacity = 4;
			arr = new T[capacity];
			frontIndex = -1;
			nextIndex = 0;
			size = 0;
		}
		
		int getSize() {
			return size;
		}
		
		bool isEmpty() {
			return size == 0;
		}
		
		void enqueue(T data) {
			if(size == capacity) {
				T *newarr = new T[capacity * 2];
				for(int i = 0; i < capacity; i++) {
					newarr[i] = arr[frontIndex];
					frontIndex = (frontIndex + 1) % capacity;
				}
				frontIndex = 0;
				nextIndex = capacity;
				capacity *= 2;
				delete [] arr;
				arr = newarr;
			}
			if(frontIndex == -1) frontIndex = 0;
			arr[nextIndex] = data;
			nextIndex = (nextIndex + 1) % capacity; 
			size++;
		}
		
		void dequeue() {
			if(isEmpty())  {
				cout << "Queue is empty" << endl;
				return;
			}
			frontIndex = (frontIndex + 1) % capacity;
			size--;
		}
		
		T front() {
			if(isEmpty()) {
				cout << "Queue is empty" << endl;
				return -1;
			}
			return arr[frontIndex];
		}
};

