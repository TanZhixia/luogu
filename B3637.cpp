// https://www.luogu.com.cn/problem/B3637
#include <bits/stdc++.h>
using namespace std;
int n, maxn, len;
int a[5005], f[5005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        if (a[i] > f[len])
            f[++ len] = a[i];
        else
            f[lower_bound(f, f + len + 1, a[i]) - f] = a[i];
    }
    cout << len << endl;
    return 0;
}
