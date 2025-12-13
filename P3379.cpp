// https://www.luogu.com.cn/problem/P3379
#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int u, v;
vector<int> g[500005];
int f[500005][25];
int d[500005];
void dfs(int x, int up = -1, int deep = 1) {
    if (f[x][0])
        return ;
    f[x][0] = up;
    d[x] = deep;
    for (int i : g[x])
        dfs(i, x, deep + 1);
}
int jump1(int x, int y) {
    int k = d[x] - d[y];
    for (int i = 21; i >= 0; i --)
        if ((k & (1 << i)) / (1 << i))
            x = f[x][i];
    return x;
}
int jump2(int x, int y) {
    if (x == y)
        return x;
    for (int i = 21; i >= 0; i --)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}
int lca(int x, int y) {
    if (d[x] < d[y])
        return lca(y, x);
    if (d[x] > d[y])
        x = jump1(x, y);
    return jump2(x, y);
}
int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i ++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(s);
    for (int j = 1; j <= 21; j ++) {
        for (int i = 1; i <= n; i ++) {
            if (f[i][j - 1] < 0) {
                f[i][j] = -1;
                continue;
            }
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
    while (m --) {
        cin >> u >> v;
        cout << lca(v, u) << endl;
    }
    return 0;
}