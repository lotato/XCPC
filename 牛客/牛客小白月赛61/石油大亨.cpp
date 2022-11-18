#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
ll t[maxn];
void solve()
{
    ll n,ec,et,p,s;
    cin>>n>>ec>>et>>p>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
    }
    ll ans=0,b=0;
    ll over=0,lst=0;
    deque<ll>q;
    queue<ll>w;
    for(int i=1;i<=n;i++)
    {
        // cout<<q.size()<<' '<<w.size()<<'\n';
        // cout<<ans<<' '<<s<<' '<<b<<'\n';
        while(w.size()&&w.front()<=ans)   //先计算完成的油井的收入
        {
            b+=p;
            s+=(ans-w.front())*b;
            w.pop();
        }
        while(s>=ec)    //能造人就硬造
        {
            // cout<<"ress:"<<s<<'\n';
            if(q.size()>=(n-i+1))
            {
                break;
            }
            s-=ec;
            q.push_back(max(ans,lst)+et);
            lst=max(lst,max(ans,lst)+et);
        }
        if(q.size()==0) //没有人就弄钱
        {
            // cout<<b<<'\n';
            if(s<ec&&b==0)
            {
                if(w.size()==0) //如果没有油井了就失败
                {
                    ans=-1;
                    break;
                }
                ans=w.front();  //还有就随便弄一个
                b+=p;
                w.pop();
            }
            // cout<<b<<'\n';
            // cout<<q.size()<<' '<<w.size()<<'\n';
            while(w.size()&&(ec-s+b-1)/b>(w.front()-ans)) //如果可能中途还有油井就算上
            {
                s+=(w.front()-ans)*b;
                b+=p;
                ans=w.front();
                w.pop();
            }
            // cout<<ans<<' '<<b<<'\n';
            //没有油井了就直接算时间
            ll t=(ec-s+b-1)/b;
            // cout<<t<<'\n';
            ans=ans+t;
            s=s+t*b-ec;
            q.push_back(max(ans,lst)+et);
            lst=max(lst,max(ans,lst)+et);
        }
        over=max(over,q.front()+t[i]);
        // cout<<"over:"<<q.front()+t[i]<<'\n';
        w.push(q.front()+t[i]);
        q.pop_front();
        // cout<<q.size()<<' '<<w.size()<<'\n';
        // cout<<ans<<' '<<s<<' '<<b<<'\n';
        // cout<<'\n';
    }
    if(ans!=-1) cout<<over<<'\n';
    else cout<<ans<<'\n';
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