
void helper(Node *root, int dist, map<int, vector<int> > &res) {
        if(root == NULL)
            return;
        res[dist].push_back(root -> data);
        helper(root -> left, dist-1, res);
        helper(root -> right, dist+1, res);
    }
 
vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int, vector<int> > result;
        helper(root, 0, result);
        vector<int> ans;
        for(auto p : result) {
            vector<int> v = p.second;
            for(auto ch : v)
            	ans.push_back(ch);
        }
        return ans;
            
   
    }
