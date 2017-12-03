#include<iostream>
#include<conio.h>
#include<fstream>
#include<math.h>
#include<cstring>
using namespace std;
long long a[100002],dem[1000002];
void SNT(){
	for(int i=2;i<=sqrt(1000000);i++){
		if(a[i]==0){
			int j=i*i;
			while(j<=1000000){
				a[j]=i;
				j+=i;
			}
		}
	}
	for(int i=2;i<=1000000;i++){
		if(a[i]==0) a[i]=i;
	}
}

int tinh(int x){
	int  tich=1;
	while (x>1)
	{
		int k=a[x];
		while (x%k==0) x/=k;
		tich*=k;
	}
	return tich;
}

main(){
	SNT();
	//ifstream fi("ep.inp");
	//ofstream fo("ep.out");
	int T;
	//fi>>T;
	cout<<a[10];
	cin>>T;
	int l,r;
	for(int i=0;i<T;i++) {
		//fi>>l>>r;
		cin>>l>>r;
		memset(dem,0,sizeof(dem));
		for(int j=l;j<=r;j++) dem[tinh(j)]++;
		long s=0;
		for(int j=1;j<=r;j++)
			if(dem[j]>1) s+=(dem[j]*(dem[j]-1))/2;
			//fo<<s<<endl;
			cout<<s<<endl;
	}
	//fi.close();
	//fo.close();
}
