#include <iostream>
using namespace std;
int main() {
    int n, v;
    int w[31];
    int f[31][20001];
    cin >> v >> n;
    for (int i = 1; i <= n; i ++)
        cin >> w[i];
    for (int i = 0; i <= v; i ++)
        f[0][i] = 0;
    for (int i = 0; i <= n; i ++)
        f[i][0] = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= v; j ++)
            if (j >= w[i])
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + w[i]);
            else
                f[i][j] = f[i - 1][j];
    cout << v - f[n][v] << endl;
    return 0;
}