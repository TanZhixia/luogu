// https://www.luogu.com.cn/problem/P4170
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int f[55][55];
int main() {
    cin >> s;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i ++)
        f[i][i] = 1;
    for (int len = 2; len <= n; len ++) {
        for (int i = 1; i + len - 1 <= n; i ++) {
            int j = i + len - 1;
            f[i][j] = 1e9;
            if (s[i] == s[j])
                f[i][j] = min({f[i][j], f[i + 1][j], f[i][j - 1]});
            for (int pos = i; pos < j; pos ++)
                f[i][j] = min({f[i][j], f[i][pos] + f[pos + 1][j]});
        }
    }
    cout << f[1][n] << endl;
    return 0;
}
