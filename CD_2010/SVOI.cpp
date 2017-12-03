#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fi("SVOI.inp");

struct baitoan {
	int a, b, c, d;
};

int n, a, b;
baitoan bt[1010];

void output() {
	for(int i=0; i < n; i++) {
		cout << bt[i].a << " " << bt[i].b << " " <<  bt[i].c << " " <<  bt[i].d << endl;
	}
}

int cmp(baitoan a, baitoan b) {
	if(a.a > b.a){
		return false;
	}
	if(a.a == b.a) {
		if(a.b > b.b) {
			return false;
		}
		if(a.b == b.b) {
			if(a.c < b.c) {
				return false;
			}
			if(a.c == b.c) {
				if(a.d < b.d) {
					return false;
				}
			}
		}
	}
	return true;
}

void solve() {
	sort(bt, bt+n, cmp);
	output();
	int d = 0;
	int index = 0;
	baitoan bt2[1010];
	int i = 0;
	while(i < n) {
		if(a >= bt[i].a  && b >= bt[i].b) {
			d++;
			a += bt[i].a;
			b += bt[i].b;
		}
		else {
			bt2[index++] = bt[i];
		}
		i++;
		if(i == n) {
			*bt = *bt2;
			n = index;
			i = 0;
			index = 0;
		}
	}
	cout << d << endl;
}

void input() {
	fi >> n >> a >> b;
	for(int i=0; i < n; i++) {
		fi >> bt[i].a >> bt[i].b >> bt[i].c >> bt[i].d;
	}
}

main() {
	input();
	solve();
}
