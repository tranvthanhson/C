#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
ifstream fi("LCM.INP");
ofstream fo("LCM.OUT");
typedef long long ll;
ll a,b;
ll nt[1000000]={0};
void sangnt()
{
    for(int i=2;i<=1000;i++)
    {
        if(nt[i]==0)
        {
            ll j=i*i;
            while(j<=1000000)
            {
                nt[j]=i;
                j=j+i;
            }
        }
    }
}
int main()
{

}
