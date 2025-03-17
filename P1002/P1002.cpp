#include <iostream>
using namespace std;
long long dp[30][30];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    dp[0][0] = 1;
    for (int i = 0; i < 8; i ++) {
        int x = a + dx[i], y = b + dy[i];
        if (x >= 0 && x <= n && y >= 0 && y <= m)
            dp[x][y] = -1;
    }
    dp[a][b] = -1;
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= m; j ++)
            if (dp[i][j] == -1)
                dp[i][j] = 0;
            else {
                if (i - 1 >= 0)
                    dp[i][j] += dp[i - 1][j];
                if (j - 1 >= 0)
                    dp[i][j] += dp[i][j - 1];
            }
    cout << dp[n][m] << endl;
    return 0;
}