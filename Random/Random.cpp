#include <iostream>
#include <cstdlib>

using namespace std;

main(){
	int max = 15, min = 10;
	for(int i=0; i<1000; i++){
		cout<<min + (rand() % (int)(max - min + 1))<<endl;
	}
	 
}
