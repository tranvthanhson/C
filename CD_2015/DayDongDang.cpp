#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fi("DayDongDang.inp");

int t, n, a[10010], b[10010];

bool check(int a1, int a2, int b1, int b2){
	if(a1 < a2 && b1 < b2) return true;
	if(a1 == a2 && b1 == b2) return true;
	if(a1 > a2 && b1 > b2) return true;
	return false;
}
// reset mang
void solve() {
	for(int i=0; i < n - 1; i++) {
		for(int j=i+1; j<n; j++){
			if(!check(a[i],a[j],b[i],b[j])) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

void input() {
	fi >> t;
	while(t--) {
		fi >> n;
		for(int i=0; i<n; i++) {
			fi >> a[i];
		}
//		for(int i=0; i<n; i++) {
//			cout << a[i] << " ";
//		}
//		cout << endl;
		for(int i=0; i<n; i++) {
			fi >> b[i];
		}
//		for(int i=0; i<n; i++) {
//			cout << b[i] << " ";
//		}
//		cout << endl;
		solve();
	}
}

main() {
	input();
}
