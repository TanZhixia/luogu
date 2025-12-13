// https://www.luogu.com.cn/problem/P10112
#include <bits/stdc++.h>
using namespace std;
int t;
int n, m, a[1005];
long long s, ans;
long long C[1005][1005];
const int MOD = 1e9 + 7;
int main() {
    C[0][1] = 1;
    for (int i = 1; i <= 1004; i ++)
        for (int j = 1; j <= i + 1; j ++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    cin >> t;
    while (t --) {
        s = 0;
        ans = 1;
        cin >> n >> m;
        for (int i = 1; i <= m; i ++) {
            cin >> a[i];
            s += a[i];
        }
        if (s > n)
            n ++;
        for (int i = 1; i <= m; i ++) {
            ans *= C[n][a[i] + 1];
            ans %= MOD;
            n -= a[i];
        }
        cout << ans << endl;
    }
    return 0;
}
