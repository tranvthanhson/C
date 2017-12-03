#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<stdlib.h>
#include<math.h>
using namespace std;
typedef long long ll;
ifstream fi("BT2.INP");
ofstream fo("BT2.OUT");
ll n,k,kq,f[102][102][102];


long long tinh(ll i,ll c,ll maxc)
{
	ll sl;
	if(i>n) return (c==0)&&(maxc==k);
	if(f[i][c][maxc]>-1) return (f[i][c][maxc]);
	sl=tinh(i+1,c+1,max(c+1,maxc));
	if(c>0)
		sl+=tinh(i+1,c-1,maxc);
	f[i][c][maxc]=sl;	
	return sl;	
}

string xuly(ll x)
{
	string str="",tmp="";
	int dem=0;
	while(x>0)
	{
		str+=(char)(x%10+48);
		x/=10;
		dem++;
	}
	for(int i=dem-1;i>dem-6;i--)
		tmp+=str[i];
	tmp+="...";	
	for(int i=4;i>=0;i--)
		tmp+=str[i];
	return tmp;	
}
int main()
{
	while(fi>>n>>k)
	{	memset(f,-1,sizeof(f));
		kq=tinh(1,0,0);
		if(kq<10000000000)
			fo<<kq<<endl;
		 else fo<<xuly(kq)<<endl;	
	}
}

