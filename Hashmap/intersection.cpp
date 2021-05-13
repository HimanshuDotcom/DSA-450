#include<unordered_map>

// Space complexity - O(n)
// Note -- Better solution is without hashmap (in array folder)

void intersection(int *arr1, int  *arr2, int n, int m) {
	unordered_map<int, int> freq1;
	for(int i = 0; i < n, i++) {
		++freq1[arr1[i]];
	}
	
	for(int i = 0; i < m; i++) {
		if(freq1.count(arr2[i]) > 0 && freq1[arr[i]] > 0) {
			--freq1[arr2[i]];
			cout << arr2[i] << " ";
		}
	}
}
