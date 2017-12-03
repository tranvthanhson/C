#include <iostream>
#include <string>

using namespace std;

//string s = "abbabxbanabx";
//string s = "12345654321";
string s = "aabccbaababbabababcbbcbacbba";
int d = 0;
int maxx = 0;
int index = 0;

void solve(){
	int n = s.length();
	for(int i=0; i<n; i++){
		int j = 0;
		d = 0;
		while(true){
			j++;
			if(i+j >= n || i-j < 0){
				break;
			}
			if(s[i+j] != s[i-j]){
				
				break;
			}
			cout<<"i: "<<i<<endl;
			cout << s[i+j] << s[i-j] << endl;
			if(j>maxx){
				maxx = j;
				index = i;
			}
		}
	}
	cout<<maxx<<endl;
	cout<<s[index]<<endl;
	cout<<index<<endl;
	for(int i = 0; i<=maxx; i++){
		cout<<s[i+index];
	}
}

main(){
	solve();
}
