// https://www.luogu.com.cn/problem/P11838
#include <bits/stdc++.h>
using namespace std;
int t;
int n, k;
int a[105];
int f[105][105];
bool check(int l, int r, int size) {
    string s, str;
    s = "";
    for (int i = l; i <= l + size - 1; i ++)
        s += a[i] + '0';
    for (int i = l + size; i + size - 1 <= r; i += size) {
        str = "";
        for (int j = i; j <= i + size - 1; j ++)
            str += a[j] + '0';
        if (s != str)
            return false;
    }
    return true;
}
int main() {
    cin >> t;
    while (t --) {
        cin >> n >> k;
        memset(f, 0x3f, sizeof f);
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        for (int i = 1; i <= n; i ++)
            f[i][i] = 1;
        for (int len = 2; len <= n; len ++) {
            for (int l = 1; l + len - 1 <= n; l ++) {
                int r = l + len - 1;
                for (int pos = l; pos < r; pos ++)
                    f[l][r] = min({f[l][r], f[l][pos] + f[pos + 1][r]});
                for (int size = 1; size * size <= len; size ++) {
                    if (len % size == 0) {
                        if (check(l, r, size))
                            f[l][r] = min({f[l][r], f[l][l + size - 1]});
                        if (check(l, r, len / size))
                            f[l][r] = min({f[l][r], f[l][l + len / size - 1]});
                    }
                }
            }
        }
        if (f[1][n] <= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
