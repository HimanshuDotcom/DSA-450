
//  ----------- This is an implementation of min priority queue  ------------- 

class PriorityQueue {
	vector<int> pq;
	
	public:
		
		int getSize() {
			return pq.size();
		}
		
		bool isEmpty() {
			return pq.size() == 0;
 		}
 		
 		int getMin() {
 			if(isEmpty())
			 return 0;
			return pq[0];	
		}
		 
		void insert(int data) {
			pq.push_back(data);
			int childIndex = pq.size() - 1;
			while(childIndex > 0) {
				int parentIndex = (childIndex - 1) / 2;
				if(pq[parentIndex] > pq[childIndex]) {
					// swaping elements
					int temp = pq[parentIndex];
					pq[parentIndex] = pq[childIndex];
					pq[childIndex] = temp;
				}
				else break;
				childIndex = parentIndex;
			}
		}
		
		void remove(){
			if(isEmpty()) {
				cout << "Queue is Empty" << endl;
				return;
			}
			pq[0] = pq[pq.size() - 1];
 			pq.pop_back();
			int parentIndex = 0;
			int leftChildIndex = 2*parentIndex + 1;
			int rightChildIndex = 2*parentIndex + 2;
			while(leftChildIndex < pq.size()) {
				int minIndex = parentIndex;
				
				// Select min of left and right child
				if(pq[minIndex] > pq[leftChildIndex]) //   Note ----- we are using minIndex not parentIndex
					minIndex = leftChildIndex; 
				if(rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex]) 
					minIndex = rightChildIndex;
					
				// element is at correct position
				if(minIndex == parentIndex)
					break;
				
				// swaping elements
				int temp = pq[parentIndex];
				pq[parentIndex] = pq[minIndex];
				pq[minIndex] = temp;
				
				parentIndex = minIndex;
				leftChildIndex = 2*parentIndex + 1;
				rightChildIndex = 2*parentIndex + 2;
			
			}
			
		}
};


