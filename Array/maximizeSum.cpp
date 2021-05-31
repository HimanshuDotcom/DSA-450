
/* -------- Given 2 sorted arrays (in increasing order), find a path through the intersections 
		that produces maximum sum and return the maximum sum ------------------- */

#include<iostream>
using namespace std;

int maximizeSum(int arr1[], int arr2[], int size1, int size2) {
	int maxSum = 0;
	int sum1 = 0, sum2 = 0;
	int i = 0, j = 0;
	while(i < size1 && j < size2) {
		if(arr1[i] < arr2[j]) {
			sum1 += arr1[i];
			++i;
		}
		else if(arr2[j] < arr1[i]) {
			sum2 += arr2[j];
			++j;
		}
		else {
			sum1 += arr1[i];
			sum2 += arr1[i];
			maxSum += max(sum1, sum2);
			sum1 = 0;
			sum2 = 0;
			++i;
			++j;
		}
	}
	while( i < size1)
		sum1 += arr1[i++];
	while(j < size2)
		sum2 += arr2[j++];
	maxSum += max(sum1, sum2);
	return maxSum;
}

int main() {
	int arr1[100], arr2[100];
	int size1, size2;
	cin >> size1 >> size2;
	for(int i = 0; i < size1; i++)
		cin >> arr1[i];
	for(int i = 0; i < size2; i++)
		cin >> arr2[i];
	
	cout <<  maximizeSum(arr1, arr2, size1, size2);
}
