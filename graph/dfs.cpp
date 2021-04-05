#include<iostream>
using namespace std;

void printDFS(int **edges, int n, int start, bool *visited) {
	if(n == 0) return;
	cout << start << " ";
	visited[start] = true;
	for(int i = 0; i < n; i++) {
		if(start != i && visited[i] == false && edges[start][i] == 1) {
			visited[i] = true;
			printDFS(edges,n,i,visited);
		}
	}
}
int main() {
	int vertices;
	int edge;
	cin >> vertices >> edge;
	int **edges = new int*[vertices];
	for(int i = 0; i < vertices; i++) {
		edges[i] = new int[vertices];
		for(int j = 0; j < vertices; j++)
			edges[i][j] = 0;
	}
	for(int i = 0; i < edge; i++) {
		int s;
		int e;
		cin >> s >> e;
		edges[s][e] = 1;
		edges[e][s] = 1;
	}
	bool *visited = new bool(vertices);
	for(int i = 0; i < vertices; i++)
		visited[i] = false;
	printDFS(edges, vertices, 0, visited);
	
	// free memory
	delete [] visited;
	for(int i = 0; i < vertices; i++)
		delete [] edges[i];
	delete [] edges;
}
