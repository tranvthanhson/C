#include <iostream>
#include <math.h>
#include <bitset>

using namespace std;

const int MN = 28123;
bitset<MN+1> doi;
bitset<MN+1> can;


// Tong cac uoc nho hon n
int D(int n){
	int can = sqrt(n);
	int t = 1;
	for(int i=2; i <= can; i++) {
		if(n % i == 0){
			t += i + (n/i);
		}
	}
	return (can*can == n)? t-can:t;
}

int D1(int n){
	int sum = 0;
	for(int i=1; i<=n/2; i++){
		if(n % i == 0){
			sum += i;
		}
	}
	return sum;
}
void allDoi(){
	doi.reset();
	can.reset();
	int ndoi = 0;
	for(int i=1; i <= MN; i++) {
		if(D(i) > i) {
//			doi[] = 1;
			for(int j = 1; j <= i; j++) {
				if(doi[j]) {
					int ij = i + j;
					if(ij > MN) break;
					can[ij] = 1;
				}
			}
		}
	}
}

main(){
	for(int i=1; i<=1000; i++){
		cout<<D(i)<<" "<<D1(i)<<endl;
	}
//	allDoi();
//	int t = 0;
//	for(int i = 1; i <= MN; i++){
//		if(can[i] == 0) {
//			t += i;
//		}
//	}
//	cout << t;
}
