#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string rom = "MCIIIIIIV";
	vector<int> ints;
	int d = 0;	
	for(auto i = rom.begin() ; i!= rom.end() ; ++i){
		switch(*i){
			case 'I':
				ints.push_back(1);
				break;	
			case 'V':
				ints.push_back(5);
				break;	
			case 'X':
				ints.push_back(10);
				break;	
			case 'C':
				ints.push_back(100);
				break;	
			case 'D':
				ints.push_back(500);
				break;	
			case 'M':
				ints.push_back(1000);
				break;
			default:
				cout << "Wrong Data" << endl;
				break;					
		}
	}
	
	cout << "Reverse" << endl;
	for(auto i = ints.rbegin(); i != ints.rend(); ++i)
		cout << *i << " ";

	cout << endl;
	cout << "Normal" << endl;
	for(auto i = ints.begin(); i != ints.end(); ++i)
		cout << *i << " ";
	cout << endl;
	
	int size = ints.size();
	
	d = ints[size-1];
	
	for(int i = size-1;i > 0;i--){
		if(ints[i] > ints[i-1])
			d = d - ints[i-1];
		if(ints[i] <= ints[i-1])
			d = d + ints[i-1];	
	}
	
	cout << "Answer: "<< d << endl;
}

