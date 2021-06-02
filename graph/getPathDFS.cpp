#include <iostream>
#include<vector>
using namespace std;

void getDFS(int start, int n, int **edges, int end, bool *visited, vector<int> &result) {
    if(start == end) {
        result.push_back(start);
        return;
    }
    
    visited[start] = true;
   
    for(int i = 0; i < n; i++) {
        if(edges[start][i] == 1 && visited[i] == false) {
            getDFS(i, n, edges, end, visited, result);
             if(result.size() != 0) {
        		result.push_back(start);
                return; 
             }
        }
            
    }
   
}

int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
            edges[i][j] = 0;
    }
    
    for(int i = 0; i < e; i++) {
        int start, end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }
    
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;
    
    int v1, v2;
    cin >> v1 >> v2;
    
    vector<int> result;
    getDFS(v1, n, edges, v2, visited, result);
    
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    
}
