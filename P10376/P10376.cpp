#include <iostream>
using namespace std;
int dp[200005];
int main() {
    const int maxn = 1000000007;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    dp[n] = 1;
    for (int i = n; i > c; i --) {
        if (i - a <= c)
            dp[c] = (dp[c] + dp[i]) % maxn;
		else
            dp[i - a] = (dp[i - a] + dp[i]) % maxn;
		if (i - b <= c)
            dp[c] = (dp[c] + dp[i]) % maxn;
		else
            dp[i - b] = (dp[i - b] + dp[i]) % maxn;
    }
    cout << dp[c] << endl;
    return 0;
}