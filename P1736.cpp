// https://www.luogu.com.cn/problem/P1736
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[2505][2505];
int s1[2505][2505];
int s2[2505][2505];
int f1[2505][2505];
int f2[2505][2505];
int ans;
void Read() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
}
void calcSum() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            s1[i][j] = s1[i][j - 1] + a[i][j];
            s2[i][j] = s2[i - 1][j] + a[i][j];
        }
    }
}
void workF1() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (a[i][j] == 0) {
                f1[i][j] = 0;
                continue;
            }
            if (i == 1 || j == 1) {
                f1[i][j] = 1;
                continue;
            }
            int cntI, cntJ;
            int size = f1[i - 1][j - 1] + 1;
            cntI = cntJ = 1;
            for (int ii = i - 1; ii > i - size && a[ii][j] == 0; ii --)
                cntI ++;
            for (int jj = j - 1; jj > j - size && a[i][jj] == 0; jj --)
                cntJ ++;
            f1[i][j] = min({cntI, cntJ, size});
        }
    }
}
void workF2() {
    for (int i = 1; i <= n; i ++)
        reverse(a[i] + 1, a[i] + 1 + m);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (a[i][j] == 0) {
                f2[i][j] = 0;
                continue;
            }
            if (i == 1 || j == 1) {
                f2[i][j] = 1;
                continue;
            }
            int cntI, cntJ;
            int size = f2[i - 1][j - 1] + 1;
            cntI = cntJ = 1;
            for (int ii = i - 1; ii > i - size && a[ii][j] == 0; ii --)
                cntI ++;
            for (int jj = j - 1; jj > j - size && a[i][jj] == 0; jj --)
                cntJ ++;
            f2[i][j] = min({cntI, cntJ, size});
        }
    }
}
void calcAns() {
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            ans = max({ans, f1[i][j], f2[i][j]});
}
void Core() {
    calcSum();
    workF1();
    workF2();
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
