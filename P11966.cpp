// https://www.luogu.com.cn/problem/P11966
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct node {
    int v, d;
};
vector<node> g[200005];
queue<int> q;
int n, m, u, v, d, s, t;
long long ans[200005];
bool vis[200005];
void spfa() {
    memset(ans, 0x3f, sizeof(ans));
    ans[s] = 0;
    q.push(s);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        vis[u] = 0;
        for (node i : g[u]) {
            v = i.v;
            d = i.d;
            if (ans[u] + d >= ans[v])
                continue;
            ans[v] = ans[u] + d;
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}
int main() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i ++) {
        cin >> u >> v >> d;
        g[u].push_back({v, d});
        g[v].push_back({u, d});
    }
    spfa();
    while (t --) {
        cin >> u;
        cout << ans[u] << endl;
    }
    return 0;
}
