#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("PS2.INP");
ofstream fo("PS2.OUT");
int n;
unsigned long long int d,M,x,y,u,v,cx,cy;
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
int main()
{
    sub2();
    return 0;
}
