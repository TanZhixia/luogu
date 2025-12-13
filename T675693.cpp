// https://www.luogu.com.cn/problem/T675693
#include <bits/stdc++.h>
using namespace std;
int m, n;
char s[2005];
int c[255][2];
int f[2005][2005];
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i ++)
        cin >> s[i];
    for (int i = 1; i <= m; i ++) {
        char op[2];
        int a, b;
        cin >> op >> a >> b;
        c[op[0]][0] = a;
        c[op[0]][1] = b;
    }
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i ++)
        f[i][i] = 0;
    for (int i = 0; i <= n + 1; i ++)
        for (int j = 0; j < i; j ++)
            f[i][j] = 0;
    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i + k <= n; i ++) {
            int j = i + k;
            f[i][j] = min(f[i + 1][j] + min(c[s[i]][0], c[s[i]][1]), f[i][j - 1] + min(c[s[j]][0], c[s[j]][1]));
            if (s[i] == s[j]) {
                if (j - i == 1)
                    f[i][j] = 0;
                else
                    f[i][j] = min(f[i][j], f[i + 1][j - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}