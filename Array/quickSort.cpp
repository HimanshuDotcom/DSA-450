int partition(int input[], int start, int end) {
    int piv = input[start];
    int count = 0;
    for(int i = start+1; i <= end; i++) {
     	if(input[i] <= piv)
            count++;
    }
    // swap
    int pivIndex = count+start;
    input[start] = input[pivIndex];
    input[pivIndex] = piv;
    
    int left = 0, right = pivIndex+1;
    while(left < pivIndex && right <= end) {
        if(input[left] <= piv)
            left++;
        else if(input[right] > piv)
            right++;
        else {
            // swap;
            int temp = input[right];
            input[right] = input[left];
            input[left] = temp;
            right++;
            left++;
        }
    }
    return pivIndex;
}

void quickSort(int input[], int start, int end) {
    if(start >= end)
        return;
    int part = partition(input, start, end);
    quickSort(input, start, part-1);
    quickSort(input, part+1, end);
} 

void quickSort(int input[], int size) {
  
    quickSort(input, 0, size-1);

}
