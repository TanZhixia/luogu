#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int a[1005][1005];
int s[1005][1005];
bool check(int mid) {
    memset(s, 0, sizeof(a));
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] >= mid);
    for (int i = 1; i + mid - 1 <= n; i ++)
        for (int j = 1; j + mid - 1 <= m; j ++)
            if (s[i + mid - 1][j + mid - 1] - s[i - 1][j + mid - 1] - s[i + mid - 1][j - 1] + s[i - 1][j - 1] == mid * mid)
                return true;
    return false;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    int l, r, ans;
    l = 1;
    r = min(n, m);
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
            continue;
        }
        r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}