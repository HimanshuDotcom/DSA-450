#include<vector>

// Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares 

#include<vector>
int minCount(int n) {
	vector<int> dp(n+1);
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= n; i++) {
		dp[i] = INT_MAX;
		for(int j = 1; i >=j*j;j++) 
			dp[i] = min(dp[i], dp[i-(j*j)]);
        dp[i] += 1;
	}
	return dp[n];
}
