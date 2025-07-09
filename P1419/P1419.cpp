#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n, s, t;
    int a[100005], sum[100005];
    cin >> n >> s >> t;
    sum[0] = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    double maxn = -1e9;
    for (int i = s; i <= t && (double) (clock()) / CLOCKS_PER_SEC < 0.95; i ++)
        for (int j = 1; j + i <= n; j ++)
            maxn = max(maxn, (sum[j + i - 1] - sum[j - 1]) / (1.0 * i));
    cout << fixed << setprecision(3) << maxn << endl;
    return 0;
}