#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
typedef long long ll;
ifstream fi("squares.inp");
ofstream fo("squares.out");
ll m,n,k,d[1000][1000],dem=0;

void sub1()
{
	for(ll r=1;r<=min(m-1,n-1);r++)//dem+=r*(m-r)(n-r)
		for(ll x=1;x<=(m-r);x++)
			for(ll y=1;y<=(n-r);y++)
				for(ll h=0;h<=(r-1);h++)
				{
					ll xA=x, yA=y+h, xB=x+h, yB=y+r, xD=x+r, yD=y+h, xC=x+r, yC=y+r-h;
					if(d[xA][yA]==0&&d[xB][yB]==0&&d[xC][yC]==0&&d[xD][yD]==0)
						dem++;
				}
	fo<<dem;			
}
void sub2()
{
		for(ll r=1;r<=min(m-1,n-1);r++)
			dem+=r*(m-r)*(n-r);
		fo<<dem;	
}

int main()
{
	fi>>m>>n>>k;
	for(int i=1;i<=k;i++)
	{
		int u,v;
		fi>>u>>v;
		d[u][v]=1;	
	}
	if(k==0)sub2();
		else sub1();
}
