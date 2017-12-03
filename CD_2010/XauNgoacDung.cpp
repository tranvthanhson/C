#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fi("XauNgoacDung.inp");

string s;

bool check(string s) {
	stack<char> st;
	for(int i=0; i < s.length(); i++) {
		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
			st.push(s[i]);
		}
		else {
			if(st.empty()){
				return false;
			}
			if(s[i] == ')' && st.top() == '('){
				st.pop();
			}
			else if(s[i] == ']' && st.top() == '['){
				st.pop();
			}
			else if(s[i] == '}' && st.top() == '{'){
				st.pop();
			}
			else {
				return false;
			}
		}
	}
	if(!st.empty()){
		return false;
	}
	return true;
}

void solve() {
	for(int i=0; i < s.length(); i++){
		s = s.substr(1) + s.substr(0,1);
		cout << s << endl;
		if(check(s)) {
			cout << i+1;
			return;
		}
	}
	cout << -1 << endl;
}

void input() {
	fi >> s;
}

main() {
	input();
	solve();
}
