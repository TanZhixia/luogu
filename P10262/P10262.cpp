#include <iostream>
#include <cstring>
#define int long long
using namespace std;
int dp[128], f[128];
string s;
signed main() {
    int p, ans = 0;
    cin >> p >> s;
    memset(dp, 0, sizeof(dp));
    memset(f, 0, sizeof(f));
    for (int i  = 0; i < s.size(); i ++) {
        int d = (s[i] - '0') % p;
        memset(f, 0, sizeof(f));
        for (int j = 0; j < p; j ++)
            if (dp[j])
                f[(j * 10 + d) % p] += dp[j];
        f[d] ++;
        ans += f[0];
        memcpy(dp, f, sizeof(f));
    }
    cout << ans << endl;
    return 0;
}