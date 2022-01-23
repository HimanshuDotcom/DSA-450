long long trappingWater(int arr[], int n){
        // code here
        vector<int> lMax(n);
        vector<int> rMax(n);
        lMax[0] = arr[0];
        int curr = arr[0];
        
        // Storing left max upto each index
        for(int i = 1; i < n; i++) {
            lMax[i] = curr;
            curr = max(curr, arr[i]);
        }
        rMax[n-1] = arr[n-1];
        curr = arr[n-1];
        
        // storing right max upto each index
        for(int i = n-2; i >= 0; i--) {
            rMax[i] = curr;
            curr = max(curr, arr[i]);
        }
        int level = 0;
        for(int i = 1; i < n-1; i++) {
            int temp = (min(lMax[i], rMax[i]) - arr[i]);
            if(temp > 0)
                level += temp;
        }
        return level;
        
}
