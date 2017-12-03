#include <iostream>
#include <string.h>
//#include <fstream>
#include <map>

using namespace std;

//ifstream fi("PalindromeSubstring.inp");

typedef long long ll;

string s;
ll t;

void solve() {
	map<string,int> m;
	map<string,int>::iterator it;
	int length = s.length();
	int index1, index2, index3;
	for(int i = 0; i < length; i++) {
//		for(int j = 0; j < length; j++) {
//			index1 = i + j;
//			index2 = i - j;
//			if(index1 == length || index2 < 0) break;
//			if(s[index1] == s[index2]) {
//				m[s.substr(index2, j) +s.substr(i, j+1)]++;
//			}
//			else {
//				break;
//			}
//		}
		for(int j = 0; j < length; j++) {
			index1 = i + j + 1;
			index2 = i - j;
			if(index1 == length || index2 < 0) break;
			if(s[index1] == s[index2]) {
				m[s.substr(index2, j) +s.substr(i, j+1)]++;
			}
			else {
				break;
			}
		}
	}
//	for(it = m.begin(); it != m.end(); it++) {
//		cout << it->first << endl;
//	}
	cout << m.size() << endl;
}

bool doiXung(string s) {
	int length = s.length();
	for(int i=0; i <= length / 2 ; i++) {
		if(s[i] != s[length-i-1]){
			return false;
		}
	}
	return true;
}

void solve2() {
	map<string,int> m;
	map<string,int>::iterator it;
	int length = s.length();
	for( int i = 0; i < length; i++) {
		for( int j=1; j<=length; j++) {
			if(i+j>length) break;
			string temp = s.substr(i,j);
			if(doiXung(temp)) 
				m[temp]++;
		}
	}
	for(it = m.begin(); it != m.end(); it++) {
		cout << it->first << endl;
	}
	cout << m.size() << endl;
}

void input() {
	cin >> t;
	for(int i = 0; i < t; i++) {
		cin >> s;
//		solve();
		solve2();
	}
	
}



main() {
	input();
//	solve();
//	string s = "thanhson";
//	cout<<s.substr(3,1);
}
