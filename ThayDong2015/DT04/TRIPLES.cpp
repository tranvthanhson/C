#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fi("TRIPLES.INP");
ofstream fo("TRIPLES.OUT");
int a[1001][1001];
int d[1001][3];
int c[1001][3];
char tmp;
long long res,p,q;
int m,n,t;
void sub2()
{
    fi>>t;
    while(t--)
    {
        fi>>m>>n;
        res=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                fi>>a[i][j];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                p=q=0;
                for (int k=0;k<n;k++)
                    if (a[i][k]-48=='3'-a[i][j])
                        p++;
                for (int k=0;k<m;k++)
                    if (a[k][j]-48=='3'-a[i][j])
                        q++;
                res+=p*q;
            }
        fo<<res<<endl;
    }
}
void sub3()
{
    fi>>t;
    while(t--)
    {
        fi>>m>>n;
        res=0;
        memset(d,0,sizeof(d));
        memset(c,0,sizeof(c));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                fi>>tmp;
                a[i][j]=tmp-'0';
                d[i][a[i][j]]++;
                c[j][a[i][j]]++;
            }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if (a[i][j]!=0)
                    res+=(d[i][ 3-a[i][j] ] * c[j][ 3-a[i][j] ]);
            }
        fo<<res<<endl;
    }
}
int main()
{
    sub3();
    return 0;
}
