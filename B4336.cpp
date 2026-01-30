// https://www.luogu.com.cn/problem/B4336
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int f[1005][1005];
int main() {
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i <= n; i ++)
        f[i][i] = 1;
    for (int len = 2; len <= n; len ++) {
        for (int l = 1; l + len - 1 <= n; l ++) {
            int r = l + len - 1;
            if (s[l] == s[r])
                f[l][r] = f[l + 1][r - 1] + 2;
            else
                f[l][r] = max({f[l + 1][r], f[l][r - 1]});
        }
    }
    cout << f[1][n] << endl;
    return 0;
}
