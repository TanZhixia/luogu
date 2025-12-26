// https://www.luogu.com.cn/problem/P13019
#include <bits/stdc++.h>
using namespace std;
int n, q;
int fa[100005][21];
int son[100005][21];
int a[100005];
int s, k;
int main() {
    cin >> n >> q;
    fa[1][0] = 1;
    for (int i = 1; i <= n; i ++)
        son[i][0] = i;
    for (int i = 2; i <= n; i ++) {
        cin >> fa[i][0];
        if (son[fa[i][0]][0] == fa[i][0])
            son[fa[i][0]][0] = i;
    }
    for (int i = 1; i <= 20; i ++)
        for (int j = 1; j <= n; j ++)
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
    for (int i = 1; i <= 20; i ++)
        for (int j = 1; j <= n; j ++)
            son[j][i] = son[son[j][i - 1]][i - 1];
    while (q --) {
        cin >> s >> k;
        for (int i = 1; i <= k; i ++)
            cin >> a[i];
        for (int i = 1; i <= k; i ++) {
            if (a[i] > 0)
                for (int j = 20; j >= 0; j --)
                    if (a[i] & (1 << j))
                        s = fa[s][j];
            if (a[i] < 0) {
                a[i] = abs(a[i]);
                for (int j = 20; j >= 0; j --)
                    if (a[i] & (1 << j))
                        s = son[s][j];
            }
        }
        cout << s << endl;
    }
    return 0;
}
