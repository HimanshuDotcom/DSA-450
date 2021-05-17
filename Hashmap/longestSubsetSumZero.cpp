

#include<unordered_map>
int longestSubsetWithSumZero(int *arr, int n) {
	unordered_map<int,int> indexWiseSum;
	int sum = arr[0];
	indexWiseSum[arr[i]] = 0;
	int maxLen = 0;
	for(int i = 0; i < n; i++) {
		// currSum
		sum += arr[i];
		
		if(sum == 0) 
			maxLen = i + 1;
		else if(indexWiseSum.count(sum) > 0) 
			maxLen = max(maxLen, i - indexWiseSum[sum]);
		
		// storing sum wrt index
		indexWiseSum[sum] = i;
		
	}
	return maxLen;
		
}
