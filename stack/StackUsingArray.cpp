
template<typename T>
class Stack {
	T *arr;
	int capacity;
	int nextIndex;
	
	public:
		
		Stack() {
			capacity = 10;
			arr = new T[10];
			nextIndex = 0; 
		}
		
		int getSize() {
			return nextIndex;
		}
		
		// insert Element
		void push(T data) {
			if(size == capacity) {
				T *newArr = new T[capacity * 2];
				for(int i = 0; i < capacity; i++)
					newArr[i] = arr[i];
					capacity *= 2;
				delete [] arr;
				arr = newArr;
			}
			arr[nextIndex] = data;
			++nextIndex;
		}
		
		//  delete Element
		void pop() {
			if(size == 0) {
				cout << "Stack is empty" << endl;
				return;
			}
			--nextIndex;
			--size;
		}
		
		// element on top
		T top() {
			if(size == 0) {
				cout << "Stack is empty" << endl;
				return -1;
			}
			return arr[nextIndex-1];
		}
		
};

