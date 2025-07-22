#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int n, k, ans;
double x[1005], y[1005];
double maxX = 0, maxY = 0;
int f[1005];
int find(int x) {
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
bool check(double mid) {
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= mid)
                f[find(i)] = find(j);
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        if (f[i] == i)
            cnt ++;
    return cnt >= k;
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> x[i] >> y[i];
        maxX = max(maxX, x[i]);
        maxY = max(maxY, y[i]);
    }
    double l = 0, r = maxX * maxX + maxY * maxY;
    while (r - l > 0.0000001) {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(2) << sqrt(l) << endl;
    return 0;
}