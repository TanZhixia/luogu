// https://www.luogu.com.cn/problem/T675692
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005], s[1005];
int dp[1005][105];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] ^ a[i];
    for (int i = 1; i <= n; i ++)
        dp[i][1] = s[i];
    for (int j = 2; j <= m; j ++)
        for (int k = 1; k <= n; k ++)
            for (int i = k; i <= n; i ++)
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + (s[i] ^ s[k]));
    cout << dp[n][m] << endl;
    return 0;
}