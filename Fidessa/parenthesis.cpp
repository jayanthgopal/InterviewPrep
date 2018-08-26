#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// function to check if paranthesis are balanced
bool ParanthesisBalanced(string expr)
{
    stack<char> s;
    char x;
 
    // Traversing the Expression
    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }
 
        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
           return false;
 
        switch (expr[i])
        {
        case ')':
 
            // Store the top element in a
            x = s.top();
            s.pop();
            if (x=='{' || x=='[')
                return false;
            break;
 
        case '}':
 
            // Store the top element in b
            x = s.top();
            s.pop();
            if (x=='(' || x=='[')
                return false;
            break;
 
        case ']':
 
            // Store the top element in c
            x = s.top();
            s.pop();
            if (x =='(' || x == '{')
                return false;
            break;
        }
    }
 
    // Check Empty Stack
    return (s.empty());
}

bool areParanthesisBalanced(string expr)
{
	if(expr[0] == ')' || expr[0] == ']' || expr[0] == '}')
		return false;
	
	stack<char> S;
		 
	for(int i = 0; i < expr.size();++i){
		if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{'){
			S.push(expr[i]);
			continue;	
		}
	
		if (S.empty())
           return false;
		else{
			if(!S.empty()){
				char top = S.top();
				S.pop();
				
				if(expr[i] == ')'){
					if(top != '(')
						return false;
				}
				if(expr[i] == ']'){
					if(top != '[')
						return false;
				}
				if(expr[i] == '}'){
					if(top != '{')
						return false;
				}
			}
		}
	}

	return (S.empty());
}

// Driver program to test above function
int main()
{
    string expr = "{()}[]}";
 
    if (areParanthesisBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}
