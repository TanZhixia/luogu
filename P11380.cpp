// https://www.luogu.com.cn/problem/P11380
#include <iostream>
using namespace std;
const int MOD = 1000000007;
int g[2][200005];
int n, m, cnt, ans = 1, sum;
bool vis[200005];
void dfs(int u) {
    vis[u] = 1;
    sum ++;
    while (g[1][u]) {
        u = g[1][u];
        if (vis[u]) {
            cout << 0 << endl;
            exit(0);
        }
        vis[u] = 1;
        sum ++;
    }
}
int main() {
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        cin >> u >> v;
        if (g[1][u] && g[1][u] != v || g[0][v] && g[0][v] != u) {
            cout << 0 << endl;
            return 0;
        }
        g[1][u] = v;
        g[0][v] = u;
    }
    for (int i = 1; i <= n; i ++) {
        if (!vis[i] && (!g[0][i])) {
            dfs(i);
            cnt ++;
        }
    }
    if (sum != n) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= cnt; i ++)
        ans = (1ll * ans * i) % MOD;
    cout << ans << endl;
    return 0;
}
