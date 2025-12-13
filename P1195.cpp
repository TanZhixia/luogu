// https://www.luogu.com.cn/problem/P1195
#include <bits/stdc++.h>
using namespace std;
struct Item {
    int u, v, x;
} b[200005];
int n, m, k;
int f[5005];
int cnt = 0;
int sum = 0;
int find(int x) {
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
void join(int x, int y) {
    if (find(x) != find(y))
        f[find(x)] = find(y);
}
int main() {
    cin >> n >> m >> k;
    if (n == k) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= m; i ++) {
        int u, v, x;
        cin >> u >> v >> x;
        b[i] = { u, v, x };
    }
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    sort(b + 1, b + m + 1, [] (Item a, Item b) {
        return a.x < b.x;
    });
    for (int i = 1; i <= m && cnt < n - k; i ++) {
        int x = b[i].u;
        int y = b[i].v;
        if (find(x) == find(y))
            continue;
        join(x, y);
        sum += b[i].x;
        cnt ++;
    }
    if (cnt != n - k) {
        cout << "No Answer" << endl;
        return 0;
    }
    cout << sum << endl;
    return 0;
}