#include <bits/stdc++.h>
#define maxn  50005
#define cuoi first
#define dau second
#define mp make_pair
#define PB push_back
#define reset(c) memset(c , 0, sizeof(c) )
using namespace std;
pair < int , int > a[maxn];
int n;
void nhap()
{
    cin >> n;
    for ( int i=1; i<=n; i++)
    {
        int u,v;
        cin >> u >> v;
        a[i]= mp(v,u);
    }
    sort(a+1,a+n+1);
}
void process() {
    long long res =0;
    for (long long i=1; i<=n; i++) {
        long long l,r,mid;
        l=0;
        r= i-1;
        long long ans=i;
        while (l <= r)
        {
            mid = ( l+r )/2;
            if ( a[mid].cuoi <= a[i].dau )
                l=mid+1;
            else {
                r=mid-1; ans = min(ans,mid);
            }
        }
        res += (i-ans);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    // freopen("INP.TXT","r",stdin);
    // freopen("OUT.TXT","w",stdout);
    nhap();
    process();
    return 0;
}
