// https://www.luogu.com.cn/problem/P11500
#include <bits/stdc++.h>
using namespace std;
int n, k;
int f[5005][5005][2];
int g[5005][5005][2];
const int mod = 1e9 + 7;
int main() {
    cin >> n >> k;
    if (n == k) {
        cout << 1 << endl;
        return 0;
    }
    f[k][k][0] = f[k][k][1] = 1;
    for (int i = 1; i <= n; i ++) {
        g[k][i][0] = g[k][i - 1][0] + f[k][i][0];
        g[k][i][1] = g[k][i - 1][0] + f[k][i][1];
    }
    for (int i = k + 1; i <= n; i ++) {
        for (int j = 1; j < i; j ++) {
            f[i][j][0] = g[i - j][j - 1][1] % mod;
            f[i][j][1] = (g[i - j][i - 1][0] - g[i - j][j][0] + mod) % mod;
        }
        for (int j = 1; j <= n; j ++) {
            g[i][j][0] = (g[i][j - 1][0] + f[i][j][0]) % mod;
            g[i][j][1] = (g[i][j - 1][1] + f[i][j][1]) % mod;
        }
    }
    cout << (g[n][n][0] + g[n][n][1]) % mod << endl;
    return 0;
}
