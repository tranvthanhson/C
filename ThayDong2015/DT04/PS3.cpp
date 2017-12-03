#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("PS3.INP");
ofstream fo("PS3.OUT");
int n;
long long t,d,M,x,y,u,v,cx,cy;
string s;
long long trend[100];
bool flag;
string genTree(long long t)
{
    string s="";
    while(t!=1)
    {
        if (t%2==0)
            s="L"+s;
        else
            s="R"+s;
        t/=2;
    }
    return s;
}
long long mul(long long a, long long b)
{
    long long res=0;
    while(b>0)
    {
        if (b%2==1)
            res=(res+a)%M;
        a=(2*a)%M;
        b/=2;
    }
    return res%M;
}
void genTreeToArray()
{
    string s=genTree(t);
    int j=1;
    if(s[0]=='L')
        j++;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='L' && j%2==0)
        {
            trend[j]++;
        }
        else if(s[i]=='L' && j%2!=0)
        {
            trend[++j]++;
        }
        if(s[i]=='R' && j%2!=0)
        {
            trend[j]++;
        }
        else if(s[i]=='R' && j%2==0)
        {
            trend[++j]++;
        }
    }
    n=j;
}
void sub1()
{
    fi>>t>>M;
    genTreeToArray();
    x=0;
    y=1;
    u=1;
    v=0;
    flag=false;
    for(int i=1;i<=n;i++)
    {
        d=trend[i];
        if(flag)
        {
            u=(u+mul(d,x))%M;
            v=(v+mul(d,y))%M;
        }
        else
        {
            x=(x+mul(d,u))%M;
            y=(y+mul(d,v))%M;
        }
        cx=(x+u)%M;
        cy=(y+v)%M;
        flag=!flag;
    }
    fo<<cx%M<<" "<<cy%M;
}
int main()
{
    sub1();
    return 0;
}
