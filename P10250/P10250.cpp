#include <iostream>
using namespace std;
int main() {
    long long dp[61], n;
    cin >> n;
    dp[0] = 1ll;
    dp[1] = 1ll;
    for (int i = 2; i <= n; i ++) {
        dp[i] = dp[i - 1];
        if (i - 2 >= 0)
            dp[i] += dp[i - 2];
        if (i - 3 >= 0)
            dp[i] += dp[i - 3];
    }
    cout << dp[n] << endl;
    return 0;
}