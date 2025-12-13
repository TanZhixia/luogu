// https://www.luogu.com.cn/problem/P4826
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int f[2005];
struct Item {
    int u, v, x;
};
vector<Item> b;
int a[2005];
int cnt, sum;
int find(int x) {
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
void join(int x, int y) {
    int xx = find(x), yy = find(y);
    if (xx != yy)
        f[xx] = yy;
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            b.push_back({ i, j, a[i] ^ a[j] });
    sort(b.begin(), b.end(), [](Item a, Item b) {
        return a.x > b.x;
    });
    for (Item i : b) {
        int fx = find(i.u), fy = find(i.v);
        if (fx == fy)
            continue;
        cnt ++;
        sum += i.x;
        join(i.u, i.v);
        if (cnt == n - 1)
            break;
    }
    cout << sum << endl;
    return 0;
}