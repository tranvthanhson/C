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
int arr[maxN+1];
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
int process(int x)
{
    int y,tmp=1;
    while (x>1)
    {
        y=prime[x];
        while(x%y==0)
            x/=y;
        tmp*=y;
    }
    return tmp;
}
void sub1()
{
    fi>>t;
    for(int i=1;i<=maxN;i++)
        arr[i]=process(i);
    while(t--)
    {
        res=0;
        fi>>a>>b;
        for (int i=a;i<=b;i++)
        {
            for (int j=i+1;j<=b;j++)
            {
                if(arr[i]==arr[j])
                    res++;
            }
        }
        fo<<res<<endl;
    }
}

int main()
{
    sieve();
    sub1();
    //sub1();
    //gen();
    return 0;
}
