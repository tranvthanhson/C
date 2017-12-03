#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int n;
map<string,int> m;

void input() {
	cin >> n;
	string temp;
	for(int i=0; i<n; i++){
		cin >> temp;
		m[temp]++;
	}
	int s = 0;
	int lan;
	for(map<string,int>::iterator it=m.begin(); it != m.end(); it++){
		lan = it->second;
		if(lan < 5){
			s += 100;
		}
		else{
			s += 100 + (lan-5);
		}
	}
	cout << s;
}

main() {
	input();
}
