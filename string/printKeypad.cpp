
string alphabets[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void printKeypad(int num, string output[]) {
	if(num == 0) {
		cout << output << endl;
		return;
	}
	int lastDigit = num % 10;
	string lastDigitString = alphabets[lastDigit];
	for(int i = 0; i < lastDigitString.size(); i++) {
		printKeypad(num/10, lastDigitString[i] + output);
	}
}

void printKeypad(int num) {
	string output = "";
	printKeypad(num, output);
}
