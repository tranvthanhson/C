#include <iostream>

using namespace std;

int UCLN(int a, int b){
	if(b == 0) return a;
	return UCLN(b, a % b);
}

int BCNN(int a, int b){
	return a * (b / UCLN(a,b));
}

main(){
	int b = 1;
	for(int i = 2; i <= 20; i++){
		b = BCNN(b, i);
	}
	cout<<b;
}
