

void removeMin(int arr[], int n) {
    
    while(n > 1) {
        // swap first and last element
        int temp = arr[0];
        arr[0] = arr[n-1];
        arr[n-1] = temp; 
        
        --n;  // decrease size of array
        int parentIndex = 0;
        int child1 = (2 * parentIndex) + 1;
        int child2 = (2 * parentIndex) + 2;
        while(child1 < n) {
            int minIndex = parentIndex;
            if(arr[minIndex] > arr[child1])
                minIndex = child1;
            if(child2 < n && arr[minIndex] > arr[child2])
                minIndex = child2;
            if(minIndex == parentIndex)
                break;
            // swap
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            
            parentIndex = minIndex;
            child1 = (2 * parentIndex) + 1;
        	child2 = (2 * parentIndex) + 2;  
        }
    }
}


void heapSort(int arr[], int n) {
	
	// Assume 1st element of array in heap now start adding further
    for(int i = 1; i < n; i++) {
        int childIndex = i;
        int parentIndex = (childIndex - 1) / 2;
        while(arr[parentIndex] > arr[childIndex]) {
            // swapping
            int temp = arr[parentIndex];
            arr[parentIndex] = arr[childIndex];
            arr[childIndex] = temp;
            
            childIndex = parentIndex;
            if(childIndex == 0) break;
            parentIndex = (childIndex - 1) / 2;
        }
    }
    removeMin(arr, n);  // Min element will get replaced with last element in each iteration
}
