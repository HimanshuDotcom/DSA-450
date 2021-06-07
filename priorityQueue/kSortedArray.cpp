#include<queue>

void kSortedArray(int *arr, int n, int k) {
	priority_queue<int> kMax;
	// k positons for 0th index
	for(int i = 0; i < k; i++)
		kMax.push(arr[i]);
		
	int ptr = 0, nxtPtr = k;
	while(!kMax.empty()) {
		arr[ptr++] = kMax.top();
		kMax.pop();
		if(nxtPtr < n)
			kMax.push(arr[nxtPtr++]);
	}
}
