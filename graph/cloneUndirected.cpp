/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int val) {
        this -> val = val;
        neighbors = vector<Node*>();
    }
    Node(int val, vector<Node*> neighbors) {
        this -> val = val;
        this -> neighbors = neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL; 
        queue<Node*> pending; // for input graph
        pending.push(node);
        vector<Node*> visited(101,NULL); // to save the nodes
        visited[node->val] = new Node(node->val);
        while(!pending.empty()) {
            Node* fr = pending.front();
            Node *root = visited[fr->val];
            pending.pop();
            for(int i = 0; i < fr -> neighbors.size(); i++) {
                if(visited[fr->neighbors[i]->val] == NULL) {
                    pending.push(fr->neighbors[i]);
                    Node *newnode = new Node(fr->neighbors[i]->val);
                    visited[fr->neighbors[i]->val] = newnode;
                    root->neighbors.push_back(newnode);
                }
                else {
                    root -> neighbors.push_back(visited[fr->neighbors[i]->val]);
                }
            }
        }
        return visited[1];
    }
};
