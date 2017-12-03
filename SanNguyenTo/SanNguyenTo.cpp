#include <iostream>
#include <math.h>
#include <bitset>

using namespace std;

typedef long long ll;

ll nt[1000000]={0};

void sanNguyenTo(){
    for(int i=2; i<=1000; i++){
        if(nt[i] == 0){
            int j = i*i;
            while(j<=1000000){
                nt[j] = i;
                j = j++;
            }
        }
    }
    for(int i=2; i<=1000000; i++){
        if(nt[i] == 0) nt[i] = i;
    }
}

const int MN = 5000;
bitset<MN> primes;

void Steve(int n){
    primes.set();
    int can = (int) sqrt(n);
    for(int i = 2; i<= can; i++){
        if(primes[i]){
            for(int j=i*i; j<=n; j+=i){
                primes[j] = 0;
            }
        }
    }
}

int SteveList(int n){
    int p[100000];
    Steve(n);
    int i,j;
    for(i = 2, j = 0; i<=n ; i++){
        if(primes[i]){
            p[j++] = i;
        }
    }
    return j;
}

main(){
    //	Steve(MN);
    //	for(int i = 2; i<= 100; i++){
    //		cout<<primes[i]<<" ";
    //	}
    cout<<SteveList(MN);
}
