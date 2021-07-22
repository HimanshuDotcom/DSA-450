#include<vector>
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
    vector<vector<int> > squares(n, vector<int>(m));
    int maxSquares = 0;
    for(int i = 0; i < m; i++) {
        squares[0][i] = arr[0][i] == 0 ? 1 : 0;
        maxSquares = max(maxSquares, squares[0][i]);
    }
    for(int i = 0; i < n; i++) {
        squares[i][0] = arr[i][0] == 0 ? 1 : 0;
        maxSquares = max(maxSquares, squares[i][0]);
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(arr[i][j] == 0)
            	squares[i][j] = min(squares[i-1][j-1], min(squares[i-1][j], squares[i][j-1])) + 1;
            else
                squares[i][j] = 0;
            maxSquares = max(maxSquares, squares[i][j]);
        }
    }
    
    return maxSquares;
    
        
}
