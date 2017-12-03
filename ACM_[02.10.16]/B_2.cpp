#include<bits/stdc++.h>

using namespace std;

map<string, int> X;
int T;
string str;

int check(int i, int j) {
    if(i==j) return true;
    if(str[i]==str[j]){
        if(i+1==j) return true;
        check(i+1,j-1);
    }
    else return false;
}

void process(string str) {
    int s= str.size();
    X.clear();
    for(int i=0;i<s;i++) {
        for(int j=s-1;j>=i;j--) {
            if(check(i,j)){
                X[str.substr(i,j-i+1)]++;
            }
        }
    }
    /*for(map<string, int> ::iterator it=X.begin();it!=X.end();it++)
    {
    cout<<it->first<<" ";
    }*/
    cout << X.size() << endl;
}

void input() {
    cin >> T;
    for(int i = 1;i <= T; i++){
        cin >> str;
        process(str);
    }
}

int main() {
    input();
}
