#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

int m, n, nam = 0, nu = 0;
string s;
void input() {
	cin >> m >> n;
	cin >> s;
	s += s[0];
	for(int i=0; i<s.length()-1; i++){
		if(s[i] == s[i+1]){
			if(s[i] == '0') nam++;
			else nu++;
		}
	}
	int d = nam-nu;
	d = (d > 0)? d:-d;
	cout << d;
}

main() {
	input();
}
