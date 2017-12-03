#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("PS4.INP");
ofstream fo("PS4.OUT");
long long n,k,m;
long long l[2][2]={{1,0},{1,1}};
long long r[2][2]={{1,1},{0,1}};
long long res[2][2]={{0,1},{1,0}};
long long tmp[2][2],ans[2][2];
void mulmatrix(long long a[2][2],long long b[2][2],long long c[2][2])
{
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c[i][j]+=(a[i][k]*b[k][j])%m;
            }
            c[i][j]%=m;
        }
    }
}
void powmatrix(long long a[2][2],long long x,long long c[2][2])
{
    long long d[2][2];
    if (x==1)
    {
        for(int i=0; i<2; i++)
           for(int j=0; j<2; j++)
               c[i][j]=a[i][j];
        return;
    }
    powmatrix(a,x/2,c);
    mulmatrix(c,c,d);
    if(x%2!=0)
        mulmatrix(a,d,c);
    else
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                c[i][j]=d[i][j];
}
void sub1()
{

    string s="";
    fi>>n>>k>>m;
    fi>>s;
    if(s[0]=='L')
          for(int x=0;x<2;x++)
                for (int y=0;y<2;y++)
                    ans[x][y]=l[x][y];
    else
          for(int x=0;x<2;x++)
                for (int y=0;y<2;y++)
                    ans[x][y]=r[x][y];
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='L')
        {
//            for(int x=0;x<2;x++)
//                for (int y=0;y<2;y++)
//                    r[x][y]=res[x][y];
            mulmatrix(ans,l,tmp);
        }
        else
        {
//            for(int x=0;x<2;x++)
//                for (int y=0;y<2;y++)
//                    l[x][y]=res[x][y];
            mulmatrix(ans,r,tmp);
        }
        for(int x=0;x<2;x++)
                for (int y=0;y<2;y++)
                    ans[x][y]=tmp[x][y];
    }
    powmatrix(ans,k,tmp);
    mulmatrix(tmp,res,ans);
    fo<<ans[0][0]+ans[0][1]<<" "<<ans[1][0]+ans[1][1];
}
int main()
{
    sub1();
    return 0;
}
