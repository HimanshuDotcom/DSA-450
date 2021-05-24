void merge(int *arr1, int size1, int *arr2, int size2, int *ans)
{
    //Write your code here   
    int i = 0, j = 0;
    int ptr = 0;
    while(i < size1 && j < size2) {
        if(arr1[i] < arr2[j]) 
            ans[ptr++] = arr1[i++];
        else
            ans[ptr++] = arr2[j++];
    }
	
    while(i < size1)
        ans[ptr++] = arr1[i++];
    while(j < size2)
        ans[ptr++] = arr2[j++];
}
