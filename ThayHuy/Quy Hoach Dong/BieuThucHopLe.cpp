#include <iostream>

using namespace std;

string s = "(()()())";


void xoa(int index) {
	s = s.substr(0,index) + s.substr(index+1);
}

void solve() {
	int stack = 0;
	int k = 0;
	int n = 0;
	int length = s.length();
	for(int i = 0; i < length; i++) {
		if(s[i] == '(') {
			stack++;
			n++;
			if(stack > k) k = stack;
		}
		else{
			stack--;
		}
	}
	cout << "n: " << n << endl;
	cout << "k: " << k << endl;
}

main() {
//	xoa(0);
//	cout<<s;
	solve();
}
