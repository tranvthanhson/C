#include<iostream>
#include<string>
#include<fstream>
using namespace std;
typedef long long ll;
ifstream fi("TRIPLES.INP");
ofstream fo("TRIPLES.OUT");
ll t,m,n,a[1000][1000],P,Q;
string str;
void nhap()
{

	fi>>m>>n;
	for(ll x=0;x<m;x++)
	{
		fi>>str;
		for(ll i=0;i<str.size();i++)
		{
			a[x][i]=str[i]-48;	
		}
	}
}
void sub1()
{
	ll sl=0;
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				P=Q=0;
				for(ll x=0;x<m;x++)
					if(a[x][j]==3-a[i][j])
						P++;
				for(ll y=0;y<n;y++)
					if(a[i][y]==3-a[i][j])
						Q++;
				sl+=P*Q;				
			}
		}
	}
	fo<<sl<<endl;
}
void sub2()
{	
	ll d[1000][3]={0},c[1000][3]={0};
	for(ll i=0;i<m;i++)
		for(ll j=0;j<n;j++)
		{
			d[i][a[i][j]]++;
			c[j][a[i][j]]++;
		}
	ll sl=0;
	for(ll i=0;i<m;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				P=d[i][3-a[i][j]];
				Q=c[j][3-a[i][j]];
				sl+=P*Q;				
			}
		}
	}
	fo<<sl<<endl;
}
int main()
{
	fi>>t;
	for(ll i=0;i<t;i++ )
	{
		nhap();
		//sub1();
		sub2();
	}
}
