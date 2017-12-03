#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
long long a[101];
ifstream fi("REMAIN.INP");
ofstream fo("REMAIN.OUT");
int n;
long long ma,mi;
long long res;
bool kt_sub1(long long d)
{
    for(int i=0;i<n-1;i++)
    {
        if (a[i]%d!=a[i+1]%d)
        {
            return false;
        }
    }
    return true;
}
void sub1()
{
    fi>>n;
    fi>>a[0];
    ma=a[0];
    for(int i=1;i<n;i++)
    {
        fi>>a[i];
        if (a[i]>ma)
            ma=a[i];
    }
    res=ma;
    while (res)
    {
        if(kt_sub1(res))
        {
            fo<<res;
            break;
        }
        res--;
    }
}
long long gcd(long long u, long long v)
{
    if(v==0)
        return u;
    return gcd(v,u%v);
}
void sub2()
{
    fi>>n;
    fi>>a[0];
    mi=a[0];
    for(int i=1;i<n;i++)
    {
        fi>>a[i];
        if (a[i]<mi)
            mi=a[i];
    }
    res=gcd(a[0]-mi,a[1]-mi);
    for(int i=2;i<n;i++)
        res=gcd(res,a[i]-mi);
    fo<<res;
}
int main()
{
    sub2();
    return 0;
}
