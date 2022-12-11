#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
struct seg
{
    int l;
    int r;
    int id;
}a[maxn];
int ans[maxn];
bool cmp(seg x,seg y)
{
    if(x.r==y.r)
    {
        return x.l<y.l;
    }
    return x.r<y.r;
}
void solve()
{
    int n;
    cin>>n;
    set<int>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
        s.insert(i);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        auto it=s.lower_bound(a[i].l);
        if(it==s.end()||*it>a[i].r)
        {
            cout<<-1<<'\n';
            return;
        }
        ans[a[i].id]=*it;
        s.erase(it);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
    return 0;
}