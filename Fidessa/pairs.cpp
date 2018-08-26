#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isUpper(char c)
{
	if(c >= 'A' && c <= 'Z')
		return true;
	else
		return false;	
}

bool isLower(char c)
{
	if(c >= 'a' && c <= 'z')
		return true;
	else
		return false;	
}

int main()
{
	string str = "ABbadD";
	
	if(!isUpper(str[0]))
		cout << "String doesnt start with Capital Letter" << endl;
	
	stack<char> S;
	int ret = 0;
	
	for(int i = 0;i < str.size();++i){
		if(isUpper(str[i])){
			S.push(str[i]);
		}
		else{
			if(!S.empty()){
				char top = S.top();
				S.pop();
				if(top == (str[i] - 32)){
					ret = i;
				}
				else{
					break;	
				}
			}
		}
	}
	
	cout << ret << endl;
}
