// https://www.luogu.com.cn/problem/P2097
#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[100005];
int u, v;
int ans;
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
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    for (int i = 1; i <= m; i ++) {
        cin >> u >> v;
        join(u, v);
    }
    for (int i = 1; i <= n; i ++)
        if (f[i] == i)
            ans ++;
    cout << ans << endl;
    return 0;
}