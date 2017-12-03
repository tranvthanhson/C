#include <iostream>

using namespace std;

int n, k;
int a[100000], t[100000];

void input() {
	cin >> n >> k;
	for(int i=0; i<k; i++) {
		a[i] = i+1;
		t[i] = 0;
	}
}

void output() {
	for(int i=0; i<k; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void solve2(int index) {
	if(index == k) {
		output();
		return;
	}
	for(int i = 0; i < n; i++) {
		a[index] = i+1;
		solve2(index+1);
		t[index] = 1;
	}
}

void solve() {
	for(int i = 0; i < n; i++) {
		a[i] = i+1;
		solve2(i+1);
		t[i] = 1;
	}
}

main() {
	input();
	solve();
}
