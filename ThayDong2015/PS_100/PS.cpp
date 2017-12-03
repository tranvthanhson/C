#include<iostream>
#include<math.h>
#include<fstream>
#include<map>
#include<cstring>
using namespace std;
ifstream fi("PS.INP");
ofstream fo("PS.OUT");
typedef long long ll;
ll p,q;
void sub1()// nhi phan
{
	ll x=0,y=1,u=1,v=0,m,n;
	while(1)
	{
		m=x+u,n=y+v;
		if(m==p&&n==q)
		{
			fo<<endl;
			break;
		}
		if(m*q<n*p)
		{
			fo<<"R";
			x=m;y=n;
		}
		else
		{
			fo<<"L";
			u=m;v=n;
		}
	}
}

int main()
{
	while(1)
	{
		fi>>p>>q;
		if(p==1&&q==1)
			break;
		sub1();	
			
	}	
}
