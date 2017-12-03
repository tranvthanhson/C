#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ifstream fi("LongestIncreasingSubsequence.inp");

int a[1000], t[1000], n;

int maxx(int a, int b) {
	return (a > b)? a : b;
}

void output() {
	for(int i=0; i<n; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
	for(int i=0; i<n; i++) {
		cout << t[i] << "\t";
	}
	cout << endl << endl;
}

void solve() {
	int i = 0;
	for(int j = i+1; j<n; ) {
		cout << "Compare " << a[i] << " and " << a[j] << "" << endl;
		if(a[i] < a[j]){
			cout << "Less than" << endl;
			cout << "i: " << i << " and j : " << j << endl;
			t[j] = max(t[j], t[i] + 1);
			output();
		}
		else if(a[i] >= a[j]) {
			cout << "More than and i++" << endl;
			cout << "i: " << i << " and j : " << j << endl;
			output();
		}
		i++;
		if(i == j) {
			cout << "i == j" << endl;
			i = 0;
			j++;
		}
	}
}

void input() {
	fi >> n;
	for(int i=0; i<n; i++) {
		fi >> a[i];
		t[i] = 1;
	}
}

main() {
	input();
	solve();
	// output();
}