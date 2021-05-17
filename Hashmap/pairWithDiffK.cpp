

#include<unordered_map>
int pairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int,int> freq;
	int pairs = 0;
	for(int i = 0; i < n; i++) {
		int comp = k + arr[i];
		pairs += freq[comp];
		if(k != 0) {
			comp = arr[i] - k;
			pairs += freq[comp];
		}
		++freq[arr[i]];
	}
	return pairs;
}
