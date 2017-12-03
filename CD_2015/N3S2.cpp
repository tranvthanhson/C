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
	int k, m, i = 1;
	cin >> k >> m;
	int index = 0;
	while(true){
		int n = i*i-1;
		if(n % 3 == 0){
			index++;
			if(index == k){
				cout << n % m<< " ";
			}
		}
		i++;
	}
}

main() {
	sinh();
}
