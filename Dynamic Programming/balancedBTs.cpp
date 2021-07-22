

// ------------- Brute force (Recurssion) ------------------

int balancedBTs(int n) {
	// base case ( in case of n = 0 NULL node)
	if(n <= 1)
		return 1;
	
	int mod = (int)(pow(10, 9) + 7);
	int x = balancedBTs(n-1);
	int y = balancedBTs(n-2);
	
	int temp1 = (int)(((long)(x)*x) % mod);
	int temp2 = (int)((2*(long)(x)*y) % mod);
	
	int ans = (int)((temp1 + temp2) % mod);
	return ans;	

}

// ------------------ DP -----------------
int balancedBTs(int n) {
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    int mod = (int)(pow(10,9) + 7);
    for(int i = 2; i <= n; i++) {
        int x = dp[i-1];
        int y = dp[i-2];
        int temp1 = (int)(((long)(x)*x) % mod);
        int temp2 = (int)((2*(long)(x)*y) % mod);
        dp[i] = (int)(temp1 + temp2)%mod;
    }
    return dp[n];
}
