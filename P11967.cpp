// https://www.luogu.com.cn/problem/P11967
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[1000005];
int a, b;
int f[1000005][20];
int d[1000005];
int tree[1000005];
int b1, b2;
int ans;
void dfs(int node, int fa = -1, int deep = 1) {
    if (f[node][0])
        return;
    if (fa == -1)
        fa = node;
    f[node][0] = fa;
    d[node] = deep;
    for (int i : g[node])
        dfs(i, node, deep + 1);
}
int jump(int x, int deep) {
    for (int i = 19; i >= 0; i --)
        if (deep & (1 << i))
            x = f[x][i];
    return x;
}
int lca(int u, int v) {
    if (d[u] > d[v])
        return lca(v, u);
    v = jump(v, d[v] - d[u]);
    if (u == v)
        return u;
    for (int i = 19; i >= 0; i --)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}
void dfs2(int node, int fa) {
    for(int v : g[node]){
		if(v == fa) continue;
		dfs2(v, node);
		tree[node] += tree[v];
	}
}
int main() {
    cin >> n >> m;
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int j = 1; j <= 19; j ++)
        for (int i = 1; i <= n; i ++)
            f[i][j] = f[f[i][j - 1]][j - 1];
    for (int i = 1; i <= m; i ++) {
        cin >> a >> b;
        int l = lca(a, b);
        tree[a] ++;
        tree[b] ++;
        tree[l] --;
        if (f[l][0] == l)
            continue;
        tree[f[l][0]] --;
    }
    cin >> b1 >> b2;
    dfs2(1, 0);
    int l = lca(b1, b2);
    for (int i = b1; i != l; i = f[i][0])
        if (tree[i] == 0)
            ans ++;
    for (int i = b2; i != l; i = f[i][0])
        if (tree[i] == 0)
            ans ++;
    if (tree[l] == 0)
        ans ++;
    cout << ans << endl;
    return 0;
}
