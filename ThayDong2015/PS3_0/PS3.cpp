#include<iostream>
#include<math.h>
#include<fstream>
#include<map>
#include<cstring>
using namespace std;
ifstream fi("PS3.INP");
ofstream fo("PS3.OUT");
typedef long long ll;
ll t,M,c[1000000]={0},dem=0;
void coso(ll a)
{
	while(a>0)
	{
		c[dem]=a%2;
		a/=2;
		dem++;
	}
}
void sub1()
{
	coso(t);
	ll x=0,y=1,u=1,v=0,p,q;
	p=x+u,q=y+v;
	for(ll i=dem-2;i>=0;i--)
	{
		if(c[i]%2==1)
		{
			x=p%M;y=q%M;
		}
		else
		{
			u=p%M;v=q%M;
		}
		p=(x+u)%M;q=(y+v)%M;
	}
	fo<<p%M<<" "<<q%M;
}
int main()
{
	fi>>t>>M;
	sub1();
}
