#include <iostream>
using namespace std;
int main() {
    int r;
    int a[1001][1001];
    int f[1001][1001];
    cin >> r;
    for (int i = 1; i <= r; i ++)
        for (int j = 1; j <= i; j ++)
            cin >> a[i][j];
    for (int i = 1; i <= r; i ++)
        f[r][i] = a[r][i];
    for (int i = r - 1; i >= 1; i --)
        for (int j = 1; j <= i; j ++)
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
    cout << f[1][1] << endl;
    return 0;
}