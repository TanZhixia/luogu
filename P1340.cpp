// https://www.luogu.com.cn/problem/P1340
#include <bits/stdc++.h>
using namespace std;
int n, w;
struct Edge {
    int u, v, x;
} edge[6005];
int f[205];
int find(int x) {
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
void join(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy)
        f[fx] = fy;
}
int main() {
    cin >> n >> w;
    for (int i = 1; i <= w; i ++) {
        int u, v, x;
        cin >> u >> v >> x;
        edge[i] = { u, v, x };
        for (int i = 1; i <= n; i ++)
            f[i] = i;
        sort(edge + 1, edge + i + 1, [](Edge a, Edge b) { return a.x < b.x; });
        int cnt = 0;
        int sum = 0;
        for (int j = 1; j <= i && cnt < n - 1; j ++) {
            int x = edge[j].u, y = edge[j].v;
            if (find(x) == find(y))
                continue;
            join(x, y);
            sum += edge[j].x;
            cnt ++;
        }
        if (cnt != n - 1) {
            cout << -1 << endl;
            continue;
        }
        cout << sum << endl;
    }
    return 0;
}