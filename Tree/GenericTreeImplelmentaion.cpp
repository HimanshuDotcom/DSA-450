#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/* ---------------------------- Note ------------------ 

	1. There are two function for take input of a tree.(Level Wise and Depth first)
	
    2. One function for print Tree.(Depth First)  // You can try level wise on you own  
    
	---------------------------End--------------------- */

template<typename T>
class TreeNode {
	
	public:
	T data;
	vector<TreeNode<T>*> children;
	
		TreeNode(T data) {
			this -> data = data;
		}
		
};

// Deep Node first
TreeNode<int>* takeInput() {
	int rootdata, numChild;
	cout << "Enter Data" << endl;
	cin >> rootdata;
	TreeNode<int> *root = new TreeNode<int>(rootdata);
	cout << "Enter no. of childrens" << endl;
	cin >> 	numChild;
	for(int i = 0; i < numChild; i++) {
		root -> children.push_back(takeInput());
	}
	return root;
}

// LevelWise input of tree
TreeNode<int>* levelWiseInput() {
	int rootdata;
	cout << "Enter root Data" << endl;
	cin >> rootdata;
	TreeNode<int> *root = new TreeNode<int>(rootdata);
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()) {
		TreeNode<int> *frontNode = pendingNodes.front();
		pendingNodes.pop();
		int numChild;
		cout << "Enter number of childrens of " << frontNode -> data << endl;
		cin >> numChild;
		for(int i = 0; i < numChild; i++) {
			cout << "Enter " << i << "th child of " << root -> data << endl;
			int childData;
			cin >> childData;
			TreeNode<int> *newnode = new TreeNode<int>(childData);
			root -> children.push_back(newnode);
			pendingNodes.push(newnode);
		}
	}
	return root;
}



void printTree(TreeNode<int>* root) {
	if(root == NULL) return;
	cout << root -> data << ":";
	for(int i = 0; i < root -> children.size(); i++) 
		cout << root -> children[i] -> data << ",";
	cout << endl;
	for(int i = 0; i < root -> children.size(); i++)
		printTree(root -> children[i]);
}

int main() {
	printTree(levelWiseInput());
}
