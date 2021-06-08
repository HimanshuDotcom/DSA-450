#include<string>

class TrieNode {
	public:
		
		char data;
		TrieNode** children;
		bool isTerminal;
		
		TrieNode(char data) {
			this -> data = data;
			children = new TrieNode*[26];  // a to z 26 alphabets
			for(int i = 0; i < 26; i++)
				children[i] = NULL;
				isTerminal = false;
		}
};

class Trie {
	TrieNode* root;
	
	void insertWord(TrieNode *root, string word) {
		if(word.length() == 0) {
			root -> isTerminal = true;
			return;
		}
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] == NULL) {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}
		else 
			child = root -> children[index];
			
		insertWord(child, word.substr(1));
	}
	
	bool searchWord(TrieNode *root, string word) {
		if(word.length() == 0) 
			return root -> isTerminal;
		int index = word[0] - 'a';
		if(root -> children[index] == NULL)
			return false;
		return searchWord(root -> children[index], word.substr(1));
			
	}
	
	void removeWord(TrieNode *root, string word) {
		if(word.length() == 0) {
			root -> isTerminal = false;
			return;
		}
		int index = word[0] - 'a';
		TrieNode *child = root -> children[index];
		if(child == NULL)
			return;
		removeWord(child, word.substr(1));
			
		// Remove child from tree if it is useless	
		if(child -> isTerminal == false) {
			for(int i = 0; i < 26; i++) {
				if(child -> children[i] != NULL)
					return;
			}
			delete child;
			root -> children[index] = NULL;
		}
			
	}
	
	public :
		Trie() {
			root = new TrieNode('\0'); 
		}
		
		void insertWord(string word) {
			insertWord(root, word);
		}
		
		bool searchWord(string word) {
			return searchWord(root, word);
		}
		
		void removeWord(string word) {
			removeWord(root, word);
		}
};
