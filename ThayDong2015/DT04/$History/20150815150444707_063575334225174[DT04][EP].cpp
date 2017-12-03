#include <iostream>
#include <map>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fi("EP.INP");
ofstream fo("EP.OUT");
const int maxN=1000000;
long long prime[maxN+1]; //max prime 999983
bool trace[maxN+1];
long long res=0;
string arr[maxN+1] ={""};
map<string,int> ma;
int a,b,t;
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
    string s="";
    int y;
    while (x>1)
    {
        y=prime[x];
        s+=y;
        x/=prime[x];
    }
    return s;
}
void sub1()
{
    fi>>t;
    string s;
    while(t--)
    {
        res=0;
        fi>>a>>b;
        ma.clear();
        for(int i=a;i<=b;i++)
        {
            if(arr[i].size()==0)
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
   for (int i=2;i<=maxN;i++)
    if (prime[i]==0)
        prime[i]=i;
    string s;
    for(int i=1;i<=maxN;i++)
    {
        process(i);
        s="";
        for(int j=1;j<=maxN;j++)
            if(trace[j])
                s+="1";
            else
                s+="0";
        arr[i]=s;
    }
}

int main()
{
    sieve();
    //sub1();
    //gen();
    return 0;
}
