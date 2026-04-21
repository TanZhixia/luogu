// https://www.luogu.com.cn/problem/P4395
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int head[N], ver[N], net[N], tot;
int n, f[N][20], ans = 0x3f3f3f3f;
void add(int a, int b) {
    net[++tot] = head[a];
    head[a] = tot;
    ver[tot] = b;
}
void dfs(int x, int fa) {
    for (int i = 1; i <= 15; i++)
        f[x][i] = i;
    for (int i = head[x]; i; i = net[i]) {
        int v = ver[i];
        if (v == fa)
            continue;
        dfs(v, x);
        for (int j = 1; j <= 15; j++) {
            int minn = 0x3f3f3f3f;
            for (int k = 1; k <= 15; k++) {
                if (j != k)
                    minn = min(minn, f[v][k]);
            }
            f[x][j] += minn;
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    for (int i = 1; i <= 15; i++)
        ans = min(ans, f[1][i]);
    printf("%d", ans);
    return 0;
}
