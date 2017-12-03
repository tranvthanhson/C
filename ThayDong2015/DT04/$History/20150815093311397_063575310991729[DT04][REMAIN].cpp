#include <iostream>
#include <fstream>
using namespace std;
long long a[101];
ifstream fi("REMAIN.INP");
ofstream fo("REMAIN.OUT");
int n;
long long ma;
long long res;
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
    bool isRes;
    while (res)
    {
        isRes=true;
        for(int i=0;i<n-1;i++)
        {
            if (a[i]%res!=a[i+1]%res)
            {
                isRes=false;
                break;
            }
        }
        if(isRes)
        {
            fo<<res;
            break;
        }
        res--;
    }
}
int main()
{
    sub1();
    return 0;
}
