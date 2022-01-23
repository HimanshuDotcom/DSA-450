long long maxSubarraySum(int arr[], int n){
        
    // Your code here
    long long currSum = arr[0], maxSum = arr[0];
    
    for(int i = 1; i < n; i++) {
        if(currSum < 0) 
            currSum = 0;
            currSum += arr[i];
            maxSum = max(currSum, maxSum);
        
        }
    	 
    return maxSum;
        
}
