#include<iostream>
using namespace std;

void printdfs(int start, int **edges, int n, bool *visited) {
	visited[start] = true;
	cout << start << " ";
	for(int i = 0; i < n; i++) {
		if(start != i && !visited[i] && edges[start][i] == 1)
			printdfs(i, edges, n, visited);
	}
}

int main() {
	int n, e; // vertex and edges
	cin >> n >> e;
	int **edges = new int*[n];
	for(int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for(int j = 0; j < n; j++)
			edges[i][j] = 0;
	}
	for(int i = 0; i < e; i++) {
		int start,end;
		cin >> start >> end;
		edges[start][end] = 1;
		edges[end][start] = 1;
	}
	bool *visited = new bool[n];
	for(int i = 0; i < n; i++)
		visited[i] = false;
		
	for(int i = 0; i < n; i++) {
		if(visited[i] == false) {
			printdfs(i, edges, n, visited);
		}
	}
	
	// free memory
	for(int i = 0; i < n; i++)
		delete [] edges[i];
	delete [] edges;
	delete [] visited;
}
