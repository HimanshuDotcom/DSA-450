// ----------- Recursive (Brute Force approach) ------------ // 

int bruteForce(int **input, int row, int col, int m, int n) {
	if(row > m || col > n)
		return INT_MAX;
	if(row ==m && col == n)
		return input[row][col];
	int rightcost = bruteForce(input, row, col+1, m, n);
	int downcost = bruteForce(input, row+1, col, m, n);
	int diagonalcost = bruteForce(input, row+1, col+1, m, n);
	return min(rightcost, min(downcost, diagonalcost)) + input[row][col];
}

//  ----------------- Memoization ------------------- //

int memoization(int **input, int row, int col, int m, int n, int **cost) {
	if(row > m || col > n)
		return INT_MAX;
	if(row ==m && col == n)
		return input[row][col];
	
	if(cost[row][col] != -1) 
		return cost[row][col];
		
	int rightcost = memoization(input, row, col+1, m, n, cost);
	int downcost = memoization(input, row+1, col, m, n, cost);
	int diagonalcost = memoization(input, row+1, col+1, m, n, cost);
	int res = min(rightcost, min(downcost, diagonalcost)) + input[row][col];
	cost[row][col] = res;
	return res;
		
}

// ----------------- Dynamic Programming ----------------- //

int DPsol(int **input, int m, int n) {
	int **cost = new int*[m];
	for(int i = 0; i < m; i++) {
		cost[i] = new int[n];
	}
	cost[0][0] = input[0][0];
	// first row 
	for(int i = 0; i < m; i++)
		cost[0][i] = cost[0][i-1] + input[0][i];
	// first col
	for(int i = 0; i < n; i++)
		cost[i][0] = cost[i-1][0] + input[i][0];
	
	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			cost[i][j] = min(cost[i-1][j-1], min(cost[i-1][j], cost[i][j-1])) + input[i][j];
		}
	}
	
	return cost[m-1][n-1];
}


int minCostPath(int **input, int m, int n) {
	int **cost = new int*[m];
	for(int i = 0; i < m; i++) {
		cost[i] = new int[n];
		for(int j = 0; j < n; j++)
			cost[i][j] = -1;
	}	
	memoization(input, 0, 0, m-1, n-1, cost);
	DPsol(input,m,n);
	
	// free memory
	for(int i = 0; i < n; i++)
		delete [] cost[i];
	delete [] cost;
}






