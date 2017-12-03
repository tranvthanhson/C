#include <iostream>

using namespace std;

string in = "     trAn             vU            thanH             sOn   ";
string out = "";

void trim() {
	while(in[0] == ' '){
		in = in.substr(1);
	}
	while(in[in.length()-1] == ' '){
		in = in.substr(0, in.length() - 1);
	}
}

void upcase(char &n){
	int temp = (int) n;
	if(temp >= 97 && temp <= 122){
		n = (int) n - 32;
	}
}

void lowercase(char &n){
	int temp = (int) n;
	if(temp >= 65 && temp <= 90) {
		n = (int) n + 32;
	}
}

void chuanHoa(){
	bool tt = false;
	upcase(in[0]);
	for(int i=1; i<in.length(); i++){
		if(tt){
			upcase(in[i]);
		}
		else{
			lowercase(in[i]);
		}
		if(in[i] == ' ') {
			tt = true;
		}
		else{
			tt = false;
		}
	}
}

void xoaKhoangTrang(){
	for(int i=0; i<in.length()-1;){
		if(in[i] == ' ' && in[i+1] == ' '){
			in = in.substr(0, i) + in.substr(i+1);
		}
		else{
			i++;
		}
	}
}

void solve() {
	trim();
	chuanHoa();
	xoaKhoangTrang();
	cout << in << endl;
}

main(){
	solve();
}
