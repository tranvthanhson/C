#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

bool check(int n) {
	n++;
	double d = sqrt(n);
	if(d * d == n) return true;
	return false;
}

void sinh() {
	for(int i=0; i<= 10000; i+=3) {
		if(i % 3 == 0 && check(i)){
			cout << i << " ";
		}
	}
}

main() {
	sinh();
}
