#include<unordered_map>

int pairSumToZero(int *arr, int n) {
	unordered_map<int,int> freq;
	int pairs = 0;
	for(int i = 0; i < n; i++) {
		if(freq[-arr[i]] > 0) {
			pairs += freq[-arr[i]];
		}
		++freq[arr[i]];
	}
	return pairs;
}
