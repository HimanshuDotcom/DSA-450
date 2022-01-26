

// ------------------------ DP Solution ------------------------
long long maximumAmount(int arr[], int n){
        // Your code here
    long long dp[n][n];
       for(int g=0;g<n;g++) // iterating over possible gaps
       {
           for(int i=0,j=g;j<n;i++,j++)
           {
               if(g==0) // only 1 element
               {
                   dp[i][j]=arr[i];
               }
               else if(g==1)  // only 2 element
               {
                   dp[i][j]=max(arr[i],arr[j]);
               }
               else
               {
                   long long  val1=arr[i]+min(dp[i+2][j],dp[i+1][j-1]);
                   long long val2=arr[j]+min(dp[i+1][j-1],dp[i][j-2]);
                   dp[i][j]=max(val1,val2);
               }
           }
       }
       return dp[0][n-1];

}

// ---------------------- Recursion ------------------
long long maximumAmount(int arr[], int st, int end) {
        if(st > end)
            return 0;
        if(st == end) return arr[st];
        if(end == st+1)
        	return max(arr[st],arr[end]);
        long long res1 = arr[st] + min(maximumAmount(arr,st+2,end),maximumAmount(arr,st+1,end-1));
        long long res2 = arr[end] + min(maximumAmount(arr,st+1,end-1),maximumAmount(arr,st,end-2));
        return max(res1,res2);
}
long long maximumAmount(int arr[], int n){
    // Your code here
        
    return maximumAmount(arr,0,n-1);
}
