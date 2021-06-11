#include<cstring>

void reverseString(char input[], int i, int j) {
	while(i < j) 
		std::swap(input[i++], input[j--]);
}

void reverseStringWordWise(char input[]) {
	
	int prevIndex = 0,
	len = strlen(input),
	i = 0;
	// reverse each word
	while(i < len) {
		if(input[i+1] == '\0' || input[i+1] == ' ') {
			reverseString(input, prevIndex, i);
			prevIndex = i+2;
		}
		i++;
	}
	
	// reverse whole string
	reverseString(input, 0, len-1);
}
