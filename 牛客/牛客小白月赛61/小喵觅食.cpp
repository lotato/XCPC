#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 500010;
const ll mod = 1e9 + 7;
int a[1010][1010];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int vis1[1010][1010], vis2[1010][1010];
int dis1[1010][1010], dis2[1010][1010];
void solve()
{
    int n, m;
    cin >> n >> m;
    int ww, tt;
    cin >> ww >> tt;
    int stx = 0, sty = 0, edx = 0, edy = 0;
    for (int i = 1; i <= n; i++)
    {
        string t;
        cin >> t;
        for (int j = 0; j < m; j++)
        {
            if (t[j] == 'P')
            {
                stx = i;
                sty = j + 1;
            }
            if (t[j] == 'M')
            {
                edx = i;
                edy = j + 1;
            }
            if (t[j] == '*')
            {
                a[i][j + 1] = 1;
            }
            else
            {
                a[i][j + 1] = 0;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({edx, edy});
    vis2[edx][edy] = 1;
    while (!q.empty())
    {
        auto pos = q.front();
        q.pop();
        int x = pos.first, y = pos.second;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (1 <= xx && xx <= n && 1 <= yy && yy <= m && !vis2[xx][yy] && a[xx][yy] != 1)
            {
                dis2[xx][yy] = dis2[x][y] + 1;
                vis2[xx][yy] = 1;
                q.push({xx, yy});
            }
        }
    }
    int ans = 2e9;
    q.push({stx, sty});
    vis1[stx][sty] = 1;
    while (!q.empty())
    {
        auto pos = q.front();
        q.pop();
        int x = pos.first, y = pos.second;
        if(vis2[x][y]&&abs(x-edx)+abs(y-edy)<=tt)
        {
            ans=min(ans,dis1[x][y]+dis2[x][y]);
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (1 <= xx && xx <= n && 1 <= yy && yy <= m && !vis1[xx][yy] && a[xx][yy] != 1 && (abs(xx - stx) + abs(yy - sty) <= ww))
            {
                dis1[xx][yy] = dis1[x][y] + 1;
                vis1[xx][yy] = 1;
                q.push({xx, yy});
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (vis1[i][j] && vis2[i][j] && (abs(i - edx) + abs(j - edy)) <= tt && (abs(i - stx) + abs(j - sty)) <= ww)
    //         {
    //             ans = min(ans, dis1[i][j] + dis2[i][j]);
    //         }
    //     }
    // }
    if (ans == 2e9)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    int t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}