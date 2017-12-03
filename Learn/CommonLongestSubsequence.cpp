#include <iostream>
#include <string>

using namespace std;

string a = " abcdaf";
string b = " acbcf";
int arr[1000][1000];

int max(int a, int b) {
	return (a>b)? a:b;
}

output() {
	cout << "  ";
	for(int j = 0; j < a.length(); j++) {
		cout << a[j] << " ";
	}
	cout << endl;
	for(int i = 0; i < b.length(); i++) {
		for(int j = 0; j < a.length(); j++) {
			if(j == 0){
				cout << b[i] << " "; 
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

solve() {
	for(int i=1; i < b.length(); i++) {
		for(int j=1; j < a.length(); j++) {
			if(a[j] == b[i]) {
				arr[i][j] = arr[i-1][j-1] + 1;
			}
			else {
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
			}
		}
	}
}

main() {
	solve();
	output();
}
