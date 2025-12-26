#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, s;
vector<int> g[150];
int d[150][150];
int dis[150], vis[150];
const int INF = 2000000000;
void dijkstra() {
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i ++)
        dis[i] = INF;
    dis[s] = 0;
    for (int i = 1; i <= n; i ++) {
        int node = 1;
        for (int j = 2; j <= n; j ++)
            if (dis[j] < dis[node] && !vis[j] || !vis[j] && vis[node])
                node = j;
        vis[node] = 1;
        for (int j = 0; j < g[node].size(); j ++)
            dis[g[node][j]] = min(dis[g[node][j]], dis[node] + d[node][g[node][j]]);
    }
}
signed main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i ++) {
        int u, v, x;
        cin >> u >> v >> x;
        g[u].push_back(v);
        d[u][v] = x;
    }
    dijkstra();
    for (int i = 1; i <= n; i ++)
        cout << dis[i] << " ";
    cout << endl;
    return 0;
}
