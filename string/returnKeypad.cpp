

int returnKeypad(int num, string alphabets[], string output[] ) {
	if(num <= 0) {
		output[0] = "";
		return 1;
	}
	int lastDigit = num % 10;
	string smallOutput[500];
	int smallOutputSize = returnKeypad(num / 10, alphabets, smallOutput);
	string appendString = alphabets[lastDigit];
	int ptr = 0;
    for(int i = 0; i < appendString.size(); i++) {
        for(int j = 0; j < smallOutputSize; j++,ptr++)
            output[ptr] = smallOutput[j] + appendString[i]; 
    }
    return ptr;
}

int returnKeypad(int num, string output[]) {
	string alphabets[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	return returnKeypad(num, alphabets, output);
}

