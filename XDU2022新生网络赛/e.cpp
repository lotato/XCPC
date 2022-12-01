#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
struct node
{
    ll l,r,c;
};
void solve()
{
    ll n,q,k;
    cin>>n>>q>>k;
    vector<node>a;
    map<ll,ll>mp;
    a.push_back({1,n,1});
    mp[1]+=n-1+1;
    for(int i=1;i<=q;i++)
    {
        ll l,r,x,c;
        cin>>l>>r>>x>>c;
        vector<node>tmp;
        for(auto ai:a)
        {
            if(min(ai.r,r)>=max(ai.l,l))
            {
                if(ai.l<=l&&ai.r>=r)
                {
                    mp[ai.c]-=(r-l+1);
                    mp[((ai.c^x)%k)+1]+=(r-l+1);
                    if(ai.l<=l-1) tmp.push_back({ai.l,l-1,ai.c});
                    tmp.push_back({l,r,((ai.c^x)%k)+1});
                    if(ai.r>=r+1) tmp.push_back({r+1,ai.r,ai.c});
                }
                else if(ai.l<=l&&ai.r<=r)
                {
                    mp[ai.c]-=(ai.r-l+1);
                    mp[((ai.c^x)%k)+1]+=(ai.r-l+1);
                    if(ai.l<=l-1) tmp.push_back({ai.l,l-1,ai.c});
                    tmp.push_back({l,ai.r,((ai.c^x)%k)+1});
                }
                else if(ai.l>=l&&ai.r<=r)
                {
                    mp[ai.c]-=(ai.r-ai.l+1);
                    mp[((ai.c^x)%k)+1]+=(ai.r-ai.l+1);
                    tmp.push_back({ai.l,ai.r,((ai.c^x)%k)+1});
                }
                else if(ai.l>=l&&ai.r>=r)
                {
                    mp[ai.c]-=(r-ai.l+1);
                    mp[((ai.c^x)%k)+1]+=(r-ai.l+1);
                    tmp.push_back({ai.l,r,((ai.c^x)%k)+1});
                    if(ai.r>=r+1) tmp.push_back({r+1,ai.r,ai.c});
                }
            }
            else
            {
                tmp.push_back(ai);
            }
        }
        // for(auto ai:tmp)
        // {
        //     cout<<ai.l<<' '<<ai.r<<' '<<ai.c<<'\n';
        // }
        a=tmp;
        cout<<mp[c]<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
    return 0;
}