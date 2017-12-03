#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("PS2.INP");
ofstream fo("PS2.OUT");
int n;
long long d,M,x,y,u,v,cx,cy;
bool flag;
void sub1()
{
    fi>>n>>M;
    x=0;
    y=1;
    u=1;
    v=0;
    cx=1;
    cy=1;
    flag=false;
    for(int i=1;i<=n;i++)
    {
        fi>>d;
        if(flag)
        {
            while(d--)
            {
                u=cx%M;
                v=cy%M;
                cx+=x;
                cy+=y;
                cx%=M;
                cy%=M;
            }
        }
        else
        {
            while(d--)
            {
                x=cx%M;
                y=cy%M;
                cx+=u;
                cy+=v;
                cx%=M;
                cy%=M;
            }
        }
        flag=!flag;
    }
    fo<<cx%M<<" "<<cy%M;
}
void sub2()
{
    fi>>n>>M;
    x=0;
    y=1;
    u=1;
    v=0;
    cx=1;
    cy=1;
    flag=false;
    for(int i=1;i<=n;i++)
    {
        fi>>d;
        if(flag)
        {
            cx+=(x*d)%M;
            cy+=(y*d)%M;
            u=(cx-x)%M;
            v=(cy-y)%M;
        }
        else
        {
            cx+=(u*d)%M;
            cy+=(v*d)%M;
            x=(cx-u)%M;
            y=(cy-v)%M;
        }
        flag=!flag;
    }
    fo<<cx%M<<" "<<cy%M;
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
void sub3()
{
    fi>>n>>M;
    x=0;
    y=1;
    u=1;
    v=0;
    flag=false;
    for(int i=1;i<=n;i++)
    {
        fi>>d;
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
