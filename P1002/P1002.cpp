#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int a, b, n, m;
    long long dp[25][25];
    int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2, 0 };
    int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1, 0 };
    cin >> a >> b >> n >> m;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < 9; i ++) {
        int newX = n + dx[i];
        int newY = m + dy[i];
        if (newX >= 0 && newX <= a && newY >= 0 && newY <= b)
            dp[newX][newY] = -1;
    }
    for (int i = 0; i <= a; i ++) {
        for (int j = 0; j <= b; j ++) {
            if (dp[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if (i - 1 >= 0)
                dp[i][j] += dp[i - 1][j];
            if (j - 1 >= 0)
                dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}