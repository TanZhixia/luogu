// https://www.luogu.com.cn/problem/P8625
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005];
vector<int> g[100005];
int f[100005];
int vis[100005];
int ans;
void dp(int node) {
    if (vis[node])
        return;
    vis[node] = 1;
    f[node] = a[node];
    if (g[node].size() == 0) {
        vis[node] = 0;
        return;
    }
    for (const auto& item : g[node]) {
        dp(item);
        if (!vis[item] && f[item] > 0)
            f[node] += f[item];
    }
    vis[node] = 0;
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp(1);
    for (int i = 1; i <= n; i ++)
        ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
