#include<queue>


// (K is the number of array, N is avg length of array)

/* ----------- Time Complexity O(N*K*log(N*K)) -----------------    
	----------	Space Complexity O(N*K) ----------------------- */

vector<int> mergeKSorted(vector<vector<int>* > input ) {
	priority_queue<int, vector<int>, greater<int> > heap;
	for(int i = 0; i < input.size(); i++) {
		for(int j = 0; j < input[i]->size(); j++)
			heap.push(input[i]->at(j));
	}
	vector<int> result;
	while(!heap.empty()) {
		result.push_back(heap.top());
		heap.pop();
	}	
	return result;
}

/* ----------- Time Complexity O(N*K*log(K)) -----------------
	----------	Space Complexity O(K) ----------------------- */
class Triplet {
	public:
		int element;
		int elementIndex;
		int arrayIndex;
};
class compare {
	public:
		bool operator()(Triplet t1, Triplet t2) {
			return t1.element > t2.element();
		}
};
vector<int> mergeKSorted2(vector<vector<int>* > input) {
	priority_queue<Triplet, vector<Triplet>, compare > heap;
	for(int i = 0; i < input.size(); i++) {
		Triplet t;
		t.element = input[i][0];
		t.elementIndex = 0;
		t.arrayIndex = i;
		heap.push(t);
	}
	vector<int> result;
	while(!heap.empty()) {
		Triplet top = heap.top();
		heap.pop();
		result.push_back(top.element);
		int index = top.elementIndex;
		int arrIndex = top.arrayIndex;
		if(index+1 >= input[arrIndex]->size())
			continue;
		else {
			Triplet t;
			t.elementIndex = index+1;
			t.element = input[arrIndex]->at(index+1);
			t.arrayIndex = arrIndex;
			heap.push(t);
		}
	}
	return result;
	
}
