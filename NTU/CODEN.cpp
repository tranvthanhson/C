#include <iostream>

using namespace std;

int m, n, d = 0;

main() {
	cin >> m >> n;
	int min = (m < n)? m:n;
	min = (min % 2 == 0)? min : min - 1;
	d = min / 2;
	d = d*d;
	m -= min;
	n -= min;
	d += n/2 + m/2;
	cout << d;
}
