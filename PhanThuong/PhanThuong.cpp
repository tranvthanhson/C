#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ifstream fi("PhanThuong.inp");
ofstream fo("PhanThuong.out");

int n, m, a[10000][10000];
int rs[1000];

void output() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

double maxx(double a, double b) {
	return (a > b)? a:b;
}

double solve(int i, int j, int rs[], int index) {
	if(j == m-1){
		if(a[i][j] < 0) return a[i][j];
		return a[i][j];
	}
	if(i == 0) {
		if(a[i][j] < 0) {
			maxx(solve(i,j+1,rs),solve(i+1,j+1,rs)) / a[i][j];
		}
		maxx(solve(i,j+1,rs),solve(i+1,j+1,rs)) + a[i][j];
	}
	if(i == n-1) {
		if(a[i][j] < 0) {
			maxx(solve(i-1,j+1,rs), solve(i,j+1,rs)) / a[i][j];
		}
		maxx(solve(i-1,j+1,rs), solve(i,j+1,rs)) + a[i][j];
	}
	if(a[i][j] < 0) {
		maxx(maxx(solve(i-1,j+1,rs), solve(i,j+1,rs)),solve(i+1,j+1,rs)) / a[i][j];
	}
	maxx(maxx(solve(i-1,j+1,rs), solve(i,j+1,rs)),solve(i+1,j+1,rs)) + a[i][j];
}

void input() {
	fi >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			fi >> a[i][j];
		}
	}
	
}

main() {
	input();
//	output();
	cout << solve(0,0,rs,0) << endl;
}
