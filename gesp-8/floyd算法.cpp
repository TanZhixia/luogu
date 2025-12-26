#include <bits/stdc++.h>
using namespace std;
int dis[15][15];
int g[15][15];
int n, m;
const int INF = 1e9;
void floyd() {
    memcpy(dis, g, sizeof(g));
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if (dis[i][k] < INF && dis[k][j] < INF)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (i != j)
                g[i][j] = INF;
    for (int i = 1; i <= m; i ++) {
        int u, v, x;
        cin >> u >> v >> x;
        g[u][v] = g[v][u] = x;
    }
    floyd();
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++)
            cout << dis[i][j] << " ";
        cout << endl;
    }
    return 0;
}
