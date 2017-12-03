#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
typedef long long ll;
ifstream fi("NM13.INP");
ofstream fo("NM13.OUT");
ll t,n,m,f[122][121][10];

long long duyet2(ll i,ll s,ll d)
{
	ll sl;
	if(s>m) return 0;
	if(f[i][s][d]>-1) return (f[i][s][d]);
	if(i>n) return(s==m);
	sl=0;
	for(ll v=0;v<=9;v++)
	{
		if(d*10+v!=13)
			sl+=duyet2(i+1,s+v,v);
			
	}
	f[i][s][d]=sl;
	return sl;
	
}
void sub2()
{
	memset(f,255,sizeof(f));
	fo<<duyet2(1,0,0)<<endl;
	
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
