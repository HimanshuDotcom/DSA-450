#include<iostream>
#include<string>
using namespace std;

void printSubsequence(string input, string output) {
	if(input.size() == 0) {
		cout << output << " ";
		return;
	}
	printSubsequence(input.substr(1), output + input[0]);
	printSubsequence(input.substr(1), output);
}

void printSubsequence(string input) {
	string output = "";
	printSubsequence(input, output);	
}

int main() {
	string str;
	cin >> str;
	printSubsequence(str);
}
