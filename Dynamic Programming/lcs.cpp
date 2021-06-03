

// ----------------- Recurssive(Brute Force) --------------- //

int lcs(string str1, string str2) {
	if(str1.size() == 0 || str2.size() == 0)
		return 0;
	if(str1[0] == str2[0])
		return lcs(str1.substr(1), str2.substr(1)) + 1;
	else {
		int x = lcs(str1.substr(1), str2.substr(1));
		int y = lcs(str1.substr(1), str2) + 1;
		int z = lcs(str1, str2.substr(1)) + 1;
		return max(x, max(y, z)) + 1;
	}
	
}

// ------------------ Memoization ----------------- //

int lcs(string str1, string str2, int **output) {
	if(str1.size() == 0 || str2.size() == 0)
		return 0;
	// size
	int m = str1.size();
	int n = str1.size();
	
	if(output[m][n] != -1)
		return output[m][n];
	
	int ans;
	if(str1[0] == str2[0]) {
		ans =  lcs(str1.substr(1), str2.substr(1)) + 1;
	}
	else {
		int x = lcs(str1.substr(1), str2.substr(1));
		int y = lcs(str1.substr(1), str2);
		int z = lcs(str1, str2.substr(1));
		ans = max(x, max(y, z));
	}
	output[m][n] = ans;
	return ans;
	
}


// --------------- DP ----------------- //

int lcs(string str1, string str2) {
	int m = str1.size();
	int n = str2.size();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
	}
	
	output[0][0] = 0;
	
	// first row
	for(int i = 0; i <= m; i++)
		output[i][0] = 0;
	
	//first col
	for(int i = 0; i <= n; i++)
		ouput[0][i] = 0;
	
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(str1[m-i] == str2[n-j])  //  the index to be matched. 
				output[i][j] = output[i-1][j-1] + 1;
				
			else 
				output[i][j] = max(output[i-1][j], max(output[i][j-1], output[i-1][j-1]));
		
	}
	return output[m][n];		
	
}
