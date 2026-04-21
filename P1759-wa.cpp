// https://www.luogu.com.cn/problem/P1759
#include <bits/stdc++.h>
using namespace std;
int n, m, v;
int a[105], b[105], c[105];
int f[205][205][105];
int dp[205][205][105][105];
int size[205][205][105];
void Read() {
    cin >> m >> v >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i] >> b[i] >> c[i];
}
void runDp() {
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= v; j ++) {
            for (int k = 1; k <= n; k ++) {
                for (int w = 0; w < size[i][j][k - 1]; w ++)
                    dp[i][j][k][w] = dp[i][j][k - 1][w];
                size[i][j][k] = size[i][j][k - 1];
                if (a[k] > i || b[k] > j) {
                    f[i][j][k] = f[i][j][k - 1];
                    continue;
                }
                // f[i][j][k] = max({f[i][j][k - 1], f[i - a[k]][j - b[k]][k - 1] + c[k]});
                if (f[i][j][k - 1] > f[i - a[k]][j - b[k]][k - 1] + c[k]) {
                    f[i][j][k] = f[i][j][k - 1];
                    continue;
                }
                f[i][j][k] = f[i - a[k]][j - b[k]][k - 1] + c[k];
                // dp[i][j][k].push_back(k);
                dp[i][j][k][size[i][j][k] ++] = k;
            }
        }
    }
}
void Core() {
    runDp();
}
void Write() {
    cout << f[m][v][n] << endl;
    for (int i = 0; i < size[m][v][n]; i ++)
        cout << dp[m][v][n][i] << " ";
    cout << endl;
}
int main() {
    Read();
    Core();
    Write();
    return 0;
}
