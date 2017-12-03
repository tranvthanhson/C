#include <cstdlib>
#include <fstream>

using namespace std;

ofstream fo("rand.txt");

f() {
	fo << 10000 << endl;
	for(int i=0; i<10000; i++) {
		fo << 1000000000 << " ";
	}
	for(int i=0; i<10000; i++) {
		fo << 1000000000 << " ";
	}
	fo << endl;
}

main() {
	fo << 10 << endl;
	for(int i=0; i<10; i++) {
		f();
	}
}
