void merge(int input[], int start, int mid, int end) {
    int leftStart = start;
    int leftEnd = mid;
    int rightStart = mid+1;
    int rightEnd = end;
    
    int output[end-start+1];
    int ptr = 0;
    
	while(leftStart <= leftEnd && rightStart <= rightEnd ) {
        if(input[leftStart] < input[rightStart]) {
            output[ptr] = input[leftStart];
            ++leftStart;
        }
        else {
             output[ptr] = input[rightStart];
            ++rightStart;
        }
        ++ptr;
    }
    
    while(leftStart <= leftEnd) 
        output[ptr++] = input[leftStart++];
    
    while(rightStart <= rightEnd) 
        output[ptr++] = input[rightStart++];
    
    for(int j = 0; j <= (end - start); j++)
        input[j+start] = output[j];
    
    
}

void mergeSort(int input[], int start, int end) {
    if(start >= end) // without equal to error
        return;
    int mid = (start + end) / 2;
    mergeSort(input, start, mid);
    mergeSort(input, mid+1, end);
    merge(input, start, mid, end);
}

void mergeSort(int input[], int size){
	// Write your code here
    return mergeSort(input, 0, size-1);
        
}

