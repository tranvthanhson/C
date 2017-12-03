#include<iostream>
#include<math.h>
#include<fstream>
#include<map>
#include<cstring>
using namespace std;
ifstream fi("EP.INP");
ofstream fo("EP.OUT");
typedef long long ll;
ll a,b,t;
ll nt[1000000]={0};

//sang nguyen to
void sangNguyenTo(){
	for(int i=2; i<=1000; i++){
		if(nt[i] == 0){
			int j = i*i;
			while(j<=1000000){
				nt[j] = i;
				j = j++;
			}
		}
	}
	for(int i=2; i<=1000000; i++){
		if(nt[i] == 0) nt[i] = i;
	}
}

ll tinh(ll y)// tính tích các uoc nguyen to cua x
{
	ll p,tmp=1,x=y;
	while(x>1)
	{
		p=nt[x];
		while(x%p==0)
			x/=p;	
		tmp*=p;	
	}
	return tmp;
}
void sub1()
{
	ll dem=0;
	for(ll i=a;i<b;i++)
	{
		for(ll j=i+1;j<=b;j++)
		{
			if(tinh(i)==tinh(j))
				dem++;
		}
	}
	fo<<dem<<endl;
}



ll dem[1000000];
void process()////dem so luong tich cac uoc nguyen to bang nhau
{
	dem[1000000]={0};
	memset(dem,0,sizeof(dem));
	for(ll i=a;i<=b;i++)
	{
		dem[tinh(i)]++;
	}
}
void sub2()
{
	process();
	ll soluong=0;
	for(ll i=1;i<=1000000;i++)
	{
		soluong+=dem[i]*(dem[i]-1)/2;
	}
	//dem[1000000]={0};

	fo<<soluong<<endl;
}
main()
{
	
	fi>>t;
	sangNguyenTo();
	for(int i=0;i<t;i++)
	{
		fi>>a>>b;
		//sub1();
		sub2();
	}	
}
