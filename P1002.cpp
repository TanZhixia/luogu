// https://www.luogu.com.cn/problem/P1002
#include <bits/stdc++.h>
using namespace std;
int x, y, n, m;
long long f[25][25];
int dx[] = {  2,  2,  1,  1, -1, -1, -2, -2 };
int dy[] = {  1, -1,  2, -2,  2, -2,  1, -1 };
bool check(int x, int y) {
    return x >= 0 && y >= 0 && x <= n && y <= m;
}
int main() {
    cin >> n >> m >> x >> y;
    f[x][y] = -1;
    for (int i = 0; i < 8; i ++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (check(xx, yy))
            f[xx][yy] = -1;
    }
    f[0][0] = 1;
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= m; j ++) {
            if (i == 0 && j == 0 || f[i][j] == -1)
                continue;
            if (j != 0 && f[i][j - 1] != -1)
                f[i][j] += f[i][j - 1];
            if (i != 0 && f[i - 1][j] != -1)
                f[i][j] += f[i - 1][j];
        }
    }
    cout << f[n][m] << endl;
    return 0;
}