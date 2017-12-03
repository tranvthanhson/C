#include <iostream>
//#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;

//ifstream fi("K.inp");

typedef long long ll;

ll n, m, a[10000], b[10000];

void input() {
	cin >> n >> m;
	for(ll i = 0; i < m; i++) {
		ll temp;
		cin >> temp;
		a[i] = temp;
		b[i] = temp;
	}
	ll index = n % m;
	cout << index << endl;	
	sort(b,b+m);
//	if(index == m) index--;
	ll s = b[index-1];
	
	cout << s <<endl;
	for(int i=0; i<m; i++) {
		if(a[i] == s) {
			cout << i+1;
			break;
		}
	}
}

main() {
	input();
}
