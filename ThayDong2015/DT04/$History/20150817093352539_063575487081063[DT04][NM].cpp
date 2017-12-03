#include <iostream>
#include <fstream>
using namespace std;
int t,m,n;
ifstream fi("NM.INP");
ofstream fo("NM.OUT");
long long trace[122][122];
int num[120];
long long res;
long long duyet(int i,int s)
{
    if(s>m)
        return 0;
    if (trace[i][s]>-1)
    {
        return trace[i][s];
    }
    if (i>n)
    {
        if(s==m)
            return 1;
        return 0;
    }
    long long sl=0;
    for(int j=0;j<=9;j++)
    {
        sl+=duyet(i+1,s+j);
    }
    trace[i][s]=sl;
    return sl;
}
int main()
{
    fi>>t;
    while(t--)
    {
        for(int i=0;i<122;i++)
            for (int j=0;j<121;j++)
                trace[i][j]=-1;
        res=0;
        fi>>n>>m;
        fo<<duyet(1,0)<<endl;
    }
    return 0;
}
