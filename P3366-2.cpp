// https://www.luogu.com.cn/problem/P3366
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m;
int dis[5005];
int g[5005][5005];
int ans;
bool book[5005];
void prim() {
    book[1] = true;
    dis[1] = 0;
    for (int i = 1; i <= n; i ++)
        dis[i] = min(dis[i], g[1][i]);
    for (int _ = 2; _ <= n; _ ++) {
        int temp = INF;
        int t = -1;
        for (int i = 1; i <= n; i ++) {
            if (!book[i] && dis[i] < temp) {
                temp = dis[i];
                t = i;
            }
        }
        if (t == -1) {
            ans = INF;
            return ;
        }
        book[t] = true;
        ans += dis[t];
        for (int i = 1; i <= n; i ++)
            dis[i] = min(dis[i], g[t][i]);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        dis[i] = INF;
        for (int j = 1; j <= n; j ++)
            g[i][j] = INF;
    }
    for (int i = 1; i <= m; i ++) {
        int u, v, x;
        cin >> u >> v >> x;
        g[u][v] = g[v][u] = min(g[u][v], x);
    }
    prim();
    if (ans == INF)
        cout << "orz" << endl;
    else
        cout << ans << endl;
    return 0;
}