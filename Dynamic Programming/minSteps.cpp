#include<iostream>
using namespace std;

//1.) Subtract 1 from it. (n = n - ­1) ,
//2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
//3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ). 
 
int minStepsToOne(int n) {
	int *arr = new int[n+1];
	arr[0] = 0;
	arr[1] = 0;
	for(int i = 2; i < n+1; i++) {
		arr[i] = arr[i-1];
		if(i % 2 == 0) res = min(arr[i],arr[i/2]);
		if(i % 3 == 0) res = min(arr[i],arr[i/3]);
		arr[i] += 1;
	}
	int res = arr[n];
	delete [] arr;
	return res;
}
int main() {
	int n;
	cout << "Enter the number" << endl;
	cin >> n;
	cout << minStepsToOne(n) << endl;
	
}
