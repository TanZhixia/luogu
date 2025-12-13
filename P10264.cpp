// https://www.luogu.com.cn/problem/P10264
#include <bits/stdc++.h>
using namespace std;
int t, n, q;
int main() {
    cin >> t;
    while (t --) {
        int x, y, a[4][15005] = {}, v[14] = {};
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> x;
            a[0][v[x]] = i;
            v[x] = i;
        }
        for (int i = 1; i <= 3; i ++) {
            for (int j = 1; j <= n - (1 << i + 1) - 1; j ++) {
                if (a[i - 1][j]) {
                    int p = a[i - 1][j];
                    if (a[0][p] == p + 1)
                        a[i][j] = a[i - 1][p + 1];
                }
            }
        }
        cin >> q;
        while (q --) {
            cin >> x >> y;
            int ans = 0;
            for (int i = x; i <= y; i ++) {
                int f = 0;
                for (int j = 3; j >= 0; j --) {
                    if (a[j][i] > i && a[j][i] <= y) {
                        i = a[j][i];
                        f = 1;
                        break;
                    }
                }
                if (!f)
                    ans ++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}