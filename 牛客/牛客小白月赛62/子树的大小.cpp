#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 500010;
const ll mod = 1e9 + 7;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x)
{
	char F[200];
	ll tmp=x>0?x:-x;
	if(x<0)
		putchar('-');
	int cnt=0;
	while(tmp>0)
	{
		F[cnt++]=tmp%10+'0';
		tmp/=10;
	}
	while(cnt>0)
		putchar(F[--cnt]);
}
void solve()
{
    ull n, k, m;
    n=read(),k=read(),m=read();
    for (int i = 1; i <= m; i++)
    {
        ull q=0;
        q=read();
        if(k==1)
        {
            cout<<n-q<<'\n';
            continue;
        }
        ull ans = 0;
        ull bs = 1;
        while (k * q + 1 < n)
        {
            ans += bs;
            bs *= k;
            q = k * q + 1;
        }
        // cout<<q<<' '<<bs<<' ';
        // for(int w=0;w<bs;w++)
        // {
        //     if(q+w<n)
        //     {
        //         ans++;
        //     }
        //     else break;
        // }
        ull l = 0, r = bs - 1;
        while (l < r)
        {
            ull mid = (l + r + 1) >> 1;
            if (q + mid < n)
                l = mid;
            else
                r = mid - 1;
        }
        // cout<<l<<' ';
        if (q + l < n)
            ans += (l + 1);
        write(ans);
        putchar('\n');
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    int t = 1;
    t=read();
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}