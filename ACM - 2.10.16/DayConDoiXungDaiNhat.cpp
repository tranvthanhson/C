//Day con doi xung day nhan
#include<iostream>
#include <string.h>
using namespace std;
int a[1000][1000]={0};
string s="aabcbaaaaaaaaaaaaa";
int tinh(){
	memset(a, 0, sizeof(a));
	int dem = 0;
	for (int i = 0; i < s.length(); i++) a[i][i] = 1;
	for (int i = s.length() - 1; i >= 0; i--)
		for (int j = i+1; j < s.length(); j++)
			if (s[i] == s[j]) {
				a[i][j] += a[i+1][j-1]+2;
				dem++;
			//	cout<<a[i][j]<<" 1"<<endl;
			}
			else {
				a[i][j] = max(a[i+1][j],a[i][j-1]);
				//cout<<a[i][j]<<" 2"<<" i="<<i<<" j="<<j<<endl;
			}
	int n = s.length();
	return n - a[0][n-1];
}
main(){
	a[0][2] = 0;
	a[0][3] = 0;
	a[0][4] = 0;
	cout << tinh();
	/*
	for(int i=0;i<s.length();i++){
		for(int j=0;j<s.length();j++){
			cout<<a[i][j]<<"\t";	
		}
		cout<<endl;
	}
	*/	
	
	
}
