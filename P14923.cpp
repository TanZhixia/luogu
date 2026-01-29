// https://www.luogu.com.cn/problem/P14923
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#define int long long
using namespace std;
struct Node {
    int v;
    int w;
    Node(int v, int w) : v(v), w(w) {}
    bool operator>(const Node& other) const {
        return w > other.w;
    }
};
Node make_node(int v, int w) {
    return Node(v, w);
}
int n, m;
int a, b;
int c[100005];
int u, v, w;
int ans;
vector<Node> g[100005];
int dis[100005], vis[100005];
priority_queue<Node, vector<Node>, greater<Node>> pq;
void dij() {
    fill(dis + 1, dis + n + 1, 1e18);
    fill(vis + 1, vis + n + 1, 0);
    dis[b] = 0;
    pq.push(make_node(b, 0));

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        int u = cur.v;

        if (vis[u]) continue;
        vis[u] = 1;

        for (const auto& edge : g[u]) {
            int v = edge.v, w = edge.w;
            if (!vis[v] && dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push(make_node(v, dis[v]));
            }
        }
    }
}
signed main() {
    cin >> n >> m;
    cin >> a >> b;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    for (int i = 1; i <= m; i ++) {
        cin >> u >> v >> w;
        g[u].push_back(make_node(v, w));
        g[v].push_back(make_node(u, w));
    }
    dij();
    for (int i = 1; i <= n; i ++)
        if (dis[i] < dis[a])
            ans += c[i];
    cout << ans << endl;
    return 0;
}
