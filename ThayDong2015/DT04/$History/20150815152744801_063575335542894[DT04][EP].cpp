#include <iostream>
#include <map>
#include <fstream>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
ifstream fi("EP.INP");
ofstream fo("EP.OUT");
const int maxN=1000000;
long long prime[maxN+1]; //max prime 999983
bool trace[maxN+1];
long long res=0;
string arr[maxN+1];
map<string,int> ma;
int a,b,t;

string NumberToString ( int Number )
{
 ostringstream ss;
 ss << Number;
 return ss.str();
}
void sieve()
{
    for(int i=2;i<=sqrt(maxN);i++)
    {
        if (prime[i]==0)
        {
            int j=i*i;
            while (j<=maxN)
            {
                prime[j]=i;
                j+=i;
            }
        }
    }
    for (int i=2;i<=maxN;i++)
        if (prime[i]==0)
            prime[i]=i;
}
string process(int x)
{
    for (int i=1;i<=maxN;i++)
        trace[i]=false;
    string s="";
    long long tmp;
    int y;
    while (x>1)
    {
        y=prime[x];
        if(!trace[y])
        s=NumberToString(y)+" "+s;
        trace[y]=true;
        x/=prime[x];
    }
    return s;
}
void sub1()
{
    fi>>t;
    while(t--)
    {
        res=0;
        fi>>a>>b;
        ma.clear();
        for(int i=a;i<=b;i++)
        {
            if(arr[i]=="")
            {
                arr[i]=process(i);
            }
            res+=ma[arr[i]]++;
        }
        fo<<res<<endl;
    }
}
void gen()
{

}

int main()
{
    sieve();
    sub1();
    //sub1();
    //gen();
    return 0;
}
