#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
ifstream fi("remain.inp");
ofstream fo("remain.out");
long long a[105],n,ma=0,mi=999999999999999999;
bool kt(long long d)
{
	for(int i=1;i<n;i++)
	{
		if(a[i]%d!=a[0]%d)
			return false;
	}
	return true;
}
long long usc(long long u, long long v)
{
	if(v==0) return u;
	else
		return usc(v,u%v);
}
void sub1()
{
	for(int i=0;i<n;i++)
	{
		fi>>a[i];
		if(a[i]>ma)
			ma=a[i];
	}
	for(int i=ma;i>0;i--)
	{
		if(kt(i))
		{
			fo<<i<<endl;
			break;
		}
	}
}
void sub2()
{
	for(int i=0;i<n;i++)
	{
		fi>>a[i];
		if(a[i]<mi)
			mi=a[i];	
	}
	long long tpm2=a[0]-mi,tpm1;
	for(int i=1;i<n;i++)
	{
		tpm1=a[i]-mi;
		tpm2=usc(tpm1,tpm2);
	}
	fo<<tpm2<<endl;
}
int main()
{

	fi>>n;
	//sub1();
	sub2();
}	
