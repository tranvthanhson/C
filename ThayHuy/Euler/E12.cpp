#include <iostream>
#include <math.h>

using namespace std;

int index;
int D = 500;
int s = 0;
int maxx = 0;

int phanTichUoc(int n){
	int d = 0;
	for(int i = 2; i <= n/2; i++){
		if(n % i == 0) d++;
	}
	return d+2;
}

int phanTichUoc2(int n){
	int d = 0;
	int can = sqrt(n);
	for(int i=1; i <= can; i++){
		if(n % i == 0){
			d+=2;
		}
	}
	return (can*can==n)? d-1:d;
}

main() {
	cout<<phanTichUoc2(82);
//	int i = 1;
//	while(true){
//		s += i;
//		i++;
//		if(phanTichUoc2(s) >= D){
//			cout<<s<<endl;
//			break;
//		}
//	}
}
