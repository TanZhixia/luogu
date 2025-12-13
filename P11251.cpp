// https://www.luogu.com.cn/problem/P11251
#include <bits/stdc++.h>
using namespace std;
int n;
int c[100005];
int u, v;
vector<int> g[100005];
int ans = -1;
int vis[100005];
void dfs(int node, int len = 1) {
    if (vis[node])
        return;
    vis[node] = 1;
    ans = max(ans, len);
    for (int i : g[node])
        dfs(i, len + 1);
    vis[node] = 0;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    for (int i = 1; i < n; i ++) {
        cin >> u >> v;
        if (c[u] != c[v]) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; i ++)
        dfs(i);
    cout << ans << endl;
    return 0;
}
