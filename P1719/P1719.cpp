#include <iostream>
using namespace std;
int main() {
    int n;
    int a[200][200];
    int sum[200][200];
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    int maxn = -10000000;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            for (int ii = i; ii <= n; ii ++)
                for (int jj = j; jj <= n; jj ++)
                    maxn = max(maxn, sum[ii][jj] - sum[i - 1][jj] - sum[ii][j - 1] + sum[i - 1][j - 1]);
    cout << maxn << endl;
    return 0;
}