// https://www.luogu.com.cn/problem/P1439
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int b[100005];
int f[100005];
map<int, int> m;
int len;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        m[a[i]] = i;
        a[i] = i;
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        b[i] = m[b[i]];
    }
    for (int i = 1; i <= n; i ++) {
        if (b[i] > f[len])
            f[++ len] = b[i];
        else
            f[lower_bound(f, f + len + 1, b[i]) - f] = b[i];
    }
    cout << len << endl;
    return 0;
}
