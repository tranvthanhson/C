#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fi("E22.inp");
//ofstream fo("E22.out");

const int n = 6000;

string names[n];

int score(int index){
	int sum = 0, length = names[index].length();
	for(int i = 0; i < length; i++){
		sum += names[index][i] - 'A' + 1;
	}
	return sum;
}

void input() {
	if(fi.fail()) {
		cout<<"Unable input file";
		exit(1);
	}
	char c;
	int index = 0;
	string temp = "";
	while(fi.get(c)) {
		if(c >= 'A' && c <= 'Z') {
			temp += c;
		}
		else {
			if(temp != ""){
				names[index++] = temp;
			}
			temp = "";
		}
	}
	sort(names, names+index);
	long sum = 0;
	for(int i = 0; i < index; i++){
		sum += score(i)*(i+1);
		//fo << names[i] << endl;
	}
	cout << sum;
}

main(){
	input();
}
