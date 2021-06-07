#include<queue>
int kthLargest(int* arr, int n, int k) {
    // Write your code here
    priority_queue<int, vector<int>, greater<int> > kElements; // minheap
    for(int i = 0; i < k; i++)
        kElements.push(arr[i]);
    for(int i = k; i < n; i++) {
        if(arr[i] > kElements.top()) {
            kElements.pop();
            kElements.push(arr[i]);
        }
    }
    return kElements.top();
    
}
