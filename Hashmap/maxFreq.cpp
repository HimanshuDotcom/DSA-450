#include<unordered_map>

// return the element with max freq. If 2 elements have same freq than return the one which come earlier in array

int highestFrequency(int arr[], int n) {
	unordered_map<int, int> freq;
	int maxFreq = 0;
	for(int i = 0; i < n; i++) {
		++freq[arr[i]];
		maxFreq = max(freq[arr[i]], maxFreq);
	}
	
	for(int i = 0; i < n; i++) {
		if(freq[arr[i]] == maxFreq)
			return arr[i];
	}
	
}
