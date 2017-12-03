#include <iostream>
#include <fstream>

using namespace std;
int m,n,k;
long long res;
bool a[1001][1001];
ifstream fi("SQUARES.INP");
ofstream fo("SQUARES.OUT");
int de[101][3];
void sub1()
{

    int x1,x2,x3,x4,y1,y2,y3,y4;
    for(int r=1;r<=min(m,n)-1;r++)
    {
        for (int x=1;x<=m-r;x++)
        {
            for(int y=1;y<=n-r;y++)
            {
                for (int h=0;h<=r-1;h++)
                {
                    x1=x;y1=y+h;
                    x2=x+h;y2=y+r;
                    x3=x+r;y3=y+r-h;
                    x4=x+r-h;y4=y;
                    if(!a[x1][y1] && !a[x2][y2] && !a[x3][y3] && !a[x4][y4])
                        res++;
                }
            }
        }
    }
    fo<<res;
}
long long cntAll()
{
    long long re;
    for (int r=1;r<=min(m,n)-1;r++)
         re+=r*(n-r)*(m-r);
    return re;
}
long long cntError()
{

}
void sub4()
{
    fi>>m>>n>>k;
    res=cntAll();
    int x,y,tmp;
    while(tmp--)
    {
        fi>>x>>y;
        a[x][y]=true;
        de[k-tmp][1]=x;
        de[k-tmp][2]=y;
    }
    for (int i=1;i<=k;i++)
    {
        for(int r=1;r<=min(m,n)-1;r++)
        {
            for(int h=0;h<=r-1;h++)
            {
                x=de[i][1];
                y=de[i][2];

            }
        }
    }
    fo<<res;
}
int main()
{
    res=0;
    fi>>m>>n>>k;
    int x,y;
    if(k==0)
    {
        fo<<cntAll()<<endl;
        return 0;
    }
    while(k--)
    {
        fi>>x>>y;
        a[x][y]=true;
    }
    sub1();
    return 0;
}
