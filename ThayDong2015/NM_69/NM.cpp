#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
typedef long long ll;
ifstream fi("NM.INP");
ofstream fo("NM.OUT");
ll t,n,m,f[122][121],dem=0;

void duyet(ll i,ll s)
{
	if(s>m) return;
	if(i>n)
	{
		if(s==m)
		{
			dem++;
		}
		return;
	}
	for(ll v=0;v<=9;v++)
	{
		duyet(i+1,s+v);
	}
}
void sub1()
{
	dem=0;
	duyet(1,0);
	fo<<dem<<endl;
}

long long duyet2(ll i,ll s)
{
	ll sl;
	if(s>m) return 0;
	if(f[i][s]>-1) return (f[i][s]);
	if(i>n) return(s==m);
	sl=0;
	for(ll v=0;v<=9;v++)
	{
		sl+=duyet2(i+1,s+v);
			
	}
	f[i][s]=sl;
	return sl;
	
}
void sub2()
{
	memset(f,255,sizeof(f));
	fo<<duyet2(1,0)<<endl;
	
}
int main()
{
	
	fi>>t;
	for(ll i=0;i<t;i++)
	{

		fi>>n>>m;
		//sub1();
		sub2();
	}
}
