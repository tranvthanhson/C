#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("LongestPalindromicSubsequence.inp");

string s;
int length;
int a[1000][1000];

void output() {
	cout << "  ";
	for(int i=0; i < length; i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < length; i++) {
		for(int j=0; j < length; j++) {
			if(j == 0) {
				cout << s[i] << " ";
			}
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int maxx(int a, int b) {
	return (a > b)? a : b;
}

void solve() {
	length = s.length();
	int i = 0, j = 0;
	int index = j;
	while(i < length && j < length){
		if(i > j){
			continue;
		}
		else {
			if(i == j) {
				a[i][j] = 1;
			}
			else if(s[i] == s[j]) {
				a[i][j] = a[i+1][j-1] + 2;
			}
			else {
				a[i][j] = maxx(a[i][j-1], a[i+1][j]);
			}

		}
		i++;
		j++;
		if(i == 0 && j == length){
			break;
		}
		if(j == length) {
			i = 0;
			j = ++index;
		}
	}
	output();
}

void input() {
	fi >> s;
}

main() {
	input();
	solve();
}