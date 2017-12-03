#include <iostream>

using namespace std;

int f[100];
int m,n;

void failureFunction(string p){
	f[0] = 0;
	int i = 1, j = 0;
	m = p.length();
	while(i < m) {
		if(p[i] == p[j]){
			f[i] = j+1;
			i++;
			j++;
		}
		else{
			if(j>0){
				j = f[j-1];
			}
			else{
				f[i] = 0;
				i++;
			}
		}
	}
	cout<<"Bang F tuong ung voi chuoi "<<p<<": "<<endl;
	for(int i=0; i<m; i++){
		cout<<f[i]<<" ";
	}
}

int KMPMatch(string t, string p){
	n = t.length();
	m = p.length();
	failureFunction(p);
	int i=0, j=0;
	while(i<n){
		if(t[i] == p[j]){
			if(j==m-1) return i-j;
			else {
				i++;
				j++;
			}
		}
		else{
			if(j>0) j = f[j-1];
			else i++;
		}
	}
	return -1;
}

main(){
	string p1 = "MNABMNBAMNAM";
	string p = "ACBNABACBNAQ";
	failureFunction(p);
	cout<<endl;
	failureFunction(p1);
}
