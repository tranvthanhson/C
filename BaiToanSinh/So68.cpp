#include <iostream>

using namespace std;

int n;
string s = "";
int index = 0;
bool stop = true;
int k = 10000000;

void init() {
    s = "";
    for(int i=0; i<n; i++){
        s += "6";
    }
}

void in() {
    cout << s << endl;
}

void sinh() {
    init();
    for(int i=n-1; i>=0; i--){
        if(s[i] == '8'){
            s[i] = '6';
        }
        else{
            s[i] = '8';
            i = n;
            index++;
            if(index==k){
                stop = false;
                in();
                return;
            }
        // in();
        }
    }
}

void solve(int l){
    int i = 1;
    while(stop){
        n = i++;
        sinh();
    }
}

main() {
    solve(999);
}
