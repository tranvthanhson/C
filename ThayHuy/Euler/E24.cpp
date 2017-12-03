#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n = 3;
const int MN = 12;
char h[MN+2];

void init(){
	h[0] = n+1;
	for(int i = 1; i <= n; i++) {
		h[i] = '0' + i-1 ;
	}
}

void PH() {
	cout << endl;
	for(int i = 1; i <= n; i++) {
		cout << (char) h[i] - 0;
	}
}

bool Next() {
	int i, j;
	for (i = n - 1; i > 0; i--) {
		if (h[i] < h[i+1]) {
			break;
		}
		if (i == 0) return false;
		for (j = n; h[j] < h[i]; j--) {
			int t = h[i];
			h[i] = h[j];
			h[j] = t;
			i++;
			j = n;
			while(i < j) {
				t = h[i];
				h[i] = h[j];
				h[j] = t;
				i++;
				j--;			
			}
		}
	}
	return true;
}

main(){
	n = 3;
	init();
	do {
		PH();
	} while (Next());
}

/*
Cach 1 Dijkstra
	Sinh day hoan vi
	Khoi ao HV don vi: h = 0123456789
	Moi buoc next h -> h
	
	bool Next: Sinh hoan vi sat sau h
	Con: true;
	het: false;
	
	Phase 1:
		if(Co diem gay) Duyet nguoc tim diem gay i: h[i] > h[i+1]
		else return false;
	Phase 2:
		Duyet lai tim diem vuot j: h[j] > h[i]
		Doi cho h[i] h[j]
		Lat doan cuoi sau i	
*/
