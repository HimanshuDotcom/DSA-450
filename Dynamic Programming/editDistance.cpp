
// ----------------- Recurssive (Brute Force) ------------------ //

int editDistance(string str1, string str2) {
	if(str1.length() == 0 || str2.length() == 0)
		return max(str1.length(), str2.length());
	
	// if first character is not equal
	if(str1[0] != str2[0]) {
		int delChar = editDistance(str1, str2.substr(1));
		int replaceChar = editDistance(str1.substr(1), str2.substr(1));
		int insertChar = editDistance(str1.substr(1), str2);
		return min(delChar, min(replaceChar, insertChar)) + 1;
	}
	return editDistance(str1.substr(1), str2.substr(1));	
}


// ----------------- Memoization ------------------------ //

int editDistance(string str1, string str2, int **output) {
	if(str1.length() == 0 || str2.length() == 0)
		return max(str1.length(), str2.length());
	
	int m  = str1.length();
	int n = str2.length();	
	if(output[m][n] != -1)
		return output[m][n];
	
	int res;
	if(str1[0] != str2[0]) {
		output[m][n-1] = editDistance(str1, str2.substr(1), output); // delete char
		output[m-1][n-1] = editDistance(str1.substr(1), str2.substr(1), output); // replace char
		output[m-1][n] = editDistance(str1.substr(1), str2, output); // insert char
		res = min(output[m][n-1], min(output[m-1][n-1], output[m-1][n])) + 1;
	}
	else
		res =  editDistance(str1.substr(1), str2.substr(1), output);
	output[m][n] = res;
	return res;
	
}

// ----------------------- DP Solution -------------------- //
int editDistanceDP(string str1, string str2) {
	if(str1.length() == 0 || str2.length() == 0)
		return max(str1.length(), str2.length());
	
	int m = str1.length();
	int n = str2.length();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) 
			output[i] = new int[n+1];
	
	output[0][0] = 0;
	
	// first row 
	for(int j = 0; j <= m; j++)
		output[0][j] = j;      //  str2 length   
	
	// first col
	for(int i = 0; i <= n; i++)
		output[i][0] = i;        // str1 length
		
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(str1[m-i] == str2[n-j])
				output[i][j] = output[i-1][j-1];
			else 
				output[i][j] = min(output[i-1][j], min(output[i-1][j-1], output[i][j-1])) + 1;
		}
	}
	return output[m][n];
	
}
