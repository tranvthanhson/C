#include <iostream>
#include <string>
#include <sstream>
//#include <fstream>
#include <stdlib.h>

using namespace std;

//ifstream fi("K.inp");

typedef long long ll;

ll t;

void input() {
    int n;
    string s = "";
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        getline(cin,s);
        int rs = 0;
        for(int j=0; j<n; j++) {
            getline(cin,s);
            if(s == "INC") {
                rs++;
            }
            else if(s == "DOUBLE") {
                rs *= 2;
            }
            else if(s == "TRIPLE") {
                rs *= 3;
            }
            else if (s =="SQR") {
                rs *= rs;
            } else {
                stringstream ss(s.substr(4));
                int temp;
                ss >> temp;
                rs = temp;
            }
        }
        cout << rs << endl;
    }
}



main() {
    input();
}
