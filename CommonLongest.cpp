#include <iostream>
#include <string>

using namespace std;

//string a = " abcdaf";
//string b = " acbcf";
string a = " abcdaf";
string b = " fa";
int arr[10010][10010];

int maxx(int a, int b) {
	return (a>b)? a:b;
}

void in(){
	string rs = "";
	int i = b.length()-1;
	for(int j = a.length()-1; j >= 0, i >=0;) {
		int x = arr[i-1][j-1];
		int y = arr[i-1][j];
		int z = arr[i][j-1];
		int t = arr[i][j];
		if(t == z){
			j--;
		}
		else if(t == y){
			i--;
		}
		else{
			rs = a[j] + rs;
			i--;
			j--;
		}
	}
	cout << rs.substr(1) << endl;
}

void solve() {
	string rs = "";
	int d = 0;
	for(int i=1; i<b.length(); i++) {
		for(int j=1; j<a.length(); j++) {
			if(a[j] == b[i]) {
				arr[i][j] = arr[i-1][j-1] + 1;
				rs += b[i];
				d++;			
			}
			else{
				arr[i][j] = maxx(arr[i-1][j], arr[i][j-1]);
			}
		}
	}
//	cout << d << endl;
//	cout << rs << endl;
//	in();
}

void init() {
	cout << "  ";
	for(int i=0; i < a.length(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for(int i=0; i < b.length(); i++) {
		arr[i][0] = 0;
	}
	for(int i=0; i < a.length(); i++) {
		arr[0][i] = 0;
	}
	for(int i=0; i < b.length(); i++) {
		for(int j=0; j < a.length(); j++) {
			if(j == 0) {
				cout << b[i] << " ";
			}
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

main() {
	solve();
	init();
}
