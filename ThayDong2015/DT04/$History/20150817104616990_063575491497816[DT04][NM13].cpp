#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fi("NM13.INP");
ofstream fo("NM13.OUT");
string trace[122][122][10];
int num[122];
int n,m,t;
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
string duyet(int i,int s, int v)
{
    if(s>m)
        return "0";
    if (trace[i][s][v]!="-1")
    {
        return trace[i][s][v];
    }
    if (i>n)
    {
        if(s==m)
        {
            return "1";
        }
        return "0";
    }
    string sl="0";
    for(int j=0;j<=9;j++)
    {
        if(j==3 && v==1)
            continue;
        sl=congsolon(sl,duyet(i+1,s+j,j));
    }
    trace[i][s][v]=sl;
    return sl;
}
void sub1()
{
    fi>>t;
    while(t--)
    {
        fi>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<10;k++)
                    trace[i][j][k]="-1";
        fo<<duyet(1,0,0)<<endl;
    }
}
int main()
{
    sub1();
    return 0;
}
