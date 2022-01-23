


// Kth largest Element in a stream

vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        priority_queue<int,vector<int>,greater<int>> minHeap;
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(i < k) 
                minHeap.push(arr[i]);
            else {
                if(minHeap.top() < arr[i]) {
                    minHeap.pop();
                    minHeap.push(arr[i]);
                }
            }
            if(minHeap.size() < k)
                result.push_back(-1);
            else
                result.push_back(minHeap.top());
        }
        
        return result;
        
}
