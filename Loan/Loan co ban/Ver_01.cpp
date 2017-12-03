#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("INPUT.txt");

int n, m, a[10000][10000];
int maxx = 0;

void input(){
	fi>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			fi>>a[i][j];
		}
	}
}

int loan(int i, int j){
	if(i<0 || j < 0 || i==n || j == n){
		return 0;
	}
	
	if(a[i][j] == 1) {
		a[i][j] = 0;
		return 1 + loan(i+1,j) + loan(i-1,j) + loan(i,j+1) + loan(i,j-1) +
		loan(i+1,j+1) + loan(i-1,j-1) + loan(i+1, j-1) + loan(i-1,j+1);
	}
}

void output(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

void solve(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j] == 1){
				int ma = loan(i,j);
//				cout<<endl;
//				output();
				if(ma>maxx){
					maxx = ma;
				}

			}
		}
	}
}

main(){
	input();
	output();
	solve();
	cout<<"Max: "<<maxx;
}
