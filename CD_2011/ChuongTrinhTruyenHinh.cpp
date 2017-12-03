#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fi("ChuongTrinhTruyenHinh.inp");

struct Node
{
	int x, y;
};

int n;
Node a[50010];

void output() {
	for(int i = 0; i < n; i++) {
		cout << a[i].x << " " << a[i].y;
		cout << endl;
	}
}

bool cmp(Node a, Node b) {
	if(a.x > b.x){
		return false;
	}
	return true;
}

void input() {
	fi >> n;
	for(int i = 0; i < n; i++) {
		fi >> a[i].x >> a[i].y;
	}
	output();
	sort(a,a+n, cmp);
	output();
	
}

main() {
	input();
}