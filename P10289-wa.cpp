// https://www.luogu.com.cn/problem/P10289
#include <bits/stdc++.h>
using namespace std;
int n, k, q;
int u, v;
int to[200005];
int Link[200005][2];
set<int> g[200005];
int vis[200005];
int ans;
void dfs(int node, int step = 0) {
    vis[node] = 1;
    if (node == v) {
        ans = min(ans, step);
        return;
    }
    if (step >= ans)
        return;
    for (int i : g[node])
        if (!vis[i])
            dfs(i, step + 1);
    vis[node] = 0;
}
int main() {
    cin >> n >> k >> q;
    for (int i = 1; i < n; i ++) {
        cin >> u >> v;
        Link[i][0] = u;
        Link[i][1] = v;
        to[i] = i;
    }
    to[n] = n;
    for (int i = 1; i <= k; i ++) {
        cin >> u;
        to[u] = 0;
    }
    for (int i = 1; i < n; i ++) {
        if (to[Link[i][0]] == to[Link[i][1]])
            continue;
        g[to[Link[i][0]]].insert(to[Link[i][1]]);
        g[to[Link[i][1]]].insert(to[Link[i][0]]);
    }
    // for (int i = 0; i <= n; i ++) {
    //     cout << i << " has: ";
    //     for (int j : g[i])
    //         cout << j << " ";
    //     cout << endl;
    // }
    while (q --) {
        cin >> u >> v;
        u = to[u];
        v = to[v];
        ans = 1e9;
        memset(vis, 0, sizeof(vis));
        dfs(u);
        cout << ans << endl;
    }
    return 0;
}
