#include<vector>
#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
	 unordered_map<int,bool> visited;
	 unordered_map<int,int> indexOfElement;
	 for(int i = 0; i < n; i++) {
         visited[arr[i]] = false;
         indexOfElement[arr[i]] = i;
     }
    int startIndex = 0;
    int maxLen = 1;
    for(int i = 0; i < n; i++) {
        int curr = arr[i];
        int len = 1;
        // greater
        int temp1 = curr + 1;
        while(visited.count(temp1) > 0 && visited[temp1] == false) {
            visited[temp1] = true;
            temp1++;
            ++len;
        }
        
        // smaller
        temp1 = curr - 1;
        while(visited.count(temp1) > 0 && visited[temp1] == false) {
            visited[temp1] = true;
            --temp1;
            ++len;
        }
        
        int index = indexOfElement[temp1+1];
        if(len > maxLen) {
            maxLen = len;
            startIndex = index;
        }
        else if(len == maxLen && index < startIndex) {
            startIndex = index;
        }
    }
    vector<int> result;
    result.push_back(arr[startIndex]);
    if(maxLen > 1)
        result.push_back(arr[startIndex] + maxLen - 1);
    return result;

}
