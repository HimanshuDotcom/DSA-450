
#include <iostream>
#include<vector>
using namespace std;

int maxKSum(vector<int> arr, int n, int k) {
	int maxSum = 0;
	for(int i = 0; i <= n-k; i++) {
		int sum = arr[i];
		for(int m = 1, j = i+1; m < k && j < n; m++,j++)
			sum += arr[j];
		maxSum = max(sum, maxSum);
	}
	return maxSum;
}

int slideWindowMaxKSum(vector<int> arr, int n, int k) {
	int currSum = 0, maxSum = 0;
	for(int i = 0; i < k; i++)
		currSum += arr[i];
	for(int i = 0; i < n-k; i++) {
		currSum = currSum - arr[i] + arr[i+k];
		maxSum = max(currSum, maxSum);
	}
	return maxSum;
}

int main() {
	// your code goes here
	vector<int> arr;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int j;
		cin >> j;
		arr.push_back(j);
	}
	int k;
	cin >> k;
	// cout << maxKSum(arr, n, k);
	cout << slideWindowMaxKSum(arr, n, k);
	return 0;
}


