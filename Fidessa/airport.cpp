#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string arr[] = {"9:00", "9:40", "9:50", "11:00" ,"15:00" ,"18:00"};
	string dep[] = {"9:10","12:00","11:20", "11:30" ,"19:00", "20:00"};

	vector<int> Arrivals;
	vector<int> Departures;
	
	int n = sizeof(arr)/sizeof(arr[0]);
	int a = 0, d = 0, cg = 0, mg = 0;
	
	for(int i = 0; i < n ; i++){
		stringstream a(arr[i]);
		stringstream d(dep[i]);

		int hr,mins;
		char c;
		
		a >> hr >> c >> mins;
		Arrivals.push_back(hr*60+mins);

		d >> hr >> c >> mins;
		Departures.push_back(hr*60+mins);
	}
	
	sort(Departures.begin(),Departures.end());
	
	while(a < n){
		if(Arrivals[a] < Departures[d]){
			cg++;
			a++;	
		}
		else{
			cg--;
			cg = max(cg,0);
			d++;
		}
		mg = max(cg,mg);
	}
	
	cout << mg << endl;
}
