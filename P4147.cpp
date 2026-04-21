// https://www.luogu.com.cn/problem/P4147
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005][1005];
int up[1005][1005];
char c;
int ans;
void Read() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> c;
            if (c == 'F')
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
}
void initUpList() {
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (a[i][j])
                up[i][j] = up[i - 1][j] + 1;
}
void calcProblem() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            int len = 1;
            for (int k = j + 1; k <= m && up[i][k] >= up[i][j]; k ++)
                len ++;
            for (int k = j - 1; k >= 1 && up[i][k] >= up[i][j]; k --)
                len ++;
            ans = max({ans, len * up[i][j]});
        }
    }
}
void calcAns() {
    ans *= 3;
}
void Core() {
    initUpList();
    calcProblem();
    calcAns();
}
void Write() {
    cout << ans << endl;
}
int main() {
    Read();
    Core();
    Write();
    return 0;
}
