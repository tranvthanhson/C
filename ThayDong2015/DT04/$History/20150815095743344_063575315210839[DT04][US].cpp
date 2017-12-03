#include <iostream>
#include <fstream>
using namespace std;
int t,a,b;
ifstream fi("US.INP");
ofstream fo("US.OUT");
long long u,v;
//long long u[1001][1001],v[1001][1001];
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
    sub1();
    return 0;
}
