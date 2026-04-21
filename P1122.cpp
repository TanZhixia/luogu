// https://www.luogu.com.cn/problem/P1122
#include <bits/stdc++.h>
using namespace std;
int n;
int a[16005];
vector<int> g[16005];
vector<int> tree[16005];
bool temp_vis[16005];
bool vis[16005];
int node_value[16005];
int ans = -1e9;
void make_tree(int node) {
    if (temp_vis[node])
        return;
    temp_vis[node] = true;
    for (int i = 0; i < g[node].size(); i ++) {
        if (temp_vis[g[node][i]])
            continue;
        tree[node].push_back(g[node][i]);
        make_tree(g[node][i]);
    }
}
void dfs(int node) {
    if (vis[node])
        return;
    vis[node] = true;
    for (int i = 0; i < tree[node].size(); i ++) {
        dfs(tree[node][i]);
        if (node_value[tree[node][i]] > 0)
            node_value[node] += node_value[tree[node][i]];
    }
    node_value[node] += a[node];
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    make_tree(1);
    dfs(1);
    for (int i = 1; i <= n; i ++)
        ans = max(ans, node_value[i]);
    cout << ans << endl;
    return 0;
}
