#include <iostream>
#include <fstream>
using namespace std;
int t,a,b;
ifstream fi("US.INP");
ofstream fo("US.OUT");
long long u,v;
long long ug[1001],vg[1001];
void sub2()
{
    int d;
    for(int i=1;i<=1000;i++)
    {
        ug[i]=1;
        vg[i]=i;
        d=i/2;
        for(int j=1;j<=d;j++)
        {
            if(i%j==0)
            {
                ug[i]++;
                vg[i]+=j;
            }
        }
    }
    /*
    for(int i=1;i<=1000;i++)
    {
        fo<<ug[i]<<",";
    }
    fo<<endl;
    for(int i=1;i<=1000;i++)
    {
        fo<<vg[i]<<",";
    }
    */
    fi>>t;
    while(t--)
    {
        fi>>a>>b;
        u=0;
        v=0;
        for(int i=a;i<=b;i++)
        {
            u+=ug[i];
            v+=vg[i];
        }
     fo<<u<<" "<<v<<endl;
    }
}
void sub1()
{
    fi>>t;
    int d;
    while(t--)
    {
        u=0;
        v=0;
        fi>>a>>b;
        for(int i=a;i<=b;i++)
        {
            u+=1;
            v+=i;
            d=i/2;
            for(int j=1;j<=d;j++)
            {
                if(i%j==0)
                {
                    u++;
                    v+=j;
                }
            }
        }
        fo<<u<<" "<<v<<endl;
    }
}
int main()
{
    sub2();
    return 0;
}
