#include <iostream>

using namespace std;

int UCLN(int a, int b){
	if(b == 0) return a;
	return UCLN(b, a % b);
}

main(){
	cout<<UCLN(49,14);
}
