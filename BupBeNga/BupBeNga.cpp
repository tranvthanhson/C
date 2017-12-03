#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fi("BupBeNga.inp");

struct bupbe{
	int h,w;
};

int t, n;
bupbe a[1000];

bool cmp(bupbe a, bupbe b) {
	if(a.w <= b.w && a.h >= b.h){
		return false;
	}
	return true;
}

void input() {
	fi >> t;
	for(int i=0; i < t; i++) {
		fi >> n;
		for(int j=0; j < n; j++) {
			fi >> a[j].w >> a[j].h;
			
		}
		sort(a,a+n,cmp);
		for(int j=0; j < n; j++) {
			cout << a[j].w << " " << a[j].h << " ___ ";	
		}
		cout << endl;
	}
}

main() {
	input();
}