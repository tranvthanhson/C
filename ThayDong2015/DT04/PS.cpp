#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("PS.INP");
ofstream fo("PS.OUT");
string res;
long long p,q,x,y,u,v,cx,cy;
void sub1()
{
    while(true)
    {
        fi>>p>>q;
       // cout<<p<<" "<<q;
        if(p==q && q==1)
            break;
        res="";
        x=0;
        y=1;
        u=1;
        v=0;
        while(cx!=p && cy!=q)
        {
            cx=x+u;
            cy=y+v;
            if (cx==p && cy==q)
                break;
            if (cx*q<cy*p)
                res+="R";
            else
                res+="L";
            if (res[res.size()-1]=='R')
            {
                x=cx;
                y=cy;
            }
            else
            {
                u=cx;
                v=cy;
            }
        }
        fo<<res<<endl;
    }
}
int main()
{
    sub1();
    return 0;
}
