// https://www.luogu.com.cn/problem/P2986
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;
int a[100005];
vector<pii> v[100005];
vector<pii> g[100005];
bool vis[100005];
int dp1[100005];
int dp2[100005];
int siz[100005];
int ans = 1e9;
void make_tree(int node) {
    vis[node] = true;
    for (int i = 0; i < v[node].size(); i ++) {
        if (vis[v[node][i].first])
            continue;
        g[node].push_back(v[node][i]);
        make_tree(v[node][i].first);
    }
}
void dfs1(int node) {
    dp1[node] = 0;
    siz[node] = a[node];
    for (int i = 0; i < g[node].size(); i ++) {
        dfs1(g[node][i].first);
        dp1[node] +=
            dp1[g[node][i].first] + siz[g[node][i].first] * g[node][i].second;
        siz[node] += siz[g[node][i].first];
    }
}
void dfs2(int node) {
    for (int i = 0; i < g[node].size(); i ++) {
        const auto &v = g[node][i].first;
        const auto &w = g[node][i].second;
        dp2[v] = dp2[node] + dp1[node] - (dp1[v] + siz[v] * w) +
                 (siz[i] - siz[v]) * w;
        dfs2(v);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i < n; i ++) {
        int a, b, l;
        cin >> a >> b >> l;
        v[a].push_back({b, l});
        v[b].push_back({a, l});
    }
    make_tree(1);
    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= n; i ++)
        ans = min(ans, dp2[i]);
    cout << ans << endl;
    return 0;
}
