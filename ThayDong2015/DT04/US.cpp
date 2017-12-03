#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
int t,a,b;
ifstream fi("USa.INP");
ofstream fo("USa.OUT");
long long u,v;
long long ug[1000001];
long long vg[1000001];
long long ugu[1000001];
long long vgv[1000001];
void gen_sub2()
{
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
//    for(int i=1;i<=1000000;i++)
//    {
//        fo<<vg[i]<<" ";
//    }
  /*  for(int i=1;i<=1000000;i++)
    {
        fo<<vg[i]<<",";
    }*/

}
void gen_sub3()
{
    for(int i=1;i<=1000000;i++)
    {
        int j=i;
        while (j<=1000000)
        {
            ug[j]+=1;
            vg[j]+=i;
            j+=i;
        }
        ugu[i]=ugu[i-1]+ug[i];
        vgv[i]=vgv[i-1]+vg[i];
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
void sub3()
{
    FILE * ipFile;
    ipFile = fopen ("US.INP","r");
    FILE * opFile;
    opFile = fopen ("US.OUT","w");
    fscanf(ipFile,"%d",&t);
    while(t--)
    {
        fscanf(ipFile,"%d %d",&a,&b);
        fprintf(opFile,"%lld %lld\n",ugu[b]-ugu[a-1],vgv[b]-vgv[a-1]);
        //fo<<ugu[b]-ugu[a-1]<<" "<<vgv[b]-vgv[a-1]<<endl;
    }
}
int main()
{
    gen_sub3();
    sub3();
    return 0;
}
