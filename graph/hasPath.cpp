#include <iostream>
using namespace std;

bool haspath(int **edges, int n, int start, int end, bool *visited) {
    if(start == end || edges[start][end]) return true;
    visited[start] = true;
    for(int i = 0; i < n; i++) {
        if(start != i && !visited[i] && edges[start][i]) {
             if(haspath(edges, n, i, end, visited))
             	return true;
        }
	}
    return false;
}
int main() {
    // Write your code here
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
            edges[i][j] = 0;
    }
    for(int i = 0; i < e; i++) {
        int s;
        int e;
        cin >> s >> e;
        edges[s][e] = 1;
        edges[e][s] = 1;
    }
    int v1, v2; // vertex to check path in b/w
    cin >> v1 >> v2;
    
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;
    cout << (haspath(edges,n,v1,v2,visited))? "true" : "false";
	
	// free memory
	for(int i = 0; i < n; i++) 
		delete [] edges[i];
	delete [] edges;
	delete [] visited;
}
