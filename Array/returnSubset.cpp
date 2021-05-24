


int returnSubset(int input[], int n, int output[][20]) {
    // Write your code here
    if(n == 0) {
        output[0][0] = 0; // storing size at first index
        return 1;
    }
    int smallOutput = returnSubset(input+1, n-1,output);
    for(int i = 0; i < smallOutput; i++) {
        output[i+smallOutput][0] = output[i][0] + 1;
        output[i+smallOutput][1] = input[0];
        for(int j = 1,k = 2; j <= output[i][0]; j++,k++) {
            output[i+smallOutput][k] = output[i][j];
        }
    }
    return smallOutput * 2;

}
