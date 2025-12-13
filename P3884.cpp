// https://www.luogu.com.cn/problem/P3884
#include <bits/stdc++.h>
using namespace std;
int n, u, v;
int x, y;
vector<int> g[105];
int d[105], w[105];
int f[105][15];
int ansD, ansW;
void dfs(int x, int father = -1, int deep = 1) {
    if (f[x][0])
        return ;
    d[x] = deep;
    f[x][0] = father;
    for (int i = 0; i < g[x].size(); i ++)
        dfs(g[x][i], x, deep + 1);
}
int jump1(int x, int y) {
    int k = d[x] - d[y];
    for (int i = 10; i >= 0; i --)
        if ((k & (1 << i)))
            x = f[x][i];
    return x;
}
int jump2(int x, int y) {
    if (x == y)
        return x;
    for (int i = 10; i >= 0; i --)
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
    cin >> n;
    for (int i = 1; i <= n - 1; i ++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> x >> y;
    dfs(1);
    ansD = d[1];
    for (int i = 2; i <= n; i ++)
        ansD = max(ansD, d[i]);
    cout << ansD << endl;
    for (int i = 1; i <= n; i ++)
        w[d[i]] ++;
    ansW = w[1];
    for (int i = 2; i <= n; i ++)
        ansW = max(ansW, w[i]);
    cout << ansW << endl;
    for (int j = 1; j <= 10; j ++) {
        for (int i = 1; i <= n; i ++) {
            if (f[i][j - 1] < 0) {
                f[i][j] = -1;
                continue;
            }
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
    cout << 2 * (d[x] - d[lca(x, y)]) + (d[y] - d[lca(x, y)]) << endl;
    return 0;
}
