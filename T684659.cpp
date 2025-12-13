// https://www.luogu.com.cn/problem/T684659
#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int u, v, cnt;
int g[100005];
bool vis[100005];
int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i ++) {
        cin >> u >> v;
        g[v] = (g[v] == 0 ? u : g[v]);
    }
    while (g[p]) {
        vis[p] = true;
        p = g[p];
        cnt ++;
        if (vis[p]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
    return 0;
}