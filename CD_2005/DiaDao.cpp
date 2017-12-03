#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("DiaDao.inp");

struct point{
	int re = 2;
	char di = 'F';
};

point p[110][110];
char huong;
int m, n, k, d, x, y;

void chuyenHuong(int h) {
	if(h != 2) {
		p[x][y].di = 'T';
	}
	if(huong == 'D') {
		if(h == 1){
			huong = 'N';
		}
		else if(h == 0){
			huong = 'B';
		}
		return;
	}
	if(huong == 'T') {
		if(h == 1){
			huong = 'B';
		}
		else if(h == 0){
			huong = 'N';
		}
		return;
	}
	if(huong == 'N') {
		if(h == 1){
			huong = 'T';
		}
		else if(h == 0){
			huong = 'D';
		}
		return;
	}
	if(huong == 'B') {
		if(h == 1){
			huong = 'D';
		}
		else if(h == 0){
			huong = 'T';
		}
		return;
	}
}

void di() {
	if(huong == 'D'){
		y++;
	}
	if(huong == 'T'){
		y--;
	}
	if(huong == 'N'){
		x++;
	}
	if(huong == 'B'){
		x--;
	}
}

void solve() {
//	cout << x << " _ " << y << " _ " << p[x][y].re <<endl;
	if(x < 0 || y < 0 || x >= n || y >= m || p[x][y].di == 'T'){
		cout << "D: " << d << endl; 
		return;
	}
	d++;
	chuyenHuong(p[x][y].re);
	di();
	solve();
}

void input() {
	fi >> m >> n >> k;
	int xx, yy, zz;
	for(int i=0; i<k; i++) {
		fi >> xx >> yy >> zz;
		p[yy][xx].re = zz;
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << p[i][j].re << " ";
		}
		cout << endl;
	}
	huong = 'D';
	d = 0;
	x = 0;
	y = 0;
	solve();
	huong = 'N';
	d = 0;
	x = 0;
	y = 0;
	solve();
}

main() {
	input();
}
