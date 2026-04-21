// https://www.luogu.com.cn/problem/P2016
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v[1505];
vector<int> g[1505];
bool vis[1505];
int f[1505][2];
void make_tree(int node) {
    vis[node] = true;
    for (const auto& item : v[node]) {
        if (vis[item])
            continue;
        g[node].push_back(item);
        make_tree(item);
    }
}
void dfs(int node) {
    for (const auto& item : g[node])
        dfs(item);
    f[node][0] = 0;
    f[node][1] = 1;
    for (const auto& item : g[node]) {
        f[node][0] += f[item][1];
        f[node][1] += min(f[item][0], f[item][1]);
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int a, b, c;
        cin >> a >> b;
        while (b --) {
            cin >> c;
            v[a].push_back(c);
            v[c].push_back(a);
        }
    }
    make_tree(0);
    dfs(0);
    cout << min(f[0][0], f[0][1]) << endl;
    return 0;
}
