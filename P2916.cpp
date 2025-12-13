// https://www.luogu.com.cn/problem/P2916
#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[10005];
int father[10005];
int ans;
struct Edge {
    int u, v, x;
} edge[100005];
int find(int x) {
    if (father[x] == x)
        return x;
    return father[x] = find(father[x]);
}
void join(int x, int y) {
    father[find(x)] = find(y);
}
int main() {
    cin >> n >> m;
    int minc = 1e9;
    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
        minc = min(minc, c[i]);
        father[i] = i;
    }
    for (int i = 1; i <= m; i ++) {
        int u, v, x;
        cin >> u >> v >> x;
        edge[i] = { u, v, x * 2 + c[u] + c[v] };
    }
    sort(edge + 1, edge + 1 + m, [] (Edge a, Edge b) {
        return a.x < b.x;
    });
    for (int i = 1; i <= m; i ++) {
        int x = edge[i].u;
        int y = edge[i].v;
        if (find(x) == find(y))
            continue;
        join(x, y);
        ans += edge[i].x;
    }
    cout << ans + minc << endl;
    return 0;
}
