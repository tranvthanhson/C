#include<iostream>
#include<fstream>
using namespace std;
ifstream fi("us.inp");
ofstream fo("us.out");
typedef long long ll;
ll t,a,b,u,v;
void sub1()
{
	for(ll i=a;i<=b;i++)
	{	
		for(ll j=1;j<=i;j++)
		 {
		 	if(i%j==0)
		 	{
		 		u++;
		 		v+=j;
		 	}
		 }
	}
	 fo<<u<<" "<<v<<endl;
	 u=0;v=0;
}

//sub2
ll su[1000001]={0},tu[1000001]={0};
void process1()// tim so luong uoc va tong uoc
{
	for(ll x=1;x<=1000000;x++)
	{
		ll y=x;
		while(y<=1000000)
		{
			su[y]++;
			tu[y]+=x;
			y+=x;
		}
	}
	//fo<<su[5]<<" "<<tu[5];
}
void sub2()
{
	ll sluoc=0,tuoc=0;
	for(ll i=a;i<=b;i++)
	{
		sluoc+=su[i];
		tuoc+=tu[i];
	}
	fo<<sluoc<<" "<<tuoc<<endl;
}

//sup3
ll dsu[1000001]={0};
ll tsu[1000001]={0};
void process2()
{
	//dsu[0]=0;
	//tsu[0]=0;
	for(ll i=1;i<=1000000;i++)
	{
		dsu[i]=dsu[i-1]+su[i];
		tsu[i]=tsu[i-1]+tu[i];
	}
}
void sub3()
{
	ll sluoc=0,tuoc=0;
	sluoc=dsu[b]-dsu[a-1];
	tuoc=tsu[b]-tsu[a-1];
	fo<<sluoc<<" "<<tuoc<<endl;
}
int main()
{
	fi>>t;
	process1();
	process2();
	for(ll i=0;i<t;i++)
	{
		fi>>a>>b;
		//sub1();
		//sub2();
		sub3();
	}	
}
