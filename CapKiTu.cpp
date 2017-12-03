#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("CapKiTu.inp");

int d[1000] = {0};
char a[1000] = {};
int n, index = 0;

void output(){
	int i = 0;
	while(d[i] == 1) {
		cout << a[i];
		i++;
	}
}

void input() {
	fi >> n;
	for(int i=0; i<n; i++) {
		int temp;
		fi >> temp;
		a[index] = 'A';
		d[index] = 1;
		a[index + temp + 1] = 'B';
		d[index + temp + 1] = 1;
		index++;
		while(d[index] == 1){
			index++;
		}
	}
}

main() {
	input();
	output();
}
