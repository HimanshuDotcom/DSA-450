#include<vector>
#include<climits>
 
 string findWinner(int n, int x, int y) {
	 vector<int> ans(n+1, 0);
	 ans[1] = 1;
	 ans[x] = 1;
	 ans[y] = 1;
	 for(int i=2; i<=n; i++) {
		 int ans1 = ans[i-1]^1;
		 int ans2 = INT_MIN, ans3 = INT_MIN;
		 if(i-x>=0)
		 	ans2 = ans[i-x] ^ 1;
		 if(i-y>=0)
		 	ans3 = ans[i-y]^1;
		ans[i] = max(ans1,max(ans2,ans3));
	 }
	 return ans[n] == 1 ? "Beerus" : "Whis";
 }
