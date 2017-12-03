#include <iostream>
#include <fstream>
using namespace std;
int t,a,b;
ifstream fi("US.INP");
ofstream fo("US.OUT");
long long u,v;
long long ug[1000001],vg[1000001];
void gen()
{
    int d;
    for(int i=1;i<=1000000;i++)
    {
        int j=i;
        while (j<=1000000)
        {
            ug[j]+=1;
            vg[j]+=i;
            j+=i;
        }
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
void sub2()
{
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
int main()
{
    gen();
    sub2();
    return 0;
}
