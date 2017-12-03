#include <iostream>

using namespace std;

typedef long long ll;

ll s = 0;
string str;

void input() {
	cin >> str;
	for(int i=0; i<str.length(); i++){
		s += (int)(str[i] - '0');
	}
	cout << s;
}

main() {
	input();
}
