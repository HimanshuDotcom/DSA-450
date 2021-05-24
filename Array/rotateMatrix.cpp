
#include<iostream>
using namespace std;

void rotateMatrix(int input[][100], int row, int col) {
	
	for(int i = 0; i < row; i++) {
		for(int j = i; j < col; j++)
			swap(input[i][j],input[j][i]);
	}
	int end = row - 1;
	for(int i = 0; i < end; i++, end--) {
		for(int j = 0; j < col; j++)
			swap(input[i][j], input[end][j]);
	}
	
}

int main() {
	int input[100][100];
	int m, n;
	cin >> m >> n;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			cin >> input[i][j];
	}
	rotateMatrix(input, m, n);
		for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			cout << input[i][j];
	}
	
}
