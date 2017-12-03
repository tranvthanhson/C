// 2640
#include <iostream>

using namespace std;

typedef long long ll;

ll bt = 0, tb = 0;

int abs(int n) {
	return (n > 0)? n : -n;
}

main() {
//	for(int i=1; i<=100; i++){
//		tb += i*i;
//		bt += i;
//	}
//	bt *= bt;
//	cout<<abs(bt-tb);
	ll a = 123;	
	ll b = 1000;
	ll s = 0;
	for(int i = a; i <= b; i++){
		s += i;
	}
	cout << s << endl;
	ll n = a * b;
	cout << n * (n + 1) / 2 << endl;
	cout << (a + b) * ( b - a + 1 ) / 2;
}
