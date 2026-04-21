// https://www.luogu.com.cn/problem/P3522
#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n;
int a[N], b[N], q[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i] >> b[i];
    int l = 1, r = 0, ans = 0, len;
    for (int i = 1; i <= n; i ++) {
        while (l <= r && a[q[l]] > b[i])
            l ++;
        if (l > r)
            len = 1;
        else
            len = i - q[l - 1];
        ans = max(ans, len);
        while (l <= r && a[q[r]] < a[i])
            r --;
        q[++ r] = i;
    }
    cout << ans << endl;
    return 0;
}
