
#include <iostream>
#include<unordered_map>
using namespace std;

// find all continuous subarray count which sums to k

int bruteForceHousing(int *arr, int n, int k) {
    int count = 0;
    for(int i = 0; i < 11; i++) {
        int sum = 0;
        for(int j = i; j < 11; j++) {
            sum += arr[j];
            if(sum == k)
                count++;  
        }
    }
    return count;
} 

int prefixSumHousing(int *arr, int n, int k) {
    int count = 0;
    unordered_map<int,int> subsetSum;
    int currSum = arr[0];
    subsetSum[arr[0]] = 0; // store sum at each index as key
    for(int i = 1; i < n; i++) {
        currSum += arr[i];
        subsetSum[currSum] = i;
        if(subsetSum.count(currSum - k) > 0) 
            count++;
    }
    return count;
}

int slidingwindowHousing(int *arr, int n, int k) {
    int i = 0, j = 0;
    int currSum = arr[i];
    int count = 0;
    for(int j = 1; j < n; j++) {
        // reduce window size
        while(currSum > k && i < j)
            currSum -= arr[i++];
        // if window sum == k
        if(currSum == k)
            count++;
        // expand window to right
        currSum += arr[j];
    }
    return count;
}

int main() {
	// your code goes here
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << slidingwindowHousing(arr, n, k);
	return 0;
}


