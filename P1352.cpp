// https://www.luogu.com.cn/problem/P1352
#include <bits/stdc++.h>
using namespace std;
int n;
int root;
int a[6005];
vector<int> g[6005];
int f[6005][2];
int cnt[6005];
void dfs(int node) {
    f[node][1] = a[node];
    for (const auto& item : g[node]) {
        dfs(item);
        if (f[item][0] <= 0 && f[item][1] <= 0)
            continue;
        f[node][0] += max(f[item][0], f[item][1]);
        f[node][1] += f[item][0];
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u);
        cnt[u] ++;
    }
    for (int i = 1; i <= n; i ++)
        if (cnt[i] == 0)
            root = i;
    dfs(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}
