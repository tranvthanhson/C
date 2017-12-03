#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef long long ll;

//ifstream fi("Bai_01.inp");

ll n, gt = 1, d = 0;

void input() {
	while(1){
		gt = 1, d = 0;
		cin >> n;
		for(int i=1; i<=n; i++){
			gt *= i;
			while(gt % 10 == 0) {
				d++;
				gt /=10;
			}
			gt %= 100000;
			cout << gt << endl;
		}
		cout << d << endl;	
	}
	
}

main() {
	input();
}
