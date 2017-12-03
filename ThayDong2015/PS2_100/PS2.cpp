#include<iostream>
#include<math.h>
#include<fstream>
#include<map>
#include<cstring>
using namespace std;
ifstream fi("PS2.INP");
ofstream fo("PS2.OUT");
typedef long long ll;
ll n,M,d[1001];
void sub1()// nhi phan     (a+b)%M=(a%M+b%M)%M
{
	ll x=0,y=1,u=1,v=0;
	ll p=x+u,q=y+v;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=d[i];j++)
		{
			if(i%2==1)
			{
				x=p;y=q;
			}
			else
			{
				u=p;v=q;
			}
			p=(x+u)%M;q=(y+v)%M;
		}
	}
	fo<<p%M<<" "<<q%M;	
}

void sub2()
{
	ll x=0,y=1,u=1,v=0;
	ll p=x+u,q=y+v;
	for(ll i=1;i<=n;i++)
	{
		
		if(i%2==1)
		{
			x=((d[i]-1)*u+p)%M;y=((d[i]-1)*v+q)%M;
		}
		else
		{
			u=((d[i]-1)*x+p)%M;v=((d[i]-1)*y+q)%M;
		}
		p=(x+u);q=(y+v);
	}
	fo<<p%M<<" "<<q%M;	
}
ll nhanmod(ll a, ll b)
{
	ll kq=0;
	while(b>0)
	{
		if(b%2==1)
			kq=(kq+a)%M;
		a=(a*2)%M;
		b/=2;	
	}
	return kq;
}
void sub3()// a*b=2a*(b/2)+ a*(b%2) nhan An Do
{
	ll x=0,y=1,u=1,v=0;
	ll p=x+u,q=y+v;
	for(ll i=1;i<=n;i++)
	{
		
		if(i%2==1)
		{
			x=(nhanmod(d[i]-1,u)+p)%M;y=(nhanmod(d[i]-1,v)+q)%M;
		}
		else
		{
			u=(nhanmod(d[i]-1,x)+p)%M;v=(nhanmod(d[i]-1,y)+q)%M;
		}
		p=(x+u);q=(y+v);
	}
	fo<<p%M<<" "<<q%M;
}
int main()
{
		fi>>n>>M;
		for(int i=1;i<=n;i++)
			fi>>d[i];
		//sub1();
		//sub2();
		sub3();	
			
		
}
