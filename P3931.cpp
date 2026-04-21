// https://www.luogu.com.cn/problem/P3931
#include <bits/stdc++.h>
using namespace std;
int n, root;
vector<pair<int, int>> v[100005];
vector<pair<int, int>> g[100005];
pair<int, int> up[100005];
bool vis[100005];
int f[100005][2];
void make_tree(int node) {
    vis[node] = true;
    for (const auto &item : v[node]) {
        if (vis[item.first])
            continue;
        g[node].push_back(item);
        up[item.first] = { node, item.second };
        make_tree(item.first);
    }
}
void dfs(int node) {
    for (const auto &item : g[node])
        dfs(item.first);
    f[node][1] = up[node].second;
    if (g[node].empty()) {
        f[node][0] = 1e9;
        return;
    }
    for (const auto &item : g[node])
        f[node][0] += min(f[item.first][0], f[item.first][1]);
}
int main() {
    cin >> n >> root;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    make_tree(root);
    dfs(root);
    // for (int i = 1; i <= n; i ++) {
    //     cout << up[i].first << " " << up[i].second << endl;
    // }
    cout << f[root][0] << endl;
    return 0;
}
