#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=500010;
const ll mod=1e9+7;
void solve()
{
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        bool flag=false;
        int t;
        cin>>t;
        for(int j=1;j<=t;j++)
        {
            string s;
            cin>>s;
            int t1=((s[0]-'0')*10+(s[1]-'0'))*60+(s[3]-'0')*10+(s[4]-'0');
            int t2=((s[6]-'0')*10+(s[7]-'0'))*60+(s[9]-'0')*10+(s[10]-'0');
            if(t2-t1>=30)
            {
                flag=1;
            }
        }
        if(flag)
        {
            cnt++;
        }
    }
    if(cnt>=n)
    {
        cout<<"ZhongYuDaWanKaLe\n";
    }
    else
    {
        cout<<"WanDanTiYuGuaLe\n";
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