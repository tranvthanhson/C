#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
typedef long long ll;
ifstream fi("NM86.INP");
ofstream fo("NM86.OUT");
ll t,n,m,f[122][121][10],h[122][121];

long long duyet2(ll i,ll s,ll d)//tinh tong cac so khong chua chu so 86
{
	ll sl;
	if(s>m) return 0;
	if(f[i][s][d]>-1) return (f[i][s][d]);
	if(i>n) return(s==m);
	sl=0;
	for(ll v=0;v<=9;v++)
	{
		if(d*10+v!=86)
			sl+=duyet2(i+1,s+v,v);
	}
	f[i][s][d]=sl;
	return sl;
}
long long duyet3(ll i,ll s) //tinh tong tat ca cac chu o co do dai n va tong cac chu so =m
{
	ll sl;
	if(s>m) return 0;
	if(h[i][s]>-1) return (h[i][s]);
	if(i>n) return(s==m);
	sl=0;
	for(ll v=0;v<=9;v++)
	{
		sl+=duyet3(i+1,s+v);
	}
	h[i][s]=sl;
	return sl;
	
}
void sub2()// tinh hieu cua tat ca cac so va so khong chua so 86
{
	memset(f,255,sizeof(f));
	memset(h,255,sizeof(h));
	fo<<-duyet2(1,0,0)+duyet3(1,0)<<endl;
	
}
// cach 2
ll g[122][121][10][2];
long long duyet4(ll i,ll s,ll d,bool Ok)
{
	ll sl;
	if(s>m) return 0;
	if(g[i][s][d][Ok]>-1) return (g[i][s][d][Ok]);
	if(i>n) return(s==m);
	sl=0;
	for(ll v=0;v<=9;v++)
	{
			sl+=duyet4(i+1,s+v,v,Ok||d*10+v==86);		
	}
	g[i][s][d][Ok]=sl;
	return sl;
	
}
void sub3()
{
	memset(g,255,sizeof(g));
	fo<<duyet4(1,0,0)<<endl;
}
int main()
{
	
	fi>>t;
	for(ll i=0;i<t;i++)
	{

		fi>>n>>m;
		//sub1();
		//sub2();
		sub3();
	}
}
