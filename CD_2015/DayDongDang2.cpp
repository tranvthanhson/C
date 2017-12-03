#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fi("DayDongDang.inp");

int t, n;

struct node{
	int gt, vt;
};

node a[10010], b[10010];

//bool check(int a1, int a2, int b1, int b2){
//	if(a1 < a2 && b1 < b2) return true;
//	if(a1 == a2 && b1 == b2) return true;
//	if(a1 > a2 && b1 > b2) return true;
//	return false;
//}

bool cmp(node a, node b){
	if(a.gt < b.gt) {
		return true;
	}
	if(a.gt == b.gt) {
		if(a.vt < b.vt) {
			return true;
		}
	}
	return false;
}

// reset mang
void solve() {
	sort(a,a+n,cmp);
	sort(b,b+n,cmp);
	for(int i=0; i < n; i++) {
		if(a[i].vt != b[i].vt){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

void input() {
	fi >> t;
	while(t--) {
		fi >> n;
		for(int i=0; i<n; i++) {
			fi >> a[i].gt;
			a[i].vt = i;
		}
//		for(int i=0; i<n; i++) {
//			cout << a[i] << " ";
//		}
//		cout << endl;
		for(int i=0; i<n; i++) {
			fi >> b[i].gt;
			a[i].vt = i;
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
