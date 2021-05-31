
// --------- print leaders(elements whose following elements are smaller or equal) in array

void Leaders(int* arr,int len)
{
	
    int max = arr[len-1];  // largest element from last
    int *output = new int[len],
    	ptr = 0;
    output[ptr++] = arr[len-1];
    for(int i = len - 2; i >= 0; i--) {
        if(arr[i] >= max) {
            output[ptr++] = arr[i];
            max = arr[i];
        }
    }
    
    // print output in reverse order
    for(int i = ptr - 1; i >=0 ; i--) 
        cout << output[i] << " ";
    
}
