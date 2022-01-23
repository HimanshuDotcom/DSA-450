    // job sequencing problem
	
	bool compare(Job j1, Job j2) {
        return (j1.profit > j2.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, compare);
        
        vector<bool> slot(n,false);
        
        int maxProfit = 0, count = 0;
        
        for(int i = 0; i < n; i++) {
            int j = arr[i].dead - 1;
            while(j >= 0 && slot[j]) 
                j--;
            if(j >= 0) { 
                slot[j] = true;
                count++;
                maxProfit += arr[i].profit;
            }
        }
        
        vector<int> result({count, maxProfit});
        return result;
	} 
