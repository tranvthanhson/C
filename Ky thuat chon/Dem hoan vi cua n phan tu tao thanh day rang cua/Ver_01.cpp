#include <iostream>

using namespace std;


int n = 5, a[] = {3,2,7,6,9}, t[] = {0,0,0,0,0};
//int n = 13, a[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13}, t[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
//int n = 10, a[] = {0,1,2,3,4,5,6,7,8,9,10}, t[] = {0,0,0,0,0,0,0,0,0,0};
int dem = 0;
int x[6];

void in(){
	dem++;
	for(int i=0; i<n; i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;	
}

//void tim(int i){
//	for(int j=0; j<n; j++){
//		if(t[j] == 0){
//			x[i] = a[j];
//			t[j] = 1;
//			if(i==n-1) in();
//			else tim(i+1);
//			t[j] = 0;
//		}
//	}
//}

void solve(int i, int chon){
	for(int j = 0; j < n; j++){
		if(t[j] == 0){
			if(chon > 0){
				if(a[j] > x[i-1]){
						x[i] = a[j];
						t[j] = 1;
						if(i==n-1) in();
						else solve(i+1,-chon);
						t[j] = 0;
				}
			}
			else{
				if(a[j] < x[i-1]){
						x[i] = a[j];
						t[j] = 1;
						if(i==n-1) in();
						else solve(i+1,-chon);
						t[j] = 0;
				}
			}
		}
	}
}

void tim1(int chon){
	for(int j = 0; j < n; j++){
		x[0] = a[j];
		t[j] = 1;
		solve(1, chon);		
		t[j] = 0;
	}
}

main(){
	tim1(10);
	cout<<dem*2;
}
