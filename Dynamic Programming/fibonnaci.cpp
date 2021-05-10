#include<iostream>
using namespace std;

int fibonnaci(int n) {
	int *arr = new int[n+1];
	for(int i = 0; i < n+1; i++)
		arr[i] = 0;
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i < n+1; i++) {
		arr[i] = arr[i-1] + arr[i-2];
	}
	int res = arr[n];
	delete [] arr;
	return res;
}

int main() {
	int n;
	cout << "Enter the number" << endl;
	cin >> n;
	cout << n << "th number is" << endl;
	cout << fibonnaci(n);
}

