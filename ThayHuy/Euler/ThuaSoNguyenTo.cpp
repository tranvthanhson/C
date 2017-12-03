#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

ll index = 0;
ll p[1000], m[1000];

ll Dcom(ll n){
	ll can = (ll) sqrt(n);
	ll uoc, mu = 0, i = 0;
	for(uoc = 2; uoc <= can; uoc++){
		if(n % uoc == 0){
			mu = 0;
			
			while(n % uoc == 0){
				n /= uoc;
				mu++;	
			}

			p[i] = uoc;
			m[i] = mu;
			i++;
		}
	}
	return i;
}

//ll Dcomp1(ll n){
//	ll i = 2;
//	ll d = 0;
//	while(n>=1){
//		if(n % i == 0){
//			d++;
//		}
//		else{
//			
//		}
//	}
//}

main(){
//	ll n = pow(2,7) * pow(5,4) * 4;
//	ll n = 3 * 4999999;
	ll n = 600851475143;
	ll k = Dcom(n);
	for(ll i=0; i < k; i++){
		cout << p[i] << "^" << m[i]<<" * ";
	}
}
