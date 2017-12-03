#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("PS4.INP");
ofstream fo("PS4.OUT");
unsigned long long int n,k,m;
unsigned long long int l[2][2]={{1,1},{0,1}};
unsigned long long int r[2][2]={{1,0},{1,1}};
unsigned long long int res[2][2]={{0,1},{1,0}};
unsigned long long int tmp[2][2],ans[2][2];
unsigned long long int mul(unsigned long long int a, unsigned long long int b)
{
    unsigned long long int re=0;
    while(b>0)
    {
        if (b%2==1)
            re=(re+a)%m;
        a=(2*a)%m;
        b/=2;
    }
    return re%m;
}
void mulmatrix(unsigned long long int a[2][2],unsigned long long int b[2][2],unsigned long long int c[2][2])
{
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<2;k++)
            {
                c[i][j]+=mul(a[i][k],b[k][j]);
                c[i][j]%=m;
            }
        }
    }
}
void powmatrix(unsigned long long int a[2][2],unsigned long long int x,unsigned long long int c[2][2])
{
    unsigned long long int d[2][2];
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
    mulmatrix(res,tmp,ans);
    fo<<ans[0][0]+ans[0][1]<<" "<<ans[1][0]+ans[1][1];
}
int main()
{
    sub1();
    return 0;
}
