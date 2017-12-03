#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("TRIPLES.INP");
ofstream fo("TRIPLES.OUT");
char a[1001][1001];
long long d;
int m,n,t;
void sub1()
{
    fi>>t;
    while(t--)
    {
        fi>>m>>n;
        d=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                fi>>a[i][j];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(a[i][j]!='0')
                {
                    for (int k=0; k<n; k++)
                    {
                        if(a[i][k]!='0')
                            for(int l=0; l<m; l++)
                            {
                                if((i!=l || j!=k)&&a[l][k]!='0')
                                {
                                    if(a[i][j]==a[l][k]&&a[i][j]!=a[i][k])
                                        d++;
                                }
                            }
                    }
                }
            }
        fo<<d<<endl;
    }
}
int main()
{
    sub1();
    return 0;
}
