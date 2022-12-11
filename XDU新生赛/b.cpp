#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1000010;
const ll mod=1e9+7;
int a[maxn];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    vector<pair<int,int>>ans;
    for(int i=2;i<=n;i++)
    {
        if(a[i]/10!=a[i-1]%10)
        {
            ans.push_back({i+ans.size(),(a[i-1]%10)*10+a[i]/10});
        }
    }
    cout<<ans.size()<<'\n';
    for(auto [x,y]:ans)
    {
        cout<<x<<' '<<y<<'\n';
    }
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