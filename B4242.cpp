// https://www.luogu.com.cn/problem/B4242
#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005];
int b[100005];
int ans = 0;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    for (int i = 1; i <= n; i ++) {
        int index = lower_bound(b + 1, b + 1 + m, a[i]) - b;
        if (index == 1)
            index = 2;
        if (index > m)
            index = m;
        ans = max(ans, min(abs(a[i] - b[index]), abs(a[i] - b[index - 1])));
    }
    cout << ans << endl;
    return 0;
}
