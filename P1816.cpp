// https://www.luogu.com.cn/problem/P1816
#include <bits/stdc++.h>
using namespace std;
int m, n;
int l, r;
int st[100005][25];
int Log[100005];
int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        cin >> st[i][0];
    Log[1] = 0;
    for (int i = 2; i <= m; i ++)
        Log[i] = Log[i / 2] + 1;
    for (int j = 1; j <= 20; j ++)
        for (int i = 1; i + (1 << j) - 1 <= m; i ++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    while (n --) {
        cin >> l >> r;
        int k = Log[r - l + 1];
        cout << min(st[l][k], st[r - (1 << k) + 1][k]) << " ";
    }
    cout << endl;
    return 0;
}