#include<stack>
void reverseStack(stack<int> &input, stack<int> &extra) {
	// base case
    if(input.empty())
        return;
        
    int top = input.top();
    input.pop();
    reverseStack(input, extra);   // recurssion
    
    // empty reversed input stack into extra
    while(!input.empty()) {
        extra.push(input.top());
        input.pop();
    }
    
    // add topmost stack element
    input.push(top);
    
    // empty extra stack into input
    while(!extra.empty()) {
        input.push(extra.top());
        extra.pop();
    }
    
}
