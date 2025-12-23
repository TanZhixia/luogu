// https://www.luogu.com.cn/problem/P14080
#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Edge {
    int index, u, v, w;
} edge[100005];
int fa[100005];
int find(int x) {
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void join(int fx, int fy) {
    if (fx != fy)
        fa[fx] = fy;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        edge[i].index = i;
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge + 1, edge + 1 + m, [] (Edge a, Edge b) {
        return a.w < b.w;
    });
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++)
            fa[j] = j;
        long long ans = 0;
        int cnt = 0;
        for (int j = 1; j <= m && cnt < n - 1; j ++) {
            if (edge[j].index == i)
                continue;
            int fx = find(edge[j].u);
            int fy = find(edge[j].v);
            if (fx == fy)
                continue;
            cnt ++;
            ans += edge[j].w;
            join(fx, fy);
            // cout << "use:" << edge[j].u << " " << edge[j].v << endl;
        }
        if (cnt < n - 1)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}
