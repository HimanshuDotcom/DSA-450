
bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for(int i = 0; i < n; i++) {
        int leftChildren = 2*i + 1;
        int rightChildren = leftChildren + 1;
        if(leftChildren < n && arr[i] < arr[leftChildren])
            return false;
        if(rightChildren < n && arr[i] < arr[rightChildren])
            return false;
    }
    return true;
    
}
