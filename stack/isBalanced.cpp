

#include<stack>
bool isBalanced(string expression) 
{
    // Write your code here
    stack<char> brackets;
    for(ch : expression) {
        if(ch == '(')
            brackets.push(ch);
        else {
            if(brackets.empty())
                return false;
            brackets.pop();
        }
    }
    return brackets.empty();
}
