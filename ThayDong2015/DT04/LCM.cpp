#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fi("LCM.INP");
ofstream fo("LCM.OUT");
int a,b,t;
long long res,k;
const long long m=111539786;
const long long maxN=1000000;
long long prime[maxN+1];
long long trace[maxN+1];
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
}
void process(long long x)
{
    long long y;
    while(x>1)
    {
        y=prime[x];
        trace[y]++;
        x/=prime[x];
    }
}
void sub1()
{
    for (int i=2;i<=maxN;i++)
        if (prime[i]==0)
            prime[i]=i;
    fi>>t;
    while(t--)
    {
        fi>>a>>b;
        res=1;
        for(int i=1;i<=maxN;i++)
            trace[i]=0;
        for (int i=a;i<=b;i++)
            process(i);
        for (int i=2;i<=b;i++)
            res=(res*((2*trace[i]+1)%m))%m;
        fo<<res<<endl;
    }
}
int main()
{
    sieve();
    sub1();
    return 0;
}
