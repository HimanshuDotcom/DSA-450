#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void primsMST(vector<vector<int> > &edges, int n) {
	vector<int> weights(n, INT_MAX);
	vector<int> parents(n, -1);
	vector<bool> visited(n, false);
	weights[0] = 0;
	
	int start = 0, count = 0;
	int minIndex = -1, minWeight = INT_MAX;;
	
	for(int count = 0; count < n-1; count++) {
		visited[start] = true;
		for(int i = 0; i < n; i++) {
			if(!visited[i] && edges[start][i] != 0) {
				// to check weight of neighbouring index and update their parent & weight
				if(weights[i] < edges[start][i]) {
					parent[i] = start;
					weights[i] = edges[start][i];
				}
				
				// for neighbouring minWeight index
				if(weights[i] < minWeight) {
					minWeight = weights[i];
					minIndex = i;
				}
			}
		}
		start = minIndex;
	}	
	
	//  printing final MST
	for(int i = 1; i < n; i++) 
		cout << min(parent[i], i) << " " << max(parent[i], i) << " " << weights[i] << endl;
}

int main() {
	int n, e;
	cin >> n >> e;
	vector<vector<int> > edges(n, vector<int>(v,0));
	
	for(int i = 0, s, d, w; i < n; i++) {
		cin >> s >> d >> w;
		edges[s][d] = w;
		edges[d][s] = w;
	}
	primsMST(edges, n);
}
