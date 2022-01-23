
// Check a cycle in graph using both bfs and dfs

// ---------------------- BFS -------------------

	bool bfs(int src, vector<int> adj[], vector<bool> &visited) {
	    queue<pair<int,int>> q;
	        
	    visited[src]=true;
	    q.push({src,-1});
	        
	    while(!q.empty()) {
	        int cur=q.front().first;
	        int parent=q.front().second;
	        q.pop();
	            
	        for(auto data: adj[cur]) {
	            if(!visited[data]){
	                visited[data]=true;
	                q.push({data,cur});
	            }
	            else if(data!=parent){
	                return true;
	            }
	        }
	    }
	        return false;
    }
    
    // ---------------------------------------- DFS -------------------------------------
    
    bool dfs(int st, vector<int> adj[], int parent, vector<bool> &visited) {
        visited[st] = true;
        for(int i = 0; i < adj[st].size(); i++) {
            if(visited[adj[st][i]]) {
                if(parent != adj[st][i]) return true;
			}
            else 
                if(isCycle(adj[st][i],adj, st, visited)) return true;
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(bfs(i,adj,visited)) {
                    return true;
                }
            }
        }
        return false;
    }
