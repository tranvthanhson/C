//5537376230390876637302048746832985971773659831892672

#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>

using namespace std;

ifstream fi("E13.inp");
ofstream fo("E13.out");

string s = "";
int soDong = 100;//MD
int soLuong = 50;//MC
int r[60];//t

void input(){
	for(int i=0; i < soLuong; i++){
		r[i] = 0;
	}
	for(int i = 0; i < soDong; i++){
		string temp;
		fi >> temp;
		for(int j = temp.length()-1, k = 0; j >= 0; j--, k++){
			r[k] += (int)temp[j] - 48;
		}
	}
	int nho = 0;
	for(int i=0; i < soLuong; i++){
		r[i] += nho;
		nho = r[i] / 10;
		r[i] %= 10;
	}
	if(nho > 0){
		fo << nho;
	}
	for(int i = soLuong - 1; i >= 0; i--){
		fo << r[i];
	}
	
}

main(){
	input();
}
