#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fi("NM13.INP");
ofstream fo("NM13.OUT");
long long trace[122][122][10];
int num[122];
int n,m,t;
long long duyet(int i,int s, int v)
{
    if(s>m)
        return 0;
    if (trace[i][s][v]>-1)
    {
        return trace[i][s][v];
    }
    if (i>n)
    {
        if(s==m)
        {
            return 1;
        }
        return 0;
    }
    long long sl=0;
    for(int j=0;j<=9;j++)
    {
        if(j==3 && v==1)
            continue;
        sl+=duyet(i+1,s+j,j);
    }
    trace[i][s][v]=sl;
    return sl;
}
void sub1()
{
    fi>>t;
    while(t--)
    {
     memset(trace,-1,sizeof(trace));
        fi>>n>>m;
        fo<<duyet(1,0,0)<<endl;
    }
}
int main()
{
    sub1();
    return 0;
}
