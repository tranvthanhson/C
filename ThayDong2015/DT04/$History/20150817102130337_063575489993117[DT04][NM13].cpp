#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fi("NM13.INP");
ofstream fo("NM13.OUT");
int trace[122][122];
int num[122];
int n,m,t;
bool check()
{
    for(int i=1;i<n;i++)
        if(num[i]==1 && num[i]==3)
            return false;
    return true;
}
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
        {
            if (check())
                return 1;
            return 0;
        }
        return 0;
    }
    long long sl=0;
    for(int j=0;j<=9;j++)
    {
        if(j==3 && num[i-1]==1)
            continue;
        num[i]=j;
        sl+=duyet(i+1,s+j);
    }
    trace[i][s]=sl;
    return sl;
}
void sub1()
{
    fi>>t;
    while(t--)
    {
     for(int i=0;i<122;i++)
        for (int j=0;j<121;j++)
            trace[i][j]=-1;
    memset(num,0,sizeof(num));
        fi>>n>>m;
        fo<<duyet(1,0)<<endl;
    }
}
int main()
{
    sub1();
    return 0;
}
