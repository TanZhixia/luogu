// https://www.luogu.com.cn/problem/B4241
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int ans = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        int number = a[i];
        for (int j = 1; j <= 30; j++) {
            int k = (1 << j) - a[i];
            if (k <= 0)
                continue;
            int l = lower_bound(a + 1 + i, a + 1 + n, k) - a;
            if (a[l] == k) {
                ans += upper_bound(a + 1, a + 1 + n, k) - a - l;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
