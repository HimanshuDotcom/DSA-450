
/* --- Find Element in a 2d array which is sorted both row and 
	   columm n wise -------- */

void findElement(int input[][100], int row, int col, int element) {
	int rowS = 0;
	int colS = col - 1;
	while(rowS < row && colS >= 0) {
		if(element == input[rowS][colS]) {
			cout << rowS << " " << colS << end;
			return;
		}
		else if(element > input[rowS][colS]) 
			rowS++;
		else
			colS--;
	}
	cout << "Element is not present" << endl;
}

