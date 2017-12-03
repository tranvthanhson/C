#include <iostream>
#include <fstream>

using namespace std;
int m,n,k;
long long res;
bool a[1001][1001];
int de[101][3];
long long cnt;
ifstream fi("SQUARES.INP");
ofstream fo("SQUARES.OUT");

void sub1()
{
    fi>>m>>n>>k;
    res=0;
    if(k==0)
    {
        for (int r=1; r<=min(m,n)-1; r++)
            res+=r*(n-r)*(m-r);
    }
    else
    {
        int x,y;
        while(k--)
        {
            fi>>x>>y;
            a[x][y]=true;
        }
        int x1,x2,x3,x4,y1,y2,y3,y4;
        for(int r=1; r<=min(m,n)-1; r++)
        {
            for (int x=1; x<=m-r; x++)
            {
                for(int y=1; y<=n-r; y++)
                {
                    for (int h=0; h<=r-1; h++)
                    {
                        x1=x;
                        y1=y+h;
                        x2=x+h;
                        y2=y+r;
                        x3=x+r;
                        y3=y+r-h;
                        x4=x+r-h;
                        y4=y;
                        if(!a[x1][y1] && !a[x2][y2] && !a[x3][y3] && !a[x4][y4])
                            res++;
                    }
                }
            }
        }
    }
    fo<<res;
}
bool isRightA(int x,int y, int xa, int ya,int h,int r)
{
    int xb,xc,xd,yb,yc,yd;
    xb=x+h; yb=y+r;
    xc=x+r-1; yc=y+r-h-1;
    xd=x+r-h-1; yd=y;
    if( (xb<=m) && (xc<=m) && (xd<=m) && (yb<=n) && (yc<=n) && (yd<=n) && (xb>=1) && (xc>=1) && (xd>=1) & (yb>=1) && (yc>=1) && (yd>=1))
    {
        if (a[xa][ya])
            return true;
    }
    return false;
}
bool isRightB(int x, int y, int xb, int yb,int h,int r)
{
    int xa,xc,xd,ya,yc,yd;
    xa=xb-h; ya=yb-(r-h)-1;
    xc=x+r-1; yc=y+r-h-1;
    xd=x+r-h-1; yd=y;
    if( (xa<=m) && (xc<=m) && (xd<=m) && (ya<=n) && (yc<=n) && (yd<=n) && (xa>=1) && (xc>=1) && (xd>=1) & (ya>=1) && (yc>=1) && (yd>=1))
    {
        if (a[xb][yb])
            return true;
    }
    return false;
}
bool isRightC(int x, int y, int xc, int yc,int h,int r)
{
    int xb,xa,xd,yb,ya,yd;
     xb=x+h; yb=yc+h;
    xa=xb-h; ya=yb-(r-h)-1;
    xd=x+r-h-1; yd=y;
    if( (xb<=m) && (xa<=m) && (xd<=m) && (yb<=n) && (ya<=n) && (yd<=n) && (xb>=1) && (xa>=1) && (xd>=1) & (yb>=1) && (ya>=1) && (yd>=1))
    {
        if (a[xc][yc])
            return true;
    }
    return false;
}
bool isRightD(int x, int y, int xd, int yd,int h,int r)
{
    int xb,xc,xa,yb,yc,ya;
    xc=x+r-1; yc=y+r-h;
    xb=x+h; yb=yc+h;
    xa=xb-h; ya=yb-(r-h)-1;
    if( (xb<=m) && (xc<=m) && (xa<=m) && (yb<=n) && (yc<=n) && (ya<=n) && (xb>=1) && (xc>=1) && (xa>=1) & (yb>=1) && (yc>=1) && (ya=1))
    {
        if (a[xd][yd])
            return true;
    }
    return false;
}
void sub4()
{
    cnt=0;
    fi>>m>>n>>k;
    for (int r=1; r<=min(m,n)-1; r++)
        res+=r*(n-r)*(m-r);
    if(k==0)
        fo<<res<<endl;
    else
    {
        int x,y,tmp=k;
        while(tmp--)
        {
            fi>>x>>y;
            a[x][y]=true;
            de[k-tmp][1]=x;
            de[k-tmp][2]=y;
        }
        int x1,x2,x3,x4,y1,y2,y3,y4;
        for(int i=1;i<=k;i++)
        {
            for(int r=1; r<=min(m,n)-1; r++)
            {
                for (int h=0; h<=r-1; h++)
                {
                    x=de[i][1];y=de[i][2]-h;
                    if (isRightA(x,y,de[i][1],de[i][2],h,r))
                        cnt++;
                    x=de[i][1]-h;y=de[i][2]-r+1;
                    if (isRightB(x,y,de[i][1],de[i][2],h,r))
                        cnt++;
                    x=de[i][1]-r+1;y=de[i][2]-r+h;
                    if (isRightC(x,y,de[i][1],de[i][2],h,r))
                        cnt++;
                    x=de[i][1]-r+h;y=de[i][2];
                    if (isRightD(x,y,de[i][1],de[i][2],h,r))
                        cnt++;
                }
            }
        }
        fo<<res-cnt<<endl;
    }
}

int main()
{
    sub4();
    return 0;
}
