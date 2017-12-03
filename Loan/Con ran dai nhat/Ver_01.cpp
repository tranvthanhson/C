#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

ifstream fi("INPUT.txt");

int n, m, a[10000][10000];
int maxx = 0;

int max_f(int a, int b, int c, int d){
	int maxx = a;
	maxx = (maxx > b)? maxx:b;
	maxx = (maxx > c)? maxx:c;
	maxx = (maxx > d)? maxx:d;
	return maxx;
}
void input(){
	fi>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			fi>>a[i][j];
		}
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

int loan1(int i, int j,int d){
	if(i < 0 || j < 0 || i == n || j == m){
		return 0;
	}
	if(a[i][j] > d) {
		d = a[i][j];
		return 1 + max_f(loan1(i+1,j,d) , loan1(i-1,j,d) , loan1(i,j+1,d) , loan1(i,j-1,d));
	}
	return 0;
}

int loan(int i, int j){
	int d = a[i][j];
	return max_f(loan1(i+1,j,d) , loan1(i-1,j,d) , loan1(i,j+1,d) , loan1(i,j-1,d));
}

void solve(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			string result = "";
			int ma = loan(i, j) + 1;
			if(ma > maxx){
				maxx = ma;
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
