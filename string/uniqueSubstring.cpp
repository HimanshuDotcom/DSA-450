


int longestUniqueSubsttr(string s){
    vector<int> count(26,-1);
    int maxLen = 0, i = 0, j = 0, currLen = 0;
    
    while(j < s.size()) {
        int index = s[j] - 'a';
        // if char is already seen   
        if(count[index] != -1 && count[index] >= i) {
            i = count[index] + 1;
            currLen = j - i;
        }
        count[index] = j;
        currLen++;
        j++;
        maxLen = max(currLen, maxLen);
    }
    
    return maxLen;
        
}
