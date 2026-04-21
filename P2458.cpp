// https://www.luogu.com.cn/problem/P2458
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1505];
vector<int> v[1505], g[1505];
bool vis[1505];
int f[1505][3];
void make_tree(int node) {
    vis[node] = true;
    for (const auto& item : v[node]) {
        if (vis[item])
            continue;
        g[node].push_back(item);
        make_tree(item);
    }
}
void dfs(int node) {
    for (const auto& item : g[node])
        dfs(item);
    f[node][0] = a[node];
    f[node][1] = 0;
    f[node][2] = 0;
    if (g[node].empty()) {
        f[node][1] = 1e9;
        return;
    }
    bool flag = true;
    int mm = 1e9;
    for (const auto& item : g[node]) {
        f[node][0] += min({f[item][0], f[item][1], f[item][2]});
        f[node][1] += min({f[item][0], f[item][1]});
        f[node][2] += min({f[item][0], f[item][1]});
        mm = min(mm, f[item][0] - f[item][1]);
        if (f[item][0] <= f[item][1])
            flag = false;
    }
    if (flag)
        f[node][1] += mm;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int index, m, node;
        cin >> index;
        cin >> a[index] >> m;
        for (int j = 1; j <= m; j ++) {
            cin >> node;
            v[index].push_back(node);
            v[node].push_back(index);
        }
    }
    make_tree(1);
    dfs(1);
    cout << min({f[1][0], f[1][1]}) << endl;
    return 0;
}
