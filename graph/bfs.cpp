#include<iostream>
#include<queue>
using namespace std;

void printBFS(int **edges, int n, int start, bool *visited) {
	queue<int> pendingVertex;
	pendingVertex.push(start);
	visited[start] = true;
	while(!pendingVertex.empty()) {
		int front = pendingVertex.front();
		cout << front << " ";
		pendingVertex.pop();
		for(int i = 0; i < n; i++) {
			if(front != i && visited[i] == false && edges[front][i] == 1) {
				pendingVertex.push(i);
				visited[i] = true;
			}
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
	printBFS(edges, vertices, 0, visited);
	
	// free memory
	delete [] visited;
	for(int i = 0; i < vertices; i++)
		delete [] edges[i];
	delete [] edges; 
}
