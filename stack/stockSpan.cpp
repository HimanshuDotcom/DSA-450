#include<stack>
int* stockSpan(int *price, int size)  {
	// Write your code here
    stack<int> s1;
    int* output = new int[size];
    output[0] = 1;
    s1.push(0);
    
    for(int i = 1; i < size; i++) {    
        while(!s1.empty() && price[s1.top()] < price[i])
            s1.pop();
            
        if(s1.empty()) 
            output[i] = i+1;      
        else 
            output[i] = i-s1.top();
        
        s1.push(i);
    }
    
    return output;
}
