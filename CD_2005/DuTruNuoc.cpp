#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long ll;

ifstream fi("DuTruNuoc.inp");

ll n, s = 0, a[1010];

void solve() {
	sort(a, a+n);
	for(int i=0; i<n; i++) {
		s-= a[i];
		if(s == 0){
			cout << n-i-1<< endl;
			return;
		}
		if(s < 0) {
			cout << n-i << endl;
			return;
		}
	}
}

void input() {
	fi >> n;
	ll temp;
	for(int i = 0; i < n; i++) {
		fi >> temp;
		s += temp;
		fi >> a[i];
	}
	solve();
}

main() {
	input();
}
