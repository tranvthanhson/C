#include <iostream>
#include <fstream>
using namespace std;
int t,m,n;
ifstream fi("NM.INP");
ofstream fo("NM.OUT");
int trace[121];
int num[120];
long long res;
void duyet(int i,int s)
{
    if(s>m)
        return;
    if (i>n)
    {
        if(s==m)
            res++;
        return;
    }
    for(int j=0;j<=9;j++)
    {
        num[i]=j;
        duyet(i+1,s+j);
    }
}
int main()
{
    fi>>t;
    while(t--)
    {
        res=0;
        fi>>m>>n;
        duyet(1,0);
        fo<<res<<endl;
    }
    return 0;
}
