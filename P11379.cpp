// https://www.luogu.com.cn/problem/P11379
#include <bits/stdc++.h>
using namespace std;
int n, k;
int u, v;
int a[1005], vis[1005];
vector<int> g[1005];
int ans = -1;
void dfs(int node, int black = 0, int step = 1) {
    if (vis[node] || black > k)
        return;
    vis[node] = 1;
    ans = max(ans, step);
    for (int i : g[node]) {
        if (a[i])
            dfs(i, black + 1, step + 1);
        else
            dfs(i, black, step + 1);
    }
    vis[node] = 0;
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i < n; i ++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i ++) {
        memset(vis, 0, sizeof(vis));
        if (a[i])
            dfs(i, 1);
        else
            dfs(i);
    }
    cout << ans << endl;
    return 0;
}
