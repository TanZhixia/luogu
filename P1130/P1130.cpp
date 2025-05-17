#include <iostream>
using namespace std;
int table[2000][2000];
int dp[2000][2000];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i ++)
        for (int j = 0; j < n; j ++)
            cin >> table[j][i];
    for (int i = 0; i < m; i ++)
        dp[0][i] = table[0][i];
    for (int i = 1; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int index1 = (j - 1 + m) % m;
            int index2 = j;
            dp[i][j] = table[i][j] + min(dp[i - 1][index1], dp[i - 1][index2]);
        }
    }
    int answer = dp[n - 1][0];
    for (int i = 1; i < m; i ++)
        answer = min(answer, dp[n - 1][i]);
    cout << answer << endl;
    return 0;
}