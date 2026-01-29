// https://www.luogu.com.cn/problem/P1133
#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, a[1000005][4], dp[1000005][4][3][4];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    dp[1][0][1][0] = a[1][0];
    dp[1][1][0][1] = a[1][1];
    dp[1][1][1][1] = a[1][1];
    dp[1][2][0][2] = a[1][2];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 2; j++) {
            dp[i][0][1][j] = max({dp[i - 1][1][0][j], dp[i - 1][2][0][j]}) + a[i][0];
            dp[i][1][0][j] = dp[i - 1][0][1][j] + a[i][1];
            dp[i][1][1][j] = dp[i - 1][2][0][j] + a[i][1];
            dp[i][2][0][j] = max({dp[i - 1][0][1][j], dp[i - 1][1][1][j]}) + a[i][2];
        }
    }
    ans = max({
        dp[n][0][1][1],
        dp[n][0][1][2],
        dp[n][1][1][2],
        dp[n][1][0][0],
        dp[n][2][0][0],
        dp[n][2][0][1]
    });
    cout << ans << endl;
    return 0;
}
