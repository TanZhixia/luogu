// https://www.luogu.com.cn/problem/P11250
#include <bits/stdc++.h>
using namespace std;
int t;
int n, m, k;
int c[1005][1005];
int pow2[2005];
const int MOD = 1e9 + 7;
void init() {
    pow2[0] = 1;
    for (int i = 1; i <= 2004; i ++)
        pow2[i] = (2ll * pow2[i - 1]) % MOD;
    c[0][1] = 1;
    for (int i = 1; i <= 1004; i ++)
        for (int j = 1; j <= i + 1; j ++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
}
int main() {
    init();
    cin >> t;
    while (t --) {
        cin >> n >> m >> k;
        if (m - 2 * k < 0 || m - 2 * k > n - k) {
            cout << 0 << endl;
            continue;
        }
        cout << (((1ll * c[n][k + 1] * c[n - k][m - 2 * k + 1]) % MOD) * pow2[m - 2 * k]) % MOD << endl;
    }
    return 0;
}
