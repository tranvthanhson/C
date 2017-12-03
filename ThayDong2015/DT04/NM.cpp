#include <iostream>
#include <fstream>
using namespace std;
int t,m,n;
ifstream fi("NM.INP");
ofstream fo("NM.OUT");
string trace[122][122];
int num[120];
long long res;
string congsolon(string sst1,string sst2)
{
    int ss1s=sst1.size(),ss2s=sst2.size(),len=ss1s;
    if (ss1s>ss2s)
    {
        for (int xx=0;xx<ss1s-ss2s;xx++)
        {
            sst2='0'+sst2;
        }
    }
    else
    {
        for (int xx=0;xx<ss2s-ss1s;xx++)
        {
            sst1='0'+sst1;
            len=ss2s;
        }
    }
    int dux=0;
    for (int xx=len-1;xx>=0;xx--)
    {
        int tmp1=sst1[xx]-48;
        int tmp2=sst2[xx]-48;
        tmp1+=tmp2+dux;
        dux=tmp1/10;
        tmp1=tmp1%10;
        sst1[xx]=char(tmp1+48);
    }
    if (dux>0) sst1=char(dux+48)+sst1;
    return (sst1);
}
string duyet(int i,int s)
{
    if(s>m)
        return "0";
    if (trace[i][s]!="-1")
        return trace[i][s];
    if (i>n)
        return (s==m)?"1":"0";
    string sl="0";
    for(int j=0;j<=9;j++)
    {
        sl=congsolon(sl,duyet(i+1,s+j));
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
                trace[i][j]="-1";
        res=0;
        fi>>n>>m;
        fo<<duyet(1,0)<<endl;
    }
    return 0;
}
