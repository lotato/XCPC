#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=200010;
const ll mod=1e9+7;

int a[maxn]; // 初始值
#define lson rt << 1	  // == rt * 2	 左儿子
#define rson rt << 1 | 1  // == rt * 2 + 1 右儿子
#define int_mid int mid = tree[rt].l + tree[rt].r >> 1

struct node {
	int l, r;
	int val;
} tree[maxn * 4];
 
void push_up(int rt) {
	tree[rt].val = min(tree[lson].val, tree[rson].val);
	//tree[rt].val = max(tree[lson].val, tree[rson].val);
	// tree[rt].val = tree[lson].val + tree[rson].val;
}

void build(int rt, int l, int r) { // 建树
	tree[rt].l = l, tree[rt].r = r;
	if (l == r) {
		tree[rt].val = a[l]; // 给定一个初始值
		return;
	} else {
		int mid = l + r >> 1; // (l + r) / 2
		build(lson, l, mid);
		build(rson, mid + 1, r);
		push_up(rt);
	}
}
 
void update_point(int rt, int pos, ll val) { // 单点更新
	if (tree[rt].l == tree[rt].r && pos == tree[rt].l) {
		tree[rt].val = val;
		return;
	}
	int_mid;
	if (pos <= mid) update_point(lson, pos, val);
	else update_point(rson, pos, val);
	push_up(rt);
}

int query(int rt,int l,int r,int val)
{
    // cout<<tree[rt].l<<' '<<tree[rt].r<<' '<<l<<' '<<r<<'\n';
    if(tree[rt].l==tree[rt].r)
    {
        if(tree[rt].val<=val)
        {
            return l;
        }
        else
        {
            return -1;
        }
    }
    int_mid;
    if(l>mid)
    {
        return query(rson,l,r,val);
    }
    if(r<=mid)
    {
        return query(lson,l,r,val);
    }
    int id=-1;
    if(tree[lson].val<=val)
    {
        id = query(lson,l,mid,val);
    }
    if(id==-1&&tree[rson].val<=val)
    {
        id = query(rson,mid+1,r,val);
    }
    return id;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        a[i]=2e9;
    }   
    build(1,1,n);
    for(int i=1;i<=q;i++)
    {
        char op;
        cin>>op;
        if(op=='M')
        {
            int x,y;
            cin>>x>>y;
            update_point(1,y,x);
        }
        else
        {
            int x,y;
            cin>>x>>y;
            cout<<query(1,y,n,x)<<'\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
    return 0;
}