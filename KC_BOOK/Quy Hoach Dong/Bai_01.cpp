#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long ll;

ifstream fi("Bai_01.inp");

ll c, n, a[10000];

void input() {
	fi >> c >> n;
	for(ll i=0; i<n; i++) {
		fi >> a[i];
	}
	sort(a,a+n);
	for(ll i=0; i<n; i++) {
		cout << a[i] << " ";
	}
}

main() {
	input();
}
