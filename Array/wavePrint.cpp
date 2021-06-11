
void spiralPrint(int **input, int i, int j, int row, int col) {
    if(i >= row || j >= col)
        return;
       
	//  row (l To R)
    for(int k = i; k < col; k++)  
        cout << input[i][k] << " ";
        
    // col (T to B)
    for(int k = i+1; k < row; k++)
        cout << input[k][col-1] << " ";
    
    // row(R To L)
    if(row-1 > i) {
        for(int k = col-2; k >= j; k--)
            cout << input[row-1][k] << " ";
    }
    
    // col(B To T)
    if(col-1 > j) {
        for(int k = row-2; k > i; k--)
            cout << input[k][j] << " ";
    }
    spiralPrint(input, i+1, j+1, row-1, col-1);
}

void spiralPrint(int **input, int nRows, int nCols)
{
    //Write your code here
    spiralPrint(input, 0, 0, nRows, nCols);
}
