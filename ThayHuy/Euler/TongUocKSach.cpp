#include <iostream>

using namespace std;

int n = 20;

main(){
	for(int i=1; i<=n; i++){
		int s = 0;
		for(int j=1; j<=i; j++){
			if(i % j == 0) s += j;
		}
		cout<<i<<":\t"<<s<<endl;
	}
}
