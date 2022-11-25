#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=4010;
const ll mod=1e9+7;
int a[4010][4010];
int f[4010];
int sz[4010];
int d[4010];
int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}
int n;
int clk,dfn[maxn],low[maxn],cut_node[maxn],cnt;
stack<int>sta;
void dfs(int u,int fa)
{
    sta.push(u);
    low[u]=dfn[u]=++clk;
    int son=0;
    for(int v=1;v<=n;v++)
    {
        if(a[u][v]==0) continue;
        if(!dfn[v])
        {
            son++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);  //父子边，树边
            if(dfn[u]<=low[v])
            {
                if(fa) cut_node[u]=true;
                cnt++;
                int t;
                do
                {
                    t=sta.top();
                    sta.pop();
                } while(t!=v);  //点双
                
            }
            if(dfn[u]<low[v])
            {
                //u,v是桥边
            }
        }
        else if(v!=fa) low[u]=min(low[u],dfn[v]);   //后向边(返祖边)
    }
    if(fa==-1&&son>1) cut_node[u]=true;
}
void tarjan()
{
    clk=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i]) dfs(i,-1);
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
        sz[i]=0;
        d[i]=0;
        dfn[i]=low[i]=cut_node[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=n;j++)
        {
            a[i][j]=s[j-1]-'0';
            if(a[i][j]) d[i]++;
        }
    }    
    tarjan();
    for(int u=1;u<=n;u++)
    {
        for(int v=1;v<=n;v++)
        {
            if(u==v) continue;
            if(find(u)==find(v)) continue;
            if(a[u][v]==0) continue;
            int fau=find(u),fav=find(v);
            f[fav]=fau;
        }
    }
    for(int i=1;i<=n;i++)
    {
        sz[find(i)]++;
    }
    int mi=n+1,id=0;
    int totc=0;
    for(int i=1;i<=n;i++)
    {
        if(find(i)!=i) continue;
        totc++;
        if(sz[find(i)]<mi)
        {
            mi=sz[find(i)];
            id=i;
        }
    }
    if(mi==n)
    {
        cout<<0<<'\n';
        return;
    }
    bool flag=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        // cout<<cut_node[i]<<' ';
        if(d[i]!=(sz[find(i)]-1)&&(!cut_node[i]))
        {
            flag=1;
            ans=i;
        }
    }
    if(flag)
    {
        cout<<1<<'\n';
        cout<<ans<<'\n';
        return;
    }
    if(totc==2||mi==1)
    {
        cout<<mi<<'\n';
        for(int i=1;i<=n;i++)
        {
            if(find(i)==id)
            {
                cout<<i<<' ';
            }
        }
        cout<<'\n';
        return;
    }
    cout<<2<<'\n';
    int pre=-1,cntt=0;
    for(int i=1;i<=n;i++)
    {
        if(find(i)==pre) continue;
        cout<<i<<' ';
        pre=find(i);
        cntt++;
        if(cntt==2)
        {
            break;
        }
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