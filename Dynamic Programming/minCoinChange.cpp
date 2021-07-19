#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int minCoinsDP(int *arr, int n, int k) {
	if(k == 0)
		return 0;
	vector<int> coins(k+1, 0);s
	for(int i = 1; i <= k; i++) {
		coins[i] = INT_MAX;
		for(int j = 0; j < n; j++) {
			if(i-arr[j] >= 0)
				coins[i] = min(coins[i], coins[i-arr[j]]);
		}
		if(coins[i] != INT_MAX)
			coins[i] += 1;
	}
	return coins[k] == INT_MAX ? 0 : coins[k];
}
int main() {
	int arr[] = {1,5,7,10};
	cout << minCoinsDP(arr, 4, 8);
}
