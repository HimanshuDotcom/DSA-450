#include<vector>

int longestIncreasingSubsequence(int *arr, int n) {
	vector<int> output(n,1);
	int maxLen = 0;
	
	for(int i = 1; i < n; i++) {
		for(int j = i-1; j >= 0; j--) {
			if(arr[i] > arr[j])
				output[j] = max(output[i] + 1, output[j]);
		}
		maxLen = max(output[i], maxLen);	
	}
	
	return maxLen;
}
