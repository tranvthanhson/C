#include <iostream>
#include <algorithm>

using namespace std;

//int n = 13, a[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13}, t[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
int n = 5, a[] = {3,2,7,6,9}, t[] = {0,0,0,0,0};
int dem = 0;

void in(int x[]){
	dem++;
	for(int i = 0; i < n; i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;	
}

void solve(int index,int x[], int i, int chon){
	if(chon > 0){
		for(int j = i+1; j < n; j++){
			if(t[j] == 0){
				x[index++] = a[j];
				t[j] = 1;
				if(index == n) {
					in(x);
					index = 0;
				}
				else {
					solve(index, x,j, -chon);
				}
				t[j] = 0;
			}
		}
	}
	else{
		for(int j = i-1; j >= 0; j--){
			if(t[j] == 0){
				x[index++] = a[j];
				t[j] = 1;
				if(index == n) {
					in(x);
					index = 0;
				}
				else {
					solve(index,x, j, -chon);
				}
				t[j] = 0;
			}
		}
	}
}

void tim1(int chon){
	for(int j = 0; j < n; j++){
		int index = 0;
		int x[100000];
		x[index++] = a[j];
		t[j] = 1;
		solve(index,x, j, chon);		
		t[j] = 0;
	}
}

main(){
	sort(a,a+n);
	tim1(10);
	cout<<dem;

//for(int i=0; i<n; i++){
//		cout<<a[i]<<" ";
//	}
}
