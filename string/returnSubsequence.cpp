#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int returnSubsequence(string str, string output[]) {
	if(str.size() == 0) {
		output[0] = "";
		return 1;
	}
	int outputSize = returnSubsequence(str.substr(1), output);
	for(int i = 0; i < outputSize; i++) {
		output[i+outputSize] = str[0] + output[i];
	} 
	return 2*outputSize;
}
void returnSubsequence(string str) {
	int outputSize = pow(2, str.size());
	string *output = new string[outputSize];
	int size = returnSubsequence(str, output);
	for(int i = 0; i < size; i++)
		cout << output[i] << " ";
	cout << endl;
	cout << size;
	
}
int main() {
	string str;
	cin >> str;
	returnSubsequence(str);
}
