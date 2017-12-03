#include <iostream>
#include <fstream>
#include <math.h>
#include <map>

using namespace std;

ifstream fi("D.inp");

int t, n, index = 0, t1, t2, s = 0, a[1010][1010];
map<int, int> canh, u;
map<int, int>::iterator it;

void input() {
	fi >> t;
	for(int i = 0; i < t; i++) {
		while(true) {
			fi >> t1 >> t2;
			if(t1 != 0 && t2 != 0){
				canh[t1] = canh[t2] = 1;
				a[t1][t2] = a[t1][t1] = 1;
			}
			else {
				break;
			}
		}
		n = canh.size();
	}
}

main() {
	input();
//	cout<<UCLN(75, 125);
}
